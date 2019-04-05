#include "gtest/gtest.h"
#include "complex.hh"
#include "complex.h"


TEST(TerrynComplex, OperatorPlus)
{
    Terryn::complex<float> comp1(1.0, 0.0);
    Terryn::complex<float> comp2(1.0, 0.0);
    std::complex<float> stdComp1(1.0, 0.0);
    std::complex<float> stdComp2(1.0, 0.0);

    comp1 += comp2;
    stdComp1 += stdComp2;
}
