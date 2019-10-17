ifneq ($(KERNELRELEASE),)
$(warning ------------------------001)
obj-m := kobject.o
else
PWD  := $(shell pwd)
KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
$(warning ------------------------002)
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	$(warning ------------------------003)
clean:
	rm -rf .*.cmd *.o *.*~ *.order *.symvers  *.mod.c *.ko .tmp_versions
endif

