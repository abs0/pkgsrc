$NetBSD: patch-psutil___psutil__bsd.c,v 1.1.2.1 2016/01/11 19:12:11 bsiegert Exp $

--- psutil/_psutil_bsd.c.orig	2015-11-25 01:20:34.000000000 +0000
+++ psutil/_psutil_bsd.c	2016-01-06 12:12:07.000000000 +0000
@@ -15,6 +15,9 @@
  * - psutil.Process.memory_maps()
  */
 
+#if defined(__NetBSD__)
+#define _KMEMUSER
+#endif
 
 #include <Python.h>
 #include <assert.h>
@@ -29,7 +32,13 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #include <sys/proc.h>
+#if defined(__NetBSD__)
+#define _KERNEL
+#include <sys/file.h>
+#undef _KERNEL
+#else
 #include <sys/file.h>
+#endif
 #include <sys/socket.h>
 #include <net/route.h>
 #include <sys/socketvar.h>    // for struct xsocket
@@ -42,6 +51,7 @@
 #include <netinet/in_pcb.h>
 #include <netinet/tcp.h>
 #include <netinet/tcp_timer.h>
+#include <netinet/ip_var.h>
 #include <netinet/tcp_var.h>   // for struct xtcpcb
 #include <netinet/tcp_fsm.h>   // for TCP connection states
 #include <arpa/inet.h>         // for inet_ntop()
@@ -63,6 +73,9 @@
     #include "arch/bsd/freebsd_socks.h"
 #elif __OpenBSD__
     #include "arch/bsd/openbsd.h"
+#elif __NetBSD__
+    #include "arch/bsd/netbsd.h"
+    #include "arch/bsd/netbsd_socks.h"
 #endif
 
 #ifdef __FreeBSD__
@@ -85,6 +98,15 @@
     #include <sys/sched.h>  // for CPUSTATES & CP_*
 #endif
 
+#if defined(__NetBSD__)
+    #include <utmpx.h>
+    #include <sys/vnode.h>  // for VREG
+    #include <sys/sched.h>  // for CPUSTATES & CP_*
+#define _KERNEL
+    #include <uvm/uvm_extern.h>
+#undef _KERNEL
+#endif
+
 
 // convert a timeval struct to a double
 #define PSUTIL_TV2DOUBLE(t) ((t).tv_sec + (t).tv_usec / 1000000.0)
@@ -95,7 +117,7 @@
                            (uint32_t) (bt.frac >> 32) ) >> 32 ) / 1000000)
 #endif
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined (__NetBSD__)
     #define PSUTIL_KPT2DOUBLE(t) (t ## _sec + t ## _usec / 1000000.0)
 #endif
 
@@ -125,7 +147,7 @@
         for (idx = 0; idx < num_processes; idx++) {
 #ifdef __FreeBSD__
             py_pid = Py_BuildValue("i", proclist->ki_pid);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
             py_pid = Py_BuildValue("i", proclist->p_pid);
 #endif
             if (!py_pid)
@@ -174,14 +196,14 @@
 static PyObject *
 psutil_proc_name(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
         return NULL;
 #ifdef __FreeBSD__
     return Py_BuildValue("s", kp.ki_comm);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     return Py_BuildValue("s", kp.p_comm);
 #endif
 }
@@ -213,14 +235,14 @@
 static PyObject *
 psutil_proc_ppid(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
         return NULL;
 #ifdef __FreeBSD__
     return Py_BuildValue("l", (long)kp.ki_ppid);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     return Py_BuildValue("l", (long)kp.p_ppid);
 #endif
 }
@@ -232,14 +254,14 @@
 static PyObject *
 psutil_proc_status(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
         return NULL;
 #ifdef __FreeBSD__
     return Py_BuildValue("i", (int)kp.ki_stat);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     return Py_BuildValue("i", (int)kp.p_stat);
 #endif
 }
@@ -252,7 +274,7 @@
 static PyObject *
 psutil_proc_uids(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -262,7 +284,7 @@
                          (long)kp.ki_ruid,
                          (long)kp.ki_uid,
                          (long)kp.ki_svuid);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
                          (long)kp.p_ruid,
                          (long)kp.p_uid,
                          (long)kp.p_svuid);
@@ -277,7 +299,7 @@
 static PyObject *
 psutil_proc_gids(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -287,7 +309,7 @@
                          (long)kp.ki_rgid,
                          (long)kp.ki_groups[0],
                          (long)kp.ki_svuid);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
                          (long)kp.p_rgid,
                          (long)kp.p_groups[0],
                          (long)kp.p_svuid);
