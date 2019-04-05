#ifndef TYPE_CONVERTER_HH
#define TYPE_CONVERTER_HH

#include <type_traits>
#include <initializer_list>
#include <array>

namespace Terryn
{

template <typename Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
constexpr static auto GetUnderlyingType(Enum e) noexcept
{
    return static_cast<std::underlying_type_t<Enum>>(e);
}


template<class Enum, typename = std::enable_if_t<std::is_enum_v<Enum>>>
union EnumConverter
{
    using EnumType = std::underlying_type_t<Enum>;

    Enum en;
    EnumType eType;
};


template<typename BiggerType, typename SmallerType>
union Converter
{
    static_assert(std::is_fundamental_v<BiggerType>, "Left Type is not a Fundamental Type");
    static_assert(std::is_fundamental_v<SmallerType>, "Right Type is not a Fundamental Type");
    static_assert((sizeof(BiggerType) > sizeof(SmallerType) || sizeof(BiggerType) == sizeof(SmallerType)),
                  "Left Type must be larger than or equal to Right type");

    static constexpr size_t GetSize()
    {
        return sizeof(BiggerType) / sizeof(SmallerType);
    }

    BiggerType leftType;
    std::array<SmallerType, GetSize()> rightType;

    Converter(const std::array<SmallerType, GetSize()> &data) : rightType(data)
    {

    }

    Converter(const BiggerType &data) : leftType(data)
    {

    }
};

union FUInt
{
    uint32_t uVal;
    int32_t ival;
    float fVal;

    FUInt()
    {
        uVal = 0;
    }
};

}


#endif // TYPE_CONVERTER_HH
