#include "int64.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<std::int64_t>::typeName = "int64";
char const * const Tahion::pTraits<std::int64_t>::componentNames = {""};

std::int64_t const Tahion::pTraits<std::int64_t>::zero = 0;
std::int64_t const Tahion::pTraits<std::int64_t>::one  = 1;

std::int64_t const Tahion::pTraits<std::int64_t>::min = INT64_MIN;
std::int64_t const Tahion::pTraits<std::int64_t>::max = INT64_MAX;

std::int64_t const Tahion::pTraits<std::int64_t>::rootMin = pTraits<std::int64_t>::min;
std::int64_t const Tahion::pTraits<std::int64_t>::rootMax = pTraits<std::int64_t>::max;


Tahion::pTraits<std::int64_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}
