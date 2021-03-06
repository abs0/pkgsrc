# $NetBSD: Makefile,v 1.18 2016/09/08 03:52:26 markd Exp $

DISTNAME=	BibTool-2.65
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/bibtool/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerd-neugebauer.de/software/TeX/BibTool.en.html
COMMENT=	Tool to manipulate BibTeX databases
LICENSE=	gnu-gpl-v1

BUILD_DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
BUILD_DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
BUILD_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
BUILD_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
BUILD_DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
BUILD_DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
BUILD_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
BUILD_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk

GNU_CONFIGURE=		yes
MAKE_FILE=	makefile
#CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/BibTcl
WRKSRC=		${WRKDIR}/${PKGBASE}
USE_TOOLS+=	perl

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	/usr/local/bin/tclsh
REPLACE.tcl.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tcl=	Tcl/bibtool.tcl
REPLACE_PERL+=		Perl/bibtool.pl

DOCDIR=			${PREFIX}/share/doc/BibTool
EXAMPLEDIR=		${PREFIX}/share/examples/BibTool

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_TARGET=	install install.man
INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLEDIR}

#pre-configure:
#	rm ${WRKSRC}/BibTcl/Makefile
#	mv ${WRKSRC}/BibTcl/Makefile.in ${WRKSRC}/BibTcl/makefile.in

post-build:
	cd ${WRKSRC}/doc && ${MAKE}
#	cd ${WRKSRC}/BibTcl && ${MAKE}

post-install:
	set -e; for i in ${WRKSRC}/doc/*.pdf; do \
		${INSTALL_DATA} "$$i" ${DESTDIR}${DOCDIR}; \
	 done
	${INSTALL_DATA} ${WRKSRC}/Perl/bibtool.pl ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Tcl/bibtool.tcl ${DESTDIR}${EXAMPLEDIR}
#	cd ${WRKSRC}/BibTcl && make install

.include "../../mk/bsd.pkg.mk"
