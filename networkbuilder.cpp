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

#include "networkbuilder.h"

NetworkBuilder::NetworkBuilder() : network(shared_ptr<Network>(new Network()))
{
}

void NetworkBuilder::addLayerFirst(size_t number_of_neurons, size_t number_of_inputs_per_neuron,
	ActivationFunction function_type)
{
  sizes.push_back(number_of_neurons);
  network->addLayer(number_of_neurons, number_of_inputs_per_neuron, function_type);
}

void NetworkBuilder::addLayer(size_t number_of_neurons, ActivationFunction function_type)
{
  network->addLayer(number_of_neurons, sizes.back(), function_type);
  sizes.push_back(number_of_neurons);
}

void NetworkBuilder::addLayerLast(size_t number_of_neurons, ActivationFunction function_type)
{
  network->addLayer(number_of_neurons, sizes.back(), function_type);
}

  
shared_ptr<Network> NetworkBuilder::getNetwork() const 
{
  return network;
}
