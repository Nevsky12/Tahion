#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::uint8_t const ui8) noexcept
{
    return word(std::to_string(int(ui8)), false);
}

template<>
struct nameOp<std::uint8_t>
{
    word operator()(std::uint8_t const ui8) noexcept
    {
        return word(std::to_string(int(ui8)), false);
    }
};


Istream & operator>>(Istream &is, std::uint8_t &     ui8) noexcept;
Ostream & operator<<(Ostream &is, std::uint8_t const ui8) noexcept;


template<>
class pTraits<std::uint8_t>
{


private:

    std::uint8_t p_;

public:

    using cmptType = std::uint8_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::uint8_t const zero;
    static std::uint8_t const one ;

    static std::uint8_t const min;
    static std::uint8_t const max;

    static std::uint8_t const rootMin;
    static std::uint8_t const rootMax;


    explicit pTraits(std::uint8_t const ui8) noexcept
    :
        p_(ui8)
    {}

    explicit pTraits(Istream &is         ) noexcept;


    operator std::uint8_t   () const noexcept { return p_; }
    operator std::uint8_t & ()       noexcept { return p_; }


};


} // namespace Tahion
