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

#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <memory>
#include <cstdlib>
#include "neuron.h"
#include "layer.h"

using namespace std;

class Network
{
private:
  vector<shared_ptr<Layer> > layers;

public:
  Network();
  ~Network();
  
  void addLayer(size_t number_of_neurons, size_t number_of_inputs_per_neuron,
	ActivationFunction function_type);
  shared_ptr<const vector<double> > response(shared_ptr<const vector<double> > const input) const;
};

#endif // NETWORK_H
