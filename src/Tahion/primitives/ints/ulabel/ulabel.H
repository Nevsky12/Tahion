#pragma once

#include "uint.H"
#include "labelFwd.H"


#define UINT_ADD_SIZE(x,s,y) x ## s ## y
#define UINT_ADD_DEF_SIZE(x,s,y) UINT_ADD_SIZE(x,s,y)
#define UINT_SIZE(x,y) UINT_ADD_DEF_SIZE(x,TWM_LABEL_SIZE,y)

namespace Tahion
{


constexpr ulabel ulabelMax = UINT_SIZE(UINT, _MAX);


inline ulabel readULabel(Istream &is) noexcept
{
    return UINT_SIZE(readUint,) (is);
}

inline ulabel readULabel(char const * const buf) noexcept
{
    return UINT_SIZE(readUint,) (buf);
}

inline ulabel readULabel(std::string const &s) noexcept
{
    return UINT_SIZE(readUint,) (s  );
}

inline bool readULabel(char const *buf, ulabel &l) noexcept
{
    return UINT_SIZE(readUint,) (buf, l);
}

inline bool readULabel(std::string const &s, ulabel &l) noexcept
{
    return UINT_SIZE(readUint,) (s  , l);
}


ulabel readRawULabel(Istream &is) noexcept;
void   readRawULabel(Istream &is, ulabel * const data, std::size_t const nElem = 1) noexcept;


ulabel pow      (ulabel const a, ulabel const b) noexcept;
ulabel factorial(ulabel const n               ) noexcept;


inline           ulabel & setComponent(ulabel &     l, direction const dir) noexcept
{
    return l;
}

inline constexpr ulabel      component(ulabel const l, direction const dir) noexcept
{
    return l;
}


} // namespace Tahion


#undef UINT_ADD_SIZE
#undef UINT_ADD_DEF_SIZE
#undef UINT_SIZE
