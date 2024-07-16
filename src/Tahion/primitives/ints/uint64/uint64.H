#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::uint64_t const ui64) noexcept
{
    return word(std::to_string(ui64), false);
}

template<>
struct nameOp<std::uint64_t>
{
    word operator()(std::uint64_t const ui64) noexcept
    {
        return word(std::to_string(ui64), false);
    }
};


std::uint64_t readUint64(Istream &is) noexcept;

       std::uint64_t readUint64(char        const *buf) noexcept;
inline std::uint64_t readUint64(std::string const &  s) noexcept
{
    return readUint64(s.c_str()     );
}

       bool readUint64(char        const *buf, std::uint64_t &ui64) noexcept;
inline bool readUint64(std::string const &  s, std::uint64_t &ui64) noexcept
{
    return  readUint64(s.c_str(), ui64);
}

inline bool read(char        const *buf, std::uint64_t &ui64) noexcept
{
    return readUint64(buf, ui64);
}
inline bool read(std::string const &  s, std::uint64_t &ui64) noexcept
{
    return readUint64(s  , ui64);
}


Istream & operator>>(Istream &is, std::uint64_t &     ui64) noexcept;
Ostream & operator<<(Ostream &is, std::uint64_t const ui64) noexcept;

#if define(__APPLE__)
    Ostream & operator<<(Ostream &is, unsigned long const l) noexcept;
#endif



template<>
class pTraits<std::uint64_t>
{


private:

    std::uint64_t p_;

public:

    using cmptType = std::uint64_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::uint64_t const zero;
    static std::uint64_t const one ;

    static std::uint64_t const min;
    static std::uint64_t const max;

    static std::uint64_t const rootMin;
    static std::uint64_t const rootMax;


    explicit pTraits(std::uint64_t const ui64) noexcept
    :
        p_(ui64)
    {}

    explicit pTraits(Istream &is           ) noexcept;


    operator std::uint64_t   () const noexcept { return p_; }
    operator std::uint64_t & ()       noexcept { return p_; }


};


} // namespace Tahion
