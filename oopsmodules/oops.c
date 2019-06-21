#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION ("Oops");
MODULE_AUTHOR("weiqifa");

static int my_oops_init(void)
{
	int *a;
	a = (int *)0x00003333;

	*a = 3;
    printk(KERN_ALERT "oops %d\n",a);
    return 0;
}
static void my_oops_exit(void)
{
    printk(KERN_ALERT "Goodbye, oops\n");
}
module_init(my_oops_init);
module_exit(my_oops_exit);

