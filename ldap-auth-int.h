/*
 * LDAP Authentication Helper Library, Internals
 *
 * Copyright (c) 2020 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef LDAP_AUTH_INT_H
#define LDAP_AUTH_INT_H  1

#include <ldap-auth.h>
#include <ldap.h>

enum ldap_auth_flags {
	LDAP_AUTH_LDAPS		= 1 << 0,
	LDAP_AUTH_STARTTLS	= 1 << 1,
};

struct ldap_auth {
	LDAP *ldap;
	int error;
	LDAPMessage *answer;

	int flags;

	const char *user;	/* bind DN */
	const char *password;

	const char *userdn;
	const char *role;	/* CN of group or role DN needed for auth */
	const char *roledn;	/* group or role base DN */
};

int ldap_auth_set_options_va (struct ldap_auth *o, va_list ap);
int ldap_auth_get_user (struct ldap_auth *o, const char *user,
			const char *attrs[]);

#endif  /* LDAP_AUTH_INT_H */
