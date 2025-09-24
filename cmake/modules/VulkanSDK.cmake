##########################################################################
# Copyright 2024 Vladislav Riabov
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

set(SDK_UNPACK_DIR "${CMAKE_BINARY_DIR}/deps/vulkan")
set(SDK_ZIP "${ROOT_DIR}/deps/vulkan/vulkan-1.4.321.1.zip")

# Extract if not done already
if(NOT EXISTS "${SDK_UNPACK_DIR}/Include/vulkan/vulkan.h")
    message(STATUS "Unpacking Vulkan SDK from ${SDK_ZIP} ...")
    file(ARCHIVE_EXTRACT
            INPUT "${SDK_ZIP}"
            DESTINATION "${SDK_UNPACK_DIR}")
endif()

# Set Vulkan SDK path
set(VULKAN_SDK_PATH "${SDK_UNPACK_DIR}/1.4.321.1")
