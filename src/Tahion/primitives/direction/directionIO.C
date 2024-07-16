#include "direction.H"
#include "IOstreams.H"

Tahion::direction Tahion::readDirection(Istream &is) noexcept
{
    direction d(0);
    is >> d;
    return d;
}

Tahion::Istream & Tahion::operator>>(Istream &is, direction &d) noexcept
{
    token t(is);

    if (!t.good())
    {
        FatalIOErrorInFunction(is)
            << "Bad token - could not get uint8(direction)"
            << exit(FatalIOError);
        is.setBad();
        return is;
    }

    if (t.isLabel())
    {
        d = direction(t.labelToken());
    }
    else
    {
        FatalIOErrorInFunction(is)
            << "Wrong token type - expected label (uint8(direction)), found "
            << t.info()
            << exit(FatalIOError);
        is.setBad();
        return is;
    }

    is.check(FUNCTION_NAME);
    return is;
}


Tahion::Ostream & Tahion::operator<<(Ostream      &os, direction const d) noexcept
{
    os.write(label(d));
    os.check(FUNCTION_NAME);
    return os;
}

std::ostream    & Tahion::operator<<(std::ostream &os, direction const d) noexcept
{
    os << int(d);
    return os;
}
