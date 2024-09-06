#include "../../kipr/core/cleanup.hpp"
#include "../../kipr/servo/servo.h"

namespace {
__attribute__((constructor(2))) void register_servo_cleanup() {
  kipr::core::cleanup_add(disable_servos);
}
} // namespace
