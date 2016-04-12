// string::back
#include <iostream>
#include <string>

int main ()
{
  std::string str ("hello world.");
  str.back() = '!';
  std::cout << str << '\n';
  return 0;
}
