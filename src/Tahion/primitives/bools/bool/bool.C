#include "bool.H"
#include "Switch.H"
#include "error.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<bool>::typeName       = "bool";
char const * const Tahion::pTraits<bool>::componentNames = {""};

bool const Tahion::pTraits<bool>::zero = false;
bool const Tahion::pTraits<bool>::one  = true;


Tahion::pTraits<bool>::pTraits(Istream &is) noexcept
{
    is >> p_;
}


Tahion::Istream & operator>>(Istream &is, bool &     b) noexcept
{
    b = static_cast<bool>(Switch(is));
    return is;
}

Tahion::Ostream & operator<<(Ostream &os, bool const b) noexcept
{
    os.write(static_cast<label>(b));
    os.check(FUNCTION_NAME);
    return os;
}

bool Tahion::readBool(Istream &is) noexcept
{
    return static_cast<bool>(Switch(is));
}
