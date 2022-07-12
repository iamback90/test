#include "slow_power.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
  printf("power3 of %s is %d\n", argv[1], power3(atoi(argv[1])));
}


