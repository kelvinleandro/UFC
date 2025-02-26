/***************************************************************************//**
*  \file       hello_world.c
*
*  \details    Simple parameters hello world driver    
*
* *******************************************************************************/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int valueETX, arr_valueETX[4];
char *nameETX;
int cb_valueETX = 0;
int sumETX = 0; // para somar os valores de arr_valueETX

/*This will create a sysfs entry. (/sys/module/hello_world_module/parameters/valueETX) */
module_param(valueETX, int, S_IRUSR|S_IWUSR);                      //integer value
/*This will create a sysfs entry. (/sys/module/hello_world_module/parameters/nameETX) */
module_param(nameETX, charp, S_IRUSR|S_IWUSR);                     //String
/*This will create a sysfs entry. (/sys/module/hello_world_module/parameters/arr_valueETX) */
module_param_array(arr_valueETX, int, NULL, S_IRUSR|S_IWUSR);      //Array of integers
/* tornando sumETX acessivel */
module_param(sumETX, int, S_IRUSR|S_IWUSR);

//module_param_array(name,type,perm);
/*
name is the name of your array (and of the parameter),
type is the type of the array elements,
perm is the usual permissions value.
*/

//module_param_array(name,type,num,perm);
/*
name is the name of your array (and of the parameter),
type is the type of the array elements,
num is an integer variable (optional) otherwise NULL,
perm is the usual permissions value.
*/
/*----------------------Module_param_cb()--------------------------------*/

void calculate_sum(void){
	int i;
	sumETX = 0;
	for(i = 0; i < (sizeof(arr_valueETX) / sizeof(int)); i++){
		sumETX += arr_valueETX[i];
	}
	printk(KERN_INFO "Updated sumETX = %d\n", sumETX);
}

int notify_param(const char *val, const struct kernel_param *kp)
{
	int i;
	int res = param_set_int(val, kp); // Use helper for write variable
        if(res==0) {
		printk(KERN_INFO "Call back function called...\n");
		printk(KERN_INFO "New value of cb_valueETX = %d\n", cb_valueETX);
				
		if(cb_valueETX == 25) {
			valueETX += cb_valueETX;
			printk(KERN_INFO "ValueETX = %d  \n", valueETX);
			printk(KERN_INFO "cb_valueETX = %d  \n", cb_valueETX);
			printk(KERN_INFO "NameETX = %s \n", nameETX);
			for (i = 0; i < (sizeof arr_valueETX / sizeof (int)); i++) {
				printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
			}
			calculate_sum(); // atualiza sumETX
		}
		return 0;
	}
	return -1;
}

const struct kernel_param_ops my_param_ops = 
{
	.set = &notify_param, // Use our setter ...
	.get = &param_get_int, // .. and standard getter
};

module_param_cb(cb_valueETX, &my_param_ops, &cb_valueETX, S_IRUGO|S_IWUSR );

/*-------------------------------------------------------------------------*/

/*
** Module init function
*/
static int __init hello_world_init(void)
{
	int i;
	printk(KERN_INFO "ValueETX = %d  \n", valueETX);
	printk(KERN_INFO "cb_valueETX = %d  \n", cb_valueETX);
	printk(KERN_INFO "NameETX = %s \n", nameETX);
	for (i = 0; i < (sizeof arr_valueETX / sizeof (int)); i++) {
		printk(KERN_INFO "Arr_value[%d] = %d\n", i, arr_valueETX[i]);
	}
	calculate_sum();
	printk(KERN_INFO "sumETX = %d\n", sumETX);
	printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
	return 0;
}

/*
** Module Exit function
*/
static void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Kernel Module Removed Successfully...\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("A simple parameters hello world driver");
MODULE_VERSION("1.0");
