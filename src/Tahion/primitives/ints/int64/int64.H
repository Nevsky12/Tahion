#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::int64_t const i64) noexcept
{
    return word(std::to_string(int(i64)), false);
}

template<>
struct nameOp<std::int64_t>
{
    word operator()(std::int64_t const i64) noexcept
    {
        return word(std::to_string(int(i64)), false);
    }
};

inline std::int64_t mag(std::int64_t const i64) noexcept
{
    return ::labs(i64);
}


std::int64_t readInt32(Istream &is) noexcept;

       std::int64_t readInt32(char        const *buf) noexcept;
inline std::int64_t readInt32(std::string const &  s) noexcept
{
    return readInt32(s.c_str()     );
}

       bool readInt32(char        const *buf, std::int64_t &i64) noexcept;
inline bool readInt32(std::string const &  s, std::int64_t &i64) noexcept
{
    return  readInt32(s.c_str(), i64);
}

inline bool read(char        const *buf, std::int64_t &i64) noexcept
{
    return readInt32(buf, i64);
}
inline bool read(std::string const &  s, std::int64_t &i64) noexcept
{
    return readInt32(s  , i64);
}


Istream & operator>>(Istream &is, std::int64_t &     i64) noexcept;
Ostream & operator<<(Ostream &is, std::int64_t const i64) noexcept;

#if define(__APPLE__)
    Istream & operator>>(Istream &is, long &     l) noexcept;
    Ostream & operator<<(Ostream &is, long const l) noexcept;
#endif



template<>
class pTraits<std::int64_t>
{


private:

    std::int64_t p_;

public:

    using cmptType = std::int64_t;
    using  magType = std::int64_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::int64_t const zero;
    static std::int64_t const one ;

    static std::int64_t const min;
    static std::int64_t const max;

    static std::int64_t const rootMin;
    static std::int64_t const rootMax;


    explicit pTraits(std::int64_t const i64) noexcept
    :
        p_(i64)
    {}

    explicit pTraits(Istream &is           ) noexcept;


    operator std::int64_t   () const noexcept { return p_; }
    operator std::int64_t & ()       noexcept { return p_; }


};


} // namespace Tahion
