# Simple-Neural-Net
A simple neural network created for my Esame di Stato

# How to build

## Using cmake

Create a new directory called "build" and run this command inside it:

``` cmake --build .. ```

and then:

``` make ```

This will create an executable named "NeuralNetC__"

## Using other compiler

This program is written in c++20, so specify this during compilation:

### gcc:

``` g++ -std=c++20 main.cpp -o NeuralNet ```
