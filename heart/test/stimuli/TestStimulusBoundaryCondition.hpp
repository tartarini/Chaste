/*

Copyright (c) 2005-2017, University of Oxford.
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


#ifndef TESTSTIMULUSBOUNDARYCONDITION_HPP_
#define TESTSTIMULUSBOUNDARYCONDITION_HPP_

#include <cxxtest/TestSuite.h>
#include "StimulusBoundaryCondition.hpp"
#include "SimpleStimulus.hpp"
#include "PdeSimulationTime.hpp"
#include "PetscSetupAndFinalize.hpp"

class TestStimulusBoundaryCondition : public CxxTest::TestSuite
{
public:
    void TestStimulusBoundaryConditionMethod()
    {
        ChastePoint<1> zero(0);
        SimpleStimulus sq_wave(23.0, 2.0, 1.0); // magnitude, duration, start time
        StimulusBoundaryCondition<1> stim_bc(&sq_wave);

        PdeSimulationTime::SetTime(0.5);
        TS_ASSERT_EQUALS(0.0, stim_bc.GetValue(zero));

        PdeSimulationTime::SetTime(1.5);
        TS_ASSERT_EQUALS(23.0, stim_bc.GetValue(zero));

        PdeSimulationTime::SetTime(5.0);
        TS_ASSERT_EQUALS(0.0, stim_bc.GetValue(zero));
    }
};

#endif /*TESTSTIMULUSBOUNDARYCONDITION_HPP_*/
