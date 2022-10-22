#include "Data_Stucture.h"



/*
*	单链表
	Singly Linked List
*/


Listnode* CreateListByInput()//读取并创建链表
{
	Listnode* headPt = NULL;	//创建头指针,单链表的起点
	Listnode* tempPt = NULL;	//创建临时指针用于输入，首先指向头节点
	Listnode* tailPt = NULL;	//创建尾指针，标记单链表结束节点
	int nodeCount = 0;	//记录节点个数
	Item data;	//储存读入数据

	scanf("%d", &data);
	while (data > 0)
	{
		tempPt = (Listnode*)malloc(sizeof(Listnode));

		tempPt->data = data;
		nodeCount++;
		if (nodeCount == 1)
		{
			headPt = tempPt;
		}
		else {
			tailPt->next = tempPt;
		}
		tailPt = tempPt;
	}
	tailPt->next = NULL;	//尾节点的next值为null，代表单链表结束

	return headPt;
}
Listnode* CreateListByArray(Item* array, const int nodeNUM)//读取数组并创建链表
{
	Listnode* headPt = NULL;	//创建头指针,单链表的起点
	Listnode* tempPt = NULL;	//创建临时指针用于输入，首先指向头节点
	Listnode* tailPt = NULL;	//创建尾指针，标记单链表结束节点
	int nodeCount;	//记录节点个数

	if (array == NULL)
	{
		return NULL;
	}
	for (nodeCount = 1; nodeCount <= nodeNUM; nodeCount++)
	{
		tempPt = (Listnode*)malloc(sizeof(Listnode));

		tempPt->data = array[nodeCount-1];
		if (nodeCount == 1)
		{
			headPt = tempPt;
		}
		else {
			tailPt->next = tempPt;
		}
		tailPt = tempPt;
	}
	tailPt->next = NULL;
	return headPt;
}
int CountNode(Listnode* headPt)
{
	int nodeCount = 0;

	for (Listnode* temp = headPt; temp != NULL; temp = temp->next)
	{
		nodeCount++;
	}

	return nodeCount;
}
void PrintList(Listnode* headPt)
{
	if (headPt == NULL)
	{
		printf("ERROR\n");

		return;
	}
	for (Listnode* tempPt = headPt; tempPt != NULL; tempPt = tempPt->next)
	{
		printf("%d\n", tempPt->data);
	}
}
Listnode* ReverseListByIteration(Listnode* headPt)
{
	Listnode* prevPt = headPt;
	Listnode* tempPt = headPt->next;
	Listnode* nextPt;

	if (headPt == NULL || headPt->next == NULL)
	{
		return headPt;
	}
	prevPt->next = NULL;
	while (tempPt!=NULL)
	{
		nextPt = tempPt->next;
		tempPt->next = prevPt;
		prevPt = tempPt;
		tempPt = nextPt;
	}

	return prevPt;
}
Listnode* ReverseListByRecursive(Listnode* headPt)
{
	if (headPt == NULL || headPt->next == NULL)
	{
		return headPt;
	}
	else {
		Listnode* newheadPt = ReverseListByRecursive(headPt->next);

		headPt->next->next = headPt;
		headPt->next = NULL;

		return newheadPt;
	}
}
Listnode* ReverseListByInserting(Listnode* headPt)
{
	Listnode* newheadPt = NULL;
	Listnode* tempPt = NULL;

	if (headPt == NULL || headPt->next == NULL)
	{
		return headPt;
	}
	while (headPt != NULL)
	{
		tempPt = headPt;
		headPt = headPt->next;
		tempPt->next = newheadPt;
		newheadPt = tempPt;
	}

	return newheadPt;
}
Listnode* ReverseListByLocal(Listnode* headPt)
{
	Listnode* begPt = NULL;
	Listnode* endPt = NULL;

	if (headPt == NULL || headPt->next == NULL)
	{
		return headPt;
	}
	begPt = headPt;
	endPt = headPt->next;
	while (endPt != NULL)
	{
		begPt->next = endPt->next;
		endPt->next = headPt;
		headPt = endPt;
		endPt = begPt->next;
	}

	return headPt;
}
Item SearchDataInList(Listnode* headPt, Item data)
{
	Listnode* tempPt = headPt;

	for (int location = 1; tempPt != NULL; tempPt = tempPt->next, location++)
	{
		if (tempPt->data == data)
		{
			return location;
		}
	}

	return -1;
}
Listnode* DeleteNodeInList(Listnode* headPt, int location)
{
	Listnode* tempPt = headPt;
	Listnode* deletePt;

	if (location == 1)
	{
		deletePt = headPt;
		headPt = headPt->next;
		free(deletePt);
		return headPt;
	}
	for (int i = 1; i < location - 1; i++)
	{
		tempPt = tempPt->next;
	}
	deletePt = tempPt->next;
	tempPt->next = tempPt->next->next;
	free(deletePt);

	return headPt;
}
Listnode* InsertDataInList(Listnode* headPt, Item data, int location)
{
	if (location >= 1 && location <= CountNode(headPt) + 1)
	{
		Listnode* tempPt = headPt;
		Listnode* addPt = (Listnode*)malloc(sizeof(Listnode));

		if (location == 1)
		{
			addPt->data = data;
			addPt->next = tempPt;
			headPt = addPt;
			return headPt;
		}
		for (int i = 1; i < location - 1; i++)
		{
			tempPt = tempPt->next;
		}
		addPt->data = data;
		addPt->next = tempPt->next;
		tempPt->next = addPt;

		return headPt;
	}
	else {
		return NULL;
	}
}
Listnode* UpdateDataInList(Listnode* headPt, Item data, int location)
{
	if (location >= 1 && location <= CountNode(headPt))
	{
		Listnode* temp = headPt;

		for (int i = 1; i < location; i++)
		{
			temp = temp->next;
		}
		temp->data = data;

		return headPt;
	}
	else {
		return NULL;
	}
}



