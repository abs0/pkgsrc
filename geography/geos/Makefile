# $NetBSD: Makefile,v 1.26 2016/10/25 23:31:39 gdt Exp $

DISTNAME=	geos-3.5.1
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

# geos has two libraries:
#   geos_c (C), which follows normal versioning rules
#   geos (C++), which uses -release, and changes on every release

# According to the geos project (as documented in README), the C++
# interface should not be directly used and other packages should not
# link against it.  Therefore, pkgsrc will perform a recursive revbump
# when the geos_c shlib version changes, and will generally ignore
# geos shlib name changes.

# The following packages incorrectly (from the geos viewpoint) link
# directly against -lgeos and should be revbumped on every update (and
# fixed not to use -lgeos):
#   geography/gdal-lib

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://geos.refractions.net/
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
