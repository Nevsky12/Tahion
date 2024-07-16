#include "label.H"

Tahion::label Tahion::readRawLabel(Istream &is) noexcept
{
    label l(0);
    readRawLabel(is, &l, 1);
    return l;
}

Tahion::label Tahion::pow(label const a, label const b) noexcept
{
    if (b < 0)
    {
        FatalErrorInFunction
            << "Negative value in pow function is not supported! "
            << abort(FatalError);
    }

    label res = 1;
    for(label i = 0; i < b; ++i)
        res *= a;

    return res;
}

Tahion::label Tahion::factorial(label const n) noexcept
{
    static label factTable[13] =
    {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320,
        362800, 3628800, 39916800, 479001600
    };

    if (n < 0 || n > 12)
    {
        FatalErrorInFunction
            << "For factorial n must be in [0, 13)! "
            << abort(FatalError);
    }

    return factTable[n];
}
