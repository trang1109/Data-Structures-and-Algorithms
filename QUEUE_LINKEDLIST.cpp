#include <stdio.h>
struct Node{
	int data;
	Node *next;
};
struct Queue{
	Node *front;
	Node *rear;
};
void init(Queue &q){
	q.front=q.rear=NULL;
}
Node* GetNode(int x){
	Node *p= new Node;
	if(p == NULL){
		printf("Khong du bo nho"); return NULL;
	}
	 
	p->data=x;
	p->next= NULL;
	return p;
}
int isEmpty(Queue q){
	return (q.front == NULL)?1:0;
}

void enQueue(Queue &q, Node *a){
	if(isEmpty(q)==1){
		q.front= q.rear = a;
	}else{
		q.rear->next= a;
		q.rear =a;
	}
}
int enQueueX(Queue &q, int x){
	Node *a= GetNode(x);
	
	if(a!= NULL){
		enQueue(q,a);
		return 1;
	}
	return 0;
}
int DeQueue(Queue &q){
	int x;
	if(!isEmpty(q)){
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
int Front(Queue q){      	//Xem thong tin phan tu dau
	if(isEmpty(q)) return 1;
	return q.front->data;
}
void create_Queue(Queue &q){
	int x;
	printf("Nhap phan tu: ");
	do{
		scanf("%d", &x);
		if(x !=-1){
			enQueueX(q,x);
		}
	}while (x!=-1);
}
void print_Queue(Queue q){
	while(!isEmpty(q)){
		int x= DeQueue(q);
		printf("%d ", x);
	}
}
int main(){
	Queue q;
	init (q);
	create_Queue(q);
	printf("Xuat cac phan tu ra khoi Queue:\n");
	print_Queue(q);
	
	return 0;
	
}