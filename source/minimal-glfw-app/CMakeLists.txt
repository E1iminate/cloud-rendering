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

set(TARGET minimal-glfw-app)

add_executable(${TARGET} ${TARGET}.cxx)

target_include_directories(${TARGET}
    PRIVATE
        ${VULKAN_SDK_PATH}/Include
)

target_link_libraries(${TARGET}
    PRIVATE
        "${VULKAN_SDK_PATH}/Lib/vulkan-1.lib"
        glfw
)
