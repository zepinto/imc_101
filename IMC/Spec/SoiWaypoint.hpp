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

#ifndef IMC_SOIWAYPOINT_HPP_INCLUDED_
#define IMC_SOIWAYPOINT_HPP_INCLUDED_

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

namespace IMC
{
  //! SOI Waypoint.
  class SoiWaypoint: public Message
  {
  public:
    //! Latitude.
    float lat;
    //! Longitude.
    float lon;
    //! Time Of Arrival.
    uint32_t eta;
    //! Duration.
    uint16_t duration;

    static uint16_t
    getIdStatic(void)
    {
      return 850;
    }

    static SoiWaypoint*
    cast(Message* msg__)
    {
      return (SoiWaypoint*)msg__;
    }

    SoiWaypoint(void)
    {
      m_header.mgid = SoiWaypoint::getIdStatic();
      clear();
    }

    SoiWaypoint*
    clone(void) const
    {
      return new SoiWaypoint(*this);
    }

    void
    clear(void)
    {
      lat = 0;
      lon = 0;
      eta = 0;
      duration = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SoiWaypoint& other__ = static_cast<const SoiWaypoint&>(msg__);
      if (lat != other__.lat) return false;
      if (lon != other__.lon) return false;
      if (eta != other__.eta) return false;
      if (duration != other__.duration) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(lat, ptr__);
      ptr__ += IMC::serialize(lon, ptr__);
      ptr__ += IMC::serialize(eta, ptr__);
      ptr__ += IMC::serialize(duration, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(lat, bfr__, size__);
      bfr__ += IMC::deserialize(lon, bfr__, size__);
      bfr__ += IMC::deserialize(eta, bfr__, size__);
      bfr__ += IMC::deserialize(duration, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(lat, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(lon, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(eta, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(duration, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SoiWaypoint::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SoiWaypoint";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 14;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "lat", lat, nindent__);
      IMC::toJSON(os__, "lon", lon, nindent__);
      IMC::toJSON(os__, "eta", eta, nindent__);
      IMC::toJSON(os__, "duration", duration, nindent__);
    }
  };
}

#endif
