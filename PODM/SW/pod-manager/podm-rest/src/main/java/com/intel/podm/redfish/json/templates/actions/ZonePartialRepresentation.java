/*
 * Copyright (c) 2016-2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.redfish.json.templates.actions;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.podm.business.services.context.Context;
import com.intel.podm.common.types.redfish.RedfishZone;
import com.intel.podm.business.services.redfish.odataid.ODataId;

import java.util.HashSet;
import java.util.Set;

import static com.intel.podm.business.services.context.ContextType.ENDPOINT;
import static com.intel.podm.business.services.context.UriToContextConverter.getContextFromUri;

public class ZonePartialRepresentation implements RedfishZone {
    private Set<Context> endpoints = new HashSet<>();

    @JsonProperty("Endpoints")
    public void setEndpoints(Set<ODataId> oDataIds) {
        if (oDataIds == null) {
            return;
        }
        oDataIds.stream()
            .map(oDataId -> getContextFromUri(oDataId.toUri(), ENDPOINT))
            .forEach(endpoints::add);
    }

    @Override
    public Set<Context> getEndpoints() {
        return endpoints;
    }
}

