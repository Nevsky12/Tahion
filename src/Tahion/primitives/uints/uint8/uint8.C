#include "uint8.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<std::uint8_t>::typeName       = "uint8";
char const * const Tahion::pTraits<std::uint8_t>::componentNames = {""};

std::uint8_t const Tahion::pTraits<std::uint8_t>::zero = 0;
std::uint8_t const Tahion::pTraits<std::uint8_t>::one  = 1;

std::uint8_t const Tahion::pTraits<std::uint8_t>::min = 0;
std::uint8_t const Tahion::pTraits<std::uint8_t>::max = UINT8_MAX;

std::uint8_t const Tahion::pTraits<std::uint8_t>::rootMin = 0;
std::uint8_t const Tahion::pTraits<std::uint8_t>::rootMax = UINT8_MAX;


Tahion::pTraits<std::uint8_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}

std::uint8_t Tahion::readUint8(Istream &is) noexcept
{
    std::uint8_t ui8(0);
    is >>  ui8;
    return ui8;
}
