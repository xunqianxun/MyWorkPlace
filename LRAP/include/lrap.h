#ifndef LRAP_H
#define LRAP_H

// extern char _pmem_start;
// #define PMEM_SIZE (128 * 1024 * 1024)
// #define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

#define ending(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))
#define putstr(s)  ({ for (const char *p = s; *p; p++) putch(*p); })
#define LRSIMTRM 0x80003f8

typedef struct {
  void *start, *end;
} Area;

extern   Area        heap;
void     putch       (char ch);
void     halt        (int code) __attribute__((__noreturn__));

#endif
