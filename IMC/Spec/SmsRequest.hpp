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

#ifndef IMC_SMSREQUEST_HPP_INCLUDED_
#define IMC_SMSREQUEST_HPP_INCLUDED_

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
  //! SMS Transmission Request.
  class SmsRequest: public Message
  {
  public:
    //! Request Identifier.
    uint16_t req_id;
    //! Destination.
    std::string destination;
    //! Timeout.
    double timeout;
    //! SMS Text.
    std::string sms_text;

    static uint16_t
    getIdStatic(void)
    {
      return 517;
    }

    static SmsRequest*
    cast(Message* msg__)
    {
      return (SmsRequest*)msg__;
    }

    SmsRequest(void)
    {
      m_header.mgid = SmsRequest::getIdStatic();
      clear();
    }

    SmsRequest*
    clone(void) const
    {
      return new SmsRequest(*this);
    }

    void
    clear(void)
    {
      req_id = 0;
      destination.clear();
      timeout = 0;
      sms_text.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SmsRequest& other__ = static_cast<const SmsRequest&>(msg__);
      if (req_id != other__.req_id) return false;
      if (destination != other__.destination) return false;
      if (timeout != other__.timeout) return false;
      if (sms_text != other__.sms_text) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(req_id, ptr__);
      ptr__ += IMC::serialize(destination, ptr__);
      ptr__ += IMC::serialize(timeout, ptr__);
      ptr__ += IMC::serialize(sms_text, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(destination, bfr__, size__);
      bfr__ += IMC::deserialize(timeout, bfr__, size__);
      bfr__ += IMC::deserialize(sms_text, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(req_id, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(destination, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(timeout, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(sms_text, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SmsRequest::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SmsRequest";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 10;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(destination) + IMC::getSerializationSize(sms_text);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "req_id", req_id, nindent__);
      IMC::toJSON(os__, "destination", destination, nindent__);
      IMC::toJSON(os__, "timeout", timeout, nindent__);
      IMC::toJSON(os__, "sms_text", sms_text, nindent__);
    }
  };
}

#endif
