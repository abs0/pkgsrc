# $NetBSD: Makefile,v 1.34 2017/01/04 18:06:59 roy Exp $

# gpsd 3.11 has been released.  It has only not been updated because
# newer versions use scons.
DISTNAME=	gpsd-2.96
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/gpsd/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/gpsd
COMMENT=	GPS information daemon

LICENSE=	modified-bsd

# XXX: In theory this is not necessary.
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.96

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c99 c++
FAKE_NCURSES=	yes

CFLAGS.SunOS=	-DLOG_PERROR=0

INSTALLATION_DIRS=	sbin

TEST_TARGET=	check

.include "../../lang/python/extension.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
