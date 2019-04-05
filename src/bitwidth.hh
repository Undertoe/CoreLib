#ifndef BITWIDTH_HH
#define BITWIDTH_HH

#include <type_traits>

namespace Terryn
{
template<typename T>
constexpr bool Is8Bit()
{
    return (sizeof(T) == 1);
}

template<typename T>
constexpr bool Is16Bit()
{
    return (sizeof(T) == 2);
}

template<typename T>
constexpr bool Is32Bit()
{
    return (sizeof(T) == 4);
}

template<typename T>
constexpr bool Is64Bit()
{
    return (sizeof(T) == 8);
}


template<typename T>
constexpr bool IsAddressEnabled()
{
    return Is8Bit<T>() || Is16Bit<T>() || Is32Bit<T>() || Is64Bit<T>();
}
}

#endif // BITWIDTH_HH
