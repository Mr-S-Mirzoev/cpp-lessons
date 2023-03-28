#include "hash.h"

#include <cstdint>
#include <type_traits>

template <class T>
concept Integral = std::is_integral<T>::value;

template <Integral T> class HashFunction<T>
{
public:
    typedef std::uint32_t value_type;

    value_type operator()(T const& v) const noexcept { return v; }
};