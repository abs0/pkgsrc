# $NetBSD: Makefile,v 1.26 2013/11/24 05:57:43 dholland Exp $

DISTNAME=	hanterm-3.1.6
PKGREVISION=	6
CATEGORIES=	x11 korean
MASTER_SITES=	http://download.kldp.net/hanterm/hanterm/3.1.6/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hanterm.kldp.net/
COMMENT=	X11R6-based xterm hacked for managing Korean languages

USE_IMAKE=	YES

SPECIAL_PERMS+=	bin/hanterm ${SETUID_ROOT_PERMS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
