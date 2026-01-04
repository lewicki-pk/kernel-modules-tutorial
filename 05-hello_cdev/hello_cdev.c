#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major;

static ssize_t my_read(struct file *file, char __user *u, size_t l, loff_t *o)
{
    printk("hello_cdev: read called\n");
    return 0;
}

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = NULL,
    .release = NULL,
    .read = my_read,
    .write = NULL,
};

static int __init my_init(void)
{
    major = register_chrdev(0, "hello_cdev", &fops);
    if (major < 0) {
        printk("hello_cdev: failed to register character device\n");
        return major;
    }
    printk("hello_cdev: registered character device with major number %d\n", major);
    return 0;
}

static void __exit my_exit(void)
{
    unregister_chrdev(major, "hello_cdev");
    printk("hello_cdev: goodbye from module\n"); 
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Piotr Lewicki");
MODULE_DESCRIPTION("Sample kernel module for creation of character device");
