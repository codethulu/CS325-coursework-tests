#include <iostream>
#include <cstdio>

// clang++ driver.cpp addition.ll -o add

#ifdef _WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C" {
    int lazyeval_and(int control);
    int lazyeval_or(int control);
}

int main() {

    int and_true = lazyeval_and(1);
    int and_false = lazyeval_and(0);

    int or_true = lazyeval_or(1);
    int or_false = lazyeval_or(0);

    if(and_true == 1)
      std::cout << "PASSED lazy_and when LHS is true Result: " << and_true << std::endl;
  	else
  	  std::cout << "FALIED lazy_and when LHS is true Result: " << and_true << std::endl;

    if(and_false == 0)
      std::cout << "PASSED lazy_and when LHS is false Result: " << and_false << std::endl;
  	else
  	  std::cout << "FALIED lazy_and when LHS is false Result: " << and_false << std::endl;
    
    if(or_true == 0)
      std::cout << "PASSED lazy_or when LHS is true Result: " << or_true << std::endl;
  	else
  	  std::cout << "FALIED lazy_or when LHS is true Result: " << or_true << std::endl;

    if(or_false == 1)
      std::cout << "PASSED lazy_or when LHS is false Result: " << or_false << std::endl;
  	else
  	  std::cout << "FALIED lazy_or when LHS is false Result: " << or_false << std::endl;
}