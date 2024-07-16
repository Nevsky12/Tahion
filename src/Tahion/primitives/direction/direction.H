#pragma once

#include <cstdint>
#include <iostream>

namespace Tahion
{


class Istream;
class Ostream;


using direction = std::uint8_t;

direction readDirection(Istream &is) noexcept;

Istream & operator>>(Istream &is, direction &     val) noexcept;
Ostream & operator<<(Ostream &os, direction const val) noexcept;

std::ostream & operator<<(std::ostream &os, direction const val) noexcept;


} // namespace Tahion
 
#include "pTraits.H"
