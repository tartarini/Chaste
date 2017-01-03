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

#ifndef _EXAMPLENASTY2DNONLINEARELLIPTICPDE_HPP_
#define _EXAMPLENASTY2DNONLINEARELLIPTICPDE_HPP_

#include "AbstractNonlinearEllipticPde.hpp"
#include <cmath>

/**
 * A fairly nasty PDE for testing the nonlinear elliptic assembler in 2D.
 */
class ExampleNasty2dNonlinearEllipticPde:public AbstractNonlinearEllipticPde<2>
{
public:

    double ComputeLinearSourceTerm(const ChastePoint<2>& )
    {
        return 0;
    }

    double ComputeNonlinearSourceTerm(const ChastePoint<2>& p, double u)
    {
        double x = p[0];
        double y = p[1];
        return -4*(u*cos(x)*cos(x) + sin(x)*sin(x)*cos(x)*cos(x) + y*y);
    }

    c_matrix<double, 2, 2> ComputeDiffusionTerm(const ChastePoint<2>& , double u)
    {
        return identity_matrix<double>(2)*u;
    }

    c_matrix<double, 2, 2> ComputeDiffusionTermPrime(const ChastePoint<2>& , double )
    {
        return identity_matrix<double>(2);
    }

    double ComputeNonlinearSourceTermPrime(const ChastePoint<2>& p, double )
    {
        return -(cos(p[0])*cos(p[0]));
    }

    virtual ~ExampleNasty2dNonlinearEllipticPde()
    {}
};

#endif //_EXAMPLENASTY2DNONLINEARELLIPTICPDE_HPP_
