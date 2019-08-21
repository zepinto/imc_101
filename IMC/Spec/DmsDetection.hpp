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

#ifndef IMC_DMSDETECTION_HPP_INCLUDED_
#define IMC_DMSDETECTION_HPP_INCLUDED_

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
  //! DMS Detection.
  class DmsDetection: public Message
  {
  public:
    //! Channel 1.
    float ch01;
    //! Channel 2.
    float ch02;
    //! Channel 3.
    float ch03;
    //! Channel 4.
    float ch04;
    //! Channel 5.
    float ch05;
    //! Channel 6.
    float ch06;
    //! Channel 7.
    float ch07;
    //! Channel 8.
    float ch08;
    //! Channel 9.
    float ch09;
    //! Channel 10.
    float ch10;
    //! Channel 11.
    float ch11;
    //! Channel 12.
    float ch12;
    //! Channel 13.
    float ch13;
    //! Channel 14.
    float ch14;
    //! Channel 15.
    float ch15;
    //! Channel 16.
    float ch16;

    static uint16_t
    getIdStatic(void)
    {
      return 908;
    }

    static DmsDetection*
    cast(Message* msg__)
    {
      return (DmsDetection*)msg__;
    }

    DmsDetection(void)
    {
      m_header.mgid = DmsDetection::getIdStatic();
      clear();
    }

    DmsDetection*
    clone(void) const
    {
      return new DmsDetection(*this);
    }

    void
    clear(void)
    {
      ch01 = 0;
      ch02 = 0;
      ch03 = 0;
      ch04 = 0;
      ch05 = 0;
      ch06 = 0;
      ch07 = 0;
      ch08 = 0;
      ch09 = 0;
      ch10 = 0;
      ch11 = 0;
      ch12 = 0;
      ch13 = 0;
      ch14 = 0;
      ch15 = 0;
      ch16 = 0;
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::DmsDetection& other__ = static_cast<const DmsDetection&>(msg__);
      if (ch01 != other__.ch01) return false;
      if (ch02 != other__.ch02) return false;
      if (ch03 != other__.ch03) return false;
      if (ch04 != other__.ch04) return false;
      if (ch05 != other__.ch05) return false;
      if (ch06 != other__.ch06) return false;
      if (ch07 != other__.ch07) return false;
      if (ch08 != other__.ch08) return false;
      if (ch09 != other__.ch09) return false;
      if (ch10 != other__.ch10) return false;
      if (ch11 != other__.ch11) return false;
      if (ch12 != other__.ch12) return false;
      if (ch13 != other__.ch13) return false;
      if (ch14 != other__.ch14) return false;
      if (ch15 != other__.ch15) return false;
      if (ch16 != other__.ch16) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(ch01, ptr__);
      ptr__ += IMC::serialize(ch02, ptr__);
      ptr__ += IMC::serialize(ch03, ptr__);
      ptr__ += IMC::serialize(ch04, ptr__);
      ptr__ += IMC::serialize(ch05, ptr__);
      ptr__ += IMC::serialize(ch06, ptr__);
      ptr__ += IMC::serialize(ch07, ptr__);
      ptr__ += IMC::serialize(ch08, ptr__);
      ptr__ += IMC::serialize(ch09, ptr__);
      ptr__ += IMC::serialize(ch10, ptr__);
      ptr__ += IMC::serialize(ch11, ptr__);
      ptr__ += IMC::serialize(ch12, ptr__);
      ptr__ += IMC::serialize(ch13, ptr__);
      ptr__ += IMC::serialize(ch14, ptr__);
      ptr__ += IMC::serialize(ch15, ptr__);
      ptr__ += IMC::serialize(ch16, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(ch01, bfr__, size__);
      bfr__ += IMC::deserialize(ch02, bfr__, size__);
      bfr__ += IMC::deserialize(ch03, bfr__, size__);
      bfr__ += IMC::deserialize(ch04, bfr__, size__);
      bfr__ += IMC::deserialize(ch05, bfr__, size__);
      bfr__ += IMC::deserialize(ch06, bfr__, size__);
      bfr__ += IMC::deserialize(ch07, bfr__, size__);
      bfr__ += IMC::deserialize(ch08, bfr__, size__);
      bfr__ += IMC::deserialize(ch09, bfr__, size__);
      bfr__ += IMC::deserialize(ch10, bfr__, size__);
      bfr__ += IMC::deserialize(ch11, bfr__, size__);
      bfr__ += IMC::deserialize(ch12, bfr__, size__);
      bfr__ += IMC::deserialize(ch13, bfr__, size__);
      bfr__ += IMC::deserialize(ch14, bfr__, size__);
      bfr__ += IMC::deserialize(ch15, bfr__, size__);
      bfr__ += IMC::deserialize(ch16, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(ch01, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch02, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch03, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch04, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch05, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch06, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch07, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch08, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch09, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch10, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch11, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch12, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch13, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch14, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch15, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(ch16, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return DmsDetection::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "DmsDetection";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 64;
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "ch01", ch01, nindent__);
      IMC::toJSON(os__, "ch02", ch02, nindent__);
      IMC::toJSON(os__, "ch03", ch03, nindent__);
      IMC::toJSON(os__, "ch04", ch04, nindent__);
      IMC::toJSON(os__, "ch05", ch05, nindent__);
      IMC::toJSON(os__, "ch06", ch06, nindent__);
      IMC::toJSON(os__, "ch07", ch07, nindent__);
      IMC::toJSON(os__, "ch08", ch08, nindent__);
      IMC::toJSON(os__, "ch09", ch09, nindent__);
      IMC::toJSON(os__, "ch10", ch10, nindent__);
      IMC::toJSON(os__, "ch11", ch11, nindent__);
      IMC::toJSON(os__, "ch12", ch12, nindent__);
      IMC::toJSON(os__, "ch13", ch13, nindent__);
      IMC::toJSON(os__, "ch14", ch14, nindent__);
      IMC::toJSON(os__, "ch15", ch15, nindent__);
      IMC::toJSON(os__, "ch16", ch16, nindent__);
    }
  };
}

#endif
