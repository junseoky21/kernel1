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
    printk(KERN_ALERT "TEST: Hello World, this is Jun");
    struct birthday *person;
    person = kmalloc(sizeof(*person), GFP_KERNEL);
    person->day = 2;
    person->month = 8;
    person->year = 
    return 0;
}
//static int 
static void hello_exit(void) {
    printk(KERN_ALERT "TEST: Good bye");
}

module_init(hello_init);
// Deallocate resources
module_exit(hello_exit);
