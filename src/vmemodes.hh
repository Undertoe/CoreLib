#ifndef VMEMODES_HH
#define VMEMODES_HH

#include <type_traits>
#include <string>

#include "bitwidth.hh"

namespace Terryn
{

enum class VMEAddressMode
{
    A16, A24, A32, A64,
};
std::string ToString(VMEAddressMode m);

enum class VMEDataWidth : uint32_t
{
    D8 = sizeof(uint8_t),
    D16 = sizeof(uint16_t),
    D32 = sizeof(uint32_t),
    D64 = sizeof(uint64_t),
};
std::string ToString(VMEDataWidth m);
template<typename DataType,
          typename = std::enable_if<std::is_integral_v<DataType>>,
          typename = std::enable_if<!Terryn::Is64Bit<DataType>()>>
constexpr static VMEDataWidth GetDataWidth(const DataType &sentinal)
{
    static_assert (IsAddressEnabled<DataType>(), "Must be an address enabled type");

    if constexpr (Is8Bit<DataType>())
    {
        return VMEDataWidth::D8;
    }
    else if constexpr (Is16Bit<DataType>())
    {
        return VMEDataWidth::D16;
    }
    else if constexpr (Is32Bit<DataType>())
    {
        return VMEDataWidth::D32;
    }
    else
    {
        return VMEDataWidth::D64;
    }
}



}


#endif // VMEMODES_HH
