/*
 * A simple artificial neuron.
 * Copyright (C) 2014  Bartosz Kosowski
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef NEURON_H
#define NEURON_H

#include <memory>		// for shared_ptr<T>
#include <vector>
#include <cstdlib>		// for size_t
#include <type_traits>		// for add_pointer for function pointer type

using namespace std;


using ActivationFunctionPointer_t = add_pointer<const double (double const&)>::type;

enum class ActivationFunction { SIGMOID };


class Neuron
{
private:
  size_t inputs_num;
  vector<double> weights;
  const double bias = 1.0d;
  const double initial_weight_range = 0.6d;
  void initalize_weights();
  
  ActivationFunctionPointer_t activation_function;
  
  const double summation(shared_ptr<const vector<double> > const input) const;
  
  void _set_weights(vector<double>& weights);
  
public:
  Neuron(size_t number_of_inputs, ActivationFunction function_type);
  Neuron(size_t number_of_inputs, ActivationFunction function_type, vector<double>& weights);
  ~Neuron();
  
  void set_activation_function(ActivationFunction function_type);
  const double response(shared_ptr<const vector<double> > const input) const;
};

#endif // NEURON_H
