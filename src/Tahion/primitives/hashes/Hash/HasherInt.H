#pragma once

#include "Hasher.H"
#include <cstdint>


namespace Tahion
{


unsigned HasherInt( std::uint32_t const * data
                  , std::size_t         length
                  , unsigned      const seed = 0
                  ) noexcept;


} // namespace Tahion
