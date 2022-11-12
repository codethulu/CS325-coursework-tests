#include <iostream>
#include <cstdio>

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
    int implicit();
}

int main() {
    if(implicit() == 3)
      std::cout << "PASSED Result: " << implicit() << std::endl;
  	else 
  	  std::cout << "FALIED Result: " << implicit() << std::endl;
}