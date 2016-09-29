#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Node_list.h"

int isNotEmpty(List list);
void deleteOne(List list);
Position findPreviousName(char *ch, List list);
Position findPreviousRank(size_t s, List list);

void list_test()
{
	struct node n0 = { "xshuo",4,"1987576327",8856.66};
	struct node n1 = { "signif",3,"13001116456",9856.56,&n0 };
	struct node n2 = { "sun",2,"18766442234",7821.5 ,&n1};
	struct node n3 = {"wchao",1,"18353114613",9653.85,&n2};
	List list = &n3;
	Position p = findPreviousName("wchao", list);
	//Position p = findPreviousRank(3, list);
	//printf("%u", p->rank);
	int flag = isNotEmpty(list);
	//printf("%d",flag);

	deleteOne("sun", list);
	printf("%u", list->next->rank);


}

int isNotEmpty(List list)
{
	if (list->next != NULL)
		return 1;
	return 0;
}

Position findPreviousName(char *ch,List list)
{
	Position p;
	p = list;
	while (p->next != NULL  &&  p->next->name != ch)
		p = p->next;
	return p;
}

Position findPreviousRank(size_t s, List list)
{
	//必须要首先判断是空，否则还是执行下一步查找工作，未定义行为报错
	Position p;
	p = list;
	while (p->next != NULL  &&  p->next->rank != s)
		p = p->next;
	return p;
}

void deleteOne(char *ch,List list)
{
	Position p,tmp;
	p = findPreviousName(ch, list);
	tmp = p->next;
	p->next = tmp->next;
	free(tmp);

}

void signif()
{
	list_test();
}
