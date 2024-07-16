#pragma once

#include "pTraits.H"
#include "direction.H"

namespace Tahion
{


Istream & operator>>(Istream &is, bool &     b) noexcept;
Ostream & operator<<(Ostream &os, bool const b) noexcept;


bool readBool(Istream &is) noexcept;


template<>
class pTraits<bool>
{
    
private:
        
    bool p_;

public:

    using cmptType = bool;
    using  magType = bool;


    static constexpr direction dim         = 3;
    static constexpr direction rank        = 0;
    static constexpr direction nComponents = 1;


    static char const * const typeName;
    static char const * const componentNames[];
    
    static bool const zero;
    static bool const one ;


    explicit pTraits(bool const b) noexcept
    :
        p_(b)
    {}

    explicit pTraits(Istream &is ) noexcept;


    operator bool   () const noexcept { return p_; }
    operator bool & ()       noexcept { return p_; }


};


} // namespace Tahion