@@ -302,14 +324,14 @@
 static PyObject *
 psutil_proc_tty_nr(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
         return NULL;
 #ifdef __FreeBSD__
     return Py_BuildValue("i", kp.ki_tdev);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     return Py_BuildValue("i", kp.p_tdev);
 #endif
 }
@@ -321,7 +343,7 @@
 static PyObject *
 psutil_proc_num_ctx_switches(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -330,7 +352,7 @@
 #ifdef __FreeBSD__
                          kp.ki_rusage.ru_nvcsw,
                          kp.ki_rusage.ru_nivcsw);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
                          kp.p_uru_nvcsw,
                          kp.p_uru_nivcsw);
 #endif
@@ -344,7 +366,7 @@
 psutil_proc_cpu_times(PyObject *self, PyObject *args) {
     long pid;
     double user_t, sys_t;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -353,7 +375,7 @@
 #ifdef __FreeBSD__
     user_t = PSUTIL_TV2DOUBLE(kp.ki_rusage.ru_utime);
     sys_t = PSUTIL_TV2DOUBLE(kp.ki_rusage.ru_stime);
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     user_t = PSUTIL_KPT2DOUBLE(kp.p_uutime);
     sys_t = PSUTIL_KPT2DOUBLE(kp.p_ustime);
 #endif
@@ -389,14 +411,14 @@
 static PyObject *
 psutil_proc_create_time(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
         return NULL;
 #ifdef __FreeBSD__
     return Py_BuildValue("d", PSUTIL_TV2DOUBLE(kp.ki_start));
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
     return Py_BuildValue("d", PSUTIL_KPT2DOUBLE(kp.p_ustart));
 #endif
 }
@@ -409,7 +431,7 @@
 static PyObject *
 psutil_proc_io_counters(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -419,7 +441,7 @@
 #ifdef __FreeBSD__
                          kp.ki_rusage.ru_inblock,
                          kp.ki_rusage.ru_oublock,
-#elif __OpenBSD__
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
                          kp.p_uru_inblock,
                          kp.p_uru_oublock,
 #endif
@@ -438,7 +460,7 @@
 static PyObject *
 psutil_proc_memory_info(PyObject *self, PyObject *args) {
     long pid;
-    struct kinfo_proc kp;
+    kinfo_proc kp;
     if (! PyArg_ParseTuple(args, "l", &pid))
         return NULL;
     if (psutil_kinfo_proc(pid, &kp) == -1)
@@ -451,7 +473,7 @@
         ptoa(kp.ki_tsize),  // text
         ptoa(kp.ki_dsize),  // data
         ptoa(kp.ki_ssize));  // stack
-#elif __OpenBSD__
+#elif defined(__OpenBSD__)
         ptoa(kp.p_vm_rssize),    // rss
         // vms, this is how ps does it, see:
         // http://anoncvs.spacehopper.org/openbsd-src/tree/bin/ps/print.c#n461
@@ -459,6 +481,9 @@
         ptoa(kp.p_vm_tsize),  // text
         ptoa(kp.p_vm_dsize),  // data
         ptoa(kp.p_vm_ssize));  // stack
+#else
+/* not implemented */
+	0, 0, 0, 0, 0);
 #endif
 }
 
@@ -472,7 +497,7 @@
     size_t size = sizeof(cpu_time);
     int ret;
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     ret = sysctlbyname("kern.cp_time", &cpu_time, &size, NULL, 0);
 #elif __OpenBSD__
     int mib[] = {CTL_KERN, KERN_CPTIME};
