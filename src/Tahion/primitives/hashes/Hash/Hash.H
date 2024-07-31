#pragma once

#include "Hasher.H"
#include <cstdint>


namespace Tahion
{


template<class T>
struct Hash
{
    unsigned operator()(T const &t, unsigned const seed = 0) const noexcept
    {
        return Tahion::Hasher(&t, sizeof(T), seed);
    }
};

template<>
struct Hash<std::nullptr_t>
{
    unsigned operator()(std::nullptr_t, unsigned const seed = 0) const noexcept
    {
        return seed;
    }
};

template<>
struct Hash<void *>
{
    unsigned operator()(void const * const ptr, unsigned const seed = 0) const noexcept
    {
        std::uintptr_t const addr = std::uintptr_t(ptr);
        return Tahion::Hasher(&addr, sizeof(addr), seed);
    }
};

#undef TAHION_HASH_SPECIALIZATION
#define TAHION_HASH_SPECIALIZATION(Type)                                           \
                                                                                   \
       template<>                                                                  \
       struct Hash<Type>                                                           \
       {                                                                           \
           unsigned operator()(Type const val) const noexcept                      \
           {                                                                       \
               return static_cast<unsigned>(val);                                  \
           }                                                                       \
           unsigned operator()(Type const val, unsigned const seed) const noexcept \
           {                                                                       \
               return Tahion::Hasher(&val, sizeof(Type), seed);                    \
           }                                                                       \
       }                                                                   
                
TAHION_HASH_SPECIALIZATION(bool);
TAHION_HASH_SPECIALIZATION(char);
TAHION_HASH_SPECIALIZATION(std::int32_t);
TAHION_HASH_SPECIALIZATION(std::int64_t);
TAHION_HASH_SPECIALIZATION(std::uint32_t);
#undef TAHION_HASH_SPECIALIZATION;


} // namespace Tahion
