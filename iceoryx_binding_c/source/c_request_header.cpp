// Copyright (c) 2022 by Apex.AI Inc. All rights reserved.
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
//
// SPDX-License-Identifier: Apache-2.0

#include "iceoryx_posh/popo/rpc_header.hpp"

using namespace iox;
using namespace iox::popo;
using namespace iox::runtime;
using namespace iox::capro;
using namespace iox::cxx;

extern "C" {
#include "iceoryx_binding_c/request_header.h"
}

iox_request_header_t iox_request_header_from_payload(void* const payload)
{
    iox::cxx::Expects(payload != nullptr);

    return RequestHeader::fromPayload(payload);
}

iox_const_request_header_t iox_request_header_from_payload_const(const void* const payload)
{
    iox::cxx::Expects(payload != nullptr);

    return RequestHeader::fromPayload(payload);
}

void iox_request_header_set_sequence_id(iox_request_header_t const self, const int64_t sequenceId)
{
    iox::cxx::Expects(self != nullptr);

    self->setSequenceId(sequenceId);
}

void iox_request_header_set_fire_and_forget(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    self->setFireAndForget();
}

bool iox_request_header_is_fire_and_forget(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->isFireAndForget();
}

bool iox_request_header_is_fire_and_forget_const(iox_const_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->isFireAndForget();
}

uint8_t iox_request_header_get_rpc_header_version(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getRpcHeaderVersion();
}

uint8_t iox_request_header_get_rpc_header_version_const(iox_const_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getRpcHeaderVersion();
}

int64_t iox_request_header_get_sequence_id(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getSequenceId();
}

int64_t iox_request_header_get_sequence_id_const(iox_const_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getSequenceId();
}

void* iox_request_header_get_user_payload(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getUserPayload();
}

const void* iox_request_header_get_user_payload_const(iox_const_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return self->getUserPayload();
}

iox_chunk_header_t* iox_request_header_get_chunk_header(iox_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return reinterpret_cast<iox_chunk_header_t*>(self->getChunkHeader());
}

const iox_chunk_header_t* iox_request_header_get_chunk_header_const(iox_const_request_header_t const self)
{
    iox::cxx::Expects(self != nullptr);

    return reinterpret_cast<const iox_chunk_header_t*>(self->getChunkHeader());
}
