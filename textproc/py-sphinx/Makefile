# $NetBSD: Makefile,v 1.36 2017/01/03 13:23:04 jperkin Exp $

DISTNAME=	Sphinx-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/Sphinx/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://sphinx.pocoo.org/
COMMENT=	Python documentation generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7:../../textproc/py-alabaster
DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.8.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-imagesize-[0-9]*:../../graphics/py-imagesize
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer-[0-9]*:../../textproc/py-snowballstemmer
DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# test dependency
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	sphinx/pycode/pgen2/token.py

USE_TOOLS+=	makeinfo
do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} run.py

post-extract:
	${RM} ${WRKSRC}/sphinx/locale/__init__.pyc

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-apidoc ${DESTDIR}${PREFIX}/bin/sphinx-apidoc${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-autogen ${DESTDIR}${PREFIX}/bin/sphinx-autogen${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-build ${DESTDIR}${PREFIX}/bin/sphinx-build${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/sphinx-quickstart ${DESTDIR}${PREFIX}/bin/sphinx-quickstart${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
