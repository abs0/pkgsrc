# $NetBSD: Makefile,v 1.4 2016/09/18 17:10:28 taca Exp $
#

COMMENT=		Postfix SMTP server PCRE map module

POSTFIX_LIB=		pcre
POSTFIX_LIBDIR=		src/util
POSTFIX_LIB_DICT=	yes
POSTFIX_LIB_MKMAP=	no

.include "../../mail/postfix/Makefile.module"

CCARGS+=		-I${BUILDLINK_PREFIX.pcre}/include
AUXLIBS_MODULE=		-L${BUILDLINK_PREFIX.pcre}/lib -lpcre			\
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pcre}/lib

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
