##########################################################################
# Copyright 2025 Vladislav Riabov
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##########################################################################

cmake_minimum_required(VERSION 3.25)
project(cloud-rendering)

set(CMAKE_CXX_STANDARD 20)

# Put all executables/DLLs in <build>/bin if no build config
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Split by build config (Debug, Release, etc.) if build configs available
foreach(OUTPUTCONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_BINARY_DIR}/bin/${OUTPUTCONFIG})
endforeach()

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
list(APPEND CMAKE_MODULE_PATH ${ROOT_DIR}/cmake/modules)

include(VulkanSDK)

add_subdirectory(deps/glfw)
add_subdirectory(source)
