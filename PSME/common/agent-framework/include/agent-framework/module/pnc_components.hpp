/*!
 * @copyright
 * Copyright (c) 2016-2017 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * @file pnc_components.hpp
 * @brief Pnc Components Interface
 * */

#pragma once



#include "agent-framework/generic/singleton.hpp"
#include "agent-framework/module/managers/generic_manager.hpp"
#include "agent-framework/module/managers/many_to_many_manager.hpp"
#include "agent-framework/module/managers/utils/manager_utils.hpp"
#include "agent-framework/module/model/model_pnc.hpp"

/*! Psme namespace */
namespace agent_framework {
namespace module {

/*!
 * @brief Class for managing chassis components and subcomponents
 * */
class PncComponents : public generic::Singleton<PncComponents> {
public:

    using SwitchManager = GenericManager<model::Switch>;
    using FabricManager = GenericManager<model::Fabric>;
    using EndpointManager = GenericManager<model::Endpoint>;
    using ZoneManager = GenericManager<model::Zone>;
    using PortManager = GenericManager<model::Port>;

    using PcieDeviceManager = GenericManager<model::PcieDevice>;
    using PcieFunctionManager = GenericManager<model::PcieFunction>;

    using ZoneEndpointManager = managers::ManyToManyManager;
    using EndpointPortManager = managers::ManyToManyManager;
    using DriveFunctionManager = managers::ManyToManyManager;
    using SystemPcieDeviceManager = managers::ManyToManyManager;

    virtual ~PncComponents();

    /*!
     * @brief Get manager for Fabrics
     * @return manager for Fabrics
     * */
    FabricManager& get_fabric_manager() {
        return m_fabric_manager;
    }

    /*!
     * @brief Get manager for Switches
     * @return manager for Switches
     * */
    SwitchManager& get_switch_manager() {
        return m_switch_manager;
    }

    /*!
     * @brief Get manager for Zones
     * @return manager for Zones
     * */
    ZoneManager& get_zone_manager() {
        return m_zone_manager;
    }

    /*!
     * Get PCIe port manager
     * @return Reference to PCIe port manager
     * */
    PortManager& get_port_manager() {
        return m_port_manager;
    }

    /*!
     * @brief Get manager for Endpoints
     * @return manager for Endpoints
     * */
    EndpointManager& get_endpoint_manager() {
        return m_endpoint_manager;
    }

    /*!
     * @brief Get manager for PcieDevices
     * @return manager for PcieDevices
     * */
    PcieDeviceManager& get_pcie_device_manager() {
        return m_pcie_device_manager;
    }

    /*!
     * @brief Get manager for PcieFunctions
     * @return manager for PcieFunctions
     * */
    PcieFunctionManager& get_pcie_function_manager() {
        return m_pcie_function_manager;
    }

    /*!
     * @brief Get manager for Zone-Endpoint mappings
     * @return manager for Zone-Endpoint mappings
     * */
    ZoneEndpointManager& get_zone_endpoint_manager() {
        return m_zone_endpoint_manager;
    }

    /*!
     * @brief Get manager for Endpoint-Port mappings
     * @return manager for Endpoint-Port mappings
     * */
    EndpointPortManager& get_endpoint_port_manager() {
        return m_endpoint_port_manager;
    }

    /*!
     * @brief Get manager for Drive-Function mappings
     * @return manager for Drive-Function mappings
     * */
    DriveFunctionManager& get_drive_function_manager() {
        return m_drive_function_manager;
    }

private:

    FabricManager m_fabric_manager{};
    SwitchManager m_switch_manager{};
    PortManager m_port_manager{};
    EndpointManager m_endpoint_manager{};
    ZoneManager m_zone_manager{};

    PcieDeviceManager m_pcie_device_manager{};
    PcieFunctionManager m_pcie_function_manager{};

    ZoneEndpointManager m_zone_endpoint_manager{};
    EndpointPortManager m_endpoint_port_manager{};
    DriveFunctionManager m_drive_function_manager{};
};

}
}
