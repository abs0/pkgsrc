# $NetBSD: Makefile,v 1.8 2017/01/01 14:43:32 wiz Exp $

DISTNAME=	pydoctor-0.5
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pydoctor/
COMMENT=	API doc generator
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nevow>=0.9.18:../../www/py-nevow

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-twisted, py-xml via py-nevow

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
