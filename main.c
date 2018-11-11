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
    struct birthday *person, *person1, *person2;
    struct birthday *ptr, *next;
    printk(KERN_ALERT "TEST: Hello World, this is Jun");
    person = kmalloc(sizeof(*person), GFP_KERNEL);  // GFP_KERNEL indicates routine kernel memory allocation
    person->day = 2;
    person->month = 8;
    person->year = 1995;
    person1 = kmalloc(sizeof(*person1), GFP_KERNEL);
    person2 = kmalloc(sizeof(*person2), GFP_KERNEL);
    INIT_LIST_HEAD(&person->list);  // List head is node in a list
    person1->day = 9;
    person1->month = 7;
    person1->year = 1993;
    INIT_LIST_HEAD(&person1->list);  // List head is node in a list
    person2->day = 11;
    person2->month = 2;
    person2->year = 1994;
    INIT_LIST_HEAD(&person2->list);  // List head is node in a list
    list_add_tail(&person->list, &birthday_list);   // Add the first node
    list_add_tail(&person1->list, &birthday_list);  // Add the second node
    list_add_tail(&person2->list, &birthday_list);  // Add the third node
    list_for_each_entry(ptr, &birthday_list, list) {
        /* On each iteration ptr points to the next birthday struct*/
//        printk(KERN_ALERT "%s", "Formatting and number of list test");
        printk(KERN_ALERT "TEST LOOP: Birthday is %d/%d/%d", ptr->month, ptr->day, ptr->year);
    }
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        /* On each iteration ptr points to the next birthday struct*/
        printk(KERN_ALERT "TEST DELETING: Birthday %d/%d/%d", ptr->month, ptr->day, ptr->year);
        list_del(&ptr->list);
        kfree(ptr);
    }
    printk(KERN_ALERT "TEST: END_OF_INIT");
    return 0;   // Success return code. Exit code is required for module entry point.
}
//static int 
static void hello_exit(void) {
    printk(KERN_ALERT "TEST: Good bye");
    printk(KERN_ALERT "TEST: CLOSING");
    // Module Exit point doesn't accept any return codes
}

module_init(hello_init);
// Deallocate resources
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Practice Module");
MODULE_AUTHOR("Jun Yoo");