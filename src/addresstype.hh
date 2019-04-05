#ifndef ADDRESSTYPE_HH
#define ADDRESSTYPE_HH

#include <stdint.h>
#include <stddef.h>
#include <type_traits>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>

#include "bitwidth.hh"

namespace Terryn
{


struct Index
{
    size_t size;
    uint32_t value;

    Index() = default;

    /// specialization that allows you to pass an array in as type
    /// very useful for passing various items into the data
    template<typename MyType,
              typename = std::enable_if_t<std::is_array_v<MyType>>,
              size_t _size = sizeof(std::remove_extent_t<MyType>)>
    constexpr Index(MyType _sentinal, uint32_t v) :  size(_size), value(v)
    {
        static_assert(IsAddressEnabled<std::remove_extent_t<MyType>>(), "Must use a simplified type for address type");
    }


    template<typename MyType, size_t _size = sizeof(MyType)>
    constexpr Index(MyType _sentinal, uint32_t v) :  size(_size), value(v)
    {
        static_assert(IsAddressEnabled<MyType>(), "Must use a simplified type for address type");
    }

    template<typename MyType, size_t _size = sizeof(MyType)>
    constexpr Index(MyType *_sentinal, uint32_t v) : size(_size), value(v)
    {
        static_assert(IsAddressEnabled<MyType>(), "Must use a simplified type for address type");
    }

    constexpr Index(const Index &other) = default;
    constexpr Index& operator =(const Index &other) = default;
    constexpr Index(Index &&other) = default;
    constexpr Index& operator =(Index &&other) = default;
};

struct Address
{
    uint32_t value;

    Address() = default;
    constexpr Address(uint32_t v) : value(v) {}
    constexpr Address(const Address &other) = default;
    constexpr Address& operator =(const Address &other) = default;
    constexpr Address(Address &&other) = default;
    constexpr Address& operator =(Address &&other) = default;
};


inline constexpr Address operator+(const Address &left, const Address &right)
{
    return Address(left.value + right.value);
}

inline constexpr Address operator-(const Address &left, const Address &right)
{
    return Address(left.value - right.value);
}


class AddressType
{
public:
    AddressType() = default;
    constexpr AddressType(Terryn::Address address) :
        _address(address.value)
    {

    }

    /// converts the type and index to the required address
    constexpr AddressType(Terryn::Index index) :
                                               _size(index.size),
                                               _address(index.size * index.value)
    {

    }

    constexpr AddressType(const AddressType &other) = default;
    constexpr AddressType& operator =(const AddressType &other) = default;
    constexpr AddressType(AddressType &&other) = default;
    constexpr AddressType& operator =(AddressType &&other) = default;

    /// ptr used for type deduction.  Gives an option of using () over <>
    template<typename AddressType/*, size_t size = */>
    constexpr uint32_t Index(const AddressType *sentinal = nullptr) const
    {
        static_assert(IsAddressEnabled<AddressType>(), "Must use a simplified type for address type");
        return _address / sizeof(AddressType);
    }

    constexpr uint32_t Address() const
    {
        return _address;
    }

    constexpr size_t Size() const
    {
        return _size;
    }

    constexpr AddressType& operator+=(const AddressType &addr)
    {
        this->_address = this->_address + addr.Address();
        return *this;
    }

    constexpr AddressType& operator-=(const AddressType &addr)
    {
        this->_address = this->_address - addr.Address();
        return *this;
    }

    std::string ToString(bool Prefix = true) const
    {
        std::stringstream ss;
        if(Prefix)
        {
            ss << "0x";
        }
        ss << std::hex << _address;
        return ss.str();
    }


private:
    size_t _size = 1;
    uint32_t _address;
};

inline constexpr bool operator<(const AddressType &left, const AddressType &right)
{
    return left.Address() < right.Address();
}

inline constexpr bool operator>(const AddressType &left, const AddressType &right)
{
    return left.Address() > right.Address();
}

inline constexpr bool operator==(const AddressType &left, const AddressType &right)
{
    return left.Address() == right.Address();
}

inline constexpr bool operator!=(const AddressType &left, const AddressType &right)
{
    return !(left == right);
}

inline constexpr AddressType operator+(const AddressType &left, const AddressType &right)
{
    return AddressType(left.Address() + right.Address());
}

inline constexpr AddressType operator-(const AddressType &left, const AddressType &right)
{
    return AddressType(left.Address() - right.Address());
}

inline constexpr AddressType MaskAddressA16(const AddressType &other)
{
    return AddressType((other.Address() & 0x0000FFFF));
}

inline constexpr AddressType MaskAddressA24(const AddressType &other)
{
    return AddressType((other.Address() & 0x00FFFFFF));
}


}

#endif // ADDRESSTYPE_HH
