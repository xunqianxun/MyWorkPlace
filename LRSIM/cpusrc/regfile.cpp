#include "common.h"
#include "regfile.h"

int64_t riscv_grp[32];

int64_t get_regdata(int32_t grp_addr){
    return riscv_grp[grp_addr];
}

int push_regdata(int32_t grp_addr, int64_t grp_data){
    riscv_grp[grp_addr] = grp_data;
    return 0;
}