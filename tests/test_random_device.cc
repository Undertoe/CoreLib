#include "gtest/gtest.h"
#include "random_device.hh"

#include <iostream>

TEST (RandomDevice, FirstTest)
{
    Terryn::RandomWordDevice word(10, 5);
    std::string randomWord = word.GetWord();
    std::string expected = "GOIrdPSAVM";
    //    std::cout << "Word: " << randomWord << std::endl;
    EXPECT_EQ(randomWord, expected);
}

/// compile time test
/// this just verifies everything initializes correctly
TEST(RandomDevice, Verify_Types_Default_Constructor)
{
    Terryn::UniformFloat32RandomDevice randomFloat;
    Terryn::UniformFloat64RandomDevice randomDouble;
    Terryn::UniformSInt8RandomDevice randomint8;
    Terryn::UniformSInt16RandomDevice randomint16;
    Terryn::UniformSInt32RandomDevice randomint32;
    Terryn::UniformSInt64RandomDevice randomint64;
    Terryn::UniformUInt8RandomDevice randomuint8;
    Terryn::UniformUInt16RandomDevice randomuint16;
    Terryn::UniformUInt32RandomDevice randomuint32;
    Terryn::UniformUInt64RandomDevice randomuint64;

    Terryn::RandomWordDevice randomWord;
    Terryn::FullyRandomStringDevice randomFullWord;

    EXPECT_TRUE(randomFloat.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomDouble.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomint8.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomint16.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomint32.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomint64.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomuint8.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomuint16.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomuint32.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomuint64.GetSeed() == std::nullopt);

    EXPECT_TRUE(randomWord.GetSeed() == std::nullopt);
    EXPECT_TRUE(randomFullWord.GetSeed() == std::nullopt);
}

TEST(RandomDevice, Verify_Seed32_Constructor)
{
    int32_t seed = 10;
    Terryn::UniformFloat32RandomDevice randomFloat(seed);
    Terryn::UniformFloat64RandomDevice randomDouble(seed);
    Terryn::UniformSInt8RandomDevice randomint8(seed);
    Terryn::UniformSInt16RandomDevice randomint16(seed);
    Terryn::UniformSInt32RandomDevice randomint32(seed);
    Terryn::UniformSInt64RandomDevice randomint64(seed);
    Terryn::UniformUInt8RandomDevice randomuint8(seed);
    Terryn::UniformUInt16RandomDevice randomuint16(seed);
    Terryn::UniformUInt32RandomDevice randomuint32(seed);
    Terryn::UniformUInt64RandomDevice randomuint64(seed);
    Terryn::RandomWordDevice randomWord(10, seed);
    Terryn::FullyRandomStringDevice randomFullWord(10, seed);


    EXPECT_TRUE(randomFloat.GetSeed() == seed);
    EXPECT_TRUE(randomDouble.GetSeed() == seed);
    EXPECT_TRUE(randomint8.GetSeed() == seed);
    EXPECT_TRUE(randomint16.GetSeed() == seed);
    EXPECT_TRUE(randomint32.GetSeed() == seed);
    EXPECT_TRUE(randomint64.GetSeed() == seed);
    EXPECT_TRUE(randomuint8.GetSeed() == seed);
    EXPECT_TRUE(randomuint16.GetSeed() == seed);
    EXPECT_TRUE(randomuint32.GetSeed() == seed);
    EXPECT_TRUE(randomuint64.GetSeed() == seed);

    EXPECT_TRUE(randomWord.GetSeed() == seed);
    EXPECT_TRUE(randomFullWord.GetSeed() == seed);
}

