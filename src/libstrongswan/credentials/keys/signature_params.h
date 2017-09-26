/*
 * Copyright (C) 2017 Tobias Brunner
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup signature_params signature_params
 * @{ @ingroup keys
 */

#ifndef SIGNATURE_PARAMS_H_
#define SIGNATURE_PARAMS_H_

typedef struct rsa_pss_params_t rsa_pss_params_t;

#include <crypto/hashers/hasher.h>

/**
 * Parameters for SIGN_RSA_EMSA_PKCS1_PSS signature scheme
 */
struct rsa_pss_params_t {
	/** Hash algorithm */
	hash_algorithm_t hash;
	/** Hash for the MGF1 function */
	hash_algorithm_t mgf1_hash;
	/** Salt length, use RSA_PSS_SALT_LEN_DEFAULT for length equal to hash */
	ssize_t salt_len;
	/** Salt value, for unit tests (not all implementations support this) */
	chunk_t salt;
#define RSA_PSS_SALT_LEN_DEFAULT -1
};

/**
 * Parse the given ASN.1 algorithm identifier params
 *
 * @param asn1		ASN.1 encoded RSASSA-PSS-params
 * @param level0	current level of the ASN.1 parser
 * @param params	parsed parameters
 * @return			TRUE if successfully parsed
 */
bool rsa_pss_params_parse(chunk_t asn1, int level0, rsa_pss_params_t *params);

/**
 * Build ASN.1 algorithm identifier params
 *
 * @param params	parameters to encode
 * @param asn1		ASN.1 encoded RSASSA-PSS-params (allocated)
 * @return			TRUE if successfully built
 */
bool rsa_pss_params_build(rsa_pss_params_t *params, chunk_t *asn1);

#endif /** SIGNATURE_PARAMS_H_ @}*/