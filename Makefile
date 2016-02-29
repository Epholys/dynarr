.PHONY: Makefile Makefile.var execall debugall testing clean cleanmain

include Makefile.var

RAWFILESC = $(shell find -type f -name *.c)
FILESC = $(RAWFILESC:./%=%)
FILESO = $(patsubst %.c, %.o, $(FILESC))

debugall : DEFFLAGS += $(GFLAGS)
debugall : $(FILESO)

testing: debugall
	$(CC) $(CFLAGS) $(GCFLAGS) $(FILESO) -o $@

%.o : %.c
	$(CC) -c $(DEFFLAGS) $(CFLAGS) $< -o $@ $(IFLAGS)

clean :
	rm $(FILESO)
