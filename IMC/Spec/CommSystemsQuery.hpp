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

#ifndef IMC_COMMSYSTEMSQUERY_HPP_INCLUDED_
#define IMC_COMMSYSTEMSQUERY_HPP_INCLUDED_

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
  //! Communication Systems Query.
  class CommSystemsQuery: public Message
  {
  public:
    //! Model.
    enum ModelEnum
    {
      //! unknown.
      CIQ_UNKNOWN = 0x00,
      //! 3DR.
      CIQ_M3DR = 0x01,
      //! RDFXXXxPtP.
      CIQ_RDFXXXXPTP = 0x02
    };

    //! Type.
    enum TypeBits
    {
      //! Query Systems.
      CIQ_QUERY = 0x01,
      //! Reply.
      CIQ_REPLY = 0x02
    };

    //! Communication Interface.
    enum CommunicationInterfaceBits
    {
      //! Acoustic.
      CIQ_ACOUSTIC = 0x01,
      //! Satellite.
      CIQ_SATELLITE = 0x02,
      //! GSM.
      CIQ_GSM = 0x04,
      //! Mobile.
      CIQ_MOBILE = 0x08,
      //! Radio.
      CIQ_RADIO = 0x10
    };

    //! Type.
    uint8_t type;
    //! Communication Interface.
    uint16_t comm_interface;
    //! Model.
    uint16_t model;
    //! System List.
    std::string list;

    static uint16_t
    getIdStatic(void)
    {
      return 189;
    }

    static CommSystemsQuery*
    cast(Message* msg__)
    {
      return (CommSystemsQuery*)msg__;
    }

    CommSystemsQuery(void)
    {
      m_header.mgid = CommSystemsQuery::getIdStatic();
      clear();
    }

    CommSystemsQuery*
    clone(void) const
    {
      return new CommSystemsQuery(*this);
    }

    void
    clear(void)
    {
      type = 0;
      comm_interface = 0;
      model = 0;
      list.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::CommSystemsQuery& other__ = static_cast<const CommSystemsQuery&>(msg__);
      if (type != other__.type) return false;
      if (comm_interface != other__.comm_interface) return false;
      if (model != other__.model) return false;
      if (list != other__.list) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(type, ptr__);
      ptr__ += IMC::serialize(comm_interface, ptr__);
      ptr__ += IMC::serialize(model, ptr__);
      ptr__ += IMC::serialize(list, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::deserialize(comm_interface, bfr__, size__);
      bfr__ += IMC::deserialize(model, bfr__, size__);
      bfr__ += IMC::deserialize(list, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(type, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(comm_interface, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(model, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(list, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return CommSystemsQuery::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "CommSystemsQuery";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 5;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(list);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "type", type, nindent__);
      IMC::toJSON(os__, "comm_interface", comm_interface, nindent__);
      IMC::toJSON(os__, "model", model, nindent__);
      IMC::toJSON(os__, "list", list, nindent__);
    }
  };
}

#endif
