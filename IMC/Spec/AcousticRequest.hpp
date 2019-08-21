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

#ifndef IMC_ACOUSTICREQUEST_HPP_INCLUDED_
#define IMC_ACOUSTICREQUEST_HPP_INCLUDED_

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
  //! Acoustic Transmission Request.
  class AcousticRequest: public Message
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

    //! Request Identifier.
    uint16_t req_id;
    //! Destination System.
    std::string destination;
    //! Timeout.
    double timeout;
    //! Range.
    float range;
    //! Type.
    uint8_t type;
    //! Message To Send.
    InlineMessage<Message> msg;

    static uint16_t
    getIdStatic(void)
    {
      return 215;
    }

    static AcousticRequest*
    cast(Message* msg__)
    {
      return (AcousticRequest*)msg__;
    }

    AcousticRequest(void)
    {
      m_header.mgid = AcousticRequest::getIdStatic();
      clear();
      msg.setParent(this);
    }

    AcousticRequest*
    clone(void) const
    {
      return new AcousticRequest(*this);
    }

    void
    clear(void)
    {
      req_id = 0;
      destination.clear();
      timeout = 0;
      range = 0;
      type = 0;
      msg.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::AcousticRequest& other__ = static_cast<const AcousticRequest&>(msg__);
      if (req_id != other__.req_id) return false;
      if (destination != other__.destination) return false;
      if (timeout != other__.timeout) return false;
      if (range != other__.range) return false;
      if (type != other__.type) return false;
      if (msg != other__.msg) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(req_id, ptr__);
      ptr__ += IMC::serialize(destination, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      ptr__ += IMC::serialize(range, ptr__);
      ptr__ += IMC::serialize(type, ptr__);
      ptr__ += msg.serialize(ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(destination, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      bfr__ += IMC::deserialize(range, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += msg.deserialize(bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(req_id, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(destination, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(timeout, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(range, bfr__, size__);
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += msg.reverseDeserialize(bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return AcousticRequest::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "AcousticRequest";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 15;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(destination) + msg.getSerializationSize();
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "req_id", req_id, nindent__);
      IMC::toJSON(os__, "destination", destination, nindent__);
      IMC::toJSON(os__, "timeout", timeout, nindent__);
      IMC::toJSON(os__, "range", range, nindent__);
      IMC::toJSON(os__, "type", type, nindent__);
      msg.toJSON(os__, "msg", nindent__);
    }

  protected:
    void
    setTimeStampNested(double value__)
    {
      if (!msg.isNull())
      {
        msg.get()->setTimeStamp(value__);
      }
    }

    void
    setSourceNested(uint16_t value__)
    {
      if (!msg.isNull())
      {
        msg.get()->setSource(value__);
      }
    }

    void
    setSourceEntityNested(uint8_t value__)
    {
      if (!msg.isNull())
      {
        msg.get()->setSourceEntity(value__);
      }
    }

    void
    setDestinationNested(uint16_t value__)
    {
      if (!msg.isNull())
      {
        msg.get()->setDestination(value__);
      }
    }

    void
    setDestinationEntityNested(uint8_t value__)
    {
      if (!msg.isNull())
      {
        msg.get()->setDestinationEntity(value__);
      }
    }
  };
}

#endif
