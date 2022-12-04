#include "./scaffold_cpp.cpp"

int main(int argc, char** argv) {
  cpp::new_proj(argv[1]);
  add_libs(argv[1]);
  return 0;
}
