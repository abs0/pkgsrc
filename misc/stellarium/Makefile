# $NetBSD: Makefile,v 1.84 2016/07/09 06:38:37 wiz Exp $

DISTNAME=	stellarium-0.12.4
PKGREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL
LICENSE=	gnu-gpl-v2

# XXX remove on next update
WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt perl pod2man

SUBST_CLASSES+=		mac
SUBST_MESSAGE.mac=	Disabling Mac OS X paths.
SUBST_FILES.mac=	src/core/StelFileMgr.cpp
SUBST_STAGE.mac=	pre-configure
SUBST_SED.mac=		-e 's,Q_OS_MAC,Q_XX_MAC,'

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-parameter
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-but-set-variable
.endif

# needs phonon (Qt phonon, not KDE's)
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=FALSE

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
