# $NetBSD: Makefile,v 1.34 2016/08/04 17:03:33 ryoon Exp $
#

DISTNAME=	xmms-pulse-0.9.4
PKGNAME=	${DISTNAME:S/xmms/bmp/}
PKGREVISION=	31
CATEGORIES=	audio
MASTER_SITES=	http://0pointer.de/lennart/projects/xmms-pulse/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0pointer.de/lennart/projects/xmms-pulse/
COMMENT=	BMP output plugin for the PulseAudio sound server

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--enable-bmp
CONFIGURE_ARGS+=	--disable-xmms
CONFIGURE_ARGS+=	--disable-lynx

.include "../../audio/bmp/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
