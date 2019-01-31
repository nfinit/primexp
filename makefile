CC	=	gcc	
CFLAGS	=	-ansi -O3 -ffast-math
# ---------------------------------------------------------------------------- #
SDIR	=	./src
IDIR	=	./include
LDIR	=	./lib
ODIR	=	./obj
BDIR	=	./bin
# ---------------------------------------------------------------------------- #
SIEVEIN		=	$(SDIR)/drivers/sievesh.c $(SDIR)/math/sieve.c
SIEVEOUT	=	$(BDIR)/sieve
# ---------------------------------------------------------------------------- #
sieve: dirs
	$(CC) $(CFLAGS) -I$(IDIR) $(SIEVEIN) -o $(SIEVEOUT)
	-@mv *.o $(ODIR)
dirs:
	mkdir -p $(ODIR)
	mkdir -p $(BDIR)
clean:
	@rm -rf $(ODIR) $(BDIR) *.o core core.*
