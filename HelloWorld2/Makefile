PWD=$(shell pwd)
VER=$(shell uname -r)
KERNEL_BUILD=/lib/modules/$(VER)/build
$(info $(PWD))
$(info $(VER))
ifneq ($(KERNELRELEASE),)
obj-m := hello.o
else
PWD  := $(shell pwd)
KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
install:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
endif

