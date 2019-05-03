// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef PROV_BACK_COMPAT_COMMON_H
#define PROV_BACK_COMPAT_COMMON_H

#include "back_compat_test_const.h"
#include "iothub_device_client.h"
#include "iothub_account.h"

#include "azure_prov_client/prov_device_ll_client.h"

#ifdef __cplusplus
extern "C" {
#endif

extern IOTHUB_ACCOUNT_INFO_HANDLE g_iothubAcctInfo;

typedef struct PROV_BACK_COMPAT_INFO_TAG* PROV_BACK_COMPAT_HANDLE;

extern PROV_BACK_COMPAT_HANDLE prov_back_compat_init(TEST_PROTOCOL_TYPE protocol_type);
extern void prov_back_compat_deinit(PROV_BACK_COMPAT_HANDLE handle);

extern int register_provisioning_device(PROV_DEVICE_TRANSPORT_PROVIDER_FUNCTION protocol);

#ifdef __cplusplus
}
#endif

#endif /* PROV_BACK_COMPAT_COMMON_H */
