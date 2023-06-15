#ifndef MMIO_H
#define MMIO_H 

#include <iostream>

using namespace std;

#define MEMSTART 0x8000000
#define ADDR(num) 0x80000000-num 

#define log_out(data) cout << "\033[31m" << data << "\033[0m" << endl;



#endif
