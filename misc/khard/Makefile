# $NetBSD: Makefile,v 1.11 2016/10/31 16:29:50 wiz Exp $

DISTNAME=		khard-0.11.3
CATEGORIES=		misc net
MASTER_SITES=		${MASTER_SITE_PYPI:=k/khard/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/scheibler/khard
COMMENT=		CLI contacts application built around CardDAV
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-atomicwrites-[0-9]*:../../devel/py-atomicwrites
DEPENDS+=		${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=		${PYPKGPREFIX}-vobject>=0.9<0.9.3:../../textproc/py-vobject
DEPENDS+=		${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27 # does not support python-2.x any longer

INSTALLATION_DIRS=	share/examples/khard
REPLACE_PYTHON+=	*/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/misc/khard/khard.conf.example ${DESTDIR}${PREFIX}/share/examples/khard
	cd ${DESTDIR}${PREFIX}/bin && ${MV} khard khard-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
