//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 009a5046be102f40bfccc623630722a7                            *
//***************************************************************************

#ifndef IMC_VERTICALPROFILE_HPP_INCLUDED_
#define IMC_VERTICALPROFILE_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>
#include <IMC/Spec/ProfileSample.hpp>

namespace IMC
{
  //! Vertical Profile.
  class VerticalProfile: public Message
  {
  public:
    //! Parameter.
    enum ParameterEnum
    {
      //! Temperature.
      PROF_TEMPERATURE = 0,
      //! Salinity.
      PROF_SALINITY = 1,
      //! Conductivity.
      PROF_CONDUCTIVITY = 2,
      //! pH.
      PROF_PH = 3,
      //! Redox.
      PROF_REDOX = 4,
      //! Chlorophyll.
      PROF_CHLOROPHYLL = 5,
      //! Turbidity.
      PROF_TURBIDITY = 6
    };

    //! Parameter.
    uint8_t parameter;
    //! Number of Samples.
    uint8_t numsamples;
    //! Samples.
    MessageList<ProfileSample> samples;
    //! Latitude.
    double lat;
    //! Longitude.
    double lon;

    static uint16_t
    getIdStatic(void)
    {
      return 111;
    }

    static VerticalProfile*
    cast(Message* msg__)
    {
      return (VerticalProfile*)msg__;
    }

    VerticalProfile(void)
    {
      m_header.mgid = VerticalProfile::getIdStatic();
      clear();
      samples.setParent(this);
    }

    VerticalProfile*
    clone(void) const
    {
      return new VerticalProfile(*this);
    }

    void
    clear(void)
    {
      parameter = 0;
      numsamples = 0;
      samples.clear();
      lat = 0;
      lon = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::VerticalProfile& other__ = static_cast<const VerticalProfile&>(msg__);
      if (parameter != other__.parameter) return false;
      if (numsamples != other__.numsamples) return false;
      if (samples != other__.samples) return false;
      if (lat != other__.lat) return false;
      if (lon != other__.lon) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(parameter, ptr__);
      ptr__ += IMC::serialize(numsamples, ptr__);
      ptr__ += samples.serialize(ptr__);
      ptr__ += IMC::serialize(lat, ptr__);
      ptr__ += IMC::serialize(lon, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(parameter, bfr__, size__);
      bfr__ += IMC::deserialize(numsamples, bfr__, size__);
      bfr__ += samples.deserialize(bfr__, size__);
      bfr__ += IMC::deserialize(lat, bfr__, size__);
      bfr__ += IMC::deserialize(lon, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(parameter, bfr__, size__);
      bfr__ += IMC::deserialize(numsamples, bfr__, size__);
      bfr__ += samples.reverseDeserialize(bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lat, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lon, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return VerticalProfile::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "VerticalProfile";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 18;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return samples.getSerializationSize();
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "parameter", parameter, nindent__);
      IMC::toJSON(os__, "numsamples", numsamples, nindent__);
      samples.toJSON(os__, "samples", nindent__);
      IMC::toJSON(os__, "lat", lat, nindent__);
      IMC::toJSON(os__, "lon", lon, nindent__);
    }

  protected:
    void
    setTimeStampNested(double value__)
    {
      samples.setTimeStamp(value__);
    }

    void
    setSourceNested(uint16_t value__)
    {
      samples.setSource(value__);
    }

    void
    setSourceEntityNested(uint8_t value__)
    {
      samples.setSourceEntity(value__);
    }

    void
    setDestinationNested(uint16_t value__)
    {
      samples.setDestination(value__);
    }

    void
    setDestinationEntityNested(uint8_t value__)
    {
      samples.setDestinationEntity(value__);
    }
  };
}

#endif
