#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ADT;
typedef struct N
{
   ADT data;
   struct N* next;
}Node;
typedef struct 
{
	Node *head,*tail;
	unsigned size;
}List;
List * init_list(List * lp)
{
	lp->head=lp->tail=(void*)0;
	lp->size=0;
	return lp;
}
Node* make_node(ADT d)
{
	Node *np=malloc(sizeof(Node));
	if(!np)
		return (void*)0;
	np->data=d;
	np->next=(void*)0;
    return np;
}

void print_list(const List* lp)
{	
	Node* cur=lp->head;
	if(cur)
	{
		printf("������%d������:%d",lp->size,cur->data);
		cur=cur->next;
		while(cur)
		{
			printf("->%d",cur->data);
			cur=cur->next;
		}
		printf("\n");
	}
	else
		printf("������\n");
}
void main(void){
//	printf("Hello World!\n");
	List list;
	printf("��ʼ��ǰ�����ͷָ��Ϊ0x%x,%x,%x\n",&list,list.head,list.tail);
	
	init_list(&list);
	printf("��ʼ���������ͷָ��Ϊ0x%x,%x,%x\n",&list,list.head,list.tail);

	Node* new_node = make_node(5);
	printf("1,%d",new_node);
	printf("�����½���������%d,ָ����%d\n",new_node->data,new_node->next);
	new_node->next = list.head;  //ͷ�������½��
	printf("1");
	list.head = new_node;       //ͷ�������½��
	if (list.tail==(void* )0)
		list.tail = list.head;
	printf("1");
	++list.size;
	printf("1");
	print_list(&list);
	printf("����һ��Ԫ�غ������ָ��Ϊ0x%x,ͷָ��%x,βָ��%x\n",&list,list.head,list.tail);
	printf("%x,%x\n",&list.size,&list.tail);

}
