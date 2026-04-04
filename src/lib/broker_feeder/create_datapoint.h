/********************************************************************************
* Copyright (c) 2022 Contributors to the Eclipse Foundation
*
* See the NOTICE file(s) distributed with this work for additional
* information regarding copyright ownership.
*
* This program and the accompanying materials are made available under the
* terms of the Apache License 2.0 which is available at
* http://www.apache.org/licenses/LICENSE-2.0
*
* SPDX-License-Identifier: Apache-2.0
********************************************************************************/
/**
 * @file      create_datapoint.h
 * @brief     File contains helper functions to create a Datapoint structure
 *
 */
#pragma once

#include "kuksa/val/v2/types.pb.h"

// Note: v2 Datapoint wraps a Value message. The Value oneof uses proto field
// names that are C++ keywords (float, double, bool); protobuf C++ codegen
// appends a trailing underscore to avoid conflicts: set_float_(), set_double_(),
// set_bool_(). Non-keyword fields (int32, uint32, int64, uint64, string) use
// their names directly.
//
// In v2 there is no "invalid" or "not_available" failure enum — omit the value
// field (leave Datapoint.value unset) to represent an absent/unknown value.

namespace sdv {
namespace broker_feeder {

kuksa::val::v2::Datapoint createDatapoint(bool value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_bool_(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(int32_t value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_int32(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(uint32_t value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_uint32(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(int64_t value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_int64(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(uint64_t value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_uint64(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(float value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_float_(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(double value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_double_(value);
    return datapoint;
}

kuksa::val::v2::Datapoint createDatapoint(const std::string& value) {
    kuksa::val::v2::Datapoint datapoint;
    datapoint.mutable_value()->set_string(value);
    return datapoint;
}

}  // namespace broker_feeder
}  // namespace sdv
