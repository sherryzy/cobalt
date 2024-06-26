// Copyright 2017 The Cobalt Authors. All Rights Reserved.
//
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

#if SB_API_VERSION < 16
#include "starboard/memory.h"

#include <windows.h>

bool SbMemoryUnmap(void* virtual_address, int64_t size_bytes) {
  // Note that SbMemoryUnmap documentation says that "This function can
  // unmap multiple contiguous regions that were mapped with separate calls
  // to SbMemoryMap()". Because of that, we cannot use MEM_FREE here.
  return VirtualFree(virtual_address, size_bytes, MEM_DECOMMIT);
}
#endif  // SB_API_VERSION < 16
