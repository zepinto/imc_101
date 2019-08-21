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

#ifndef IMC_ACOUSTICSTATUS_HPP_INCLUDED_
#define IMC_ACOUSTICSTATUS_HPP_INCLUDED_

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
  //! Acoustic Transmission Status.
  class AcousticStatus: public Message
  {
  public:
    //! Type.
    enum TypeEnum
    {
      //! Abort.
      TYPE_ABORT = 0,
      //! Range.
      TYPE_RANGE = 1,
      //! Reverse Range.
      TYPE_REVERSE_RANGE = 2,
      //! Message.
      TYPE_MSG = 3,
      //! Raw.
      TYPE_RAW = 4
    };

    //! Status.
    enum StatusEnum
    {
      //! Queued.
      STATUS_QUEUED = 0,
      //! In Progress.
      STATUS_IN_PROGRESS = 1,
      //! Sent.
      STATUS_SENT = 2,
      //! Range Received.
      STATUS_RANGE_RECEIVED = 3,
      //! Busy.
      STATUS_BUSY = 100,
      //! Input Error.
      STATUS_INPUT_FAILURE = 101,
      //! Error trying to send acoustic text.
      STATUS_ERROR = 102,
      //! Message Type is not defined or is unsupported.
      STATUS_UNSUPPORTED = 666
    };

    //! Request Identifier.
    uint16_t req_id;
    //! Type.
    uint8_t type;
    //! Status.
    uint8_t status;
    //! Information.
    std::string info;
    //! Range.
    float range;

    static uint16_t
    getIdStatic(void)
    {
      return 216;
    }

    static AcousticStatus*
    cast(Message* msg__)
    {
      return (AcousticStatus*)msg__;
    }

    AcousticStatus(void)
    {
      m_header.mgid = AcousticStatus::getIdStatic();
      clear();
    }

    AcousticStatus*
    clone(void) const
    {
      return new AcousticStatus(*this);
    }

    void
    clear(void)
    {
      req_id = 0;
      type = 0;
      status = 0;
      info.clear();
      range = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::AcousticStatus& other__ = static_cast<const AcousticStatus&>(msg__);
      if (req_id != other__.req_id) return false;
      if (type != other__.type) return false;
      if (status != other__.status) return false;
      if (info != other__.info) return false;
      if (range != other__.range) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(req_id, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      ptr__ += IMC::serialize(status, ptr__);
      ptr__ += IMC::serialize(info, ptr__);
      ptr__ += IMC::serialize(range, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(status, bfr__, size__);
      bfr__ += IMC::deserialize(info, bfr__, size__);
      bfr__ += IMC::deserialize(range, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(status, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(info, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(range, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return AcousticStatus::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "AcousticStatus";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 8;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(info);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "req_id", req_id, nindent__);
      IMC::toJSON(os__, "type", type, nindent__);
      IMC::toJSON(os__, "status", status, nindent__);
      IMC::toJSON(os__, "info", info, nindent__);
      IMC::toJSON(os__, "range", range, nindent__);
    }
  };
}

#endif
