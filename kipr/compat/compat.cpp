#include "../../kipr/compat/compat.hpp"

#include <sched.h>
#include <unistd.h>

int kipr::compat::yield() { return sched_yield(); }

int kipr::compat::microsleep(unsigned long microseconds) {
  return usleep(microseconds);
}
