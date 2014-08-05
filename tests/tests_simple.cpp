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

 /*
  * More info on testing:
  * https://code.google.com/p/googletest/wiki/V1_6_Primer
  * 
  */
 
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "../neuron.h"
#include <gtest/gtest.h>

using namespace std;

// Tests some trivial cases.
TEST(SingleNeuronTest, Trivial) {
  const vector<double> inputs{0.5d, 0.2d};
  vector<double> weights{1.0d, 1.0d, 0.5d};
  const size_t inputs_num = inputs.size();
  
  Neuron neuro(inputs_num, ActivationFunction::SIGMOID, weights);
  
  const double output = neuro.response(inputs);
  const double summed = inputs.at(0)*weights.at(0) + inputs.at(1)*weights.at(1) + 1.0*weights.at(2);
  const double expected_response = 1.0d / (1.0d + exp(-summed));
  
  ASSERT_NE(&neuro, nullptr);
  EXPECT_EQ(output, expected_response);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
