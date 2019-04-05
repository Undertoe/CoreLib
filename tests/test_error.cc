#include "gtest/gtest.h"
#include "error.hh"

TEST(TerrynError, DefaultConstructor)
{
    Terryn::Error rror;
    EXPECT_EQ(rror.InError(), false);
    EXPECT_EQ(rror.GetError(), std::nullopt);
}

TEST(TerrynError, SetError)
{
    std::string errorString = "Default Error Flag";
    Terryn::Error rror;
    rror.SetError(errorString);
    EXPECT_EQ(rror.InError(), true);
    EXPECT_EQ(rror.GetError(), errorString);
}


TEST(TerrynError, AppendError)
{
    std::string errorString1 = "Default Error Flag";
    std::string errorString2 = "Another Error";
    Terryn::Error rror;
    std::string fullString = errorString1 + "\n" + errorString2;
    rror.AppendError(errorString1);
    rror.AppendError(errorString2);
    EXPECT_EQ(rror.InError(), true);
    EXPECT_EQ(rror.GetError(), fullString);
}

TEST(TerrynError, ErrorDoesNotOverride)
{
    std::string errorString1 = "Default Error Flag";
    std::string errorString2 = "Another Error";
    Terryn::Error rror;
    rror.SetError(errorString1);
    rror.SetError(errorString2);
    EXPECT_EQ(rror.InError(), true);
    EXPECT_EQ(rror.GetError(), errorString1);
    EXPECT_NE(rror.GetError(), errorString2);
}

TEST(TerrynError, GetErrorResetsState)
{
    std::string errorString = "Default Error Flag";
    Terryn::Error rror;
    rror.SetError(errorString);
    EXPECT_EQ(rror.InError(), true);
    EXPECT_EQ(rror.GetError(), errorString);
    EXPECT_EQ(rror.InError(), false);
    EXPECT_EQ(rror.GetError(), std::nullopt);
}
