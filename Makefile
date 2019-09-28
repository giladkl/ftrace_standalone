PWD := $(shell pwd)
export FTRACE_INCLUDE_PATH := $(PWD)/include
export BUILD_DIR := $(PWD)/build

default: loader
	cp build/loader ../rootfs/loader
	bash -c "cd ../rootfs; sync"

module:
	$(MAKE) -C ftrace/

loader: module
	$(MAKE) -C loader/

clean_loader:
	$(MAKE) -C loader/ clean

clean_module:
	$(MAKE) -C ftrace/ clean

clean: clean_loader clean_module
	
