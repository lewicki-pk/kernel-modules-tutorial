#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major;

// int (*open) (struct inode *, struct file *);
static int my_open(struct inode *inode, struct file *filp)
{
    pr_info("hello_cdev: Major: %d, Minor: %d\n", imajor(inode), iminor(inode));
    pr_info("hello_cdev: filp->f_pos: %lld\n", filp->f_pos);
    pr_info("hello_cdev: filp->f_mode: 0x%x\n", filp->f_mode);
    pr_info("hello_cdev: filp->f_flags: 0x%x\n", filp->f_flags);

    return 0;

}

// int (*release) (struct inode *, struct file *);
static int my_release(struct inode *inode, struct file *filp)
{
    pr_info("hello_cdev: Device closed\n");
    return 0;
}

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = my_open,
    .release = my_release,
};

static int __init my_init(void)
{
    major = register_chrdev(0, "hello_cdev", &fops);
    if (major < 0) {
        pr_err("hello_cdev: failed to register character device\n");
        return major;
    }
    pr_info("hello_cdev: registered character device with major number %d\n", major);
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
