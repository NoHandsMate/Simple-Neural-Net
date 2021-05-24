//
// Created by lorenzo on 22/05/21.
//

#ifndef NEURALNETC___NEURON_HPP
#define NEURALNETC___NEURON_HPP


template<typename Type>
class Neuron {
public:

  constexpr explicit Neuron(Type initial_value, Type initial_weight)
        : data(initial_value), weight(initial_weight)
  {}

  [[nodiscard]] auto get_data() const noexcept {
      return data;
    }
  [[nodiscard]] auto get_weight() const noexcept {
      return weight;
    }

  void set_weight(Type new_weight) {
      weight = new_weight;
    }

private:

    Type data;
    Type weight;
};

#endif //NEURALNETC___NEURON_HPP
