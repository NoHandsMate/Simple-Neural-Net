#include <iostream>

#include "Neuron.hpp"
#include "Math.hpp"
#include <array>
#include <string>

int main()
{

    // Create the input layer
    std::array<Neuron<long double>, 2> input_layer = {
            Neuron<long double>(0.05, 0.15),
            Neuron<long double>(0.10, 0.20)
    };


    constexpr long double target = 0.6; // The "Expected Value"

    long double neuron_output = 0.0;
	
	bool first_time = true;
	
	long long int iterations = 0;

    for(; iterations < 2000000; ++iterations) {

        neuron_output = activation_function(sum(input_layer[0].get_data() * input_layer[0].get_weight(),
                                                     input_layer[1].get_data() * input_layer[1].get_weight()));

        auto exponent_helper = sum(input_layer[0].get_data() * input_layer[0].get_weight(),
                                   input_layer[1].get_data() * input_layer[1].get_weight());

		auto error = loss_function(target, neuron_output);

		if(first_time) {

			std::string response = "";
			std::cout << "NEURON OUTPUT: " << neuron_output << '\n';
			std::cout << "ERROR: " << error << '\n';
			std::cout << "START THE TRAINING? ";
			std::cin >> response;
			std::cout << '\n';
			first_time = false;
		
		} else {
			std::cout << "ERROR: " << error << '\r';
		}
		

		if(error <= 0.0000001) {
			break;
		}

        auto partial = derivative_loss_function(target, neuron_output,
                                                input_layer[0].get_data(),
                                                exponent_helper);

        auto new_weight_1 = input_layer[0].get_weight() - partial * 0.5;

        auto partial_2 = derivative_loss_function(target, neuron_output,
                                                  input_layer[1].get_data(),
                                                  exponent_helper);

        auto new_weight_2 = input_layer[1].get_weight() - partial_2 * 0.5;

        input_layer[0].set_weight(new_weight_1);
        input_layer[1].set_weight(new_weight_2);
	

    }
	
	auto iter = 1000000;
    std::cout << '\n';
    std::cout << "NEURON OUTPUT: " << neuron_output << '\n';
    std::cout << "EXPECTED OUTPUT: " << target << '\n';
	std::cout << "ITERATIONS: " << iterations << '\n'; 
    return 0;
}
