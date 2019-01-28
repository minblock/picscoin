#include <boost/test/unit_test.hpp>

#include <string>
#include <vector>

#include "serialize.h"
#include "hash.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(serialize_tests)

BOOST_AUTO_TEST_CASE(sizes)
{
   BOOST_CHECK_EQUAL(sizeof(char), GetSerializeSize(char(0), 0));
   BOOST_CHECK_EQUAL(sizeof(int8_t), GetSerializeSize(int8_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(uint8_t), GetSerializeSize(uint8_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(int16_t), GetSerializeSize(int16_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(uint16_t), GetSerializeSize(uint16_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(int32_t), GetSerializeSize(int32_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(uint32_t), GetSerializeSize(uint32_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(int64_t), GetSerializeSize(int64_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(uint64_t), GetSerializeSize(uint64_t(0), 0));
   BOOST_CHECK_EQUAL(sizeof(float), GetSerializeSize(float(0), 0));
   BOOST_CHECK_EQUAL(sizeof(double), GetSerializeSize(double(0), 0));
   // Bool is serialized as char
   BOOST_CHECK_EQUAL(sizeof(char), GetSerializeSize(bool(0), 0));

   // Sanity-check GetSerializeSize and c type matching
   BOOST_CHECK_EQUAL(GetSerializeSize(char(0), 0), 1);
   BOOST_CHECK_EQUAL(GetSerializeSize(int8_t(0), 0), 1);
   BOOST_CHECK_EQUAL(GetSerializeSize(uint8_t(0), 0), 1);
   BOOST_CHECK_EQUAL(GetSerializeSize(int16_t(0), 0), 2);
   BOOST_CHECK_EQUAL(GetSerializeSize(uint16_t(0), 0), 2);
   BOOST_CHECK_EQUAL(GetSerializeSize(int32_t(0), 0), 4);
   BOOST_CHECK_EQUAL(GetSerializeSize(uint32_t(0), 0), 4);
   BOOST_CHECK_EQUAL(GetSerializeSize(int64_t(0), 0), 8);
   BOOST_CHECK_EQUAL(GetSerializeSize(uint64_t(0), 0), 8);
   BOOST_CHECK_EQUAL(GetSerializeSize(float(0), 0), 4);
   BOOST_CHECK_EQUAL(GetSerializeSize(double(0), 0), 8);
   BOOST_CHECK_EQUAL(GetSerializeSize(bool(0), 0), 1);
}

BOOST_AUTO_TEST_CASE(floats_conversion)
{
   // Choose values that map unambigiously to binary floating point to avoid
   // rounding issues at the compiler side.
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x00000000), 0.0F);
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x3f000000), 0.5F);
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x3f800000), 1.0F);
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x40000000), 2.0F);
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x40800000), 4.0F);
   BOOST_CHECK_EQUAL(ser_uint32_to_float(0x44444444), 785.066650390625F);

   BOOST_CHECK_EQUAL(ser_float_to_uint32(0.0F), 0x00000000);
   BOOST_CHECK_EQUAL(ser_float_to_uint32(0.5F), 0x3f000000);
   BOOST_CHECK_EQUAL(ser_float_to_uint32(1.0F), 0x3f800000);
   BOOST_CHECK_EQUAL(ser_float_to_uint32(2.0F), 0x40000000);
   BOOST_CHECK_EQUAL(ser_float_to_uint32(4.0F), 0x40800000);
   BOOST_CHECK_EQUAL(ser_float_to_uint32(785.066650390625F), 0x44444444);
}

