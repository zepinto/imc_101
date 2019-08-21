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

#ifndef IMC_SOISTATE_HPP_INCLUDED_
#define IMC_SOISTATE_HPP_INCLUDED_

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
  //! SOI State.
  class SoiState: public Message
  {
  public:
    //! State.
    enum StateEnum
    {
      //! Executing.
      SOISTATE_EXEC = 1,
      //! Idle.
      SOISTATE_IDLE = 2,
      //! Inactive.
      SOISTATE_INACTIVE = 3
    };

    //! State.
    uint8_t state;
    //! Plan Identifier.
    uint16_t plan_id;
    //! Waypoint Identifier.
    uint8_t wpt_id;
    //! Settings Checksum.
    uint16_t settings_chk;

    static uint16_t
    getIdStatic(void)
    {
      return 853;
    }

    static SoiState*
    cast(Message* msg__)
    {
      return (SoiState*)msg__;
    }

    SoiState(void)
    {
      m_header.mgid = SoiState::getIdStatic();
      clear();
    }

    SoiState*
    clone(void) const
    {
      return new SoiState(*this);
    }

    void
    clear(void)
    {
      state = 0;
      plan_id = 0;
      wpt_id = 0;
      settings_chk = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SoiState& other__ = static_cast<const SoiState&>(msg__);
      if (state != other__.state) return false;
      if (plan_id != other__.plan_id) return false;
      if (wpt_id != other__.wpt_id) return false;
      if (settings_chk != other__.settings_chk) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(state, ptr__);
      ptr__ += IMC::serialize(plan_id, ptr__);
      ptr__ += IMC::serialize(wpt_id, ptr__);
      ptr__ += IMC::serialize(settings_chk, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(state, bfr__, size__);
      bfr__ += IMC::deserialize(plan_id, bfr__, size__);
      bfr__ += IMC::deserialize(wpt_id, bfr__, size__);
      bfr__ += IMC::deserialize(settings_chk, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(state, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(plan_id, bfr__, size__);
      bfr__ += IMC::deserialize(wpt_id, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(settings_chk, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SoiState::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SoiState";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 6;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "state", state, nindent__);
      IMC::toJSON(os__, "plan_id", plan_id, nindent__);
      IMC::toJSON(os__, "wpt_id", wpt_id, nindent__);
      IMC::toJSON(os__, "settings_chk", settings_chk, nindent__);
    }
  };
}

#endif
