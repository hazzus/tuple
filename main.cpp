#include <iostream>
#include <vector>
#include <memory>
#include <assert.h>

#include "tuple.h"


int main() {
    {
        my::Tuple<int> a;
        static_assert(std::is_same<decltype(my::get<0>(a)), int&>::value, "Reference get fails");
        const my::Tuple<int> b;
        static_assert(std::is_same<decltype(my::get<0>(b)), int const&>::value, "Const reference get fails");
    }
    {
        my::Tuple<double> a(42.0);
        assert(my::get<0>(a) - 42 < 1e-8);
    }
    {
        my::Tuple<int> a(42);
        my::Tuple<int> b(a);
    }
}
