# $NetBSD: Makefile,v 1.18 2017/01/09 08:07:53 ryoon Exp $

DISTNAME=	krdc-15.12.0
PKGREVISION=	5
CATEGORIES=	net
COMMENT=	KDE remote desktop client
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../net/libvncserver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
