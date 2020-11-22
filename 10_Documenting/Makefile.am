bin_PROGRAMS=guessnumber
pkgdata_DATA=ru/LC_MESSAGES/guessnumber.mo

ru/LC_MESSAGES/guessnumber.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guessnumber.pot guessnumber.c
	xgettext -k_ -c guessnumber.c -o messages.new.pot
	cp guessnumber.pot messages.pot
	msgmerge -U messages.pot messages.new.pot
