#pragma once

#include <cstdint>

#include "direction.H"
#include "pTraits.H"
#include "word.H"

namespace Tahion
{


inline word name(std::uint16_t const ui16) noexcept
{
    return word(std::to_string(int(ui16)), false);
}

template<>
struct nameOp<std::uint16_t>
{
    word operator()(std::uint16_t const ui16) noexcept
    {
        return word(std::to_string(int(ui16)), false);
    }
};


Istream & operator>>(Istream &is, std::uint16_t &     ui16) noexcept;
Ostream & operator<<(Ostream &is, std::uint16_t const ui16) noexcept;


} // namespace Tahion
