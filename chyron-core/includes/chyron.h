#pragma comment (lib, "User32.lib")
#pragma comment (lib, "UserEnv.lib")
#pragma comment (lib, "bcrypt.lib")

#pragma once

/* Generated with cbindgen:0.20.0 */

#include <cstdarg>
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <new>

using OnEventCallback = void(*)();

extern "C" {

void chyron_initialize();

void chyron_register_callback(OnEventCallback cb);

} // extern "C"
