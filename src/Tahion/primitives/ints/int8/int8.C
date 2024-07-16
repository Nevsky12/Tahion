#include "int8.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<std::int8_t>::typeName       = "int8";
char const * const Tahion::pTraits<std::int8_t>::componentNames = {""};

std::int8_t const Tahion::pTraits<std::int8_t>::zero = 0;
std::int8_t const Tahion::pTraits<std::int8_t>::one  = 1;

std::int8_t const Tahion::pTraits<std::int8_t>::min = INT8_MIN;
std::int8_t const Tahion::pTraits<std::int8_t>::max = INT8_MAX;

std::int8_t const Tahion::pTraits<std::int8_t>::rootMin = INT8_MIN;
std::int8_t const Tahion::pTraits<std::int8_t>::rootMax = INT8_MAX;


Tahion::pTraits<std::int8_t>::pTraits(Istream &is) noexcept
{
    is >> p_;
}

Tahion::Istream & operator>>(Istream &is, std::int8_t &i8) noexcept
{
    token t(is);

    if (!t.good())
    {
        FatalIOErrorInFunction(is)
            << "Bad token - could not get int8"
            << exit(FatalIOError);
        is.setBad();
        return is;
    }
    
    if (t.isLabel())
    {
        i8 = std::int8_t(t.labelToken());
    }
    else
    {
        FatalIOErrorInFunction(is)
            << "Wrong token type - expected label (int8), found "
            << t.info() 
            << exit(FatalIOError);
        is.setBad();
        return is;
    }

    is.check(FUNCTION_NAME);
    return is;
}

Tahion::Ostream & operator<<(Ostream &os, std::int8_t const i8) noexcept
{
    os.write(label(i8));
    os.check(FUNCTION_NAME);
    return os;
}
