#Juan Andrés Orocondo Álvarez 20993208G
OPTS = -Wall -Wextra -O3 -std=c++0x

all: quickSort quickSort.CPUtimes graphs

graphs: quickSort.CPUtimes quickSort.gpi
	gnuplot quickSort.gpi

quickSort: quickSort.cc
	g++ ${OPTS} -o quickSort quickSort.cc	 

quickSort.CPUtimes: quickSort
	./quickSort > quickSort.CPUtimes

tar: quickSort.cc quickSort.gpi makefile
	tar cvfz 20993208G.tar.gz quickSort.cc quickSort.gpi makefile

clean: 
	rm -f quickSort quickSort.CPUtimes fit.log quickSort*.png *~
 
