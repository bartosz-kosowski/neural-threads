/*
 * A simple sequential (non-parallel) neural network.
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

#include "network.h"

Network::Network()
{

}


void Network::addLayer(size_t number_of_neurons, size_t number_of_inputs_per_neuron,
	ActivationFunction function_type)
{
  layers.push_back(
    shared_ptr<Layer> (new Layer(number_of_neurons, number_of_inputs_per_neuron, function_type))
  );
}

shared_ptr<const vector<double> > Network::response(shared_ptr<const vector<double> > const input) const
{
  shared_ptr<const vector<double> > output = input;
  
  for (shared_ptr<Layer> layer : layers) {
    // previous output
    // (or the method's "input" argument in the case of the first layer)
    // becomes input for current layer.
    // Then the layer returns output, which then become input for the next layer
    // (or is returned from the method in the case of the last layer).
    output = layer->response(output);
  }
  
  return output;
}


Network::~Network()
{

}
