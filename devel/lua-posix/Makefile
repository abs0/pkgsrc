# $NetBSD: Makefile,v 1.14 2016/07/09 06:38:10 wiz Exp $

DISTNAME=	luaposix-release-v31
PKGNAME=	${DISTNAME:S/lua/${LUA_PKGPREFIX}-/:S/release-v//}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/luaposix/luaposix/archive/release-v31.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/luaposix/luaposix
COMMENT=	POSIX library (including curses) for lua
LICENSE=	mit

LUA_VERSIONS_INCOMPATIBLE=	53

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c99
USE_TOOLS+=	perl:build
USE_LIBTOOL=	yes

GNU_CONFIGURE_LIBDIR=	${PREFIX}/${LUA_CDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/${LUA_DOCDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${LUA_LDIR}

INSTALLATION_DIRS+=	${LUA_LDIR} ${LUA_CDIR}

.include "../../lang/lua/luaversion.mk"

.if ${LUA_PKGPREFIX} == "lua51"
DEPENDS+=	lua51-BitOp-[0-9]*:../../devel/lua-BitOp
.endif

post-patch:
	${TOUCH} ${WRKSRC}/configure ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
