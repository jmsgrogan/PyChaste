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

#ifndef VTKSCENE_HPP_
#define VTKSCENE_HPP_

#include <vector>
#include "SmartPointers.hpp"
#if VTK_MAJOR_VERSION > 5
    #include <vtkAutoInit.h>
    VTK_MODULE_INIT(vtkRenderingOpenGL);
#endif
#define _BACKWARD_BACKWARD_WARNING_H 1 //Cut out the vtk deprecated warning
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkLookupTable.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkOggTheoraWriter.h>
#include <vtkWindowToImageFilter.h>
#include "AbstractCellPopulation.hpp"

/**
 * A simple vtk renderer for cell populations
 */
template<unsigned DIM>
class VtkScene
{
    /**
     * The vtk renderer
     */
    vtkSmartPointer<vtkRenderer> mpRenderer;

    /**
     * The vtk render window
     */
    vtkSmartPointer<vtkRenderWindow> mpRenderWindow;

    /**
     * The vtk render window interactor
     */
    vtkSmartPointer<vtkRenderWindowInteractor> mpRenderWindowInteractor;

    /**
     * The cell population
     */
    boost::shared_ptr<AbstractCellPopulation<DIM> > mpCellPopulation;

    /**
     * The path for output
     */
    std::string mOutputFilePath;

    /**
     * The color lookup
     */
    vtkSmartPointer<vtkLookupTable> mpColorLookUpTable;

    /**
     * The animation writer
     */
    vtkSmartPointer<vtkOggTheoraWriter> mAnimationWriter;

    /**
     * The image to window filter
     */
    vtkSmartPointer<vtkWindowToImageFilter> mWindowToImageFilter;

    bool mIsInteractive;

    bool mSaveAsAnimation;

    bool mSaveAsImages;

    bool mHasStarted;

public:

    /**
     * Constructor
     */
    VtkScene();

    /**
     * Destructor
     */
    ~VtkScene();

    void ResetRenderer(unsigned time_step=0);


    void UpdateCellPopulationActor();


    void SetCellPopulation(boost::shared_ptr<AbstractCellPopulation<DIM> > pCellPopulation);

    /**
     * Render the scene
     */
    void Start();

    /**
     * Shut down the scene
     */
    void End();

    /**
     * Set the path for output
     * @param rPath the path for output
     */
    void SetOutputFilePath(const std::string& rPath);

    void SetIsInteractive(bool isInteractive);

    void SetSaveAsAnimation(bool saveAsAnimation);

    void SetSaveAsImages(bool saveAsImages);

    void StartInteractiveEventHandler();

};

#endif /* VTKSCENE_HPP_*/
