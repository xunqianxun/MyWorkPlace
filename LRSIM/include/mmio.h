#ifndef MMIO_H
#define MMIO_H 

#include <iostream>

using namespace std;

#define MEMSTART 0x8000000
#define ADDR(num) 0x80000000-num 

int32_t inst_read(int32_t inst_data);
int write_all(int32_t write_addr, int64_t write_date);


#endif
