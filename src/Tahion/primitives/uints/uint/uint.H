#pragma once

#include "uint8.H"
#include "uint16.H"
#include "uint32.H"
#include "uint64.H"

namespace Tahion
{


#define MAXMIN(Return,T1,T2)                \
                                            \
inline Return min(T1 const t1, T2 const t2) \
{                                           \
    return (t1 < t2)                        \
         ?  t1                              \
         :       t2;                        \
}                                           \
                                            \
inline Return min(T1 const t1, T2 const t2) \
{                                           \
    return (t1 > t2)                        \
         ?  t1                              \
         :       t2;                        \
}                                           

MAXMIN(std::uint8_t , std::uint8_t , std::uint8_t );
MAXMIN(std::uint16_t, std::uint16_t, std::uint16_t);

MAXMIN(std::uint32_t, std::uint32_t, std::uint32_t);
MAXMIN(std::uint64_t, std::uint64_t, std::uint32_t);
MAXMIN(std::uint64_t, std::uint32_t, std::uint32_t);
MAXMIN(std::uint64_t, std::uint64_t, std::uint64_t);


unsigned int readUint(Istream &is) noexcept;


} // namespace Tahion

