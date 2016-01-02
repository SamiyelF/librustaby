/*
 * comm_speed_test.c
 *
 *  Created on: Nov 4, 2015
 *      Author: Joshua Southerland
 */

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "wallaby/wallaby.h"

long elapsed_usec(struct timeval t1, struct timeval t2)
{
	return 1000000*(t2.tv_sec-t1.tv_sec) + (t2.tv_usec - t1.tv_usec);
}

int main(int argc, char ** argv)
{
    while(1)
    {
    	struct timeval start, stop;
    	unsigned long int samples_start, samples_stop, num_samples;

    	gettimeofday(&start, NULL);

    	samples_start = get_robot_update_count();

    	usleep(100000);

    	samples_stop = get_robot_update_count();

    	gettimeofday(&stop, NULL);

    	num_samples = samples_stop - samples_start;

    	long elapsed_time = elapsed_usec(start, stop);
    	double avg_sample_time_usec = ((double)elapsed_time)/((double)num_samples);

    	printf("%f uS per sample average (%f Hz)\n", avg_sample_time_usec, (1000000.0/avg_sample_time_usec));
    }

    return 0;
}
