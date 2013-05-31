all: beaprint

beaprint: beaprint.o
	gcc beaprint.o -I./include/ -o beaprint ./lib/libBeaEngine_s_d.a

beaprint.o: beaprint.c
	gcc -I./include/ -c beaprint.c

clean:
	rm -rf *o beaprint
