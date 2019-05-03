// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifdef __cplusplus
#include <cstdlib>
#include <cstddef>
#include <cstring>
#else
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif

#include "azure_c_shared_utility/threadapi.h"
#include "azure_c_shared_utility/shared_util_options.h"
#include "azure_c_shared_utility/tickcounter.h"
#include "azure_c_shared_utility/xlogging.h"

#include "iothub.h"
#include "prov_back_compat_test_common.h"
#include "azure_prov_client/prov_security_factory.h"

#include "prov_service_client/provisioning_service_client.h"
#include "prov_service_client/provisioning_sc_enrollment.h"

//#include "iothub_account.h"
typedef struct PROV_BACK_COMPAT_INFO_TAG
{
    TEST_PROTOCOL_TYPE protocol;
    //IOTHUB_ACCOUNT_INFO_HANDLE acct_info;
    TICK_COUNTER_HANDLE tick_cntr_handle;
    //TRANSPORT_HANDLE transport_handle;
} PROV_BACK_COMPAT_INFO;

void create_x509_enrollment_device(const char* prov_conn_string, bool use_tracing)
{
    INDIVIDUAL_ENROLLMENT_HANDLE indiv_enrollment = NULL;

    /*PROVISIONING_SERVICE_CLIENT_HANDLE prov_sc_handle = prov_sc_create_from_connection_string(prov_conn_string);
    ASSERT_IS_NOT_NULL(prov_sc_handle, "Failure creating provisioning service client");

    if (use_tracing)
    {
        prov_sc_set_trace(prov_sc_handle, TRACING_STATUS_ON);
    }

#ifdef SET_TRUSTED_CERT_IN_SAMPLES
    ASSERT_ARE_EQUAL(PROV_DEVICE_RESULT, PROV_DEVICE_RESULT_OK, prov_sc_set_certificate(prov_sc_handle, certificates), "Failure setting Trusted Cert option");
#endif // SET_TRUSTED_CERT_IN_SAMPLES

    PROV_AUTH_HANDLE auth_handle = prov_auth_create();
    ASSERT_IS_NOT_NULL(auth_handle, "Failure creating auth client");

    char* registration_id = prov_auth_get_registration_id(auth_handle);
    ASSERT_IS_NOT_NULL(registration_id, "Failure prov_auth_get_common_name");

    if (prov_sc_get_individual_enrollment(prov_sc_handle, registration_id, &indiv_enrollment) != 0)
    {
        char* x509_cert = prov_auth_get_certificate(auth_handle);
        ASSERT_IS_NOT_NULL(x509_cert, "Failure prov_auth_get_certificate");

        ATTESTATION_MECHANISM_HANDLE attest_handle = attestationMechanism_createWithX509ClientCert(x509_cert, NULL);
        ASSERT_IS_NOT_NULL(attest_handle, "Failure hsm_client_riot_get_certificate ");

        indiv_enrollment = individualEnrollment_create(registration_id, attest_handle);
        ASSERT_IS_NOT_NULL(indiv_enrollment, "Failure hsm_client_riot_get_certificate ");

        ASSERT_ARE_EQUAL(int, 0, prov_sc_create_or_update_individual_enrollment(prov_sc_handle, &indiv_enrollment), "Failure prov_sc_create_or_update_individual_enrollment");

        free(x509_cert);
    }
    free(registration_id);
    individualEnrollment_destroy(indiv_enrollment);
    prov_auth_destroy(auth_handle);
    prov_sc_destroy(prov_sc_handle);*/
}

PROV_BACK_COMPAT_HANDLE prov_back_compat_init(TEST_PROTOCOL_TYPE protocol_type)
{
    PROV_BACK_COMPAT_INFO* result;

    if (IoTHub_Init() != 0)
    {
        LogError("Failure calling IoTHub_Init");
    }
    else if ((result = (PROV_BACK_COMPAT_INFO*)malloc(sizeof(PROV_BACK_COMPAT_INFO))) == NULL)
    {
        LogError("Failure allocating back compat info");
        result = NULL;
    }
    else
    {
        // Create DPS Enrollment

    }
    return result;
}

void prov_back_compat_deinit(PROV_BACK_COMPAT_HANDLE handle)
{
    if (handle != NULL)
    {
        free(handle);
    }
}

static int register_x509_provisioning_device(PROV_DEVICE_TRANSPORT_PROVIDER_FUNCTION protocol)
{
    int result;
    SECURE_DEVICE_TYPE hsm_type = SECURE_DEVICE_TYPE_X509;
    if (prov_dev_security_init(hsm_type) != 0)
    {
        LogError("Failure calling prov_dev_security_init");
        result = __LINE__;
    }
    else
    {
        result = 0;
    }
    return result;
}