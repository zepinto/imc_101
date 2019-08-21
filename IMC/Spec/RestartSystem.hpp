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

#ifndef IMC_RESTARTSYSTEM_HPP_INCLUDED_
#define IMC_RESTARTSYSTEM_HPP_INCLUDED_

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
  //! Restart System.
  class RestartSystem: public Message
  {
  public:
    //! Restart Type.
    enum RestartTypeEnum
    {
      //! Dune.
      RSTYPE_DUNE = 1,
      //! System.
      RSTYPE_SYSTEM = 2
    };

    //! Restart Type.
    uint8_t type;

    static uint16_t
    getIdStatic(void)
    {
      return 9;
    }

    static RestartSystem*
    cast(Message* msg__)
    {
      return (RestartSystem*)msg__;
    }

    RestartSystem(void)
    {
      m_header.mgid = RestartSystem::getIdStatic();
      clear();
    }

    RestartSystem*
    clone(void) const
    {
      return new RestartSystem(*this);
    }

    void
    clear(void)
    {
      type = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::RestartSystem& other__ = static_cast<const RestartSystem&>(msg__);
      if (type != other__.type) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(type, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return RestartSystem::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "RestartSystem";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 1;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "type", type, nindent__);
    }
  };
}

#endif
