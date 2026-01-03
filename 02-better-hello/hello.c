#include <linux/module.h>
#include <linux/init.h>

int my_init(void) {
    printk("Lewiatan - hello from module\n");
    return 0;
}

void my_exit(void) {
    printk("Lewiatan - goodbye from module\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");