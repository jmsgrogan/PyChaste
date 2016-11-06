/*

Copyright (c) 2005-2016, University of Oxford.
 All rights reserved.

 University of Oxford means the Chancellor, Masters and Scholars of the
 University of Oxford, having an administrative office at Wellington
 Square, Oxford OX1 2JD, UK.

 This file is part of Chaste.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice,
 this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 * Neither the name of the University of Oxford nor the names of its
 contributors may be used to endorse or promote products derived from this
 software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#define _BACKWARD_BACKWARD_WARNING_H 1 //Cut out the vtk deprecated warning
#include <vtkWindowToImageFilter.h>
#include <vtkPNGWriter.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkUnsignedCharArray.h>
#if VTK_MAJOR_VERSION > 5
    #include <vtkNamedColors.h>
#endif
#include <vtkSphereSource.h>
#include <vtkGlyph3D.h>
#include <vtkGlyph2D.h>
#include <vtkCubeAxesActor2D.h>
#include <vtkImageData.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkObjectFactory.h>
#include <vtkActorCollection.h>
#include <vtkUnstructuredGrid.h>
#include <vtkGeometryFilter.h>
#include <vtkTubeFilter.h>
#include <vtkExtractEdges.h>
#include <vtkCamera.h>
#include <vtkVertexGlyphFilter.h>
#include "UblasIncludes.hpp"
#include "UblasVectorInclude.hpp"
#include "Exception.hpp"
#include "VtkScene.hpp"

// For some reason an explicit interactor style is needed capture mouse events
class customMouseInteractorStyle : public vtkInteractorStyleTrackballCamera
{
  public:
    static customMouseInteractorStyle* New();
    vtkTypeMacro(customMouseInteractorStyle, vtkInteractorStyleTrackballCamera);

    virtual void OnLeftButtonDown()
    {
      // Forward events
      vtkInteractorStyleTrackballCamera::OnLeftButtonDown();
    }

    virtual void OnMiddleButtonDown()
    {
      // Forward events
      vtkInteractorStyleTrackballCamera::OnMiddleButtonDown();
    }

    virtual void OnRightButtonDown()
    {
      // Forward events
      vtkInteractorStyleTrackballCamera::OnRightButtonDown();
    }

};

vtkStandardNewMacro(customMouseInteractorStyle);

template<unsigned DIM>
VtkScene<DIM>::VtkScene()
    : mpRenderer(vtkSmartPointer<vtkRenderer>::New()),
      mpRenderWindow(vtkSmartPointer<vtkRenderWindow>::New()),
      mpRenderWindowInteractor(vtkSmartPointer<vtkRenderWindowInteractor>::New()),
      mpCellPopulation(),
      mOutputFilePath(),
      mpColorLookUpTable(vtkSmartPointer<vtkLookupTable>::New()),
    #if VTK_MAJOR_VERSION > 5
      mAnimationWriter(vtkSmartPointer<vtkOggTheoraWriter>::New()),
    #endif
      mWindowToImageFilter(vtkSmartPointer<vtkWindowToImageFilter>::New()),
      mIsInteractive(true),
      mSaveAsAnimation(false),
      mSaveAsImages(false),
      mHasStarted(false),
      mAddAnnotations(false),
      mOutputFrequency(1)
{
    mpRenderer->SetBackground(1.0, 1.0, 1.0);

    // Create a default LUT
    mpColorLookUpTable->SetNumberOfTableValues(10);
    mpColorLookUpTable->Build();

    #if VTK_MAJOR_VERSION > 5
        vtkSmartPointer<vtkNamedColors> p_named_colors = vtkSmartPointer<vtkNamedColors>::New();
        mpColorLookUpTable->SetTableValue(0, p_named_colors->GetColor4d("Black").GetData());
        mpColorLookUpTable->SetTableValue(1, p_named_colors->GetColor4d("Banana").GetData());
        mpColorLookUpTable->SetTableValue(2, p_named_colors->GetColor4d("Tomato").GetData());
        mpColorLookUpTable->SetTableValue(3, p_named_colors->GetColor4d("Wheat").GetData());
        mpColorLookUpTable->SetTableValue(4, p_named_colors->GetColor4d("Lavender").GetData());
        mpColorLookUpTable->SetTableValue(5, p_named_colors->GetColor4d("Flesh").GetData());
        mpColorLookUpTable->SetTableValue(6, p_named_colors->GetColor4d("Raspberry").GetData());
        mpColorLookUpTable->SetTableValue(7, p_named_colors->GetColor4d("Salmon").GetData());
        mpColorLookUpTable->SetTableValue(8, p_named_colors->GetColor4d("Mint").GetData());
        mpColorLookUpTable->SetTableValue(9, p_named_colors->GetColor4d("Peacock").GetData());
    #endif

    mpRenderWindow->AddRenderer(mpRenderer);
    mpRenderWindow->SetSize(800.0, 600.0);

    mpRenderWindowInteractor->SetRenderWindow(mpRenderWindow);

    vtkSmartPointer<customMouseInteractorStyle> style = vtkSmartPointer<customMouseInteractorStyle>::New();
    mpRenderWindowInteractor->SetInteractorStyle( style );
}

template<unsigned DIM>
VtkScene<DIM>::~VtkScene()
{

}

template<unsigned DIM>
void VtkScene<DIM>::SetIsInteractive(bool isInteractive)
{
    mIsInteractive = isInteractive;
}

template<unsigned DIM>
void VtkScene<DIM>::SetSaveAsImages(bool saveAsImages)
{
    mSaveAsImages = saveAsImages;
}

template<unsigned DIM>
void VtkScene<DIM>::ResetRenderer(unsigned time_step)
{
    if(!mHasStarted)
    {
        Start();
    }

    vtkSmartPointer<vtkActorCollection> p_actors = mpRenderer->GetActors();
    vtkActor *p_actor;
    for( p_actors->InitTraversal(); (p_actor = p_actors->GetNextItem())!=NULL; )
    {
        mpRenderer->RemoveActor(p_actor);
    }
    mpRenderer->Clear();

    if(mpCellPopulation)
    {
        UpdateCellPopulationActor();
    }
    mpRenderer->ResetCamera();

    if(mSaveAsImages)
    {
        mpRenderWindow->SetOffScreenRendering(1);
        mpRenderWindow->Render();
        mWindowToImageFilter->Modified();
        vtkSmartPointer<vtkPNGWriter> p_writer = vtkSmartPointer<vtkPNGWriter>::New();
        p_writer->SetWriteToMemory(1);
        p_writer->SetInputConnection(mWindowToImageFilter->GetOutputPort());
        if(!mOutputFilePath.empty())
        {
            p_writer->SetWriteToMemory(0);
            p_writer->SetFileName((mOutputFilePath+"_"+boost::lexical_cast<std::string>(time_step)+".png").c_str());
            p_writer->Write();
        }
    }
    #if VTK_MAJOR_VERSION > 5
    if(mSaveAsAnimation)
    {
        if(!mSaveAsImages)
        {
            mpRenderWindow->SetOffScreenRendering(1);
            mpRenderWindow->Render();
            mWindowToImageFilter->Modified();
        }
        mAnimationWriter->Write();
    }
    #endif
    if(mIsInteractive)
    {
        mpRenderWindow->SetOffScreenRendering(0);
        mpRenderWindow->Render();
    }
}

template<unsigned DIM>
void VtkScene<DIM>::SetOutputFilePath(const std::string& rPath)
{
    mOutputFilePath = rPath;
}

template<unsigned DIM>
void VtkScene<DIM>::SetSaveAsAnimation(bool saveAsAnimation)
{
    mSaveAsAnimation = saveAsAnimation;
}

template<unsigned DIM>
void VtkScene<DIM>::UpdateCellPopulationActor()
{
    // Check the cell population type
    if(boost::dynamic_pointer_cast<MeshBasedCellPopulation<DIM> >(mpCellPopulation))
    {
        UpdateMeshBasedCellPopulationActor();
    }
    else
    {
        // fall back to a centre based default
        vtkSmartPointer<vtkPoints> p_points = vtkSmartPointer<vtkPoints>::New();
        vtkSmartPointer<vtkPolyData> p_polydata = vtkSmartPointer<vtkPolyData>::New();

        for (typename AbstractCellPopulation<DIM>::Iterator cell_iter = mpCellPopulation->Begin();
             cell_iter != mpCellPopulation->End(); ++cell_iter)
        {
            c_vector<double, DIM> centre = mpCellPopulation->GetLocationOfCellCentre(*cell_iter);
            if(DIM==3)
            {
                p_points->InsertNextPoint(centre[0], centre[1], centre[2]);
            }
            else
            {
                p_points->InsertNextPoint(centre[0], centre[1], 0.0);
            }
        }
        p_polydata->SetPoints(p_points);

        vtkSmartPointer<vtkSphereSource> p_spheres = vtkSmartPointer<vtkSphereSource>::New();
        p_spheres->SetRadius(0.5);
        p_spheres->SetPhiResolution(16);
        p_spheres->SetThetaResolution(16);

        vtkSmartPointer<vtkGlyph3D> p_glyph = vtkSmartPointer<vtkGlyph3D>::New();
        #if VTK_MAJOR_VERSION <= 5
            p_glyph->SetInput(p_polydata);
            p_glyph->SetSource(p_spheres->GetOutput());
        #else
            p_glyph->SetInputData(p_polydata);
            p_glyph->SetSourceConnection(p_spheres->GetOutputPort());
        #endif
        p_glyph->ClampingOff();
        p_glyph->SetScaleModeToScaleByScalar();
        p_glyph->SetScaleFactor(1.0);
        p_glyph->Update();

        vtkSmartPointer<vtkPolyDataMapper> p_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
        #if VTK_MAJOR_VERSION <= 5
            p_mapper->SetInput(p_glyph->GetOutput());
        #else
            p_mapper->SetInputData(p_glyph->GetOutput());
        #endif
        p_mapper->ScalarVisibilityOn();

        vtkSmartPointer<vtkActor> p_actor = vtkSmartPointer<vtkActor>::New();
        p_actor->SetMapper(p_mapper);
        p_actor->GetProperty()->SetColor(0,1,0);
        mpRenderer->AddActor(p_actor);
    }

}

template<unsigned DIM>
void VtkScene<DIM>::UpdateMeshBasedCellPopulationActor()
{
    boost::shared_ptr<MeshBasedCellPopulation<DIM> > p_mesh = boost::dynamic_pointer_cast<MeshBasedCellPopulation<DIM> >(mpCellPopulation);

    if(!p_mesh)
    {
        EXCEPTION("Could not cast mesh to MeshBased type.");
    }


    vtkSmartPointer<vtkPoints> p_points = vtkSmartPointer<vtkPoints>::New();
    vtkSmartPointer<vtkPolyData> p_polydata = vtkSmartPointer<vtkPolyData>::New();

    for (typename AbstractCellPopulation<DIM>::Iterator cell_iter = mpCellPopulation->Begin();
         cell_iter != mpCellPopulation->End(); ++cell_iter)
    {
        c_vector<double, DIM> centre = mpCellPopulation->GetLocationOfCellCentre(*cell_iter);
        if(DIM==3)
        {
            p_points->InsertNextPoint(centre[0], centre[1], centre[2]);
        }
        else
        {
            p_points->InsertNextPoint(centre[0], centre[1], 0.0);
        }
    }
    p_polydata->SetPoints(p_points);

    vtkSmartPointer<vtkSphereSource> p_spheres = vtkSmartPointer<vtkSphereSource>::New();
    p_spheres->SetRadius(0.5);
    p_spheres->SetPhiResolution(16);
    p_spheres->SetThetaResolution(16);

    vtkSmartPointer<vtkGlyph3D> p_glyph = vtkSmartPointer<vtkGlyph3D>::New();
    #if VTK_MAJOR_VERSION <= 5
        p_glyph->SetInput(p_polydata);
        p_glyph->SetSource(p_spheres->GetOutput());
    #else
        p_glyph->SetInputData(p_polydata);
        p_glyph->SetSourceConnection(p_spheres->GetOutputPort());
    #endif
    p_glyph->ClampingOff();
    p_glyph->SetScaleModeToScaleByScalar();
    p_glyph->SetScaleFactor(1.0);
    p_glyph->Update();

    vtkSmartPointer<vtkPolyDataMapper> p_mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    #if VTK_MAJOR_VERSION <= 5
        p_mapper->SetInput(p_glyph->GetOutput());
    #else
        p_mapper->SetInputData(p_glyph->GetOutput());
    #endif
    p_mapper->ScalarVisibilityOn();

    vtkSmartPointer<vtkActor> p_actor = vtkSmartPointer<vtkActor>::New();
    p_actor->SetMapper(p_mapper);
    p_actor->GetProperty()->SetColor(0,1,0);
    mpRenderer->AddActor(p_actor);
}

template<unsigned DIM>
void VtkScene<DIM>::SetCellPopulation(boost::shared_ptr<AbstractCellPopulation<DIM> > pCellPopulation)
{
    mpCellPopulation = pCellPopulation;
}

template<unsigned DIM>
void VtkScene<DIM>::End()
{
    #if VTK_MAJOR_VERSION > 5
    if(mSaveAsAnimation and mHasStarted)
    {
        mAnimationWriter->End();
    }
    #endif
}

template<unsigned DIM>
void VtkScene<DIM>::Start()
{
    mpRenderer->ResetCamera();
    mpRenderer->GetActiveCamera()->Azimuth(45.0);

    if(mSaveAsImages or mSaveAsAnimation)
    {
        mpRenderWindow->SetOffScreenRendering(1);
        mWindowToImageFilter->SetInput(mpRenderWindow);
        mWindowToImageFilter->Update();
    }

    if(mSaveAsAnimation)
    {
        #if VTK_MAJOR_VERSION > 5
        mAnimationWriter->SetInputConnection(mWindowToImageFilter->GetOutputPort());
        mAnimationWriter->SetFileName((mOutputFilePath+".ogg").c_str());
        mAnimationWriter->SetRate(1.0);
        mAnimationWriter->Start();
        #endif
    }

    mHasStarted = true;
    ResetRenderer();

    if(mIsInteractive)
    {
        mpRenderWindowInteractor->Initialize();
    }

}

template<unsigned DIM>
void VtkScene<DIM>::StartInteractiveEventHandler()
{
    mpRenderWindowInteractor->Start();
}

template class VtkScene<2>;
template class VtkScene<3>;
