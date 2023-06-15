#include "common.h"
#include "regfile.h"

int64_t riscv_grp[32];

int64_t get_regdata(int grp_addr){
    return riscv_grp[grp_addr];
}