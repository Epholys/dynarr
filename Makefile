.PHONY: Makefile Makefile.var execall debugall testing clean cleanmain

include Makefile.var

RAWFILESC = $(shell find -type f -name *.c ! -name main.c)
FILESC = $(RAWFILESC:./%=%)
FILESO = $(patsubst %.c, %.o, $(FILESC))

debugall : DEFFLAGS += $(GFLAGS)
debugall : $(FILESO)

testing: debugall
	$(CC) $(CFLAGS) $(GFLAGS) -c $(TESTDIR)main.c -o $(TESTDIR)main.o $(IFLAGS)
	$(CC) $(CFLAGS) $(GCFLAGS) $(FILESO) $(TESTDIR)main.o -o $@

%.o : %.c
	$(CC) -c $(DEFFLAGS) $(CFLAGS) $< -o $@ $(IFLAGS)

clean :
	rm $(FILESO)
