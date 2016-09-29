#pragma once
//#define NodeSize 20

struct node;

typedef struct node *ptrNode;
typedef ptrNode List;
typedef ptrNode Position;

//int isEmpty(List list);


//结构体的定义
struct node {
	//char name[NodeSize];
	//这里无法使用字符串数组，因为后面空格也站字符串数组，所以会导致失败
	char *name;
	size_t rank;
	//char phone[NodeSize];
	char *phone;
	double salary;
	Position next;
};
