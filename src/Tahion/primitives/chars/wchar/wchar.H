#pragma once

#include <cwchar>
#include <string>

namespace Tahion
{


class Istream;
class Ostream;


Ostream & operator<<(Ostream &os, wchar_t const       wc) noexcept;
Ostream & operator<<(Ostream &os, wchar_t const     * wc) noexcept;
Ostream & operator<<(Ostream &os, std::wstring const &ws) noexcept;


} // namespace Tahion
