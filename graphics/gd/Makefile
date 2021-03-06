# $NetBSD: Makefile,v 1.112 2016/10/05 03:10:31 taca Exp $

DISTNAME=	libgd-2.2.3
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/libgd/gd/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libgd/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://libgd.bitbucket.org/
COMMENT=	Graphics library for the dynamic creation of images

GITHUB_PROJECT=	libgd
GITHUB_RELEASE=	gd-${PKGVERSION_NOREV}

.include "options.mk"

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--with-fontconfig=${BUILDLINK_PREFIX.fontconfig}
CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-png=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-tiff=${BUILDLINK_PREFIX.tiff}
CONFIGURE_ARGS+=	--with-webp=${BUILDLINK_PREFIX.libwebp}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
REPLACE_PERL+=		src/bdftogd
PTHREAD_AUTO_VARS=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
