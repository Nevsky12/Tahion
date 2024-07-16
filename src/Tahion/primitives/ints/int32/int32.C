#include "int32.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<std::int32_t>::typeName = "int32";
char const * const Tahion::pTraits<std::int32_t>::componentNames = {""};

std::int32_t const Tahion::pTraits<std::int32_t>::zero = 0;
std::int32_t const Tahion::pTraits<std::int32_t>::one  = 1;

std::int32_t const Tahion::pTraits<std::int32_t>::min = INT32_MIN;
std::int32_t const Tahion::pTraits<std::int32_t>::max = INT32_MAX;

std::int32_t const Tahion::pTraits<std::int32_t>::rootMin = pTraits<std::int32_t>::min;
std::int32_t const Tahion::pTraits<std::int32_t>::rootMax = pTraits<std::int32_t>::max;


Tahion::pTraits<std::int32_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}
