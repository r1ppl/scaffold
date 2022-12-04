#include <string>
#include <fstream>
#include "../libs/scaf.hpp"

namespace cpp {
  /// Creates a new project
  static void new_proj(std::string directory) {
    fs::create_directories("./" + directory);
    fs::create_directories(directory + "/src/");
 
    fs::create_directories(directory + "/target/");

    std::string create_makefile = "touch " + directory + "/Makefile";
    std::string create_main = "touch " + directory + "/src/main.cpp";
    command(create_makefile);
    command(create_main);
    command("touch " + directory + "/.scaf");

    std::ofstream scaf;
    scaf.open(directory + "/.scaf");
    scaf << "Name: " << directory << "\n";
  
    std::string git_init = "git init " + directory;
    system(git_init.c_str());

    std::ofstream main(directory + "/src/main.cpp");
    main << R"(#include <iostream>

int main(){
    std::cout << "Hello, World!" << std::endl;
})";
    main.close();

    std::ofstream make(directory + "/Makefile");
    make << "all:\n"
            "\tclang++ src/main.cpp -o ./target/build";
    make.close();
}}