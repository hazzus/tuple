#ifndef TUPLE_H
#define TUPLE_H

#include <typeinfo>
#include <type_traits>
namespace my {

template<typename First, typename... Rest>
struct Tuple {
    Tuple() : first(), inside() {}
    Tuple(First first, Rest... rest): first(first), inside(rest...) {}

    template<std::size_t index, typename U, typename... V>
    friend struct getter;

    template <typename T, typename... TupleTypes>
    friend T const& get(Tuple<TupleTypes...> const& tuple);
    template <typename T, typename... TupleTypes>
    friend T & get(Tuple<TupleTypes...> & tuple);


    template <typename T, typename... TupleTypes>
    friend T const& get(Tuple<T, TupleTypes...> const& tuple);
    template <typename T, typename... TupleTypes>
    friend T & get(Tuple<T, TupleTypes...> & tuple);

private:
    First first;
    Tuple<Rest...> inside;
};

template<typename First>
struct Tuple<First> {
    Tuple() : first() {}
    Tuple(First first): first(first) {}

    template<typename T>
    friend T& get(Tuple<T> & tuple);

    template<typename T>
    friend T const& get(Tuple<T> const& tuple);
private:
    First first;
};


// getters non-const

template<typename T>
T& get(Tuple<T> & tuple) {
    return tuple.first;
}

template <typename T, typename... TupleTypes>
T& get(Tuple<T, TupleTypes...> & tuple) {
    return tuple.first;
}

template <typename T, typename... TupleTypes>
T& get(Tuple<TupleTypes...> & tuple) {
    return get<T>(tuple.inside);
}

template<std::size_t index, typename First, typename... Rest>
struct getter {
    static auto value(const Tuple<First, Rest...>* t) -> decltype(getter<index - 1, Rest...>::value(&t->inside)) {
        return getter<index - 1, Rest...>::value(&t->inside);
    }
    static auto value(Tuple<First, Rest...>* t) -> decltype(getter<index - 1, Rest...>::value(&t->inside)) {
        return getter<index - 1, Rest...>::value(&t->inside);
    }
};

template<typename First, typename... Rest>
struct getter<0, First, Rest...> {
    static First& value(Tuple<First, Rest...>* t){
        return t->first;
    }
    static First const& value(const Tuple<First, Rest...>* t) {
        return t->first;
    }
};

template<std::size_t index, typename... TupleTypes>
auto get(Tuple<TupleTypes...> & tuple) -> decltype (getter<index, TupleTypes...>::value(&tuple))& {
    return getter<index, TupleTypes...>::value(&tuple);
}

// getters const

template<typename T>
T const& get(Tuple<T> const& tuple) {
    return tuple.first;
}

template <typename T, typename... TupleTypes>
T const& get(Tuple<T, TupleTypes...> const& tuple) {
    return tuple.first;
}

template <typename T, typename... TupleTypes>
T const& get(Tuple<TupleTypes...> const& tuple) {
    return get<T>(tuple.inside);
}


template<std::size_t index, typename... TupleTypes>
auto get(Tuple<TupleTypes...> const& tuple) -> decltype (getter<index, TupleTypes...>::value(&tuple))& {
    return getter<index, TupleTypes...>::value(&tuple);
}

}

#endif // TUPLE_H