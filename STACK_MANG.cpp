#include <stdio.h>
#define MAX 100
struct Stack{
	int a[MAX];
	int top;
};
void init(Stack &s){
	s.top= -1;
}
bool isEmpty(Stack s){
	return s.top<0;
}
bool isFull(Stack s){
	return s.top>=MAX -1;
}
void push(Stack &s, int x){
	if(!isFull(s)){
		s.a[++s.top]= x;
	}
}
int pop (Stack &s){
	if(!isEmpty(s)){
		return s.a [s.top--];
	}
}
void output(Stack s){
	for(int i=0; i<= s.top; i++){
		printf("%d\t",s.a [i]);
	}
}
int main(){
	Stack s;
	init (s);
	push(s,10);
	push(s,5);
	output(s);
}
