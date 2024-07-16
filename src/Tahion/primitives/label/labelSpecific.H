namespace Tahion
{


inline label sign(label const l) noexcept
{
    return (s >= 0) ? 1 : -1;
}

inline label pos0(label const l) noexcept
{
    return (s >= 0) ? 1 :  0;
}

inline label neg (label const l) noexcept
{
    return (s <  0) ? 1 :  0;
}

inline label neg0(label const l) noexcept
{
    return (s <= 0) ? 1 :  0;
}

inline label posPart(label const l) noexcept
{
    return (s > 0) ? s : 0;
}

inline label negPart(label const l) noexcept
{
    return (s < 0) ? s : 0;
}


} // namespace Tahion
