#OSCAR CASADO LORENZO 77580351V	
OPTS = -Wall -O3 -std=c++0x
maxsum: maze.cc
	g++ ${OPTS} -o maze maze.cc

tar: maxsum.cc makefile
	tar cvfz 77580351V.tar.gz maxsum.cc makefile

clean:
	-rm maxsum