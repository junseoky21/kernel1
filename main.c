/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: junseoky
 *
 * Created on October 29, 2018, 11:38 AM
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

//#include <linux >
struct birthday {
    int day;
    int month;
    int year;
    struct list_head list;
};

// Initializes the variable birthday_list, which is of type struct list_head
static LIST_HEAD(birthday_list);


static int hello_init(void) {
    struct birthday *person;
    struct birthday *ptr, *next;
    printk(KERN_ALERT "TEST: Hello World, this is Jun");
    person = kmalloc(sizeof(*person), GFP_KERNEL);  // GFP_KERNEL indicates routine kernel memory allocation
    person->day = 2;
    person->month = 8;
    person->year = 1995;
    INIT_LIST_HEAD(&person->list);
    list_add_tail(&person->list, &birthday_list);
    list_for_each_entry(ptr, &birthday_list, list) {
        /* On each iteration ptr points to the next birthday struct*/
//        printk(KERN_ALERT "%s", "Formatting and number of list test");
        printk(KERN_ALERT "Looping Birthday: %d/%d/%d", ptr->month, ptr->day, ptr->year);
    }
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        /* On each iteration ptr points to the next birthday struct*/
        list_del(&ptr->list);
        kfree(ptr);
    }
    return 0;
}
//static int 
static void hello_exit(void) {
    
    printk(KERN_ALERT "TEST: Good bye");
}

module_init(hello_init);
// Deallocate resources
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Practice Module");
MODULE_AUTHOR("SGG");