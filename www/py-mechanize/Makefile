# $NetBSD: Makefile,v 1.17 2017/01/01 14:44:05 wiz Exp $

DISTNAME=	mechanize-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mechanize/} \
		http://wwwsearch.sourceforge.net/mechanize/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwsearch.sourceforge.net/mechanize/
COMMENT=	Stateful programmatic web browsing in Python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.2.5

do-test:
	${RUN}cd ${WRKSRC}; ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
