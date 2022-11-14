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
    int returns(int x);
}

int main() {
    if(returns(1) == 0 && returns(2) == 1 && returns(-1) == 2) {
        std::cout << "Success" << std::endl;
      std::cout << "PASSED Result: "  << std::endl;
    }else {
  	  std::cout << "FALIED Result: "  << std::endl;
    }
}