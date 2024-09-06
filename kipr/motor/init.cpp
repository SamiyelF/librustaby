#include "../../kipr/core/cleanup.hpp"
#include "../../kipr/motor/motor.h"

namespace {
__attribute__((constructor)) void register_motor_cleanup() {
  kipr::core::cleanup_add(ao);
}
} // namespace
