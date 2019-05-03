// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hsm_client_data.h"

extern int hsm_client_x509_init(void);
extern void hsm_client_x509_deinit(void);
extern int hsm_client_tpm_init(void);
extern void hsm_client_tpm_deinit(void);

extern HSM_CLIENT_HANDLE prov_custom_hsm_create(void);
extern void prov_custom_hsm_destroy(HSM_CLIENT_HANDLE handle);
extern char* prov_custom_hsm_get_certificate(HSM_CLIENT_HANDLE handle);
extern char* prov_custom_hsm_get_key(HSM_CLIENT_HANDLE handle);
extern char* prov_custom_hsm_get_common_name(HSM_CLIENT_HANDLE handle);
extern int prov_custom_hsm_get_endorsement_key(HSM_CLIENT_HANDLE handle, unsigned char** key, size_t* key_len);
extern int prov_custom_hsm_get_storage_root_key(HSM_CLIENT_HANDLE handle, unsigned char** key, size_t* key_len);
extern int prov_custom_hsm_sign_with_identity(HSM_CLIENT_HANDLE handle, const unsigned char* data, size_t data_len, unsigned char** key, size_t* key_len);
extern int prov_custom_hsm_activate_identity_key(HSM_CLIENT_HANDLE handle, const unsigned char* key, size_t key_len);
extern char* prov_custom_hsm_symm_key(HSM_CLIENT_HANDLE handle);
extern char* prov_custom_hsm_get_registration_name(HSM_CLIENT_HANDLE handle);

extern const HSM_CLIENT_TPM_INTERFACE* hsm_client_tpm_interface(void);
extern const HSM_CLIENT_X509_INTERFACE* hsm_client_x509_interface(void);
extern const HSM_CLIENT_KEY_INTERFACE* hsm_client_key_interface(void);
