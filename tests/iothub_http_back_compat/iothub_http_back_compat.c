// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>

#include "testrunnerswitcher.h"

#include "back_compat_test_common.h"
#include "iothubtransporthttp.h"

static BACK_COMPAT_HANDLE g_back_compat_handle;

BEGIN_TEST_SUITE(iothub_http_back_compat)

    TEST_SUITE_INITIALIZE(suite_init)
    {
        g_back_compat_handle = back_compat_init(TEST_HTTP);
        ASSERT_IS_NOT_NULL(g_back_compat_handle, "Failure creating iothub device in hub");
    }

    TEST_SUITE_CLEANUP(suite_cleanup)
    {
        back_compat_deinit(g_back_compat_handle);
    }

    TEST_FUNCTION_INITIALIZE(method_init)
    {
    }

    TEST_FUNCTION_CLEANUP(method_cleanup)
    {
    }

    // COMPAT_TEST_07_IoTHubDeviceClient_LL_CreateFromConnectionString
    // COMPAT_TEST_07_IoTHubDeviceClient_LL_Destroy
    // COMPAT_TEST_07_IoTHubDeviceClient_LL_SetConnectionStatusCallback
    // COMPAT_TEST_07_IoTHubMessage_CreateFromString
    // COMPAT_TEST_07_IoTHubMessage_GetContentType
    // COMPAT_TEST_07_IoTHubMessage_GetString
    // COMPAT_TEST_07_IoTHubMessage_SetMessageId
    // COMPAT_TEST_07_IoTHubMessage_GetMessageId
    // COMPAT_TEST_07_IoTHubMessage_SetCorrelationId
    // COMPAT_TEST_07_IoTHubMessage_GetCorrelationId
    // COMPAT_TEST_07_IoTHubMessage_SetContentTypeSystemProperty
    // COMPAT_TEST_07_IoTHubMessage_GetContentTypeSystemProperty
    // COMPAT_TEST_07_IoTHubMessage_SetContentEncodingSystemProperty
    // COMPAT_TEST_07_IoTHubMessage_GetContentEncodingSystemProperty
    // COMPAT_TEST_07_IoTHubMessage_SetOutputName
    // COMPAT_TEST_07_IoTHubMessage_GetOutputName
    // COMPAT_TEST_07_IoTHubMessage_SetInputName
    // COMPAT_TEST_07_IoTHubMessage_GetInputName
    // COMPAT_TEST_07_IoTHubMessage_SetProperty
    // COMPAT_TEST_07_IoTHubDeviceClient_LL_SendEventAsync
    // COMPAT_TEST_07_IoTHubDeviceClient_LL_DoWork
    // COMPAT_TEST_07_IoTHubDeviceClient_LL_Destroy
    // COMPAT_TEST_07_HTTP_Protocol
    // COMPAT_TEST_07_IOTHUB_MESSAGE_HANDLE
    // COMPAT_TEST_07_IOTHUB_DEVICE_CLIENT_LL_HANDLE
    // COMPAT_TEST_07_IOTHUB_CLIENT_EVENT_CONFIRMATION_CALLBACK
    // COMPAT_TEST_07_TRANSPORT_PROVIDER
    TEST_FUNCTION(MQTT_test_telemetry_string_with_connection_string)
    {
        int result = send_telemetry_with_device_client(g_back_compat_handle, DEVICE_CREATION_CONN_STRING, TEST_MESSAGE_CREATE_STRING, HTTP_Protocol);
        ASSERT_ARE_EQUAL(int, 0, result);
    }

    TEST_FUNCTION(MQTT_test_telemetry_byte_array_with_create)
    {
        int result = send_telemetry_with_device_client(g_back_compat_handle, DEVICE_CREATION_CREATE, TEST_MESSAGE_CREATE_BYTE_ARRAY, HTTP_Protocol);
        ASSERT_ARE_EQUAL(int, 0, result);
    }

    TEST_FUNCTION(MQTT_test_c2d_with_create)
    {
        int result = test_c2d_with_device_client(g_back_compat_handle, DEVICE_CREATION_CREATE, HTTP_Protocol);
        ASSERT_ARE_EQUAL(int, 0, result);
    }

END_TEST_SUITE(iothub_http_back_compat)
