#include <sys/time.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdlib.h>
#include <stdio.h>

#define TIME_s 0
#define TIME_ms 1
#define TIME_us 2
#define TIME_ns 3

double get_time(int resolution);

void tic(double * time, int resolution);

void tac(double * time, int resolution);