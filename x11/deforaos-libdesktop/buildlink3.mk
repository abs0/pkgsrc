# $NetBSD: buildlink3.mk,v 1.15 2016/08/03 10:22:20 adam Exp $
#

BUILDLINK_TREE+=	deforaos-libdesktop

.if !defined(DEFORAOS_LIBDESKTOP_BUILDLINK3_MK)
DEFORAOS_LIBDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdesktop+=	deforaos-libdesktop>=0.2.1nb1
BUILDLINK_ABI_DEPENDS.deforaos-libdesktop?=	deforaos-libdesktop>=0.2.1nb2
BUILDLINK_PKGSRCDIR.deforaos-libdesktop?=	../../x11/deforaos-libdesktop

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# DEFORAOS_LIBDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdesktop
