# $NetBSD: Makefile,v 1.54 2016/09/08 15:19:19 joerg Exp $

DISTNAME=	kdebindings-${_KDE_VERSION}
PKGNAME=	kdebindings-ruby-${_KDE_VERSION}
PKGREVISION=	39
CATEGORIES=	x11
COMMENT=	Ruby bindings for the KDE integrated X11 desktop

MAKE_JOBS_SAFE=		no

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-pythondir
CONFIGURE_ENV+=		DO_NOT_COMPILE="dcopperl python kjsembed qtsharp"

RUBY_VERSIONS_ACCEPTED= 18
REPLACE_RUBY+= \
	qtruby/bin/rbqtapi \
	qtruby/bin/rbqtsh

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
