#include "int8.H"
#include "IOstreams.H"

Tahion::Istream & operator>>(Istream &is, std::int16_t &i16) noexcept
{
    std::int32_t parsed;
    is >> parsed;

    i16 = std::int16_t(parsed);
    return is;
}

Tahion::Ostream & operator<<(Ostream &os, std::int16_t const i16) noexcept
{
    return (os << std::int32_t(i16));
}