/*
	数组栈
	Stack in array
*/

int HeightOfStackArray(StackArray stack)//查询栈的高度
{
	return stack.topOfStack;
}
bool isFull(StackArray stack)//查询栈是否满了
{
	return stack.topOfStack == _STACK_SIZE - 1;
}
bool isStackArrayEmpty(StackArray stack)//查询栈是否空了
{
	return stack.topOfStack == -1;
}
bool PushDataToStackArray(StackArray stack, Item data)
{
	if (!isFull(stack))
	{
		stack.topOfStack++;
		stack.stack[stack.topOfStack] = data;

		return true;
	}
	else {
		return false;
	}
}
bool PopDataFromStackArray(StackArray stack, Item* data)
{
	if (!isStackArrayEmpty(stack))
	{
		*data = stack.stack[stack.topOfStack];
		stack.topOfStack--;

		return true;
	}
	else {
		return false;
	}
}




/*
	链表栈
	StackList
*/

StackList* CreateStackList(void)
{
	StackList* stackHead = (StackList*)malloc(sizeof(StackList));

	stackHead->next = NULL;

	return stackHead;
}
bool isStackListEmpty(StackList* stack)
{
	return stack->next == NULL;
}
bool PushDataToStackList(StackList* stack, Item data)
{
	StackList* temp = (StackList*)malloc(sizeof(StackList));

	if (temp == NULL)
	{
		return false;
	}
	temp->value = data;
	temp->next = stack->next;
	stack->next = temp;

	return true;
}
bool PopDataFromStackList(StackList* stack, Item* data)
{
	if (!isStackListEmpty(stack))
	{
		StackList* temp = stack->next;

		*data = stack->next->value;
		stack->next = stack->next->next;
		free(temp);
		temp = NULL;

		return true;
	}
	else {
		return false;
	}
}