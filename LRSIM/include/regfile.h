#ifndef REGFILE_H
#define REGFILE_H

int64_t get_regdata(int32_t grp_addr);
int push_regdata(int32_t grp_addr, int64_t grp_data);

#endif