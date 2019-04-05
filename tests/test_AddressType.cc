#include "gtest/gtest.h"
#include "error.hh"

#include <array>

#include "addresstype.hh"

TEST(AddressType, AddressInitBase)
{
    EXPECT_TRUE(true);
//    AddressType add1;
//    EXPECT_EQ(add1.Address(), 0);
}

TEST(AddressType, CompileCheck)
{
    uint32_t address = 0x1000;
    Terryn::AddressType add1((Terryn::Address(address)));
    Terryn::AddressType add2(Terryn::Index(address, address));
}

TEST(AddressType, AddressInitAddress)
{
    using namespace Terryn;
    uint32_t data[200];
    AddressType add2(Address(0x05060708));
    AddressType add3(add2);

    uint64_t *ptrData = new uint64_t(100);
    AddressType add4(Index(ptrData, 0));

//    std::cout << "Pointer detected: " << std::boolalpha << add4.PointerDetected << std::endl;

    EXPECT_EQ(add2.Index(data), 0x5060708 / 4);
    EXPECT_EQ(add2.Address(), add3.Address());
}

TEST(AddressType, AddressInitIndex)
{
    using namespace Terryn;
    uint32_t data[2000];
    AddressType add1(Index(data, 100));
    uint64_t data2[20000];
    AddressType add2(Index(data2, 50));

    EXPECT_EQ(add1.Size(), sizeof(uint32_t));
    EXPECT_EQ(add2.Size(), sizeof(uint64_t));


    EXPECT_EQ(add1.Address(), 100 * sizeof(uint32_t));
    EXPECT_EQ(add1.Index(data2), 50);

    EXPECT_EQ(add1.Address(), add2.Address());

}

TEST(AddressType, PointerGet)
{
    using namespace Terryn;

    uint32_t Data[2000];
    uint32_t start = 1;
    for(auto &d : Data)
    {
        start += start;
        d = start;
    }

//    uint32_t *ptr = &Data[1000];

    uint32_t location = 0x0100;
    AddressType addr((Address(location)));
    uint32_t *ptr = &Data[1000];
    EXPECT_EQ(addr.Index(ptr), location / 4);
}


TEST(AddressType, Comparisons)
{
    using namespace Terryn;
    AddressType add1(Address(0x05060708));
    AddressType add2(Address(0x05060709));

    EXPECT_TRUE(add1 < add2);
    EXPECT_FALSE(add1 > add2);

    AddressType add3(add1);
    EXPECT_TRUE(add1 == add3);
    EXPECT_FALSE(add2 == add3);
}


TEST(AddressType, Addition)
{
    using namespace Terryn;
    AddressType addr1(Address(0x01020304));
    addr1 += AddressType(Address(0x00001000));

    EXPECT_EQ(addr1.Address(), 0x01021304);
}

TEST(AddressType, Subtraction)
{
    using namespace Terryn;
    AddressType addr1(0x00010FFF);
    addr1 -= AddressType(0x00000FFF);

    EXPECT_EQ(addr1.Address(), 0x00010000);
}


TEST(AddressType, ConstexprChecks)
{
    using namespace  Terryn;
    constexpr AddressType addrBegin(Address(0x48000000));
    constexpr AddressType addrEnd(Address(0x48001000));
    constexpr AddressType addrOffset(Address(0x00001000));

    constexpr AddressType range = addrEnd - addrBegin;

    std::array<uint32_t, range.Index<uint32_t>()> data1;
    std::array<uint32_t, AddressType(addrEnd - addrBegin).Index<uint32_t>()> data2;
    std::array<uint32_t, AddressType(AddressType(addrOffset + addrBegin) - addrBegin).Index<uint32_t>()> data3;
    std::array<uint32_t, AddressType(addrOffset).Index<uint32_t>()> data4;

    constexpr uint32_t count = 0x1000 / 4;

    constexpr uint32_t testarray[3] = {1, 2, 3};

    constexpr AddressType indexBased((Index(count, count)));
    std::array<uint32_t, indexBased.Index<uint32_t>()> data5;

    constexpr AddressType ArrayInitializedIndex(Index(testarray, count));
    std::array<uint32_t, ArrayInitializedIndex.Index<uint32_t>()> data6;


    EXPECT_EQ(count, data1.size());
    EXPECT_EQ(count, data2.size());
    EXPECT_EQ(count, data3.size());
    EXPECT_EQ(count, data4.size());
    EXPECT_EQ(count, data5.size());
    EXPECT_EQ(count, data6.size());
}

TEST(AddressType, ToStringTests)
{
    using namespace  Terryn;
    constexpr AddressType addrBegin(Address(0x48000000));

    std::string expectedPrefixString = "0x48000000";
    std::string expectedNoPrefixString = "48000000";

    EXPECT_EQ(addrBegin.ToString(), expectedPrefixString);
    EXPECT_EQ(addrBegin.ToString(true), expectedPrefixString);
    EXPECT_EQ(addrBegin.ToString(false), expectedNoPrefixString);
}
