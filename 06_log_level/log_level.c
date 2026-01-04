#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void) {
    printk(KERN_INFO "log_level - This is an INFO\n");
    printk(KERN_WARNING "log_level - This is an WARNING\n");
    printk(KERN_ALERT "log_level - This is an ALERT\n");
    printk(KERN_DEBUG "log_level - This is an DEBUG\n");
    return 0;
}

static void __exit my_exit(void) {
    pr_emerg( "log_level - This is an EMERGENCY\n");
    pr_err( "log_level - This is an ERROR\n");
    pr_info( "log_level - This is an INFO\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Piotr Lewicki");
MODULE_DESCRIPTION("Basic kernel module that has init and exit functions - improved version");
