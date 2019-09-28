CC := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
PWD := $(PWD)

default: make_raw_ko
	$(CC) -I $(FTRACE_INCLUDE_PATH) -static $(BUILD_DIR)/out_binary loader.c -o $(BUILD_DIR)/loader

make_raw_ko:
	cd $(BUILD_DIR) && $(OBJCOPY) -I binary -O elf32-tradbigmips -B mips ftrace.ko out_binary
	
	cd $(PWD)

clean:
	rm -f $(BUILD_DIR)/out_binary
	rm -f $(BUILD_DIR)/loader