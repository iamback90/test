#include "slow_power.h"
#include <stdio.h>

int power2(int i) {
  printf("slow power2\n");
  return i*i;
}

int power3(int i) {
  return i * power2(i);
}
