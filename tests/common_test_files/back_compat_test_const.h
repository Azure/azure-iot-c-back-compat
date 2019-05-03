// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef BACK_COMPAT_CONST_E2E_H
#define BACK_COMPAT_CONST_E2E_H

#include "iothub_device_client.h"
#include "iothub_account.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TEST_PROTOCOL_TYPE_TAG
{
    TEST_MQTT,
    TEST_MQTT_WEBSOCKETS,
    TEST_AMQP,
    TEST_AMQP_WEBSOCKETS,
    TEST_HTTP
} TEST_PROTOCOL_TYPE;

#ifdef __cplusplus
}
#endif

#endif /* BACK_COMPAT_CONST_E2E_H */
