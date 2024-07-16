#pragma once

#include <cstdint>
#include <climits>
#include <cstdlib>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::int8_t const i8) noexcept
{
    return word(std::to_string(int(i8)), false);
}

template<>
struct nameOp<std::int8_t>
{
    word operator()(std::int8_t const i8) noexcept
    {
        return word(std::to_string(int(i8)), false);
    }
};


Istream & operator>>(Istream &is, std::int8_t &     i8) noexcept;
Ostream & operator<<(Ostream &is, std::int8_t const i8) noexcept;


template<>
class pTraits<std::int8_t>
{


private:

    std::int8_t p_;

public:

    using cmptType = std::int8_t;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static std::int8_t const zero;
    static std::int8_t const one ;

    static std::int8_t const min;
    static std::int8_t const max;

    static std::int8_t const rootMin;
    static std::int8_t const rootMax;


    explicit pTraits(std::int8_t const i8) noexcept
    :
        p_(i8)
    {}

    explicit pTraits(Istream &is         ) noexcept;


    operator std::int8_t   () const noexcept { return p_; }
    operator std::int8_t & ()       noexcept { return p_; }


};


} // namespace Tahion
