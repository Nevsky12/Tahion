#pragma once

#include "int.H"
#include "labelFwd.H"


#define INT_ADD_SIZE(x,s,y) x ## s ## y
#define INT_ADD_DEF_SIZE(x,s,y) INT_ADD_SIZE(x,s,y)
#define INT_SIZE(x,y) INT_ADD_DEF_SIZE(x,TWM_LABEL_SIZE,y)

namespace Tahion
{


constexpr label labelMin = INT_SIZE(INT, _MIN);
constexpr label labelMax = INT_SIZE(INT, _MAX);


inline label readLabel(Istream &is) noexcept
{
    return INT_SIZE(readInt,) (is);
}

inline label readLabel(char const * const buf) noexcept
{
    return INT_SIZE(readInt,) (buf);
}

inline label readLabel(std::string const &s) noexcept
{
    return INT_SIZE(readInt,) (s  );
}

inline bool readLabel(char const *buf, label &l) noexcept
{
    return INT_SIZE(readInt,) (buf, l);
}

inline bool readLabel(std::string const &s, label &l) noexcept
{
    return INT_SIZE(readInt,) (s  , l);
}


label readRawLabel(Istream &is) noexcept;
void  readRawLabel(Istream &is, label * const data, std::size_t const nElem = 1) noexcept;


label pow      (label const a, label const b) noexcept;
label factorial(label const n               ) noexcept;


inline           label & setComponent(label &     l, direction const dir) noexcept
{
    return l;
}

inline constexpr label      component(label const l, direction const dir) noexcept
{
    return l;
}


template<class T>
inline bool equal(T const &a, T const &b) noexcept
{
    return (a == b);
}

template<class T>
inline T clamp(T const &t, T const &lo, T const &up) noexcept
{
    return min(max(lo, t), up);
}


template<class> struct labelOp;

template<>
struct labelOp<std::int32_t>
{
    constexpr label operator()(std::int32_t const &i32) const noexcept
    {
        return i32;
    }
};
template<>
struct labelOp<std::int64_t>
{
    constexpr label operator()(std::int64_t const &i64) const noexcept
    {
        #if TWM_LABEL_SIZE == 32 
        return label(i64);
        #elif TWM_LABEL_SIZE == 64
        return       i64;
        #endif
    }
};


inline std::int32_t narrowInt32(std::int64_t const i64) noexcept
{
    return 
    (
        (i64 < INT32_MIN) 
             ? INT32_MIN :
        (i64 > INT32_MAX)
             ? INT32_MAX :
        static_cast<std::int32_t>(i64)
    );
}


} // namespace Tahion

#include "labelSpecific.H"

#undef INT_ADD_SIZE
#undef INT_ADD_DEF_SIZE
#undef INT_SIZE
