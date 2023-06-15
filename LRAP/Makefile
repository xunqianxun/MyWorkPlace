include ./test/testfile/Makefile

CC = riscv64-linux-gnu-gcc
LD = riscv64-linux-gnu-ld
OBJDUMP = riscv64-linux-gnu-objdump
OBJCOPY = riscv64-linux-gnu-objcopy
TESTSRC += ./test/testfile/dummy.c
TESTSRC += $(wildcard src/*.c)
OBJCTC = $(TESTSRC:.c=.o)
TESTCOM = $(wildcard src/*.S)
OBJCTS = $(TESTCOM:.S=.o)

OBJSRC = $(wildcard src/*.o)

CFLAGS += -fdata-sections -ffunction-sections #puting funvtion indepent sections

CFLAGS += -I ./include
CFLAGS += -std=gnu11
CFLAGS += -march=rv64i -static
CFLAGS += -O2 -MMD -Wall -fno-asynchronous-unwind-tables \
		  -fno-builtin -fno-stack-protector \
		  -fno-ident \
		  -Wno-main -U_FORTIFY_SOURCE

LDFLAGS += -T ./src/Link.ld
LDFLAGS += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS += --gc-sections -e _start #cut usless section and point out enter address

ASFLAGS += -MMD -I compuse

TARGETIMG = target

BUILD_DIR = ./test/build

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@) && echo CC + $<
	@$(CC) $(CFLAGS) -c -o$@ $(realpath $<)
$(BUILD_DIR)/%.o: %.S
	@mkdir -p $(dir $@) && echo AS + $<
	@$(CC) $(ASFLAGS) -c -o$@ $(realpath $<)
$(TARGETIMG).elf: $(OBJSRC)
	@$(LD) $(LDFLAGS) -o $(TARGETIMG).elf --start-group $(abspath $(OBJSRC)) --end-group

img: $(OBJCTC) $(OBJCTS) $(TARGETIMG).elf  
 
run:img
	img
