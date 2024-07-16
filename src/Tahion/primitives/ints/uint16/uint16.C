#include "uint16.H"
#include "int32.H"
#include "IOstreams.H"

Tahion::Istream & operator>>(Istream &is, std::uint16_t &ui16) noexcept
{
    std::int32_t parsed;
    is >> parsed;

    ui16 = std::uint16_t(parsed);
    return is;
}

Tahion::Ostream & operator<<(Ostream &os, std::uint16_t const ui16) noexcept
{
    return (os << std::int32_t(ui16));
}
