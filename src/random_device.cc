#include "random_device.hh"

Terryn::RandomWordDevice::RandomWordDevice() :
    _dev(static_cast<uint32_t>(0), static_cast<uint32_t>(_values.size() - 1), 0)
{ }

Terryn::RandomWordDevice::RandomWordDevice(uint32_t count, int32_t seed) :
    _dev(static_cast<uint32_t>(0), static_cast<uint32_t>(_values.size() - 1), seed),
    _wordSize(count)
{ }

std::string Terryn::RandomWordDevice::GetWord()
{
    std::string retval = "";
    for(uint32_t i = 0; i < _wordSize; i ++)
    {
        retval += _values.at(_dev.GetRandom());
    }
    return retval;
}

std::string Terryn::RandomWordDevice::GetWord(uint32_t wordSize)
{
    std::string retval = "";
    for(uint32_t i = 0 ; i < wordSize; i ++)
    {
        retval += _values.at(_dev.GetRandom());
    }
    return retval;
}

void Terryn::RandomWordDevice::SetSeed(int32_t seed)
{
    _dev.SeedEngine(seed);
}

std::optional<int32_t> Terryn::RandomWordDevice::GetSeed() const
{
    return _dev.GetSeed();
}


Terryn::FullyRandomStringDevice::FullyRandomStringDevice() :
     _dev(static_cast<uint32_t>(32), static_cast<uint32_t>(126), 0)
{ }

Terryn::FullyRandomStringDevice::FullyRandomStringDevice(uint32_t count, int32_t seed) :
    _dev(static_cast<uint32_t>(32), static_cast<uint32_t>(126), seed),
    _wordSize(count)
{ }

std::string Terryn::FullyRandomStringDevice::GetWord()
{
    std::string retval = "";
    for(uint32_t i = 0; i < _wordSize; i ++)
    {
        retval += std::to_string(_dev.GetRandom());
    }
    return retval;
}

std::string Terryn::FullyRandomStringDevice::GetWord(uint32_t wordSize)
{
    std::string retval = "";
    for(uint32_t i = 0 ; i < wordSize; i ++)
    {
        retval += std::to_string(_dev.GetRandom());
    }
    return retval;
}

void Terryn::FullyRandomStringDevice::SetSeed(int32_t seed)
{
    _dev.SeedEngine(seed);
}

std::optional<int32_t> Terryn::FullyRandomStringDevice::GetSeed() const
{
    return _dev.GetSeed();
}


