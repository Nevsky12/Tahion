#include "Hasher.H"
#include "HasherInt.H"
#include "tahionEndianFwd.H"


#define bitRotateLeft(x, nBits) (((x) << (nBits)) | ((x) >> (32 - (nBits))))

#define bitMixer(a, b, c)                                                      \
    {                                                                          \
        a -= c; a ^= bitRotateLeft(c, 4); c += b;                              \
        b -= a; b ^= bitRotateLeft(a, 6); a += c;                              \
        c -= b; c ^= bitRotateLeft(b, 8); b += a;                              \
        a -= c; a ^= bitRotateLeft(c,16); c += b;                              \
        b -= a; b ^= bitRotateLeft(a,19); a += c;                              \
        c -= b; c ^= bitRotateLeft(b, 4); b += a;                              \
    }

#define bitMixerFinal(a, b, c)                                                 \
    {                                                                          \
        c ^= b; c -= bitRotateLeft(b, 14);                                     \
        a ^= c; a -= bitRotateLeft(c, 11);                                     \
        b ^= a; b -= bitRotateLeft(a, 25);                                     \
        c ^= b; c -= bitRotateLeft(b, 16);                                     \
        a ^= c; a -= bitRotateLeft(c, 4);                                      \
        b ^= a; b -= bitRotateLeft(a, 14);                                     \
        c ^= b; c -= bitRotateLeft(b, 24);                                     \
    }


unsigned Tahion::HasherInt( std::uint32_t const * k
                          , std::size_t         length
                          , unsigned      const seed
                          ) noexcept
{
    std::uint32_t a, b, c;

    a = b = c = 0xdeadbeef 
              + (static_cast<std::uint32_t>(length) << 2)
              + seed;

    while(length > 3)
    {
        a += k[0];
        b += k[1];
        c += k[2];
        bitMixer(a,b,c);
        length -= 3;
        k += 3;
    }

    switch(length)
    {
        case 3 : c += k[2]; [[fallthrough]];
        case 2 : b += k[1]; [[fallthrough]];
        case 1 : a += k[0]; 
            bitMixerFinal(a,b,c);
            [[fallthrough]];
        case 0 :
            break;
    }

    return c;
}

