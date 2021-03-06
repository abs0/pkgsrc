$NetBSD: patch-pdns_recursor__cache.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/recursor_cache.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/recursor_cache.cc
@@ -53,7 +53,7 @@ DNSResourceRecord String2DNSRR(const str
       rr.content=".";
   }
   else {
-    shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
+    boost::shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
     rr.content=regen->getZoneRepresentation();
   }
   rr.content.reserve(0);
@@ -79,7 +79,7 @@ string DNSRR2String(const DNSResourceRec
       return simpleCompress(rr.content, rr.qname);
   else {
     string ret;
-    shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
+    boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
     ret=drc->serialize(rr.qname);
   //  cerr<<"stored '"<<rr.qname<<" '"<<rr.qtype.getName()<<"' '"<<rr.content<<"' as "<<ret.size()<<" bytes"<<endl;
     return ret;
