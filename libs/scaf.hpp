#pragma once

#include <filesystem>
#include <string>
#include <cstdlib>

/// C++17 Filesystem module
namespace fs = std::filesystem;

/// Runs a command, returns void
static void command(std::string command) {
  system(command.c_str());
}

/// Adds a lib/ to the project
void add_libs(std::string directory) {
  fs::create_directories("./" + directory + "/libs/");
  std::string setup = "touch ./" + directory + "/libs/libs.hpp";
  command(setup);
}

static void sync() {}