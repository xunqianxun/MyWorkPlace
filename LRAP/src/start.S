//.section指令用于告诉编译器将代码或数据放置在特定的段中。entry是一个段的名称，它通常用于存放程序的入口点代码。"ax"是这个段的属性，其中a表示这个段是可分配的（可读写），x表示这个段是可执行的（包含可执行代码）。因此，.section entry, "ax"的作用是将下面的代码放到一个可读写且可执行的段中，以便程序可以正确地执
.section entry, "ax"
.globl _start
.type _start, @function //asteartain_start type is function

_start:
  mv s0, zero
  la sp, _stack_pointer
  jal _trm_init
