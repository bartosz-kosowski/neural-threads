/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2014  Genkaku <email>
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

#include "neuron.h"
#include <cmath>
#include <numeric>
#include <random>

const double activation_sigmoid(double const& summed) {
  // y=1/(1+e^(-x))
  return 1.0d / (1.0d + exp(-summed));
}


Neuron::Neuron(size_t number_of_inputs, ActivationFunction function_type)
  : inputs_num(number_of_inputs)
{
  weights.reserve(inputs_num + 1);
  initalize_weights();
  
  set_activation_function(function_type);
}

Neuron::Neuron(size_t number_of_inputs, ActivationFunction function_type, vector<double>& weights)
  : inputs_num(number_of_inputs)
{
  this->weights = weights;
  
  set_activation_function(function_type);
}


void Neuron::initalize_weights()
{
  //for details see: http://en.cppreference.com/w/cpp/numeric/random

  // Seed with a real random value, if available
  std::random_device rnd_dev;

  std::default_random_engine random_engine(rnd_dev());
  std::uniform_real_distribution<double> uniform_dist(-initial_weight_range, initial_weight_range);

  for (size_t windex = 0; windex <= inputs_num; ++windex) {
    weights.push_back(uniform_dist(random_engine));
  }
}

void Neuron::set_activation_function(ActivationFunction function_type)
{
  switch (function_type) {
    case ActivationFunction::SIGMOID:
      activation_function = activation_sigmoid;
      break;
  }
}

const double Neuron::summation(shared_ptr<const vector<double> > const input) {
  double summed = 0.0d;
  
  for (size_t w = 0; w < inputs_num; w++) {
    summed += weights.at(w) * input->at(w);
  }
  
  summed += bias * weights.at(inputs_num);
  return summed;
}

const double Neuron::response(shared_ptr<const vector<double> > const input) {
  return activation_function(summation(input));
}

Neuron::~Neuron()
{

}
