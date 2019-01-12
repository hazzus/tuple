#include <iostream>
#include <type_traits>
#include <tuple>
#include <utility>
#include <vector>
#include <memory>

#include "tuple.h"


int main() {
    int aaa;
    std::tuple<int> aff(aaa);
    const my::Tuple<int, char> a(1, 'c');
    int a_m = 1;
    my::Tuple<int> x(std::move(a_m));

    std::cout << my::get<0>(a) << std::endl;
    std::cout << my::get<int>(a) << std::endl;
    std::cout << my::get<char>(a) << std::endl;
    // my::get<long long>(a);  // -- compliation error
    my::Tuple<int, char, int> no(2, 'c', 3); //
    //std::cout << "AAAA " << my::get<int>(no) << std::endl;
    my::Tuple<int, char, long long, double> b(32, 'a', 400000, 4.32);
    my::get<double>(b) = 4.4444441;
    my::get<2>(b) = 42;
    std::cout << my::get<0>(b) << " " << my::get<1>(b) << " " << my::get<2>(b) << " " << my::get<3>(b);
    std::cout << std::endl;

    my::Tuple<int, char> c;
    c = a;

    {
        /*std::vector<int> a = {1, 2, 3, 4, 5, 6};

        my::Tuple<std::vector<int>> b(a);
        for (int const& i : a) {
            std::cout << i << " ";
        }*/

        int a;
        my::Tuple<int, std::unique_ptr<int>,int > b(a, std::make_unique<int>(42), a);

    }
}
