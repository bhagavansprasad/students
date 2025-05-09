
# DiskSim Storage Subsystem Simulation Environment (Version 4.0)
# Revision Authors: John Bucy, Greg Ganger
# Contributors: John Griffin, Jiri Schindler, Steve Schlosser
#
# Copyright (c) of Carnegie Mellon University, 2001-2008.
#
# This software is being provided by the copyright holders under the
# following license. By obtaining, using and/or copying this software,
# you agree that you have read, understood, and will comply with the
# following terms and conditions:
#
# Permission to reproduce, use, and prepare derivative works of this
# software is granted provided the copyright and "No Warranty" statements
# are included with all reproductions and derivative works and associated
# documentation. This software may also be redistributed without charge
# provided that the copyright and "No Warranty" statements are included
# in all redistributions.
#
# NO WARRANTY. THIS SOFTWARE IS FURNISHED ON AN "AS IS" BASIS.
# CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
# EXPRESSED OR IMPLIED AS TO THE MATTER INCLUDING, BUT NOT LIMITED
# TO: WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY
# OF RESULTS OR RESULTS OBTAINED FROM USE OF THIS SOFTWARE. CARNEGIE
# MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT
# TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
# COPYRIGHT HOLDERS WILL BEAR NO LIABILITY FOR ANY USE OF THIS SOFTWARE
# OR DOCUMENTATION.




include .paths

CFLAGS=-g $(LIBDDBG_CFLAGS) $(LIBPARAM_CFLAGS) $(DISKMODEL_CFLAGS) -I..

LIBPARAM=$(LIBPARAM_PREFIX)
PACKAGE=disksim

all : all-redirect

# module parameter proto files
PARAM_PROTO = bus.modspec ctlr.modspec iodriver.modspec\
	ioqueue.modspec disk.modspec \
	simpledisk.modspec\
	device_stats.modspec bus_stats.modspec ctlr_stats.modspec\
	iodriver_stats.modspec pf_stats.modspec global.modspec\
	stats.modspec syncset.modspec synthgen.modspec synthio.modspec\
	logorg.modspec pf.modspec\
	cachemem.modspec cachedev.modspec device.modspec\
	iosim.modspec iomap.modspec

PARAM_CODE = $(PARAM_PROTO:%.modspec=$(PACKAGE)_%_param.c)

PARAM_OBJ = $(PARAM_PROTO:%.modspec=$(PACKAGE)_%_param.o)


PARAM_HEADERS = $(PARAM_PROTO:%.modspec=$(PACKAGE)_%_param.h)

$(PARAM_CODE): $(PACKAGE)_%_param.c: %.modspec 
	$(LIBPARAM)/mod.pl $(PACKAGE) $< 
	indent $@ || true

all-redirect: $(PARAM_OBJ) modules.h

modules.h: $(PARAM_HEADERS)
	$(LIBPARAM)/make_modules_h.pl $(PACKAGE) *.modspec > modules.h

clean:
	rm -f *.h *.c *.tex *~ *.o

distclean: clean