#ifdef WM_LITTLE_ENDIAN
static unsigned jenkins_hashlittle
(
    void     const * key,
    size_t           length,
    unsigned const   initval
) noexcept
{
    uint32_t a, b, c;
    union { const void *ptr; size_t i; } u; // to cast key to (size_t) happily

    // Set up the internal state
    a = b = c = 0xdeadbeef + static_cast<uint32_t>(length) + initval;

    u.ptr = key;
    if ((u.i & 0x3) == 0)
    {
        // 32-bit chunks
        const uint32_t *k = reinterpret_cast<const uint32_t*>(key);

        // all but last block: aligned reads and affect 32 bits of (a,b,c)
        while (length > 12)
        {
            a += k[0];
            b += k[1];
            c += k[2];
            bitMixer(a,b,c);
            length -= 12;
            k += 3;
        }

        // handle the last (probably partial) block byte-wise
        const uint8_t *k8 = reinterpret_cast<const uint8_t*>(k);
        switch (length)
        {
            case 12: c += k[2]; b += k[1]; a += k[0];          break;
            case 11: c += static_cast<uint32_t>(k8[10]) << 16; [[fallthrough]];
            case 10: c += static_cast<uint32_t>(k8[9])  << 8;  [[fallthrough]];
            case 9 : c += k8[8];                               [[fallthrough]];
            case 8 : b += k[1]; a += k[0];                     break;
            case 7 : b += static_cast<uint32_t>(k8[6]) << 16;  [[fallthrough]];
            case 6 : b += static_cast<uint32_t>(k8[5]) << 8;   [[fallthrough]];
            case 5 : b += k8[4];                               [[fallthrough]];
            case 4 : a += k[0];                                break;
            case 3 : a += static_cast<uint32_t>(k8[2]) << 16;  [[fallthrough]];
            case 2 : a += static_cast<uint32_t>(k8[1]) << 8;   [[fallthrough]];
            case 1 : a += k8[0];                               break;
            case 0 : return c;  // zero-length requires no mixing
        }
    }
    else if ((u.i & 0x1) == 0)
    {
        // 16-bit chunks
        const uint16_t *k = reinterpret_cast<const uint16_t*>(key);

        // all but last block: aligned reads and different mixing
        while (length > 12)
        {
            a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
            b += k[2] + (static_cast<uint32_t>(k[3]) << 16);
            c += k[4] + (static_cast<uint32_t>(k[5]) << 16);
            bitMixer(a,b,c);
            length -= 12;
            k += 6;
        }

        // handle the last (probably partial) block
        const uint8_t *k8 = reinterpret_cast<const uint8_t*>(k);
        switch (length)
        {
            case 12:
                c += k[4] + (static_cast<uint32_t>(k[5]) << 16);
                b += k[2] + (static_cast<uint32_t>(k[3]) << 16);
                a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
                break;
            case 11:
                c += static_cast<uint32_t>(k8[10]) << 16;
                [[fallthrough]];
            case 10:
                c += k[4];
                b += k[2] + (static_cast<uint32_t>(k[3]) << 16);
                a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
                break;
            case 9 :
                c += k8[8];
                [[fallthrough]];
            case 8 :
                b += k[2] + (static_cast<uint32_t>(k[3]) << 16);
                a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
                break;
            case 7 :
                b += static_cast<uint32_t>(k8[6]) << 16;
                [[fallthrough]];
            case 6 :
                b += k[2];
                a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
                break;
            case 5 :
                b += k8[4];
                [[fallthrough]];
            case 4 :
                a += k[0] + (static_cast<uint32_t>(k[1]) << 16);
                break;
            case 3 :
                a += static_cast<uint32_t>(k8[2]) << 16;
                [[fallthrough]];
            case 2 :
                a += k[0];
                break;
            case 1 :
                a += k8[0];
                break;
            case 0 : return c;     // zero-length requires no mixing
        }
    }
    else
    {
        // need to read the key one byte at a time
        const uint8_t *k = reinterpret_cast<const uint8_t*>(key);

        // all but the last block: affect some 32 bits of (a,b,c)
        while (length > 12)
        {
            a += k[0];
            a += static_cast<uint32_t>(k[1]) << 8;
            a += static_cast<uint32_t>(k[2]) << 16;
            a += static_cast<uint32_t>(k[3]) << 24;
            b += k[4];
            b += static_cast<uint32_t>(k[5]) << 8;
            b += static_cast<uint32_t>(k[6]) << 16;
            b += static_cast<uint32_t>(k[7]) << 24;
            c += k[8];
            c += static_cast<uint32_t>(k[9])  << 8;
            c += static_cast<uint32_t>(k[10]) << 16;
            c += static_cast<uint32_t>(k[11]) << 24;

            bitMixer(a,b,c);
            length -= 12;
            k += 12;
        }

        // last block: affect all 32 bits of (c)
        switch (length) // most case statements fall through
        {
            case 12: c += static_cast<uint32_t>(k[11]) << 24; [[fallthrough]];
            case 11: c += static_cast<uint32_t>(k[10]) << 16; [[fallthrough]];
            case 10: c += static_cast<uint32_t>(k[9]) << 8;   [[fallthrough]];
            case 9 : c += k[8];                               [[fallthrough]];

            case 8 : b += static_cast<uint32_t>(k[7]) << 24; [[fallthrough]];
            case 7 : b += static_cast<uint32_t>(k[6]) << 16; [[fallthrough]];
            case 6 : b += static_cast<uint32_t>(k[5]) << 8;  [[fallthrough]];
            case 5 : b += k[4];                              [[fallthrough]];

            case 4 : a += static_cast<uint32_t>(k[3]) << 24; [[fallthrough]];
            case 3 : a += static_cast<uint32_t>(k[2]) << 16; [[fallthrough]];
            case 2 : a += static_cast<uint32_t>(k[1]) << 8;  [[fallthrough]];
            case 1 : a += k[0];
                break;

            case 0 : return c;
        }
    }

    bitMixerFinal(a,b,c);
    return c;
}
#endif

