SUBDIRS = src tests
ACLOCAL_AMFLAGS = -I m4

gitclean: maintainer-clean
	git clean -fd

gcov:	check
	$(MAKE) -C src gcov
