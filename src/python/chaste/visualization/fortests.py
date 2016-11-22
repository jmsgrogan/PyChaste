#!/usr/bin/env python
"""Helper classes for running tests
"""

__copyright__ = """Copyright (c) 2005-2016, University of Oxford.
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
"""

PYCHASTE_CAN_IMPORT_IPYTHON = True
PYCHASTE_CAN_IMPORT_VTK = True

try:
    import IPython                    
except ImportError:
    PYCHASTE_CAN_IMPORT_IPYTHON = False  
    
try:
    import vtk                    
except ImportError:
    PYCHASTE_CAN_IMPORT_VTK = False      
    
if PYCHASTE_CAN_IMPORT_IPYTHON:
    from IPython.display import Image
    
    def vtk_show_basic(scene, width=400, height=300):
        
        """
        Takes a Scene instance and returns an IPython Image with the rendering.
        """
        
        data = str(buffer(scene.GetSceneAsCharBuffer()))
        
        return Image(data)
    
    if PYCHASTE_CAN_IMPORT_VTK:
        def vtk_show(scene, width=400, height=300):
            
            """
            Takes vtkRenderer instance and returns an IPython Image with the rendering.
            """
            
            scene.ResetRenderer(0)
            
            renderWindow = vtk.vtkRenderWindow()
            renderWindow.SetOffScreenRendering(1)
            renderWindow.AddRenderer(scene.GetRenderer())
            renderWindow.SetSize(width, height)
            renderWindow.Render()
             
            windowToImageFilter = vtk.vtkWindowToImageFilter()
            windowToImageFilter.SetInput(renderWindow)
            windowToImageFilter.Update()
             
            writer = vtk.vtkPNGWriter()
            writer.SetWriteToMemory(1)
            writer.SetInputConnection(windowToImageFilter.GetOutputPort())
            writer.Write()
            data = str(buffer(writer.GetResult()))
            
            return Image(data)