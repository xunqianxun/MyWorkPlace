#include "mmio.h"
#include "common.h"

using namespace std;

vector <char> memory (64 * 1024 *1024);

int load_file(char* path){
    ifstream infile(path, ios::binary);

    infile.seekg(0, ios::end);
	streampos fileSize = infile.tellg();
    infile.seekg(0, ios::beg);
    char* buffer = new char[fileSize];
    if(!infile.read(buffer, fileSize))
        log_out("explod img falt!!");
    memcpy(memory.data(), buffer, fileSize);
    infile.close();
    delete[] buffer;

    return 0;	
}

int64_t inst_read(int32_t inst_data){
	if(inst_data < MEMSTART)
		log_out("Instruction address out of bounds!!");
	return memory[ADDR(inst_data)];
}

int write_all(int32_t write_addr, int64_t write_date){
    if(write_addr < MEMSTART)
        log_out("write address out of bounds!!");
    memory[ADDR(write_addr)] = write_date;
}
