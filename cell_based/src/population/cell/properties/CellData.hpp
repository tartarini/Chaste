/*

Copyright (c) 2005-2012, University of Oxford.
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

#ifndef CELLDATA_HPP_
#define CELLDATA_HPP_

#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
#include <vector>

#include "AbstractCellProperty.hpp"
#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/map.hpp>
#include "Exception.hpp"

class CellData;

/**
 * CellData class.
 *
 * Each Cell owns a CellData property
 *
 */
class CellData : public AbstractCellProperty
{
private:

    /**
     * Cell data
     */
    std::map<std::string, double> mCellData;

    /** Needed for serialization. */
    friend class boost::serialization::access;
    /**
     * Archive the member variables.
     *
     * @param archive the archive
     * @param version the current version of this class
     */
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractCellProperty>(*this);
        archive & mCellData;
    }

public:

    /**
     * Constructor/destructor are default.
     */

    /**
     * This assigns the cell data.
     * \todo #2115 This method is to be deprecated.
     * 
     * @param variableNumber the index of the data to be set.
     * @param data the value to set it to.
     */
    void SetItem(unsigned variableNumber, double data);

    /**
     * This assigns the cell data.
     *
     * @param variableName the index of the data to be set.
     * @param data the value to set it to.
     */
    void SetItem(const std::string& variableName, double data);

    /**
     * Get data.
     * \todo #2115 This method is to be deprecated.
     * 
     * @param variableNumber the index of the data required.
     */
    double GetItem(unsigned variableNumber) const;

    /**
     * Get data.
     *
     * @param variableName the index of the data required.
     */
    double GetItem(const std::string& variableName) const;

    /**
     * Get number of data items
     * 
     */
    unsigned GetNumItems() const;
    /**
     * Get all keys
     * These are sorted in lexicographical/alphabetic order (so that the order is independent of any map iteration method)
     *
     */
    std::vector<std::string> GetKeys() const;
};

#include "SerializationExportWrapper.hpp"
// Declare identifier for the serializer
CHASTE_CLASS_EXPORT(CellData)

#endif /* CELLDATA_HPP_ */
