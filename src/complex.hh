#ifndef COMPLEX_HH
#define COMPLEX_HH

#include <type_traits>
#include <cmath>

namespace Terryn
{
template<typename _type> struct complex;

template<typename _type> _type abs(const complex<_type>&);
template<typename _type> _type arg(const complex<_type>&);
template<typename _type> _type norm(const complex<_type>&);
template<typename _type> complex<_type> conj(const complex<_type>&);
template<typename _type> complex<_type> polar(const _type &, const _type & = 0);

/// trancendentals:
template<typename _type> complex<_type> cos(const complex<_type> &);
template<typename _type> complex<_type> cosh(const complex<_type> &);
template<typename _type> complex<_type> exp(const complex<_type> &);
template<typename _type> complex<_type> log(const complex<_type> &);
template<typename _type> complex<_type> log10(const complex<_type> &);
template<typename _type> complex<_type> pow(const complex<_type> &);
template<typename _type> complex<_type> pow(const complex<_type> &, const _type &);
template<typename _type> complex<_type> pow(const complex<_type> &, const complex<_type> &);
template<typename _type> complex<_type> pow(const _type &, const complex<_type> &);
template<typename _type> complex<_type> sin(const complex<_type> &);
template<typename _type> complex<_type> sinh(const complex<_type> &);
template<typename _type> complex<_type> sqrt(const complex<_type> &);
template<typename _type> complex<_type> tan(const complex<_type> &);
template<typename _type> complex<_type> tanh(const complex<_type> &);



template<typename _type>
struct complex
{
    static_assert (std::is_floating_point_v<_type>, "Complex requires floating point");
    using value_type = _type;

    value_type real, imag;

    constexpr complex(const _type & _r = _type(), const _type & _i = _type());

    constexpr complex(const complex & other) = default;

    template<typename _other>
    constexpr complex(const complex<_other> & _z);

    constexpr complex<_type>& operator=(const _type &_t)
    {
        real = _t;
    }

    constexpr complex<_type> & operator+=(const _type& _t);
//    {
//        real += _t;
//        return *this;
//    }
    constexpr complex<_type> &operator-=(const _type &_t);
//    {
//        real -= _t;
//        return *this;
//    }
    constexpr complex<_type> &operator*=(const _type &_t);
    constexpr complex<_type> &operator/=(const _type & _t);


    template<typename _other>
    constexpr complex<_type>& operator= (const complex<_other> & _z);
    template<typename _other>
    constexpr complex<_type>& operator+=(const complex<_other> & _z);
    template<typename _other>
    constexpr complex<_type>& operator-=(const complex<_other> & _z);
    template<typename _other>
    constexpr complex<_type>& operator*=(const complex<_other> & _z);
    template<typename _other>
    constexpr complex<_type>& operator/=(const complex<_other> & _z);


    /// inline operators
};

template<typename _type>
constexpr inline complex<_type> operator+(const complex<_type> &_x, const complex<_type> &_y)
{
    complex<_type> _r = _x;
    _r += _y;
    return _r;
}

template struct complex<float>;
template struct complex<double>;
template struct complex<long double>;

}

#endif // COMPLEX_HH
