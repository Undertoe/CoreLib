#ifndef BUFFER_HH
#define BUFFER_HH

#include <array>
#include <type_traits>
#include <optional>

#include "addresstype.hh"


namespace Terryn
{
template<typename Type, size_t BytesLong,
          size_t length = BytesLong / sizeof(Type),
          typename = std::enable_if<Terryn::IsAddressEnabled<Type>>
          >
class Buffer
{
public:

    using type = Type;
    using typeptr = Type *;

    Buffer() = default;
    constexpr Buffer(const AddressType &offset) : _offset(offset)
    {

    }


    std::optional<typeptr> GetPointer(uint32_t index)
    {
        if(index > _data.size())
        {
            return std::nullopt;
        }

        return &_data[index];
    }

    std::optional<typeptr> GetPointer(const AddressType address)
    {
        if(address < _offset)
        {
            return std::nullopt;
        }

        const AddressType offsetAddress = _offset - address;
        if(offsetAddress.Index(_data) > _data.size())
        {
            return std::nullopt;
        }
        return &_data[offsetAddress.Index(_data)];
    }


    const std::optional<type> Value(uint32_t index)
    {
        return _data[index];
    }

    const std::optional<type> Value(const AddressType address)
    {
        if(address < _offset)
        {
            return std::nullopt;
        }

        const AddressType offsetAddress = _offset - address;
        if(offsetAddress.Index(_data) > _data.size())
        {
            return std::nullopt;
        }
        return _data[offsetAddress.Index(_data)];
    }


    const bool Set(uint32_t index, type data)
    {
        if(index > _data.size())
        {
            return false;
        }
        _data[index] = data;
        return true;
    }

    const bool Set(const AddressType &address, type data)
    {
        if(address < _offset)
        {
            return false;
        }
        const AddressType offsetAddress = _offset - address;
        if(offsetAddress.Index(_data) > _data.size())
        {
            return false;
        }

        _data[offsetAddress.Index(_data)] = data;
        return true;
    }


private:
    AddressType _offset = AddressType(Address(0x0));
    std::array<Type, length> _data;

};
}

#endif // BUFFER_HH
