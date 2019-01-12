#include <iostream>
#include <type_traits>
#include <tuple>
#include "tuple.h"

int main() {
    const my::Tuple<int, char> a(1, 'c');
    std::cout << my::get<0>(a) << std::endl;
    std::cout << my::get<int>(a) << std::endl;
    std::cout << my::get<char>(a) << std::endl;
    // my::get<long long>(a);  // -- compliation error
    my::Tuple<int, int> no(1, 2);
    my::get<int>(no);
    my::Tuple<int, char, long long, double> b(32, 'a', 400000, 4.32);
    my::get<double>(b) = 4.4444441;
    my::get<2>(b) = 42;
    std::cout << my::get<0>(b) << " " << my::get<1>(b) << " " << my::get<2>(b) << " " << my::get<3>(b);
    std::cout << std::endl;

    my::Tuple<int, char> c;
    c = a;
}