BOOST_AUTO_TEST_CASE(doubles_conversion)
{
   // Choose values that map unambigiously to binary floating point to avoid
   // rounding issues at the compiler side.
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x0000000000000000ULL), 0.0);
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x3fe0000000000000ULL), 0.5);
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x3ff0000000000000ULL), 1.0);
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x4000000000000000ULL), 2.0);
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x4010000000000000ULL), 4.0);
   BOOST_CHECK_EQUAL(ser_uint64_to_double(0x4088888880000000ULL), 785.066650390625);

   BOOST_CHECK_EQUAL(ser_double_to_uint64(0.0), 0x0000000000000000ULL);
   BOOST_CHECK_EQUAL(ser_double_to_uint64(0.5), 0x3fe0000000000000ULL);
   BOOST_CHECK_EQUAL(ser_double_to_uint64(1.0), 0x3ff0000000000000ULL);
   BOOST_CHECK_EQUAL(ser_double_to_uint64(2.0), 0x4000000000000000ULL);
   BOOST_CHECK_EQUAL(ser_double_to_uint64(4.0), 0x4010000000000000ULL);
   BOOST_CHECK_EQUAL(ser_double_to_uint64(785.066650390625), 0x4088888880000000ULL);
}


BOOST_AUTO_TEST_CASE(varints)
{
    // encode

    CDataStream ss(SER_DISK, 0);
    CDataStream::size_type size = 0;
    for (int i = 0; i < 100000; i++) {
        ss << VARINT(i);
        size += ::GetSerializeSize(VARINT(i), 0, 0);
        BOOST_CHECK(size == ss.size());
    }

    for (uint64 i = 0;  i < 100000000000ULL; i += 999999937) {
        ss << VARINT(i);
        size += ::GetSerializeSize(VARINT(i), 0, 0);
        BOOST_CHECK(size == ss.size());
    }

    // decode
    for (int i = 0; i < 100000; i++) {
        int j = -1;
        ss >> VARINT(j);
        BOOST_CHECK_MESSAGE(i == j, "decoded:" << j << " expected:" << i);
    }

    for (uint64 i = 0;  i < 100000000000ULL; i += 999999937) {
        uint64 j = -1;
        ss >> VARINT(j);
        BOOST_CHECK_MESSAGE(i == j, "decoded:" << j << " expected:" << i);
    }

}

BOOST_AUTO_TEST_CASE(insert_delete)
{
    // Test inserting/deleting bytes.
    CDataStream ss(SER_DISK, 0);
    BOOST_CHECK_EQUAL(ss.size(), 0);

    ss.write("\x00\x01\x02\xff", 4);
    BOOST_CHECK_EQUAL(ss.size(), 4);

    char c = (char)11;

    // Inserting at beginning/end/middle:
    ss.insert(ss.begin(), c);
    BOOST_CHECK_EQUAL(ss.size(), 5);
    BOOST_CHECK_EQUAL(ss[0], c);
    BOOST_CHECK_EQUAL(ss[1], 0);

    ss.insert(ss.end(), c);
    BOOST_CHECK_EQUAL(ss.size(), 6);
    BOOST_CHECK_EQUAL(ss[4], (char)0xff);
    BOOST_CHECK_EQUAL(ss[5], c);

    ss.insert(ss.begin()+2, c);
    BOOST_CHECK_EQUAL(ss.size(), 7);
    BOOST_CHECK_EQUAL(ss[2], c);

    // Delete at beginning/end/middle
    ss.erase(ss.begin());
    BOOST_CHECK_EQUAL(ss.size(), 6);
    BOOST_CHECK_EQUAL(ss[0], 0);

    ss.erase(ss.begin()+ss.size()-1);
    BOOST_CHECK_EQUAL(ss.size(), 5);
    BOOST_CHECK_EQUAL(ss[4], (char)0xff);

    ss.erase(ss.begin()+1);
    BOOST_CHECK_EQUAL(ss.size(), 4);
    BOOST_CHECK_EQUAL(ss[0], 0);
    BOOST_CHECK_EQUAL(ss[1], 1);
    BOOST_CHECK_EQUAL(ss[2], 2);
    BOOST_CHECK_EQUAL(ss[3], (char)0xff);

    // Make sure GetAndClear does the right thing:
    CSerializeData d;
    ss.GetAndClear(d);
    BOOST_CHECK_EQUAL(ss.size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
