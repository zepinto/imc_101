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

#ifndef IMC_SOIPLAN_HPP_INCLUDED_
#define IMC_SOIPLAN_HPP_INCLUDED_

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
#include <IMC/Spec/SoiWaypoint.hpp>

namespace IMC
{
  //! SOI Plan.
  class SoiPlan: public Message
  {
  public:
    //! Plan Identifier.
    uint16_t plan_id;
    //! Waypoints.
    MessageList<SoiWaypoint> waypoints;

    static uint16_t
    getIdStatic(void)
    {
      return 851;
    }

    static SoiPlan*
    cast(Message* msg__)
    {
      return (SoiPlan*)msg__;
    }

    SoiPlan(void)
    {
      m_header.mgid = SoiPlan::getIdStatic();
      clear();
      waypoints.setParent(this);
    }

    SoiPlan*
    clone(void) const
    {
      return new SoiPlan(*this);
    }

    void
    clear(void)
    {
      plan_id = 0;
      waypoints.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SoiPlan& other__ = static_cast<const SoiPlan&>(msg__);
      if (plan_id != other__.plan_id) return false;
      if (waypoints != other__.waypoints) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(plan_id, ptr__);
      ptr__ += waypoints.serialize(ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      bfr__ += waypoints.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(plan_id, bfr__, size__);
      bfr__ += waypoints.reverseDeserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SoiPlan::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SoiPlan";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 2;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return waypoints.getSerializationSize();
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "plan_id", plan_id, nindent__);
      waypoints.toJSON(os__, "waypoints", nindent__);
    }

  protected:
    void
    setTimeStampNested(double value__)
    {
      waypoints.setTimeStamp(value__);
    }

    void
    setSourceNested(uint16_t value__)
    {
      waypoints.setSource(value__);
    }

    void
    setSourceEntityNested(uint8_t value__)
    {
      waypoints.setSourceEntity(value__);
    }

    void
    setDestinationNested(uint16_t value__)
    {
      waypoints.setDestination(value__);
    }

    void
    setDestinationEntityNested(uint8_t value__)
    {
      waypoints.setDestinationEntity(value__);
    }
  };
}

#endif
