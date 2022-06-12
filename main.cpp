#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory>
#include <string>
#include <stdexcept>
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
std::string paste()
{
  return exec("pbpaste");
}
std::string copy(const char * new_clipboard)
{
  std::stringstream cmd;
  cmd << "echo \"" << new_clipboard << "\" | pbcopy";
  return exec(cmd.str().c_str());
}
int main(){
  
}
