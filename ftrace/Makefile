obj-m := ftrace.o
KDIR := /home/gilad/excer/ftrace/linux-5.2.9
PWD := $(shell pwd)
CC := $(CROSS_COMPILE)gcc

default:
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) src=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(BUILD_DIR) src=$(PWD) clean
