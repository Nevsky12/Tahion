#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::uint32_t const ui32) noexcept
{
    return word(std::to_string(ui32), false);
}

template<>
struct nameOp<std::uint32_t>
{
    word operator()(std::uint32_t const ui32) noexcept
    {
        return word(std::to_string(ui32), false);
    }
};


std::uint32_t readUint32(Istream &is) noexcept;

       std::uint32_t readUint32(char        const *buf) noexcept;
inline std::uint32_t readUint32(std::string const &  s) noexcept
{
    return readUint32(s.c_str()     );
}

       bool readUint32(char        const *buf, std::uint32_t &ui32) noexcept;
inline bool readUint32(std::string const &  s, std::uint32_t &ui32) noexcept
{
    return  readUint32(s.c_str(), ui32);
}

inline bool read(char        const *buf, std::uint32_t &ui32) noexcept
{
    return readUint32(buf, ui32);
}
inline bool read(std::string const &  s, std::uint32_t &ui32) noexcept
{
    return readUint32(s  , ui32);
}


Istream & operator>>(Istream &is, std::uint32_t &     ui32) noexcept;
Ostream & operator<<(Ostream &is, std::uint32_t const ui32) noexcept;


template<>
class pTraits<std::uint32_t>
{


private:

    std::uint32_t p_;

public:

    using cmptType = std::uint32_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::uint32_t const zero;
    static std::uint32_t const one ;

    static std::uint32_t const min;
    static std::uint32_t const max;

    static std::uint32_t const rootMin;
    static std::uint32_t const rootMax;


    explicit pTraits(std::uint32_t const ui32) noexcept
    :
        p_(ui32)
    {}

    explicit pTraits(Istream &is         ) noexcept;


    operator std::uint32_t   () const noexcept { return p_; }
    operator std::uint32_t & ()       noexcept { return p_; }


};


} // namespace Tahion
