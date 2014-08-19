/*
 * A builder helper class for constructing non-parallel neural networks.
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

#ifndef NETWORKBUILDER_H
#define NETWORKBUILDER_H

#include <vector>
#include <memory>
#include <cstdlib>
#include "neuron.h"
#include "layer.h"
#include "network.h"

class NetworkBuilder
{
private:
  size_t layer_1_inputs;
  size_t layer_last_outputs;
  vector<size_t> sizes;
  shared_ptr<Network> network;

public:
  NetworkBuilder();
  
  void addLayerFirst(size_t number_of_neurons, size_t number_of_inputs_per_neuron,
	ActivationFunction function_type);
  void addLayer(size_t number_of_neurons, ActivationFunction function_type);
  void addLayerLast(size_t number_of_neurons, ActivationFunction function_type);
  
  shared_ptr<Network> getNetwork() const;
};

#endif // NETWORKBUILDER_H
