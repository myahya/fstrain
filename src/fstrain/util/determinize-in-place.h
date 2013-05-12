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
#ifndef FSTRAIN_UTIL_DETERMINIZE_IN_PLACE_H_
#define FSTRAIN_UTIL_DETERMINIZE_IN_PLACE_H_

#include "fst/mutable-fst.h"
#include "fst/determinize.h"

namespace fstrain { namespace util {

template <class A>
void Determinize(fst::MutableFst<A>* fst, double del = fst::kDelta) {
  *fst = fst::DeterminizeFst<A>(*fst, 
                                fst::DeterminizeFstOptions<A>(fst::CacheOptions(true, 0), del));
}

} } // end namespace fstrain::util

#endif 
