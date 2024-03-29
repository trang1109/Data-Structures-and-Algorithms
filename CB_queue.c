#include <stdio.h>
struct Node{
	int data;
	Node *next;	
};
struct Queue{
	Node *front,*rear;	
};
void Init(Queue &q);
int is_empty(Queue q);
void EnQueue(Queue &q,Node *new_node);
int EnQueue_data(Queue &q,int x);
void create_Queue(Queue &q);
int DeQueue(Queue &q);
Node *GetNode(int x);
void print_Queue(Queue q);
int main(int argc, char *argv[])
{
	Queue q;
	Init(q);
	create_Queue(q);
	print_Queue(q);
	return 0;
}
void Init(Queue &q){
	q.front=q.rear=NULL;
}
int is_empty(Queue q){
	if(q.front==NULL)
		return 1;
	return 0;	
}
Node *GetNode(int x){
	Node*p;
	p=new Node;
	if(p==NULL){
		printf("khong thanh cong!");return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
void EnQueue(Queue &q,Node *new_node){
	if(is_empty(q)==1)
		q.front=q.rear=new_node;
	else
	{
		q.rear->next=new_node;q.rear=new_node;		
	}	
}
int EnQueue_data(Queue &q,int x){
	Node *new_node=GetNode(x);
	if(new_node!=NULL){
		EnQueue(q,new_node);return 1;
	}
	return 0;
}
void create_Queue(Queue &q){
	int x;
	do{
		printf("nhap data:");scanf("%d",&x);
		if(x!=-1)
			EnQueue_data(q,x);
	}while(x!=-1);
}
int DeQueue(Queue &q){
	int x;
	if(!is_empty(q)){
		Node *p=q.front;
		q.front=q.front->next;
		p->next=NULL;
		x=p->data;
		delete(p);
		return x;
	}
	else{
		return -1;
	}
		
}
void print_Queue(Queue q){
	while(!is_empty(q)){
		int x=DeQueue(q);printf("%d ",x);		
	}	
}