#pragma once

#include "bool.H"
#include "stdTahion.H"

#undef FALSE
#undef TRUE
#undef NO
#undef YES
#undef OFF
#undef ON
#undef NONE

namespace Tahion
{


class dictionary;
class token;
class word;
class Switch;


Istream & operator>>(Istream &is, Switch &     sw) noexcept;
Ostream & operator<<(Ostream &os, Switch const sw) noexcept;


class Switch
{


public:

    enum SwitchType: unsigned char
    {
        FALSE   = 0,  TRUE = 1,
        NO      = 2,  YES  = 3,
        OFF     = 4,  ON   = 5,
        NONE    = 6,  ANY  = 7,
        INVALID = 8
    };

private:

    unsigned char value_;

    static switchType parse(std::string const &s, bool const failOnError) noexcept;

public:


    Switch            (Switch const &) noexcept = default;
    Switch & operator=(Switch const &) noexcept = default;


    constexpr Switch(                     ) noexcept
    :
        value_(switchType::FALSE)
    {}

    constexpr Switch(switchType const &swt) noexcept
    :
        value_(swt             )
    {}

    constexpr Switch(bool const b         ) noexcept
    :
        value_
        (
            b ? switchType::TRUE 
              : switchType::FALSE
        )
    {}

    constexpr Switch(int  const i         ) noexcept
    :
        value_
        (
            i ? switchType::TRUE 
              : switchType::FALSE
        )
    {}


    explicit Switch(char        const *s) noexcept;
    explicit Switch(std::string const &s) noexcept;
    
    explicit Switch(float  const fl, float  const tol = 0.5f) noexcept;
    explicit Switch(double const dl, double const tol = 0.5 ) noexcept;

    explicit Switch(token const &tk) noexcept;
    explicit Switch(Istream     &is) noexcept;

    Switch
    (
        word       const &key,
        dictionary const &dict
    ) noexcept;
    
    Switch
    (
        word       const &key,
        dictionary const &dict,
        Switch     const deflt,
        bool       const warnOnly
    ) noexcept;


    static Switch getOrDefault
    (
        word       const &key,
        dictionary const &dict,
        Switch     const deflt = switchType::FALSE
    ) noexcept;

    static Switch getOrAddToDict
    (
        word       const &key,
        dictionary       &dict,
        Switch     const deflt = switchType::FALSE
    ) noexcept;


    static char const * const name(bool const b) noexcept;
    static bool contains(std::string const &str) noexcept;
    static Switch   find(std::string const &str) noexcept;
    static bool    found(std::string const &str) noexcept { return contains(str); }

    bool good() const noexcept;
    bool bad () const noexcept { return !good(); }

    switchType type() const noexcept;

    void negate() noexcept;

    char const * const c_str() const noexcept;
    std::string          str() const noexcept;

    bool readIfPresent
    (
        word       const &key,
        dictionary const &dict
    ) noexcept;


    operator bool() const noexcept
    {
        return (value_ & 0x1);
    }

    Switch & operator=(switchType const &sw) noexcept
    {
        value_ = sw;
        return *this;
    }

    Switch & operator=(bool const b) noexcept
    {
        value_ = (b ? Switch::TRUE : Switch::FALSE);
        return *this;
    }
};


} // namespace Tahion
