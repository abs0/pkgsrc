$NetBSD: patch-vm__trace.c,v 1.1 2015/11/20 14:31:59 joerg Exp $

--- vm_trace.c.orig	2015-11-16 15:02:00.000000000 +0000
+++ vm_trace.c
@@ -390,7 +390,7 @@ rb_suppress_tracing(VALUE (*func)(VALUE)
     volatile int raised;
     volatile int outer_state;
     VALUE result = Qnil;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t * volatile th = GET_THREAD();
     int state;
     const int tracing = th->trace_arg ? 1 : 0;
     rb_trace_arg_t dummy_trace_arg;
