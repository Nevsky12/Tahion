#include "uint64.H"

char const * const Tahion::pTraits<std::uint64_t>::typeName = "uint64";
char const * const Tahion::pTraits<std::uint64_t>::componentNames = {""};

std::uint64_t const Tahion::pTraits<std::uint64_t>::zero = 0;
std::uint64_t const Tahion::pTraits<std::uint64_t>::one  = 1;

std::uint64_t const Tahion::pTraits<std::uint64_t>::min = 0;
std::uint64_t const Tahion::pTraits<std::uint64_t>::max = UINT64_MAX;

std::uint64_t const Tahion::pTraits<std::uint64_t>::rootMin = 0;
std::uint64_t const Tahion::pTraits<std::uint64_t>::rootMax = pTraits<std::uint64_t>::max;


Tahion::pTraits<std::uint64_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}
