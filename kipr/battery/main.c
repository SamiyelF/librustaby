/*
 * battery_test.c
 *
 *  Created on: Nov 2, 2015
 *      Author: Joshua Southerland
 */

#include "../time/time.h"
#include "battery.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  while (1) {
    float v = power_level();
    printf("%f\n", v);
    msleep(250);
  }

  return 0;
}
