# $NetBSD: Makefile,v 1.9 2016/12/30 11:16:59 jaapb Exp $

DISTNAME=	sexplib-${VERS}
PKGNAME=	ocaml-${DISTNAME}
VERS=		113.33.03
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/sexplib/archive/}
DISTFILES=	${VERS}${EXTRACT_SUFX}
DIST_SUBDIR=	ocaml-sexplib

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-js-build-tools/buildlink3.mk"
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-type_conv/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
