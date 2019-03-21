// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef IOTHUBCLIENT_COMMON_E2E_H
#define IOTHUBCLIENT_COMMON_E2E_H

#include "iothub_device_client.h"
#include "iothub_account.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct E2E_TEST_OPTIONS_TAG
{
    bool set_mac_address;
    bool use_special_chars;
} E2E_TEST_OPTIONS;

typedef enum TEST_PROTOCOL_TYPE_TAG
{
    TEST_MQTT,
    TEST_MQTT_WEBSOCKETS,
    TEST_AMQP,
    TEST_AMQP_WEBSOCKETS,
    TEST_HTTP
} TEST_PROTOCOL_TYPE;

typedef enum DEVICE_CREATION_TYPE_TAG
{
    DEVICE_CREATION_CONN_STRING,
    DEVICE_CREATION_CREATE,
    DEVICE_CREATION_WITH_TRANSPORT
} DEVICE_CREATION_TYPE;

typedef enum MESSAGE_CREATION_MECHANISM_TAG
{
    TEST_MESSAGE_CREATE_BYTE_ARRAY,
    TEST_MESSAGE_CREATE_STRING
} MESSAGE_CREATION_MECHANISM;

extern E2E_TEST_OPTIONS g_e2e_test_options;
extern IOTHUB_ACCOUNT_INFO_HANDLE g_iothubAcctInfo;

extern int back_compat_init(TEST_PROTOCOL_TYPE protocol_type);
extern void back_compat_deinit(void);

extern int send_telemetry_with_device_connection_string(DEVICE_CREATION_TYPE create_type, MESSAGE_CREATION_MECHANISM msg_type, IOTHUB_CLIENT_TRANSPORT_PROVIDER protocol);

#ifdef __cplusplus
}
#endif

#endif /* IOTHUBCLIENT_COMMON_E2E_H */
