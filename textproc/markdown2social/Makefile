# $NetBSD: Makefile,v 1.4 2017/01/01 14:44:00 wiz Exp $

DISTNAME=	markdown2social-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:M=/markdown2social/} \
		${MASTER_SITE_GITHUB:=jmmv/markdown2social/releases/download/${DISTNAME}/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://github.com/jmmv/markdown2social/
COMMENT=	Converts simple Markdown documents to Google+ posts
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-markdown>=2.6:../../textproc/py-markdown

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
