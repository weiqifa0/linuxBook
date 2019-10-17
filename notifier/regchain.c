#include <asm/uaccess.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/notifier.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");

/*
* 注册通知链
*/
extern int register_test_notifier(struct notifier_block*);
extern int unregister_test_notifier(struct notifier_block*);

static int test_event1(struct notifier_block *this, unsigned long event, void *ptr)
{
  printk("In Event 1: Event Number is %d\n", event);
  return 0;
}

static int test_event2(struct notifier_block *this, unsigned long event, void *ptr)
{
  printk("In Event 2: Event Number is %d\n", event);
  return 0;
}

static int test_event3(struct notifier_block *this, unsigned long event, void *ptr)
{
  printk("In Event 3: Event Number is %d\n", event);
  return 0;
}

/*
* 事件1，该节点执行的函数为test_event1
*/
static struct notifier_block test_notifier1 =
{
    .notifier_call = test_event1,
};

/*
* 事件2，该节点执行的函数为test_event1
*/
static struct notifier_block test_notifier2 =
{
    .notifier_call = test_event2,
};

/*
* 事件3，该节点执行的函数为test_event1
*/
static struct notifier_block test_notifier3 =
{
    .notifier_call = test_event3,
};

/*
* 对这些事件进行注册
*/
static int __init reg_notifier(void)
{
  int err;
  printk("Begin to register:\n");
  
  err = register_test_notifier(&test_notifier1);
  if (err)
  {
    printk("register test_notifier1 error\n");
    return -1;
  }
  printk("register test_notifier1 completed\n");

  err = register_test_notifier(&test_notifier2);
  if (err)
  {
    printk("register test_notifier2 error\n");
    return -1;
  }
  printk("register test_notifier2 completed\n");

  err = register_test_notifier(&test_notifier3);
  if (err)
  {
    printk("register test_notifier3 error\n");
    return -1;
  }
  printk("register test_notifier3 completed\n");
  
  return err;
}

/*
* 卸载刚刚注册了的通知链
*/
static void __exit unreg_notifier(void)
{
  printk("Begin to unregister\n");
  unregister_test_notifier(&test_notifier1);
  unregister_test_notifier(&test_notifier2);
  unregister_test_notifier(&test_notifier3);
  printk("Unregister finished\n");
}

module_init(reg_notifier);
module_exit(unreg_notifier);
