#pragma once

#include "direction.H"
#include <type_traits>
#include <utility>
 
namespace Tahion
{


class zeroOne {};


template<class Base>
class pTraits: public Base
{

public:

    explicit pTraits(Base const &b) noexcept
    :
        Base(b)
    {}

    explicit pTraits(Istream   &is) noexcept
    : 
        Base(is)
    {}

};


template<class T, class = void>
struct isVectorSpace: std::false_type {};

template<class T>
struct isVectorSpace<T, std::void_t<decltype(T::rank)>>
:
    std::integral_constant<bool, (T::rank != 0)>
{};


template<class T, class = void>
struct pTraitsRank: std::integral_constant<Tahion::direction, 0> {};

template<class T>
struct pTraitsRank: std::integral_constant
<
    T,
    std::void_t<Tahion::direction, pTraits<T>::rank>
>
{};


template<class T, class = void>
struct pTraitsCmptType { using type = T; };

template<class T>
struct pTraitsCmptType<T, std::void_t<decltype(pTraits<T>::zero)>>
{
    using type = typename pTraits<T>::cmptType;
};


template<class T, class = void>
struct pTraitsNoComponents: std::integral_constant<Tahion::direction, 1> {};

template<class T>
struct pTraitsNoComponents
<
    T,
    std::void_t<decltype(pTraits<T>::nComponents)>
>
:
    std::integral_constant<Tahion::direction, pTraits<T>::nComponents>
{};


template<class T, class = void>
struct pTraitsHasZero: std::false_type {};

template<class T>
struct pTraitsHasZero
<
    T,
    std::void_t<decltype(pTraits<T>::zero)>
>
:
    std::true_type
{};


template<class T, class = void>
struct is_range: std::false_type {};

template<class T>
struct is_range
<
    T,
    std::void_t
    <
        decltype(std::begin(std::declval<T>())),
        decltype(std::  end(std::declval<T>()))
    >
>
:
    std::true_type
{};


} // namespace Tahion
