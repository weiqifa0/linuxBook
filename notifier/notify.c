#include <asm/uaccess.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/notifier.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");

extern int test_notifier_call_chain(unsigned long val, void *v);

/*
* 向通知链发送消息以触发注册了的函数
*/
static int __init call_notifier(void)
{
  int err;
  printk("Begin to notify:\n");

  /*
  * 调用自定义的函数，向test_chain链发送消息
  */
  printk("==============================\n");
  err = test_notifier_call_chain(1, NULL);
  printk("==============================\n");
  if (err)
          printk("notifier_call_chain error\n");
  return err;
}

static void __exit uncall_notifier(void)
{
    printk("End notify\n");
}

module_init(call_notifier);
module_exit(uncall_notifier);
