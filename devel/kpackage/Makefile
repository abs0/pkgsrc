# $NetBSD: Makefile,v 1.4 2016/12/04 05:17:05 ryoon Exp $

DISTNAME=	kpackage-${KF5VER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Installation and loading of additional content as packages
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kconfig/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
