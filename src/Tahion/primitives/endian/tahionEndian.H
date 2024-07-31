#pragma once

#include "tahionEndianFwd.H"


namespace Tahion
{


class endian
{

public:

    inline static bool isBig   () noexcept;
    inline static bool isLittle() noexcept;

    inline static std::uint32_t swap32(std::uint32 const) noexcept;
    inline static std::uint64_t swap64(std::uint64 const) noexcept;

};

#include "tahionEndianI.H"


} // namespace Tahion
