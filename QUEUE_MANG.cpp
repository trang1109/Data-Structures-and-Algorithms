#include <stdio.h>
#define max 100
struct Queue{
	int list[max];
	int n;
	int front, rear;
};
void init(Queue &q){
	q.front= 0;
	q.rear= max-1;
	q.n=0;
}
bool isEmpty(Queue q){
	return (q.n ==0);
}
bool isFull(Queue q){
	return (q.n == max);
}
int enQueue(Queue &q, int x){
	if(isFull(q)) return 0;
	q.rear = (q.rear+1) % max;
	q.list[q.rear] = x;
	q.n++;
	return 1;
}
int deQueue (Queue &q){
	if(!isEmpty(q)) {
		int x= q.list[q.front];
		q.front = (q.front+1) % max;
		
		q.n--;
		return x;
	}
	
	
}
