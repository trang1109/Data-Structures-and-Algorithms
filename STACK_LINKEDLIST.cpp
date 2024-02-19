#include <stdio.h>

struct Node{
	float data;
	Node *next;
};
struct Stack{
	Node *top;
};
void init(Stack &s){
	s.top= NULL;
}
bool isEmpty(Stack s){
	return (s.top == NULL);
}

void push(Stack &s, float x){
	Node *a= new Node;
	if(a== NULL){
		printf("Khong du bo nho"); return;
	}
	a->data= x;
	a->next = NULL;
	if(s.top == NULL)
		s.top= a;
	else{
		a->next= s.top;
		s.top= a;
	}	
}
void create_stack(stack &s){
	int x;
	do{
	printf("nhap data:");scanf("%d",&x);
	if(x!=-1)
		push(s,x);
	}while(x!=-1);
}
float pop (Stack &s){
	if(s.top == NULL){
		printf("\nStack rong");
		return;
	} 
	Node *a= s.top;
	a->next= NULL;
	float x= a->data;
	s.top= s.top->next;
	
	
	delete(a);
	return x;
}
void print_stack(stack s){
	while(s.top!=NULL){
		int x=pop(s);
		printf("%d ",x);
	}
}
int main(){
	Stack s;
	init(s);
	create_stack(s);
	print_stack(s);
	return 0;
}
