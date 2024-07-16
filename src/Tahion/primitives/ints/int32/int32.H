#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::int32_t const i32) noexcept
{
    return word(std::to_string(int(i32)), false);
}

template<>
struct nameOp<std::int32_t>
{
    word operator()(std::int32_t const i32) noexcept
    {
        return word(std::to_string(int(i32)), false);
    }
};

inline std::int32_t mag(std::int32_t const i32) noexcept
{
    return ::abs(i32);
}


std::int32_t readInt32(Istream &is) noexcept;

       std::int32_t readInt32(char        const *buf) noexcept;
inline std::int32_t readInt32(std::string const &  s) noexcept
{
    return readInt32(s.c_str()     );
}

       bool readInt32(char        const *buf, std::int32_t &i32) noexcept;
inline bool readInt32(std::string const &  s, std::int32_t &i32) noexcept
{
    return  readInt32(s.c_str(), i32);
}

inline bool read(char        const *buf, std::int32_t &i32) noexcept
{
    return readInt32(buf, i32);
}
inline bool read(std::string const &  s, std::int32_t &i32) noexcept
{
    return readInt32(s  , i32);
}


Istream & operator>>(Istream &is, std::int32_t &     i32) noexcept;
Ostream & operator<<(Ostream &is, std::int32_t const i32) noexcept;

#if (__SIZEOF_LONG__ == 4)
    Istream & operator>>(Istream &is, long &     l) noexcept;
    Ostream & operator<<(Ostream &is, long const l) noexcept;
#endif



template<>
class pTraits<std::int32_t>
{


private:

    std::int32_t p_;

public:

    using cmptType = std::int32_t;
    using  magType = std::int32_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::int32_t const zero;
    static std::int32_t const one ;

    static std::int32_t const min;
    static std::int32_t const max;

    static std::int32_t const rootMin;
    static std::int32_t const rootMax;


    explicit pTraits(std::int32_t const i32) noexcept
    :
        p_(i32)
    {}

    explicit pTraits(Istream &is         ) noexcept;


    operator std::int32_t   () const noexcept { return p_; }
    operator std::int32_t & ()       noexcept { return p_; }


};


} // namespace Tahion
