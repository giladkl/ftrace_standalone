#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/fs.h>
#include <linux/types.h>


// const struct modversion_info ____versions[] __used __attribute__((section("__versions"))) = {
// 	{ 0x13371337, "module_layout" },
// };

static int __init init_ftrace(void)
{
	return 0;
}

static void __exit cleanup_ftrace(void)
{
	return;
}


module_init(init_ftrace);
module_exit(cleanup_ftrace);

MODULE_INFO(intree, "Y");
MODULE_INFO(vermagic, "VERMAGICHEREPLEASEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

MODULE_LICENSE("GPL");
