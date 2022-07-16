#include "mytime.h"


double get_time(int resolution)
/******************************************************************************
 returns the time in the desired resolution
 
 TIME_s - seconds
 TIME_ms - miliseconds
 TIME_us - microseconds
 TIME_ns - nanoseconds
 ******************************************************************************/
{
	struct timespec ts;
	double ret;
    
	clock_gettime(CLOCK_REALTIME, &ts);
	
	switch (resolution)
	{
		case TIME_s:
			ret = (((double)ts.tv_sec) + (((double)ts.tv_nsec) / 1000000000));
			//printf("s %.20lf\n", ret);
			return ret;
		case TIME_ms:
			ret = ((((double)ts.tv_sec) * 1000) + (((double)ts.tv_nsec) / 1000000));
			//printf("ms %.20lf\n", ret);
			return ret;
		case TIME_us:
			ret = ((((double)ts.tv_sec)) * 1000000 + (((double)ts.tv_nsec) / 1000));
			//printf("us %.20lf\n", ret);
			return ret;
		case TIME_ns:
			ret = ((((double)ts.tv_sec)) * 1000000000 + ((double)ts.tv_nsec));
			//printf("ns %.20lf\n", ret);
	 		return ret;
		default:
			fprintf(stderr, "treb_get_time() - resolution not supported\n");
			exit(1);
	}		
}

void tic(double * time, int resolution)
{
    *time = get_time(resolution);
}

void tac(double * time, int resolution)
{
    *time = get_time(resolution) - *time;
}
