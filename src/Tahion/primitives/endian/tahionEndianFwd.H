#pragma once

#include <cstdint>

#ifdef __BYTE_ORDER__
    #if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
        #define WM_LITTLE_ENDIAN
    #elif (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
        #define WM_BIG_ENDIAN
    #else
        #error "__BYTE_ORDER__ is not BIG or LITTLE endian"
    #endif
#endif

#if !defined(WM_BIG_ENDIAN) && !defined(WM_LITTLE_ENDIAN)
    #error "Cannot determine BIG or LITTLE endian."
    #error "Please add to compilation options"
#endif


namespace Tahion
{


class endian;


} // namespace Tahion
