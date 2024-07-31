#pragma once

#include <cstddef>

namespace Tahion
{


unsigned Hasher( void const * const data
               , std::size_t  const len
               , unsigned     const seed = 0
               ) noexcept;


} // namespace Tahion
