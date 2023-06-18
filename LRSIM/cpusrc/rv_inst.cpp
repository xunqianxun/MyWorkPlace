#include <bitset>
#include "common.h"
#include "regfile.h"
#include "rv_inst.h"
#include "mmio.h"
using namespace std;

char* add_inst = "??????? ????? ????? ??? ????? 00101 11";

class riscv_inst{

	private:
        int32_t   inst_type;
        int32_t   inst_num ;
        int32_t   rs1      ;
        int32_t   rs2      ;
	    int32_t   rd       ;
	 	int32_t   imm      ;
		int64_t   pc = ENTRDAAR   ;
	public:

		void decode (int32_t type, int32_t inst, int32_t r1, \
					 int32_t r2, int32_t rdn, int32_t immn){
			inst_type = type ;
			inst_num  = inst ;
			rs1       = r1   ;
			rs2       = r2   ;
			rd        = rdn  ;
			imm       = immn ;
		}
		int push_pc(int64_t pc_data){
			pc = pc_data;
			return 0;
		}
		int64_t get_pc(){
			return pc;
		}

		int32_t get_type(){
			return inst_type;
		}

		int32_t get_inst(){
			return inst_num;
		}

		int32_t get_rs1(){
			return rs1;
		}
		
		int32_t get_rs2(){
			return rs2;
		}

		int32_t get_rd(){
			return rd;
		}

		int32_t get_imm(){
			return imm;
		}
};


int inst_db(int32_t bit_number, char* inst_search){
	bool ret=1;
	char* ad_inst = inst_search;
	bitset<32> inst_32bit(bit_number);
	for(int i=0; i<32; i++){
		if((inst_32bit[i] != ad_inst[i]) & (ad_inst[i] != '?')){
			ret = 0;
			break;
		}
	}
 return ret;
}

int decode_inst(int32_t inst_data, int64_t pc, int32_t* inst_tpye, \
				int32_t*inst_num, int32_t* rs1, int64_t* pc_n,     \
			    int32_t* rs2, int32_t* rd, int32_t*imm){
	bool end_decode = TURE;
	int32_t inst_name = ADD;
	while (end_decode){
	
		switch (inst_name)
		{
		case ADD: if(inst_db(inst_data, add_inst)){
					*inst_tpye = ADD;
					*inst_num  = inst_data;
					*rs1       = inst_data & RS1_MASK;
					*rs2       = inst_data & RS2_MASK;
					*rd        = inst_data & RD_MASK ;
					*imm       = inst_data & IMM_MASK;
					*pc_n      =  pc + NEXT_PCADD;
					end_decode = FALSE;
		 		  }
				  else 
				  	inst_name = ADDI;
			      break;
		
		default: end_decode = FALSE;
				 inst_name  = ADD  ;
			break;
		}
	}
}

int ex_once(){
	int32_t type, number, rs1, rs2, rd, imm;
	int64_t next_pc;
	riscv_inst riscv;
	int32_t inst_data ;
	inst_data = inst_read(riscv.get_pc());
	decode_inst(inst_data, riscv.get_pc(), &type, &number, &rs1, &next_pc, &rs2, &rd, &imm);
	riscv.decode(type, number, rs1, rs2, rd, imm);
	switch (riscv.get_type())
	{
	case ADD:
			 push_regdata(riscv.get_rd(), get_regdata(riscv.get_rs1()) + get_regdata(riscv.get_rs2()));
			 riscv.push_pc(next_pc);
		break;
	
	default:
		break;
	}

}
