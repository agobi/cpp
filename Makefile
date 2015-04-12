SUBDIRS := $(sort $(dir $(wildcard */Makefile)))
RECURSIVE_TARGETS = all clean
$(RECURSIVE_TARGETS):
	@target=$@;\
	for dir in $(SUBDIRS); do\
	    echo "Makefile $$target in $$dir";\
	    $(MAKE) -C $$dir $$target;\
	done