@@ -499,14 +524,14 @@
  * utility has the same problem see:
  * https://github.com/giampaolo/psutil/issues/595
  */
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 800000 || __OpenBSD__
+#if (defined(__FreeBSD_version) && __FreeBSD_version >= 800000) || __OpenBSD__ || defined(__NetBSD__)
 static PyObject *
 psutil_proc_open_files(PyObject *self, PyObject *args) {
     long pid;
     int i, cnt;
     struct kinfo_file *freep = NULL;
     struct kinfo_file *kif;
-    struct kinfo_proc kipp;
+    kinfo_proc kipp;
     PyObject *py_retlist = PyList_New(0);
     PyObject *py_tuple = NULL;
 
@@ -530,11 +555,16 @@
                 (kif->kf_vnode_type == KF_VTYPE_VREG))
         {
             py_tuple = Py_BuildValue("(si)", kif->kf_path, kif->kf_fd);
-#else
+#elif defined(__OpenBSD__)
         if ((kif->f_type == DTYPE_VNODE) &&
                 (kif->v_type == VREG))
         {
             py_tuple = Py_BuildValue("(si)", "", kif->fd_fd);
+#elif defined(__NetBSD__)
+        if ((kif->ki_ftype == DTYPE_VNODE) &&
+                (kif->ki_vtype == VREG))
+        {
+            py_tuple = Py_BuildValue("(si)", "", kif->ki_fd);
 #endif
             if (py_tuple == NULL)
                 goto error;
@@ -567,7 +597,11 @@
     long len;
     uint64_t flags;
     char opts[200];
+#if defined(__NetBSD__)
+    struct statvfs *fs = NULL;
+#else
     struct statfs *fs = NULL;
+#endif
     PyObject *py_retlist = PyList_New(0);
     PyObject *py_tuple = NULL;
 
@@ -576,7 +610,11 @@
 
     // get the number of mount points
     Py_BEGIN_ALLOW_THREADS
+#if defined(__NetBSD__)
+    num = getvfsstat(NULL, 0, MNT_NOWAIT);
+#else
     num = getfsstat(NULL, 0, MNT_NOWAIT);
+#endif
     Py_END_ALLOW_THREADS
     if (num == -1) {
         PyErr_SetFromErrno(PyExc_OSError);
@@ -591,7 +629,11 @@
     }
 
     Py_BEGIN_ALLOW_THREADS
+#if defined(__NetBSD__)
+    num = getvfsstat(fs, len, MNT_NOWAIT);
+#else
     num = getfsstat(fs, len, MNT_NOWAIT);
+#endif
     Py_END_ALLOW_THREADS
     if (num == -1) {
         PyErr_SetFromErrno(PyExc_OSError);
@@ -601,24 +643,32 @@
     for (i = 0; i < num; i++) {
         py_tuple = NULL;
         opts[0] = 0;
+#if defined(__NetBSD__)
+        flags = fs[i].f_flag;
+#else
         flags = fs[i].f_flags;
+#endif
 
         // see sys/mount.h
         if (flags & MNT_RDONLY)
             strlcat(opts, "ro", sizeof(opts));
         else
             strlcat(opts, "rw", sizeof(opts));
-#ifdef __FreeBSD__
         if (flags & MNT_SYNCHRONOUS)
             strlcat(opts, ",sync", sizeof(opts));
         if (flags & MNT_NOEXEC)
             strlcat(opts, ",noexec", sizeof(opts));
         if (flags & MNT_NOSUID)
             strlcat(opts, ",nosuid", sizeof(opts));
-        if (flags & MNT_UNION)
-            strlcat(opts, ",union", sizeof(opts));
         if (flags & MNT_ASYNC)
             strlcat(opts, ",async", sizeof(opts));
+        if (flags & MNT_NOATIME)
+            strlcat(opts, ",noatime", sizeof(opts));
+        if (flags & MNT_SOFTDEP)
+            strlcat(opts, ",softdep", sizeof(opts));
+#ifdef __FreeBSD__
+        if (flags & MNT_UNION)
+            strlcat(opts, ",union", sizeof(opts));
         if (flags & MNT_SUIDDIR)
             strlcat(opts, ",suiddir", sizeof(opts));
         if (flags & MNT_SOFTDEP)
@@ -631,27 +681,39 @@
             strlcat(opts, ",multilabel", sizeof(opts));
         if (flags & MNT_ACLS)
             strlcat(opts, ",acls", sizeof(opts));
-        if (flags & MNT_NOATIME)
-            strlcat(opts, ",noatime", sizeof(opts));
         if (flags & MNT_NOCLUSTERR)
             strlcat(opts, ",noclusterr", sizeof(opts));
         if (flags & MNT_NOCLUSTERW)
             strlcat(opts, ",noclusterw", sizeof(opts));
         if (flags & MNT_NFS4ACLS)
             strlcat(opts, ",nfs4acls", sizeof(opts));
-#elif __OpenBSD__
-        if (flags & MNT_SYNCHRONOUS)
-            strlcat(opts, ",sync", sizeof(opts));
-        if (flags & MNT_NOEXEC)
-            strlcat(opts, ",noexec", sizeof(opts));
-        if (flags & MNT_NOSUID)
-            strlcat(opts, ",nosuid", sizeof(opts));
-        if (flags & MNT_ASYNC)
-            strlcat(opts, ",async", sizeof(opts));
-        if (flags & MNT_SOFTDEP)
-            strlcat(opts, ",softdep", sizeof(opts));
-        if (flags & MNT_NOATIME)
-            strlcat(opts, ",noatime", sizeof(opts));
+#elif __NetBSD__
+        if (flags & MNT_NODEV)
+            strlcat(opts, ",nodev", sizeof(opts));
+        if (flags & MNT_UNION)
+            strlcat(opts, ",union", sizeof(opts));
+        if (flags & MNT_NOCOREDUMP)
+            strlcat(opts, ",nocoredump", sizeof(opts));
+#ifdef MNT_RELATIME
+        if (flags & MNT_RELATIME)
+            strlcat(opts, ",relatime", sizeof(opts));
+#endif
+        if (flags & MNT_IGNORE)
+            strlcat(opts, ",ignore", sizeof(opts));
+#ifdef MNT_DISCARD
+        if (flags & MNT_DISCARD)
+            strlcat(opts, ",discard", sizeof(opts));
+#endif
+#ifdef MNT_EXTATTR
+        if (flags & MNT_EXTATTR)
+            strlcat(opts, ",extattr", sizeof(opts));
+#endif
+        if (flags & MNT_LOG)
+            strlcat(opts, ",log", sizeof(opts));
+        if (flags & MNT_SYMPERM)
+            strlcat(opts, ",symperm", sizeof(opts));
+        if (flags & MNT_NODEVMTIME)
+            strlcat(opts, ",nodevmtime", sizeof(opts));
 #endif
         py_tuple = Py_BuildValue("(ssss)",
                                  fs[i].f_mntfromname,  // device
@@ -778,7 +840,7 @@
     if (py_retlist == NULL)
         return NULL;
 
-#if __FreeBSD_version < 900000 || __OpenBSD__
+#if (defined(__FreeBSD_version) && (__FreeBSD_version < 900000)) || __OpenBSD__
     struct utmp ut;
     FILE *fp;
 
@@ -812,6 +874,7 @@
 #else
     struct utmpx *utx;
 
+    setutxent();
     while ((utx = getutxent()) != NULL) {
         if (utx->ut_type != USER_PROCESS)
             continue;
@@ -883,20 +946,21 @@
      "Return process tty (terminal) number"},
     {"proc_cwd", psutil_proc_cwd, METH_VARARGS,
      "Return process current working directory."},
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 800000 || __OpenBSD__
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800000 || __OpenBSD__ || defined(__NetBSD__)
     {"proc_num_fds", psutil_proc_num_fds, METH_VARARGS,
      "Return the number of file descriptors opened by this process"},
 #endif
-#if defined(__FreeBSD_version) && __FreeBSD_version >= 800000 || __OpenBSD__
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 800000 || __OpenBSD__ || defined(__NetBSD__)
     {"proc_open_files", psutil_proc_open_files, METH_VARARGS,
      "Return files opened by process as a list of (path, fd) tuples"},
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     {"proc_exe", psutil_proc_exe, METH_VARARGS,
      "Return process pathname executable"},
     {"proc_num_threads", psutil_proc_num_threads, METH_VARARGS,
      "Return number of threads used by process"},
+#if defined(__FreeBSD__)
     {"proc_memory_maps", psutil_proc_memory_maps, METH_VARARGS,
      "Return a list of tuples for every process's memory map"},
     {"proc_cpu_affinity_get", psutil_proc_cpu_affinity_get, METH_VARARGS,
@@ -906,6 +970,7 @@
     {"cpu_count_phys", psutil_cpu_count_phys, METH_VARARGS,
      "Return an XML string to determine the number physical CPUs."},
 #endif
+#endif
 
     // --- system-related functions
 
@@ -932,7 +997,7 @@
      "Return a Python dict of tuples for disk I/O information"},
     {"users", psutil_users, METH_VARARGS,
      "Return currently connected users as a list of tuples"},
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     {"net_connections", psutil_net_connections, METH_VARARGS,
      "Return system-wide open connections."},
 #endif
@@ -1010,6 +1075,13 @@
     PyModule_AddIntConstant(module, "SZOMB", SZOMB);  // unused
     PyModule_AddIntConstant(module, "SDEAD", SDEAD);
     PyModule_AddIntConstant(module, "SONPROC", SONPROC);
+#elif  defined(__NetBSD__)
+    PyModule_AddIntConstant(module, "SIDL", SIDL);
+    PyModule_AddIntConstant(module, "SACTIVE", SACTIVE);
+    PyModule_AddIntConstant(module, "SDYING", SDYING);
+    PyModule_AddIntConstant(module, "SSTOP", SSTOP);
+    PyModule_AddIntConstant(module, "SZOMB", SZOMB);
+    PyModule_AddIntConstant(module, "SDEAD", SDEAD);
 #endif
 
     // connection status constants
