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

#ifndef IMC_TELEMETRYMSG_HPP_INCLUDED_
#define IMC_TELEMETRYMSG_HPP_INCLUDED_

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
  //! Telemetry Message.
  class TelemetryMsg: public Message
  {
  public:
    //! Type.
    enum TypeEnum
    {
      //! Tx.
      TM_TX = 0x01,
      //! Rx.
      TM_RX = 0x02,
      //! TxStatus.
      TM_TXSTATUS = 0x03
    };

    //! Code.
    enum CodeEnum
    {
      //! Code unknown.
      TM_CODE_UNK = 0x00,
      //! Code Report.
      TM_CODE_REPORT = 0x01,
      //! Code IMC.
      TM_CODE_IMC = 0x02,
      //! Code raw.
      TM_CODE_RAW = 0x03
    };

    //! Status.
    enum StatusEnum
    {
      //! Does not apply.
      TM_NONE = 0x00,
      //! Successfull transmission.
      TM_DONE = 1,
      //! Error while trying to transmit message.
      TM_FAILED = 2,
      //! Message has been queued for transmission.
      TM_QUEUED = 3,
      //! Message is currently being transmitted.
      TM_TRANSMIT = 4,
      //! Message's TTL has expired. Transmition cancelled.
      TM_EXPIRED = 5,
      //! No more messages to be transmitted or received.
      TM_EMPTY = 6,
      //! Invalid address.
      TM_INV_ADDR = 7,
      //! Invalid transmission size.
      TM_INV_SIZE = 8
    };

    //! Acknowledge.
    enum AcknowledgeBits
    {
      //! Not acknowledge.
      TM_NAK = 0x00,
      //! acknowledge.
      TM_AK = 0x01
    };

    //! Type.
    uint8_t type;
    //! Request Identifier.
    uint32_t req_id;
    //! Time to live.
    uint16_t ttl;
    //! Code.
    uint8_t code;
    //! Destination Identifier.
    std::string destination;
    //! Source Identifier.
    std::string source;
    //! Acknowledge.
    uint8_t acknowledge;
    //! Status.
    uint8_t status;
    //! Data.
    std::vector<char> data;

    static uint16_t
    getIdStatic(void)
    {
      return 190;
    }

    static TelemetryMsg*
    cast(Message* msg__)
    {
      return (TelemetryMsg*)msg__;
    }

    TelemetryMsg(void)
    {
      m_header.mgid = TelemetryMsg::getIdStatic();
      clear();
    }

    TelemetryMsg*
    clone(void) const
    {
      return new TelemetryMsg(*this);
    }

    void
    clear(void)
    {
      type = 0;
      req_id = 0;
      ttl = 0;
      code = 0;
      destination.clear();
      source.clear();
      acknowledge = 0;
      status = 0;
      data.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::TelemetryMsg& other__ = static_cast<const TelemetryMsg&>(msg__);
      if (type != other__.type) return false;
      if (req_id != other__.req_id) return false;
      if (ttl != other__.ttl) return false;
      if (code != other__.code) return false;
      if (destination != other__.destination) return false;
      if (source != other__.source) return false;
      if (acknowledge != other__.acknowledge) return false;
      if (status != other__.status) return false;
      if (data != other__.data) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(type, ptr__);
      ptr__ += IMC::serialize(req_id, ptr__);
      ptr__ += IMC::serialize(ttl, ptr__);
      ptr__ += IMC::serialize(code, ptr__);
      ptr__ += IMC::serialize(destination, ptr__);
      ptr__ += IMC::serialize(source, ptr__);
      ptr__ += IMC::serialize(acknowledge, ptr__);
      ptr__ += IMC::serialize(status, ptr__);
      ptr__ += IMC::serialize(data, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(req_id, bfr__, size__);
      bfr__ += IMC::deserialize(ttl, bfr__, size__);
      bfr__ += IMC::deserialize(code, bfr__, size__);
      bfr__ += IMC::deserialize(destination, bfr__, size__);
      bfr__ += IMC::deserialize(source, bfr__, size__);
      bfr__ += IMC::deserialize(acknowledge, bfr__, size__);
      bfr__ += IMC::deserialize(status, bfr__, size__);
      bfr__ += IMC::deserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(req_id, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ttl, bfr__, size__);
      bfr__ += IMC::deserialize(code, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(destination, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(source, bfr__, size__);
      bfr__ += IMC::deserialize(acknowledge, bfr__, size__);
      bfr__ += IMC::deserialize(status, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(data, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return TelemetryMsg::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "TelemetryMsg";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 10;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(destination) + IMC::getSerializationSize(source) + IMC::getSerializationSize(data);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "type", type, nindent__);
      IMC::toJSON(os__, "req_id", req_id, nindent__);
      IMC::toJSON(os__, "ttl", ttl, nindent__);
      IMC::toJSON(os__, "code", code, nindent__);
      IMC::toJSON(os__, "destination", destination, nindent__);
      IMC::toJSON(os__, "source", source, nindent__);
      IMC::toJSON(os__, "acknowledge", acknowledge, nindent__);
      IMC::toJSON(os__, "status", status, nindent__);
      IMC::toJSON(os__, "data", data, nindent__);
    }
  };
}

#endif
