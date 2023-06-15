#include <fstream>
#include <iostream>
#include <cstdint>

using namespace std;

int* memory  = new int[64 * 1024 * 1024];

int load_file(char* path){
    ifstream infile(path, ios::binary);

    infile.seekg(0, ios::end);
	streampos fileSize = infile.tellg();
    infile.seekg(0, ios::beg);

    infile.read(memory, fileSize);

    infile.close();

    return 0;	
}

int64_t inst_read(int32_t inst_data){
	if(inst_data < MEMSTART)
		log_out("Instruction address out of bounds!!");
	return memory[ADDR(inst_data)];
}

int write_all(int32_t write_addr, int64_t write_date){

}
