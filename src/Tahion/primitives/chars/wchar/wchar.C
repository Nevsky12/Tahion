#include "error.H"
#include "wchar.H"
#include "IOstreams.H"

Tahion::Ostream & Tahion::operator<<(Ostream &os, wchar_t const *wc) noexcept
{
    if (wc)
    {
        for(wchar_t const *it = wc; *it; ++it)
            os << *it;
    }

    return os;
}

Tahion::Ostream & Tahion::operator<<(Ostream &os, std::wstring const &ws) noexcept
{
    for(auto it = std::cbegin(ws); it != std::end(ws); ++it)
        os << *it;
    return os;
}

Tahion::Ostream & Tahion::operator<<(Ostream &os, wchar_t const wc) noexcept
{
         if (!(wc & ~0x000007F ))
    {
        os.write(char(wc));
    }
    else if (!(wc & ~0x000007FF))
    {
        os.write(char(0xC0 | ((wc >>  6) & 0x1F)));
        os.write(char(0x80 | ((wc      ) & 0x3F)));
    }
    else if (!(wc & ~0x0000FFFF))
    {
        os.write(char(0xE0 | ((wc >> 12) & 0x0F)));
        os.write(char(0x80 | ((wc >>  6) & 0x3F)));
        os.write(char(0x80 | ((wc      ) & 0x3F)));
    }
    else if (!(wc & ~0x001FFFFF))
    {
        os.write(char(0xF0 | ((wc >> 18) & 0x07)));
        os.write(char(0x80 | ((wc >> 12) & 0x3F)));
        os.write(char(0x80 | ((wc >>  6) & 0x3F)));
        os.write(char(0x80 | ((wc      ) & 0x3F)));
    }
    else if (!(wc & ~0x03FFFFFF))
    {
        os.write(char(0xF8 | ((wc >> 24) & 0x03)));
        os.write(char(0x80 | ((wc >> 18) & 0x3F)));
        os.write(char(0x80 | ((wc >> 12) & 0x3F)));
        os.write(char(0x80 | ((wc >>  6) & 0x3F)));
        os.write(char(0x80 | ((wc      ) & 0x3F)));
    }
    else if (!(wc & ~0x7FFFFFFF))
    {
        os.write(char(0xFC | ((wc >> 30) & 0x01)));
        os.write(char(0x80 | ((wc >> 24) & 0x3F)));
        os.write(char(0x80 | ((wc >> 18) & 0x3F)));
        os.write(char(0x80 | ((wc >> 12) & 0x3F)));
        os.write(char(0x80 | ((wc >>  6) & 0x3F)));
        os.write(char(0x80 | ((wc      ) & 0x3F)));
    }
    else
    {
        os.write(char(0xEF));
        os.write(char(0xBF));
        os.write(char(0xBD));
    }

    os.check(FUNCTION_NAME);
    return os;
}
