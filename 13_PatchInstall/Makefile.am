bin_PROGRAMS=guessnumber
AM_CPPFLAGS = -D LOCALEDIR='"$(DESTDIR)/$(localedir)"'
pkgdatadir = $(DESTDIR)/$(localedir)/ru/LC_MESSAGES
pkgdata_DATA= $(DESTDIR)/$(localedir)/ru/LC_MESSAGES/guessnumber.mo


$(DESTDIR)/$(localedir)/ru/LC_MESSAGES/guessnumber.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guessnumber.pot guessnumber.c
	xgettext -k_ -c guessnumber.c -o messages.new.pot
	cp guessnumber.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
