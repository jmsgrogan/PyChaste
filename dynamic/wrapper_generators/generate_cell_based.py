#!/usr/bin/env python

"""Copyright (c) 2005-2017, University of Oxford.
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

"""
This scipt automatically generates Python bindings using a rule based approach
"""
import sys
from pyplusplus import module_builder
from pyplusplus.module_builder import call_policies
from pygccxml import parser
import generate_bindings
import classes_to_be_wrapped

def update_builder(builder, class_collection):

    voronoi_writer_prefix = 'def("AddPopulationWriterVoronoiDataWriter", &'
    voronoi_writer_suffix = '::AddPopulationWriter<VoronoiDataWriter>)'
    label_writer_prefix = 'def("AddCellWriterCellLabelWriter", &'
    label_writer_suffix = '::AddCellWriter<CellLabelWriter>)'
    
    for eachTemplate in ["<2,2>", "<3,3>"]:
        builder.class_("AbstractCellBasedSimulation"+eachTemplate).constructors().exclude()
        builder.class_("MeshBasedCellPopulation"+eachTemplate).add_registration_code(voronoi_writer_prefix + 'MeshBasedCellPopulation' + eachTemplate + voronoi_writer_suffix)   

    for eachTemplate in ["<2>", "<3>"]: 
        builder.class_("PottsBasedCellPopulation"+eachTemplate).add_registration_code(label_writer_prefix + 'PottsBasedCellPopulation' + eachTemplate + label_writer_suffix) 
        builder.class_("MeshBasedCellPopulationWithGhostNodes"+eachTemplate).add_registration_code(voronoi_writer_prefix + 'MeshBasedCellPopulationWithGhostNodes' + eachTemplate + voronoi_writer_suffix) 

        builder.class_("AbstractPdeModifier"+eachTemplate).constructors().exclude()  
        builder.class_('AbstractPdeModifier'+eachTemplate).calldefs().use_default_arguments=False 
        builder.class_('CellwiseSourceEllipticPde'+eachTemplate).calldefs().use_default_arguments=False   
        builder.class_('AbstractGrowingDomainPdeModifier'+eachTemplate).calldefs().use_default_arguments=False 
        builder.class_("AbstractGrowingDomainPdeModifier"+eachTemplate).constructors().exclude()      
        builder.class_('EllipticGrowingDomainPdeModifier'+eachTemplate).calldefs().use_default_arguments=False    
        builder.class_("EllipticGrowingDomainPdeModifier"+eachTemplate).add_declaration_code("BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Vec )")
        builder.class_("EllipticGrowingDomainPdeModifier"+eachTemplate).add_declaration_code("BOOST_PYTHON_OPAQUE_SPECIALIZED_TYPE_ID( _p_Mat )")

    return builder, class_collection