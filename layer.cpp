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

#include "layer.h"

Layer::Layer(size_t number_of_neurons, size_t number_of_inputs_per_neuron,
	ActivationFunction function_type) : neurons_num(number_of_neurons)
{
  neurons.reserve(neurons_num);
  for (size_t n = 0; n < neurons_num; ++n) {
    neurons.push_back(
      unique_ptr<Neuron>(
	new Neuron(number_of_inputs_per_neuron, function_type))
    );
  }
}

shared_ptr<const vector<double> > Layer::response(shared_ptr<const vector<double> > const input)
{
  shared_ptr<vector<double> > output(new vector<double>);
  output->reserve(neurons_num);
  
  for (shared_ptr<Neuron> neuro_ptr : neurons) {
    output->push_back(
      neuro_ptr->response(input)
    );
  }
  
  return output;
}

vector<shared_ptr<Neuron> > const& Layer::getNeurons()
{
  return neurons;
}

Layer::~Layer()
{

}
