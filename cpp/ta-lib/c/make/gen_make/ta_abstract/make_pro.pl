#! /usr/bin/perl

# This file generates the "ta_abstract.pro"
#
# The output simply goes to stdout.

print "# Do not modify this file. It is automatically\n";
print "# generated by make_pro.pl\n";
print "\n";

print "TEMPLATE  = lib\n";
print "CONFIG   -= qt\n";
print "CONFIG   += staticlib\n";
print "\n";
print "# Identify the temp dir\n";
print "cmd:OBJECTS_DIR = ../../../../../temp/cmd\n";
print "cmr:OBJECTS_DIR = ../../../../../temp/cmr\n";
print "cmp:OBJECTS_DIR = ../../../../../temp/cmp\n";
print "csd:OBJECTS_DIR = ../../../../../temp/csd\n";
print "csr:OBJECTS_DIR = ../../../../../temp/csr\n";
print "csp:OBJECTS_DIR = ../../../../../temp/csp\n";
print "cdr:OBJECTS_DIR = ../../../../../temp/cdr\n";
print "cdd:OBJECTS_DIR = ../../../../../temp/cdd\n";
print "\n";
print "# Identify the target\n";
print "LIBTARGET = ta_abstract\n";
print "cmd:TARGET = ta_abstract_cmd\n";
print "cmr:TARGET = ta_abstract_cmr\n";
print "cmp:TARGET = ta_abstract_cmp\n";
print "csd:TARGET = ta_abstract_csd\n";
print "csr:TARGET = ta_abstract_csr\n";
print "csp:TARGET = ta_abstract_csp\n";
print "cdr:TARGET = ta_abstract_cdr\n";
print "cdd:TARGET = ta_abstract_cdd\n";
print "\n";
print "# Output info\n";
print "DESTDIR     = ../../../../../lib\n";
print "\n";
print "# Files to process\n";
print "SOURCES	= ../../../../../src/ta_abstract/ta_abstract.c \\ \n";
print "          ../../../../../src/ta_abstract/ta_def_ui.c \\ \n";
print "          ../../../../../src/ta_abstract/ta_func_api.c \\ \n";
print "          ../../../../../src/ta_abstract/ta_group_idx.c \\ \n";
print "          ../../../../../src/ta_abstract/frames/ta_frame.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_a.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_b.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_c.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_d.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_e.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_f.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_g.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_h.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_i.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_j.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_k.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_l.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_m.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_n.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_o.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_p.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_q.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_r.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_s.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_t.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_u.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_v.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_w.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_x.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_y.c \\ \n";
print "          ../../../../../src/ta_abstract/tables/table_z.c";

# Generate the list of functions.

print " \n";

