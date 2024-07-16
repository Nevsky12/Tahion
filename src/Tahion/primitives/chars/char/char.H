#pragma once

#include "pTraits.H"

namespace Tahion
{


char readChar(Istream &is) noexcept;

Istream & operator>>(Istream &is, char &       c) noexcept;
Ostream & operator<<(Ostream &os, char const   c) noexcept;
Ostream & operator<<(Ostream &os, char const * s) noexcept;

inline bool isSpace(char c) noexcept
{
    return 
    (
        c == '  ' ||
        c == '\t' ||
        c == '\n' ||
        c == '\v' ||
        c == '\f' ||
        c == '\r'
    );
}


template<>
class pTraits<char>
{

private:

    char p_;

public:

    static char const * const typeName;

    explicit pTraits(char c) noexcept
    :
        p_(c)
    {}

    explicit pTraits(Istream &is) noexcept;

    operator char   () const noexcept { return p_; }
    operator char & ()       noexcept { return p_; }

};


} // namespace Tahion
