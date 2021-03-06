/*!
 * @copyright
 * Copyright (c) 2015-2017 Intel Corporation
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
 * */

#include "agent-framework/module/model/attributes/usb_device.hpp"
#include "agent-framework/module/constants/compute.hpp"
#include <json/json.h>

using namespace agent_framework::model::attribute;
using namespace agent_framework::model;

UsbDevice::UsbDevice() { }

UsbDevice::~UsbDevice() { }

Json::Value attribute::UsbDevice::to_json() const {
    Json::Value json;
    json[literals::UsbDevice::DEVICE_ID] = get_device_id();
    json[literals::UsbDevice::VENDOR_ID] = get_vendor_id();
    return json;
}

UsbDevice UsbDevice::from_json(const Json::Value& json) {
    UsbDevice usb_device;
    usb_device.set_device_id(json[literals::UsbDevice::DEVICE_ID].asString());
    usb_device.set_vendor_id(json[literals::UsbDevice::VENDOR_ID].asString());
    return usb_device;
}
