#include "common.h"
#include "regfile.h"
#include "rv_inst.h"
#include "mmio.h"
using namespace std;

class riscv_inst{

	private:
        int8_t   inst_type;
        int32_t  inst_num ;
        int8_t   rs1      ;
        int8_t   rs2      ;
	    int8_t   rd       ;
	 	int32_t  imm      ;
		int64_t  pc = ENTRDAAR   ;
	public:

		void decode (int type, int inst, int r1, int r2, int rdn, int immn){
			inst_type = type ;
			inst_num  = inst ;
			rs1       = r1   ;
			rs2       = r2   ;
			rd        = rdn  ;
			imm       = immn ;
		}
		int push_pc(int64_t pc_data){
			pc = pc_data;
		}
		int64_t get_pc(){
			return pc;
		}

		int8_t get_type(){
			return inst_type;
		}

		int32_t get_inst(){
			return inst_num;
		}

		int8_t get_rs1(){
			return rs1;
		}
		
		int8_t get_rs2(){
			return rs2;
		}

		int8_t get_rd(){
			return rd;
		}

		int32_t get_imm(){
			return imm;
		}

		int64_t add (){
			return get_regdata(rs1) + get_regdata(rs2);
		}
};

int ex_once(){
	riscv_inst riscv;
	int64_t inst_data ;
	inst_data = inst_read(riscv.get_pc());

}
