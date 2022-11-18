#include <cstdio>
#include <iostream>

// clang++ driver.cpp addition.ll -o add

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C" DLLEXPORT int print_int(int X) {
  fprintf(stderr, "%d\n", X);
  return 0;
}

extern "C" DLLEXPORT float print_float(float X) {
  fprintf(stderr, "%f\n", X);
  return 0;
}

extern "C" {
void infinite();
}

int main() {
  std::cout << "this test tests how your program does with infinite loops and "
               "accidently also tests if your program handles the fact there "
               "is no returns in any block of a void function"
            << std::endl;
  std::cout << "if you see 1 printing forever, you probably PASSED, maybe "
               "consider Ctrl+C or Ctrl+Z to exit this test as it actually doesn't end automatically..."
            << std::endl;
  infinite();
}