# $NetBSD: Makefile,v 1.2 2015/08/02 12:21:43 markd Exp $

DISTNAME=	minitoc
PKGNAME=	tex-${DISTNAME}-61
TEXLIVE_REV=	37852

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/minitoc
COMMENT=	Produce a table of contents for each chapter, part or section
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<3.0nb29
DEPENDS+=	tex-cmsd>=2010:../../fonts/tex-cmsd
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-notoccite>=2009:../../print/tex-notoccite
DEPENDS+=	tex-placeins>=2.2:../../print/tex-placeins

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
