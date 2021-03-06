// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: markus.dreyer@gmail.com (Markus Dreyer)
//
#include <sys/time.h>
#include <iostream>
#include "fstrain/util/timer.h"

namespace fstrain { namespace util {

Timer::Timer() {
  start();
}
Timer::~Timer() {}

void Timer::start() {
  gettimeofday(&startTime, NULL);
  running = true;
}

void Timer::stop() {
  if (running) {
    gettimeofday(&stopTime, NULL);
    running = false;

    elapsedTime =
        (stopTime.tv_sec - startTime.tv_sec)*1000
        + (stopTime.tv_usec - startTime.tv_usec)/1000;
  }else{
    std::cerr << "Called stop() before start() on Timer object";
  }
}

double Timer::get_elapsed_time_millis() {
  return (double)elapsedTime;
}

double Timer::get_elapsed_time_seconds() {
  return elapsedTime / 1000.0f;
}

} } // end namespaces
