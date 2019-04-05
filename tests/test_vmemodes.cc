#include "gtest/gtest.h"
#include "random_device.hh"

#include <iostream>

#include "vmemodes.hh"

TEST(VMEModes, Setup)
{
    EXPECT_TRUE(true);
}


TEST(VMEModes, AddressModeToString)
{
    using namespace Terryn;
    EXPECT_EQ("a16", ToString(VMEAddressMode::A16));
    EXPECT_EQ("a24", ToString(VMEAddressMode::A24));
    EXPECT_EQ("a32", ToString(VMEAddressMode::A32));
    EXPECT_EQ("a64", ToString(VMEAddressMode::A64));
}


TEST(VMEModes, DataWidthToString)
{
    using namespace Terryn;
    EXPECT_EQ("d8", ToString(VMEDataWidth::D8));
    EXPECT_EQ("d16", ToString(VMEDataWidth::D16));
    EXPECT_EQ("d32", ToString(VMEDataWidth::D32));
    EXPECT_EQ("d64", ToString(VMEDataWidth::D64));
}
