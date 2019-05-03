// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include <stdio.h>
#include <stdlib.h>

#include "testrunnerswitcher.h"

#include "prov_back_compat_test_common.h"
#include "azure_prov_client/prov_transport_mqtt_client.h"

static PROV_BACK_COMPAT_HANDLE g_back_compat_handle;

BEGIN_TEST_SUITE(prov_mqtt_back_compat)

    TEST_SUITE_INITIALIZE(suite_init)
    {
        //g_back_compat_handle = back_compat_init(TEST_HTTP);
        ASSERT_IS_NOT_NULL(g_back_compat_handle, "Failure creating iothub device in hub");
    }

    TEST_SUITE_CLEANUP(suite_cleanup)
    {
        //back_compat_deinit(g_back_compat_handle);
    }

    TEST_FUNCTION_INITIALIZE(method_init)
    {
    }

    TEST_FUNCTION_CLEANUP(method_cleanup)
    {
    }

    TEST_FUNCTION(MQTT_test_telemetry_string_with_connection_string)
    {
        int result = 0;
        ASSERT_ARE_EQUAL(int, 0, result);
    }

END_TEST_SUITE(prov_mqtt_back_compat)