print "# Compiler Options\n";
print "INCLUDEPATH = ../../../../../src/ta_common \\ \n";
print "              ../../../../../src/ta_abstract \\ \n";
print "              ../../../../../src/ta_abstract/tables \\ \n";
print "              ../../../../../src/ta_abstract/frames \\ \n";
print "              ../../../../../include\n";
print "\n";
print "# debug/release dependent options.\n";
print "debug:DEFINES   *= TA_DEBUG\n";
print "debug:DEFINES   *= _DEBUG\n";
print "DEFINES        += TA_SINGLE_THREAD\n";
print "thread:DEFINES -= TA_SINGLE_THREAD\n";
print "\n";
print "# Platform dependent options.\n";
print "win32:DEFINES         *= WIN32\n";
print "win32-msvc:DEFINES    *= _MBCS _LIB\n";
print "freebsd-g++:LIBS      -= -ldl\n";
print "freebsd-g++:INCLUDEPATH += /usr/local/include\n";
print "\n";
print "cmd:TEMP_CLEAN_ALL = ../../../../../temp/cmd/*.pch\n";
print "cmr:TEMP_CLEAN_ALL = ../../../../../temp/cmr/*.pch\n";
print "cmp:TEMP_CLEAN_ALL = ../../../../../temp/cmp/*.pch\n";
print "csd:TEMP_CLEAN_ALL = ../../../../../temp/csd/*.pch\n";
print "csr:TEMP_CLEAN_ALL = ../../../../../temp/csr/*.pch\n";
print "csp:TEMP_CLEAN_ALL = ../../../../../temp/csp/*.pch\n";
print "cdr:TEMP_CLEAN_ALL = ../../../../../temp/cdr/*.pch\n";
print "cdd:TEMP_CLEAN_ALL = ../../../../../temp/cdd/*.pch\n";
print "\n";
print "cmd:TEMP_CLEAN_ALL2 = ../../../../../temp/cmd/*.idb\n";
print "cmr:TEMP_CLEAN_ALL2 = ../../../../../temp/cmr/*.idb\n";
print "cmp:TEMP_CLEAN_ALL2 = ../../../../../temp/cmp/*.idb\n";
print "csd:TEMP_CLEAN_ALL2 = ../../../../../temp/csd/*.idb\n";
print "csr:TEMP_CLEAN_ALL2 = ../../../../../temp/csr/*.idb\n";
print "csp:TEMP_CLEAN_ALL2 = ../../../../../temp/csp/*.idb\n";
print "cdr:TEMP_CLEAN_ALL2 = ../../../../../temp/cdr/*.idb\n";
print "cdd:TEMP_CLEAN_ALL2 = ../../../../../temp/cdd/*.idb\n";
print "\n";
print "cmd:TEMP_CLEAN_ALL3 = ../../../../../temp/cmd/\$\$LIBTARGET/*.pch\n";
print "cmr:TEMP_CLEAN_ALL3 = ../../../../../temp/cmr/\$\$LIBTARGET/*.pch\n";
print "cmp:TEMP_CLEAN_ALL3 = ../../../../../temp/cmp/\$\$LIBTARGET/*.pch\n";
print "csd:TEMP_CLEAN_ALL3 = ../../../../../temp/csd/\$\$LIBTARGET/*.pch\n";
print "csr:TEMP_CLEAN_ALL3 = ../../../../../temp/csr/\$\$LIBTARGET/*.pch\n";
print "csp:TEMP_CLEAN_ALL3 = ../../../../../temp/csp/\$\$LIBTARGET/*.pch\n";
print "cdr:TEMP_CLEAN_ALL3 = ../../../../../temp/cdr/\$\$LIBTARGET/*.pch\n";
print "cdd:TEMP_CLEAN_ALL3 = ../../../../../temp/cdd/\$\$LIBTARGET/*.pch\n";
print "\n";
print "cmd:TEMP_CLEAN_ALL4 = ../../../../../temp/cmd/\$\$LIBTARGET/*.idb\n";
print "cmr:TEMP_CLEAN_ALL4 = ../../../../../temp/cmr/\$\$LIBTARGET/*.idb\n";
print "cmp:TEMP_CLEAN_ALL4 = ../../../../../temp/cmp/\$\$LIBTARGET/*.idb\n";
print "csd:TEMP_CLEAN_ALL4 = ../../../../../temp/csd/\$\$LIBTARGET/*.idb\n";
print "csr:TEMP_CLEAN_ALL4 = ../../../../../temp/csr/\$\$LIBTARGET/*.idb\n";
print "csp:TEMP_CLEAN_ALL4 = ../../../../../temp/csp/\$\$LIBTARGET/*.idb\n";
print "cdr:TEMP_CLEAN_ALL4 = ../../../../../temp/cdr/\$\$LIBTARGET/*.idb\n";
print "cdd:TEMP_CLEAN_ALL4 = ../../../../../temp/cdd/\$\$LIBTARGET/*.idb\n";
print "\n";
print "cmd:TEMP_CLEAN_ALL5 = ../../../../../temp/cmd/\$\$LIBTARGET/*.obj\n";
print "cmr:TEMP_CLEAN_ALL5 = ../../../../../temp/cmr/\$\$LIBTARGET/*.obj\n";
print "cmp:TEMP_CLEAN_ALL5 = ../../../../../temp/cmp/\$\$LIBTARGET/*.obj\n";
print "csd:TEMP_CLEAN_ALL5 = ../../../../../temp/csd/\$\$LIBTARGET/*.obj\n";
print "csr:TEMP_CLEAN_ALL5 = ../../../../../temp/csr/\$\$LIBTARGET/*.obj\n";
print "csp:TEMP_CLEAN_ALL5 = ../../../../../temp/csp/\$\$LIBTARGET/*.obj\n";
print "cdr:TEMP_CLEAN_ALL5 = ../../../../../temp/cdr/\$\$LIBTARGET/*.obj\n";
print "cdd:TEMP_CLEAN_ALL5 = ../../../../../temp/cdd/\$\$LIBTARGET/*.obj\n";
print "\n";
print "win32:CLEAN_FILES = ../../../../../bin/*.map ../../../../../bin/*._xe ../../../../../bin/*.tds ../../../../../bin/*.pdb ../../../../../bin/*.pbo ../../../../../bin/*.pbi ../../../../../bin/*.pbt \$\$TEMP_CLEAN_ALL \$\$TEMP_CLEAN_ALL2 \$\$TEMP_CLEAN_ALL3 \$\$TEMP_CLEAN_ALL4 \$\$TEMP_CLEAN_ALL5\n";

