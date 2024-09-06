#include "../../kipr/core/cleanup.hpp"
#include "../../kipr/create/create.h"

namespace {
__attribute__((constructor)) void register_create_cleanup() {
  kipr::core::cleanup_add([]() {
    create_stop();
    create_disconnect();
  });
}
} // namespace
