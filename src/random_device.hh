#ifndef RANDOM_DEVICE_HH
#define RANDOM_DEVICE_HH

#include <random>
#include <optional>
#include <type_traits>
#include <array>

//#include "singleton.h"

namespace Terryn
{
template<typename ReturnType, typename DistributionType,
          typename = std::enable_if<std::is_arithmetic_v<ReturnType>>
          >
class BasicRandomDevice
{
private:
    std::mt19937_64 *engine;
    DistributionType distribution;

    bool _seeded = false;
    int32_t _seed = 0;

    template<typename BoundType,typename = std::enable_if<std::is_arithmetic_v<BoundType>>>
    void SetupDistribution(BoundType lower = std::numeric_limits<BoundType>::min(),
                           BoundType upper = std::numeric_limits<BoundType>::max())
    {
        distribution = DistributionType(lower, upper);
    }

    void SetupEngine()
    {
        //        engine = &Singleton<std::mt19937_64>::Instance();
        engine = new std::mt19937_64();
    }

public:

    BasicRandomDevice()
    {
        SetupEngine();
        std::random_device device;
        engine->seed(device());
        SetupDistribution<ReturnType>();
    }

    BasicRandomDevice(int32_t seed): _seed(seed), _seeded(true)
    {
        SetupEngine();
        engine->seed(seed);
        SetupDistribution<ReturnType>();
    }

    BasicRandomDevice(int64_t seed) : _seed(seed), _seeded(true)
    {
        SetupEngine();
        engine->seed(seed);
        SetupDistribution<ReturnType>();
    }


    template<typename BoundType, typename SeedType,
              typename = std::enable_if<std::is_integral_v<SeedType>>,
             typename = std::enable_if<std::is_arithmetic_v<BoundType>>,
              typename = std::enable_if<std::is_same_v<BoundType, ReturnType>>
              >
    BasicRandomDevice(BoundType lower, BoundType upper, SeedType seed = 0)
    {
        SetupEngine();
        if(seed != 0)
        {
            _seeded = true;
            _seed = seed;
            engine->seed(seed);
        }
        else
        {
            std::random_device device;
            engine->seed(device());
        }
        SetupDistribution(lower, upper);
    }

    ~BasicRandomDevice()
    {
        delete engine;
    }

    ReturnType GetRandom()
    {
        return distribution(*engine);
    }

    std::optional<int32_t> GetSeed() const
    {
        return _seeded ? std::optional<int32_t>(_seed) : std::nullopt;
    }

    void SeedEngine(int32_t seed = 0)
    {
        if(seed == 0)
        {
            std::random_device device;
            engine->seed(device());
            _seeded = false;
            _seed = 0;
        }
        else
        {
            engine->seed(seed);
            _seeded = true;
            _seed = seed;
        }

    }

};



template<typename T>
using UniformRealRandomDevice = BasicRandomDevice<T, std::uniform_real_distribution<T>>;

using UniformFloat32RandomDevice = UniformRealRandomDevice<float>;
using UniformFloat64RandomDevice = UniformRealRandomDevice<double>;

template<typename T>
using UniformIntRandomDevice = BasicRandomDevice<T, std::uniform_int_distribution<T>>;

using UniformSInt64RandomDevice = UniformIntRandomDevice<int64_t>;
using UniformUInt64RandomDevice = UniformIntRandomDevice<uint64_t>;
using UniformSInt32RandomDevice = UniformIntRandomDevice<int32_t>;
using UniformUInt32RandomDevice = UniformIntRandomDevice<uint32_t>;
using UniformSInt16RandomDevice = UniformIntRandomDevice<int16_t>;
using UniformUInt16RandomDevice = UniformIntRandomDevice<uint16_t>;
using UniformSInt8RandomDevice = UniformIntRandomDevice<int8_t>;
using UniformUInt8RandomDevice = UniformIntRandomDevice<uint8_t>;


class RandomWordDevice
{
private:
    static constexpr std::array<char, 52> _values =
        {
            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
             't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
             'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}
    };
    UniformUInt64RandomDevice _dev;
    uint32_t _wordSize = 1;

public:
    RandomWordDevice();
    RandomWordDevice(uint32_t count, int32_t seed);

    std::string GetWord();
    std::string GetWord(uint32_t wordSize);

    void SetSeed(int32_t seed);
    std::optional<int32_t> GetSeed() const;

};

class FullyRandomStringDevice
{
private:
    UniformSInt8RandomDevice _dev;
    uint32_t _wordSize = 1;

public:
    FullyRandomStringDevice();
    FullyRandomStringDevice(uint32_t count, int32_t seed);

    std::string GetWord();
    std::string GetWord(uint32_t wordSize);

    void SetSeed(int32_t seed);
    std::optional<int32_t> GetSeed() const;

}; /// end namespace 


}

#endif // RANDOM_DEVICE_HH
