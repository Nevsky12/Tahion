#pragma once

#include "Hasher.H"
#include <cstdint>


namespace Tahion
{


unsigned HasherInt( std::uint32_t const * const data
                  , std::size_t   const length
                  , unsigned      const seed = 0
                  ) noexcept;

unsigned HasherDual( std::uint32_t const * const data
                   , std::size_t   const length
                   , unsigned & hash1
                   , unsigned & hash2
                   ) noexcept;


} // namespace Tahion
