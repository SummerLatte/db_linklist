/*
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Library General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc.
#
# See the COPYING file for license information.
#
#Copyright (c) 2013  sim szm <xianszm007@gmail.com>
*/

/*
#This is the head file of the db_linklist.It include the dependent head file,
#define the struct of the list and the node,and declare functions. 
#这是链表的头文件。它包含了所依赖的头文件，定义里表和节点的结构体，声明所实现的函数
*/
#ifndef DB_LINKLIST_H
#define DB_LINKLIST_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

//struct of node
//数据的结构体
typedef struct db_lnode{
	void* data;                   //a void pointer to data  指向数据的空指针
	struct db_lnode* prev;   	  //a struct pointer to previous node  指向前一个结点的结构体指针
	struct db_lnode* next;
}db_lnode_t;

//struct of list
//表的结构体
typedef struct db_list{
	int limit_size;               //describe the max size of the list  描述这个表的最大值 
	db_lnode_t* head;             //a struct pointer to the head of the list 指向一个表头的结构体指针
	db_lnode_t* tail;
}db_list_t;

db_list_t* db_list_create(void );
static inline int __db_list_insert_before(db_list_t** ,int ,void* );
static inline int __db_list_insert_after(db_list_t** ,int ,void* );
static inline void __db_lnode_flush(db_list_t* ,int ,void* );
static inline void __db_list_delete(db_list_t** ,int );
static inline void __db_list_destory(db_list_t* );
static inline void* __db_list_visit(db_list_t** ,int );
static inline void __db_list_travel(db_list_t* ,void(*do_function)(void* ));
static inline int __db_list_search(db_list_t** ,void* ,int(*compare)(void* ,void* ));

#endif
