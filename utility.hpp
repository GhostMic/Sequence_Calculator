#ifndef MIC_UTILITY
#define MIC_UTILITY
#include "header.hpp"

void cls(){
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}

void cinError(){
  cin.clear();
  cin.ignore(256, '\n');
}

#endif // MIC_UTILITY
