ifneq ($(KERNELRELEASE),)
EXTRA_CFLAGS = -Wall -g
obj-m := buildchain.o regchain.o notify.o
else
PWD  := $(shell pwd)
KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	rm -rf .*.cmd *.o *.mod.c *.ko .tmp_versions
endif