#ifdef WM_BIG_ENDIAN
static unsigned jenkins_hashbig
(
    void const *   key,
    size_t         length,
    unsigned const initval
) noexcept
{
    uint32_t a, b, c;
    union { const void *ptr; size_t i; } u; // to cast key to (size_t) happily

    // Set up the internal state
    a = b = c = 0xdeadbeef + static_cast<uint32_t>(length) + initval;

    u.ptr = key;
    if ((u.i & 0x3) == 0)
    {
        // 32-bit chunks
        const uint32_t *k = reinterpret_cast<const uint32_t*>(key);

        // all but last block: aligned reads and affect 32 bits of (a,b,c)
        while (length > 12)
        {
            a += k[0];
            b += k[1];
            c += k[2];
            bitMixer(a,b,c);
            length -= 12;
            k += 3;
        }

        // handle the last (probably partial) block byte-wise
        const uint8_t *k8 = reinterpret_cast<const uint8_t*>(k);

        switch (length) // most the case statements fall through
        {
            case 12: c += k[2]; b += k[1]; a += k[0];         break;
            case 11: c += static_cast<uint32_t>(k8[10]) << 8; [[fallthrough]];
            case 10: c += static_cast<uint32_t>(k8[9]) << 16; [[fallthrough]];
            case 9 : c += static_cast<uint32_t>(k8[8]) << 24; [[fallthrough]];
            case 8 : b += k[1]; a += k[0];                    break;
            case 7 : b += static_cast<uint32_t>(k8[6]) << 8;  [[fallthrough]];
            case 6 : b += static_cast<uint32_t>(k8[5]) << 16; [[fallthrough]];
            case 5 : b += static_cast<uint32_t>(k8[4]) << 24; [[fallthrough]];
            case 4 : a += k[0];                               break;
            case 3 : a += static_cast<uint32_t>(k8[2]) << 8;  [[fallthrough]];
            case 2 : a += static_cast<uint32_t>(k8[1]) << 16; [[fallthrough]];
            case 1 : a += static_cast<uint32_t>(k8[0]) << 24; break;
            case 0 : return c;
        }
    }
    else
    {
        // need to read the key one byte at a time
        const uint8_t *k = reinterpret_cast<const uint8_t*>(key);

        // all but the last block: affect some 32 bits of (a,b,c)
        while (length > 12)
        {
            a += static_cast<uint32_t>(k[0]) << 24;
            a += static_cast<uint32_t>(k[1]) << 16;
            a += static_cast<uint32_t>(k[2]) << 8;
            a += static_cast<uint32_t>(k[3]);
            b += static_cast<uint32_t>(k[4]) << 24;
            b += static_cast<uint32_t>(k[5]) << 16;
            b += static_cast<uint32_t>(k[6]) << 8;
            b += static_cast<uint32_t>(k[7]);
            c += static_cast<uint32_t>(k[8]) << 24;
            c += static_cast<uint32_t>(k[9]) << 16;
            c += static_cast<uint32_t>(k[10]) << 8;
            c += static_cast<uint32_t>(k[11]);

            bitMixer(a,b,c);
            length -= 12;
            k += 12;
        }

        // last block: affect all 32 bits of (c)
        switch (length) // the case statements fall through
        {
            case 12: c += k[11];                             [[fallthrough]];
            case 11: c += static_cast<uint32_t>(k[10]) << 8; [[fallthrough]];
            case 10: c += static_cast<uint32_t>(k[9]) << 16; [[fallthrough]];
            case 9 : c += static_cast<uint32_t>(k[8]) << 24; [[fallthrough]];
            case 8 : b += k[7];                              [[fallthrough]];
            case 7 : b += static_cast<uint32_t>(k[6]) << 8;  [[fallthrough]];
            case 6 : b += static_cast<uint32_t>(k[5]) << 16; [[fallthrough]];
            case 5 : b += static_cast<uint32_t>(k[4]) << 24; [[fallthrough]];
            case 4 : a += k[3];                              [[fallthrough]];
            case 3 : a += static_cast<uint32_t>(k[2]) << 8;  [[fallthrough]];
            case 2 : a += static_cast<uint32_t>(k[1]) << 16; [[fallthrough]];
            case 1 : a += static_cast<uint32_t>(k[0]) << 24; [[fallthrough]];
                break;
            case 0 : return c;
        }
    }

    bitMixerFinal(a,b,c);
    return c;
}
#endif


unsigned Tahion::Hasher( void const * key
                       , std::size_t  length
                       , unsigned const initval
                       ) noexcept
{
#if defined(WM_BIG_ENDIAN)
    return jenkins_hashbig(key, length, initval);
#elif defined(WM_LITTLE_ENDIAN)
    return jenkins_hashlittle(key, length, initval);
#else
    #error "Cannot determine WM_BIG_ENDIAN or WM_LITTLE_ENDIAN."
#endif
}
