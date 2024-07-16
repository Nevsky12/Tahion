#pragma once

#include <cstdint>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::int16_t const i16) noexcept
{
    return word(std::to_string(int(i16)), false);
}

template<>
struct nameOp<std::int16_t>
{
    word operator()(std::int16_t const i16) noexcept
    {
        return word(std::to_string(int(i16)), false);
    }
};


Istream & operator>>(Istream &is, std::int16_t &     i16) noexcept;
Ostream & operator<<(Ostream &is, std::int16_t const i16) noexcept;


} // namespace Tahion
