#include "char.H"
#include "IOstreams.H"


char const * const Tahion::pTraits<char>::typeName = "char";

Tahion::pTraits<char>::pTraits(Istream &is) noexcept
{
    is >> p_;
}

char Tahion::readChar(Istream &is) noexcept
{
    char c;
    is.read(c);
    return c;
}

Tahion::Istream & Tahion::operator>>(Istream &is, char &     c) noexcept
{
    is.read(c);
    is.check(FUNCTION_NAME);
    return is;
}

Tahion::Ostream & Tahion::operator<<(Ostream &os, char const c) noexcept
{
    os.write(c);
    os.check(FUNCTION_NAME);
    return os;
}

Tahion::Ostream & Tahion::operator<<(Ostream &os, char const *s) noexcept
{
    os.write(s);
    os.check(FUNCTION_NAME);
    return os;
}
