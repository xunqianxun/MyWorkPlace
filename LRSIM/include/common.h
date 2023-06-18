#ifndef COMMON_H
#define COMMON_H

#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>

#include <iostream>

#define TURE  1
#define FALSE 0

//Log information using 
#define log_out(data) std::cout << "\033[31m" << data << "\033[0m" << std::endl; //red
#define log_yel(data) std::cout << "\033[33m" << data << "\033[0m" << std::endl;
#define log_gre(data) std::cout << "\033[32m" << data << "\033[0m" << std::endl;
#define log_blu(data) std::cout << "\033[34m" << data << "\033[0m" << std::endl;


//for mmio define divice addr using


#endif 
