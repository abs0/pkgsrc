# $NetBSD: Makefile,v 1.62 2017/01/01 16:06:38 adam Exp $

DISTNAME=	kdewebdev-15.12.0
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	3
CATEGORIES=	www
COMMENT=	HTML editor and tools suitable for experienced web developers
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kde-runtime4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
