#include "complex.hh"

/// constructors
template<typename _type>
constexpr Terryn::complex<_type>::complex(const _type & _r, const _type & _i) :
    real(_r), imag(_i)
{

}
template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>::complex(const complex<_other> & _z) :
    real(_z.real), imag(_z.imag)
{

}

/// <_type> operators
template<typename _type>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator+=(const _type &_t)
{
    real += _t;
    return *this;
}

template<typename _type>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator-=(const _type &_t)
{
    real -= _t;
    return *this;
}

template<typename _type>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator*=(const _type &_t)
{
    real *= _t;
    imag *= _t;
    return *this;
}

template<typename _type>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator/=(const _type &_t)
{
    real /= _t;
    imag /= _t;
    return *this;
}


/// complex<_type> operators
template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator=(const Terryn::complex<_other> &_t)
{
    real = _t.real;
    imag = _t.imag;
    return *this;
}

template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator+=(const Terryn::complex<_other> &_t)
{
    real += _t.real;
    imag += _t.imag;
    return *this;
}

template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator-=(const Terryn::complex<_other> &_t)
{
    real -= _t.real;
    imag -= _t.imag;
    return *this;
}

template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator*=(const Terryn::complex<_other> &_t)
{
    const _type _tmp = real * _t.real - imag * _t.imag;
    imag = real * _t.imag + imag * _t.real;
    real = _tmp;
    return *this;
}

template<typename _type>
template<typename _other>
constexpr Terryn::complex<_type>& Terryn::complex<_type>::operator/=(const Terryn::complex<_other> &_t)
{
    const _type _tmp = real * _t.real + imag * _t.imag;
    const _type _norm = Terryn::norm(_t);
    imag = (imag * _t.real - real * _t.imag) / _norm;
    real = _tmp / _norm;
    return *this;
}


