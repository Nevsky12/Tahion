#ifdef __GNUC__
    #define USE_BUILTIN_BYTESWAP
#else
    #undef USE_BUILTIN_BYTESWAP
#endif


inline bool Tahion::endian::isBig() noexcept
{
    short const testBig = 0x100;

    return *(reinterpret_cast<char const *>(&testBig));
}

inline bool Tahion::endian::isLittle() noexcept
{
    short const testLittle = 0x0001;

    return *(reinterpret_cast<char const *>(&testLittle));
}

inline std::uint32_t Tahion::endian::swap32(std::uint32_t const u) noexcept
{
#ifdef USE_BUILTIN_BYTESWAP
    return __builtin_bswap32(u);
#else
    return
    (
          (((u) & 0xff000000) >> 24)
        | (((u) & 0x00ff0000) >>  8)
        | (((u) & 0x0000ff00) <<  8)
        | (((u) & 0x000000ff) << 24)
    );
#endif
}

inline std::uint64_t Tahion::endian::swap64(std::uint64_t const u) noexcept
{
#ifdef USE_BUILTIN_BYTESWAP
    return __builtin_bswap64(u);
#else
    return
    (
          (((u) & 0xff00000000000000ull) >> 56)
        | (((u) & 0x00ff000000000000ull) >> 40)
        | (((u) & 0x0000ff0000000000ull) >> 24)
        | (((u) & 0x000000ff00000000ull) >>  8)
        | (((u) & 0x00000000ff000000ull) <<  8)
        | (((u) & 0x0000000000ff0000ull) << 24)
        | (((u) & 0x000000000000ff00ull) << 40)
        | (((u) & 0x00000000000000ffull) << 56)
    );
#endif
}

