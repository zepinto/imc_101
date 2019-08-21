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

#ifndef IMC_SOICOMMAND_HPP_INCLUDED_
#define IMC_SOICOMMAND_HPP_INCLUDED_

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
#include <IMC/Spec/SoiPlan.hpp>

namespace IMC
{
  //! SOI Command.
  class SoiCommand: public Message
  {
  public:
    //! Type.
    enum TypeEnum
    {
      //! Request.
      SOITYPE_REQUEST = 1,
      //! Success.
      SOITYPE_SUCCESS = 2,
      //! Error.
      SOITYPE_ERROR = 3
    };

    //! Command.
    enum CommandEnum
    {
      //! Execute Plan.
      SOICMD_EXEC = 1,
      //! Stop Execution.
      SOICMD_STOP = 2,
      //! Set Parameters.
      SOICMD_SET_PARAMS = 3,
      //! Get Parameters.
      SOICMD_GET_PARAMS = 4,
      //! Get Plan.
      SOICMD_GET_PLAN = 5,
      //! Resume Execution.
      SOICMD_RESUME = 6
    };

    //! Type.
    uint8_t type;
    //! Command.
    uint8_t command;
    //! Settings.
    std::string settings;
    //! Plan.
    InlineMessage<SoiPlan> plan;
    //! Extra Information.
    std::string info;

    static uint16_t
    getIdStatic(void)
    {
      return 852;
    }

    static SoiCommand*
    cast(Message* msg__)
    {
      return (SoiCommand*)msg__;
    }

    SoiCommand(void)
    {
      m_header.mgid = SoiCommand::getIdStatic();
      clear();
      plan.setParent(this);
    }

    SoiCommand*
    clone(void) const
    {
      return new SoiCommand(*this);
    }

    void
    clear(void)
    {
      type = 0;
      command = 0;
      settings.clear();
      plan.clear();
      info.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SoiCommand& other__ = static_cast<const SoiCommand&>(msg__);
      if (type != other__.type) return false;
      if (command != other__.command) return false;
      if (settings != other__.settings) return false;
      if (plan != other__.plan) return false;
      if (info != other__.info) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(type, ptr__);
      ptr__ += IMC::serialize(command, ptr__);
      ptr__ += IMC::serialize(settings, ptr__);
      ptr__ += plan.serialize(ptr__);
      ptr__ += IMC::serialize(info, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(command, bfr__, size__);
      bfr__ += IMC::deserialize(settings, bfr__, size__);
      bfr__ += plan.deserialize(bfr__, size__);
      bfr__ += IMC::deserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(command, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(settings, bfr__, size__);
      bfr__ += plan.reverseDeserialize(bfr__, size__);
      bfr__ += IMC::reverseDeserialize(info, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SoiCommand::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SoiCommand";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 2;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(settings) + plan.getSerializationSize() + IMC::getSerializationSize(info);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "type", type, nindent__);
      IMC::toJSON(os__, "command", command, nindent__);
      IMC::toJSON(os__, "settings", settings, nindent__);
      plan.toJSON(os__, "plan", nindent__);
      IMC::toJSON(os__, "info", info, nindent__);
    }

  protected:
    void
    setTimeStampNested(double value__)
    {
      if (!plan.isNull())
      {
        plan.get()->setTimeStamp(value__);
      }
    }

    void
    setSourceNested(uint16_t value__)
    {
      if (!plan.isNull())
      {
        plan.get()->setSource(value__);
      }
    }

    void
    setSourceEntityNested(uint8_t value__)
    {
      if (!plan.isNull())
      {
        plan.get()->setSourceEntity(value__);
      }
    }

    void
    setDestinationNested(uint16_t value__)
    {
      if (!plan.isNull())
      {
        plan.get()->setDestination(value__);
      }
    }

    void
    setDestinationEntityNested(uint8_t value__)
    {
      if (!plan.isNull())
      {
        plan.get()->setDestinationEntity(value__);
      }
    }
  };
}

#endif
