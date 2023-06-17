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
int32_t vector_read(int32_t start_addr){
    int32_t ret_32inst;
    for (int i = 0; i < 4; i++) {
        ret_32inst |= static_cast<int32_t>(memory[start_addr + i]) << (8 * i);
    }
    return ret_32inst;
}

int32_t inst_read(int32_t inst_addr){
	if(inst_addr < MEMSTART)
		log_out("Instruction address out of bounds!!");
	return vector_read(ADDR(inst_addr));
}

int write_all(int32_t write_addr, int64_t write_date){
    if(write_addr < MEMSTART)
        log_out("write address out of bounds!!");
    memory[ADDR(write_addr)] = write_date;
}
