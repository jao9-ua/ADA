#Juan Andrés Orocondo Álvarez 20993208G
	
OPTS = -Wall -O3 -std=c++0x

all: qs-vs-hs qs-vs-hs.Msteps graphs

qs-vs-hs: qs-vs-hs.cc
	g++ ${OPTS} -o qs-vs-hs qs-vs-hs.cc	 


qs-vs-hs.Msteps: qs-vs-hs
	./qs-vs-hs > qs-vs-hs.Msteps

graphs: qs-vs-hs.Msteps qs-vs-hs.gpi
	gnuplot qs-vs-hs.gpi



tar: qs-vs-hs.cc qs-vs-hs.gpi makefile
	tar cvfz 20993208G.tar.gz qs-vs-hs.cc qs-vs-hs.gpi makefile

clean: 
	-rm qs-vs-hs qs-vs-hs.Msteps fit.log *.png 
