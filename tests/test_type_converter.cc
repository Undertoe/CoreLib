#include "type_converter.hh"
#include "gtest/gtest.h"

enum class TempEnum : std::uint32_t
{
    VAL1 = 1,
    VAL2 = 2,
    VAL3 = 3,
};

TEST(TypeConverters, GetUnderlyingType)
{

    EXPECT_EQ(1, Terryn::GetUnderlyingType(TempEnum::VAL1));
}


TEST(TypeConverters, EnumConverter)
{
    Terryn::EnumConverter<TempEnum> myTmpEnum;
    myTmpEnum.en = TempEnum::VAL1;
    std::uint32_t staticValue = 1;

    EXPECT_EQ(staticValue, myTmpEnum.eType);

    staticValue = 2;
    myTmpEnum.en = TempEnum::VAL2;
    EXPECT_EQ(staticValue, myTmpEnum.eType);

}