TEST(RandomDevice, Verify_Seed64_Constructor)
{
    int64_t seed = 10;
    Terryn::UniformFloat32RandomDevice randomFloat(seed);
    Terryn::UniformFloat64RandomDevice randomDouble(seed);
    Terryn::UniformSInt8RandomDevice randomint8(seed);
    Terryn::UniformSInt16RandomDevice randomint16(seed);
    Terryn::UniformSInt32RandomDevice randomint32(seed);
    Terryn::UniformSInt64RandomDevice randomint64(seed);
    Terryn::UniformUInt8RandomDevice randomuint8(seed);
    Terryn::UniformUInt16RandomDevice randomuint16(seed);
    Terryn::UniformUInt32RandomDevice randomuint32(seed);
    Terryn::UniformUInt64RandomDevice randomuint64(seed);
    Terryn::RandomWordDevice randomWord(10, 10);
    Terryn::FullyRandomStringDevice randomFullWord(10, 10);


    EXPECT_TRUE(randomFloat.GetSeed() == seed);
    EXPECT_TRUE(randomDouble.GetSeed() == seed);
    EXPECT_TRUE(randomint8.GetSeed() == seed);
    EXPECT_TRUE(randomint16.GetSeed() == seed);
    EXPECT_TRUE(randomint32.GetSeed() == seed);
    EXPECT_TRUE(randomint64.GetSeed() == seed);
    EXPECT_TRUE(randomuint8.GetSeed() == seed);
    EXPECT_TRUE(randomuint16.GetSeed() == seed);
    EXPECT_TRUE(randomuint32.GetSeed() == seed);
    EXPECT_TRUE(randomuint64.GetSeed() == seed);

    EXPECT_TRUE(randomWord.GetSeed() == seed);
    EXPECT_TRUE(randomFullWord.GetSeed() == seed);
}


TEST(RandomDevice, Verify_Bounds_Constructor)
{
    int64_t seed = 10;
    Terryn::UniformFloat32RandomDevice randomFloat(1.0f, 5.0f, seed);
    Terryn::UniformFloat64RandomDevice randomDouble(1.0, 5.0, seed);
    Terryn::UniformSInt8RandomDevice randomint8(static_cast<int8_t>(0), static_cast<int8_t>(10), seed);
    Terryn::UniformSInt16RandomDevice randomint16(static_cast<int16_t>(0), static_cast<int16_t>(10), seed);
    Terryn::UniformSInt32RandomDevice randomint32(static_cast<int32_t>(0), static_cast<int32_t>(10), seed);
    Terryn::UniformSInt64RandomDevice randomint64(static_cast<int64_t>(0), static_cast<int64_t>(10), seed);
    Terryn::UniformUInt8RandomDevice randomuint8(static_cast<uint8_t>(0), static_cast<uint8_t>(10), seed);
    Terryn::UniformUInt16RandomDevice randomuint16(static_cast<uint16_t>(0), static_cast<uint16_t>(10), seed);
    Terryn::UniformUInt32RandomDevice randomuint32(static_cast<uint32_t>(0), static_cast<uint32_t>(10), seed);
    Terryn::UniformUInt64RandomDevice randomuint64(static_cast<uint64_t>(0), static_cast<uint64_t>(10), seed);


    EXPECT_TRUE(randomFloat.GetSeed() == seed);
    EXPECT_TRUE(randomDouble.GetSeed() == seed);
    EXPECT_TRUE(randomint8.GetSeed() == seed);
    EXPECT_TRUE(randomint16.GetSeed() == seed);
    EXPECT_TRUE(randomint32.GetSeed() == seed);
    EXPECT_TRUE(randomint64.GetSeed() == seed);
    EXPECT_TRUE(randomuint8.GetSeed() == seed);
    EXPECT_TRUE(randomuint16.GetSeed() == seed);
    EXPECT_TRUE(randomuint32.GetSeed() == seed);
    EXPECT_TRUE(randomuint64.GetSeed() == seed);
}


TEST(RandomDevice, Seed_Unseeded_Basic_Device)
{
    Terryn::UniformFloat64RandomDevice testDevice;
    EXPECT_TRUE(testDevice.GetSeed() == std::nullopt);
    testDevice.SeedEngine(1);
    EXPECT_EQ(1, testDevice.GetSeed());
}

TEST(RandomDevice, Unseed_Seeded_Basic_Device)
{
    Terryn::UniformFloat32RandomDevice testDevice(13);
    EXPECT_TRUE(testDevice.GetSeed() == 13);
    testDevice.SeedEngine(0);
    EXPECT_TRUE(testDevice.GetSeed() == std::nullopt);
}
