#pragma once

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>
#include <type_traits>
#include <span>

namespace Tahion
{

namespace Detail {};

namespace Module {};


struct identityOp
{
    template<class T>
    constexpr T&& operator()(T&& t) const noexcept
    {
        return std::forward<T>(t);
    };

    template<class T>
    constexpr T&& operator[](T&& t) const noexcept
    {
        return std::forward<T>(t);
    };
};


template<class T>
void Swap(T& a, T&b) noexcept
{
    std::swap(a, b);
}

template<class T, std::size_t N>
void Swap(T (&a)[N], T (&b)[N]) noexcept 
{
    std::swap(a, b);
}


}; // namespace Tahion

#define forAllIters(cont,it)         \
    for                              \
    (                                \
        auto it  = std::begin(cont); \
             it != std::end  (cont); \
           ++it                      \
    )

#define forAllConstIters(cont,it)     \
    for                               \
    (                                 \
        auto it  = std::cbegin(cont); \
             it != std::cend  (cont); \
           ++it                       \
    )

#define forAllReverseIters(cont,it)   \
    for                               \
    (                                 \
        auto it  = std::rbegin(cont); \
             it != std::rend  (cont); \
           ++it                       \
    )

#define forAllConstReverseIters(cont,it) \
    for                                  \
    (                                    \
        auto it  = std::crbegin(cont);   \
             it != std::crend  (cont);   \
           ++it                          \
    )


#define forAll(list,i)                           \
    for(Tahion::label i=0; i<(list).size(); ++i)      

#define forAllReverse(list,i)                       \
    for(Tahion::label i=(list).size()-1; i>=0; --i)
