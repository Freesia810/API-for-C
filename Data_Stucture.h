#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0
typedef int Item;
typedef int bool;



/*
*	单链表
	Singly Linked List
*/


//结点结构体声明
struct Listnode {
	Item data;
	struct Listnode* next;
};
typedef struct Listnode Listnode;

//单链表操作
Listnode* CreateListByInput();//读取并创建链表
Listnode* CreateListByArray(Item* array, const int nodeNUM);//读取数组并创建链表
int CountNode(Listnode* headPt);//计算链表的节点数
void PrintList(Listnode* headPt);//输出链表
Listnode* ReverseListByIteration(Listnode* headPt);//迭代法反转单链表
Listnode* ReverseListByRecursive(Listnode* headPt);//递归法反转单链表
Listnode* ReverseListByInserting(Listnode* headPt);//插入法反转单链表
Listnode* ReverseListByLocal(Listnode* headPt);//直接逆置法反转单链表
Item SearchDataInList(Listnode* headPt, Item data);//查找指定数据的节点位置
Listnode* DeleteNodeInList(Listnode* headPt, int location);//删除指定节点
Listnode* InsertDataInList(Listnode* headPt, Item data, int location);//向指定节点插入数据
Listnode* UpdateDataInList(Listnode* headPt, Item data, int location);//更新指定节点数据









/*
	栈
	Stack
*/



/*
	数组栈
	Stack in array
*/

#define _STACK_SIZE 100	//栈的高度
#define _TOP_OF_STACK -1  //栈的顶部

//数组栈结构体声明
struct StackArray
{
	int topOfStack;
	Item stack[_STACK_SIZE];
};
typedef struct StackArray StackArray;

//数组栈操作
int HeightOfStackArray(StackArray stack);//查询栈的高度
bool isFull(StackArray stack);//查询栈是否满了
bool isStackArrayEmpty(StackArray stack);//查询栈是否空了
bool PushDataToStackArray(StackArray stack, Item data);//将指定数据压入栈中
bool PopDataFromStackArray(StackArray stack, Item* data);//数据出栈



/*
	链表栈
	StackList
*/

//链表栈结构体声明
struct StackList
{
	Item value;
	struct StackList* next;
};
typedef struct StackList StackList;

//链表栈操作
StackList* CreateStackList(void);//创建链表栈
bool isStackListEmpty(StackList* stack);//查询栈是否空了
bool PushDataToStackList(StackList* stack, Item data);//将指定数据压入栈中
bool PopDataFromStackList(StackList* stack, Item* data);//数据出栈
