#include "/home/mulin/MyWorkPlace/LRAP/include/lrap.h"

extern char _heap_start;
int main(const char *args);

//Area hrap = {.start=&_heap_start, .end=PMEM_END};
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  outb(LRSIMTRM, ch);
}
void halt(int code) { 
  ending(code);
  while (1);
}

void _trm_init(){
  int ret = main(mainargs);
  halt(ret);
} 
