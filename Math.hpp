//
// Created by lorenzo on 22/05/21.
//

#ifndef NEURALNETC___MATH_HPP
#define NEURALNETC___MATH_HPP

#include <cmath>
#include <type_traits>

template<typename T>
concept ArithmeticValue = std::is_arithmetic_v<T>;

template<typename T>
[[nodiscard]] constexpr auto activation_function(T value) requires ArithmeticValue<T> {
    return 1/(1 + std::exp(-(value)));
}

template<typename... ArithmeticValue>
[[nodiscard]] constexpr auto sum(ArithmeticValue... values) {
    return (values + ...);
}

template<typename T>
[[nodiscard]] constexpr auto loss_function(const T target, const T output) requires ArithmeticValue<T> {
    return std::pow(target - output, 2);
}

template<typename T>
[[nodiscard]] constexpr auto derivative_loss_function(T target, T neuron_output, T input, T exponent) requires ArithmeticValue<T> {

    auto inverse_activation_function = [=]() constexpr noexcept -> T {
        return (1 + std::exp(-(exponent)));
    };

    return 2 * (target - neuron_output) * (-1) * std::pow(inverse_activation_function(), -2) *
                 std::exp(-(exponent)) * input;
}


#endif //NEURALNETC___MATH_HPP
