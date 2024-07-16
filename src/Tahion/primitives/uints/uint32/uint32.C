#include "uint32.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<std::uint32_t>::typeName = "uint32";
char const * const Tahion::pTraits<std::uint32_t>::componentNames = {""};

std::uint32_t const Tahion::pTraits<std::uint32_t>::zero = 0;
std::uint32_t const Tahion::pTraits<std::uint32_t>::one  = 1;

std::uint32_t const Tahion::pTraits<std::uint32_t>::min = 0;
std::uint32_t const Tahion::pTraits<std::uint32_t>::max = UINT32_MAX;

std::uint32_t const Tahion::pTraits<std::uint32_t>::rootMin = 0;
std::uint32_t const Tahion::pTraits<std::uint32_t>::rootMax = pTraits<std::uint32_t>::max;


Tahion::pTraits<std::uint32_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}
