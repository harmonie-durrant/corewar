.POSIX:

PROJECT = doxygen-awesome-css

PREFIX = /usr/local
DATADIR = share
INSTALLDIR = $(DESTDIR)$(PREFIX)/$(DATADIR)/$(PROJECT)

INSTALL = install -m 644
MKDIR = mkdir -p
RM = rm -f

FILES = doxygen-awesome-darkmode-toggle.js \
  doxygen-awesome-fragment-copy-button.js \
  doxygen-awesome-interactive-toc.js \
  doxygen-awesome-paragraph-link.js \
  doxygen-awesome-sidebar-only-darkmode-toggle.css \
  doxygen-awesome-sidebar-only.css \
  doxygen-awesome.css

re: fclean all
all: main

main:
	@doxygen Doxyfile

# Cleaning functions

clean:
	@rm -rf ./docs/

fclean:
	@rm -rf ./docs

install:
	$(MKDIR) $(INSTALLDIR)
	$(INSTALL) $(FILES) $(INSTALLDIR)/

uninstall: fclean
	$(RM) -r $(INSTALLDIR)/

.PHONY: all clean install uninstall
