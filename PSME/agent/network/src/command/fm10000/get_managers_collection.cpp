/*!
 * @brief Implementation of GetManagersCollection command.
 *
 * File contains all implementations of methods for GetManagersCollection command.
 *
 * @copyright Copyright (c) 2016-2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Files}
 * @file get_managers_collection.cpp
 */

#include "agent-framework/module/common_components.hpp"
#include "agent-framework/command-ref/registry.hpp"
#include "agent-framework/command-ref/network_commands.hpp"



using namespace agent_framework::command_ref;
using namespace agent_framework::module;
using namespace agent_framework::model;

namespace {
void get_managers_collection(const GetManagersCollection::Request&,
                             GetManagersCollection::Response& response) {
    auto common_components = CommonComponents::get_instance();
    auto& manager = common_components->get_module_manager();
    for (const auto& uuid : manager.get_keys()) {
        response.add_entry(attribute::ManagerEntry(uuid));
    }
    log_debug(GET_LOGGER("fm10000"), "Getting managers collection is successfully finished.");
}
}

REGISTER_COMMAND(GetManagersCollection, ::get_managers_collection);
