# $NetBSD: Makefile,v 1.31 2017/01/03 21:30:38 roy Exp $

DISTNAME=	frotz-2.43
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=frotz/} \
		ftp://ftp.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	seebs@plethora.net
HOMEPAGE=	http://frotz.sourceforge.net/
COMMENT=	Curses-based interpreter for Infocom-compatible games

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=	SOUND_DEFS=-DOSS_SOUND
MAKE_ENV+=	SOUND_LIB=${LIBOSSAUDIO}
MAKE_ENV+=	SOUND_DEV=${DEVOSSSOUND}
.endif

SAMPLEDIR=	${PREFIX}/share/examples/frotz
DOCDIR=		${PREFIX}/share/doc/frotz

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/frotz.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6
	${INSTALL_DATA_DIR} ${DESTDIR}${SAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/frotz.conf-big \
		${DESTDIR}${SAMPLEDIR}/frotz.conf
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL HOW_TO_PLAY \
		${DESTDIR}${DOCDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
