LIBS=./libProgPag076.so
PROG=progPag076

progPag076: progPag076.o libProgPag076.so
		gcc progPag076.o ${LIBS} -o ${PROG}
progPag076.a: 
		gcc progPag076.o${LIBS} -o ${PROG}
progPag076Stat:	libProgPag076.a progPag076.o
		gcc progPag076.o -o progPag076Stat		
progPag076.o: progPag076.c
		gcc progPag076.c -c

libProgPag076.so: mychio.h mychio.c mypushpop.c mypushpop.h mygetop.c mygetop.h
		gcc mychio.c mypushpop.c  mygetop.c -shared -fPIC -o libProgPag076.so

clean:
		rm *.o *.so *.a ${PROG}
