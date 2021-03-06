/**********************************************************************
  rng.h - Provides a function to generate random doubles between a min
          and a max value

  Copyright (C) 2016 by Patrick S. Avery

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

 ***********************************************************************/

#ifndef RNG_H
#define RNG_H

#include <random>

// C++11 way of generating random numbers in a thread-safe manner...
// Creating a new distribution each time is supposedly very fast...
static inline double getRandDouble(double min, double max)
{
  // This one may not be thread-safe. thread_local is not supported in msvc2013
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<double> distribution(min, max);
  return distribution(generator);
}

static inline int getRandInt(int min, int max)
{
  // This one may not be thread-safe. thread_local is not supported in msvc2013
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

#endif
