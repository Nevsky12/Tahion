#pragma once

#include <cstdint>

namespace Tahion
{


#if TWM_LABEL_SIZE == 32

using  label = std:: int32_t;
using ulabel = std::uint32_t;

#elif TWM_LABEL_SIZE == 64

using  label = std:: int64_t;
using ulabel = std::uint64_t;

#else
    #error "TWM_LABEL_SIZE must be set to either 32 or 64"
#endif


} // namespace Tahion
