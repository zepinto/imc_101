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

#ifndef IMC_VTOLSTATE_HPP_INCLUDED_
#define IMC_VTOLSTATE_HPP_INCLUDED_

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
  //! VTOL State.
  class VtolState: public Message
  {
  public:
    //! State.
    enum StateEnum
    {
      //! Undefined.
      VTOL_STATE_UNDEFINED = 0,
      //! Transition to Fixed-Wing.
      VTOL_STATE_TRANSITION_TO_FW = 1,
      //! Transition to MultiCopter.
      VTOL_STATE_TRANSITION_TO_MC = 2,
      //! MutiCopter.
      VTOL_STATE_MC = 3,
      //! Fixed-Wing.
      VTOL_STATE_FW = 4
    };

    //! State.
    uint8_t state;

    static uint16_t
    getIdStatic(void)
    {
      return 519;
    }

    static VtolState*
    cast(Message* msg__)
    {
      return (VtolState*)msg__;
    }

    VtolState(void)
    {
      m_header.mgid = VtolState::getIdStatic();
      clear();
    }

    VtolState*
    clone(void) const
    {
      return new VtolState(*this);
    }

    void
    clear(void)
    {
      state = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::VtolState& other__ = static_cast<const VtolState&>(msg__);
      if (state != other__.state) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(state, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(state, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(state, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return VtolState::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "VtolState";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 1;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "state", state, nindent__);
    }
  };
}

#endif
