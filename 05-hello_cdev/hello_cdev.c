#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major;

static int __init my_init(void) {
    printk("Lewiatan - hello from module\n");
    return 0;
}

static void __exit my_exit(void) {
    printk("Lewiatan - goodbye from module\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Piotr Lewicki");
MODULE_DESCRIPTION("Sample kernel module for creation of character device");
