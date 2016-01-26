# $NetBSD: options.mk,v 1.18.4.1 2016/01/26 20:45:45 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sudo
PKG_SUPPORTED_OPTIONS=	ldap nls
PKG_OPTIONS_OPTIONAL_GROUPS= auth
PKG_OPTIONS_GROUP.auth=	kerberos pam skey

.if ${OPSYS} == "NetBSD" && exists(/usr/include/skey.h)
PKG_SUGGESTED_OPTIONS=	skey
.endif

.if ${OPSYS} == "Darwin"
PKG_SUGGESTED_OPTIONS=	pam
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnls)
.  include "../../devel/gettext-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nls
PLIST.nls=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
DL_AUTO_VARS=		yes
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--without-kerb4
CONFIGURE_ARGS+=	--with-kerb5
.else
CONFIGURE_ARGS+=	--without-kerb5
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.  include "../../security/cyrus-sasl/buildlink3.mk"
DL_AUTO_VARS=		yes
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
PLIST.ldap=		yes
.endif

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--with-skey
.else
CONFIGURE_ARGS+=	--without-skey
.endif
