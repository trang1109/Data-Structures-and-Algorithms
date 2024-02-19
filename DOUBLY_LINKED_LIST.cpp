#include <stdio.h>


struct Node
{
	int data;
	Node * next;
	Node *prev;
};

struct List
{
	Node * first;
	Node * last;
		
};
Node *GetNode(int x){
	Node *p=new Node;
	if(p==NULL){
		printf("khong thanh cong");
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	p->prev=NULL;
	return p;
}

void Init (List &L)
{
	L.first = L.last = NULL;	
}
void addFirst(List &L, Node *p){
	if(L.first= NULL){
		L.first= L.last=p;
	}else{
		p->next=L.first;
		L.first->prev=p;
		L.first=p;
	}
}

void InsertFirst(List &L, int x){
	Node *a = GetNode(x);
	if(a==NULL){
		printf("\nKhong du bo nho"); return;
	}else{
		addFirst(L,a);
	}
	
}

void addLast(List &L, Node *p){
	if(L.first == NULL)
		L.first = L.last = p;
	else
		{	L.last ->next = p;
			p->prev= L.last;
			L.last = p;
		}
}

Node* InsertLast(List &L, int x){
	Node *p= GetNode (x);
	if(p==NULL) return NULL;
	
	addLast(L,p);
	return p;
} 
void create_List(List &L){
	int x;
	do{
		printf("nhap data:");scanf("%d",&x);
		if(x!=-1){
			
			InsertLast(L,x);
		}
	}while(x!=-1);
}



void addAfter(List &L, int v, int x){		//Chen sau vi tri v
	
	Node *a= L.first;
	while(a != NULL && a->data !=v){
		a= a->next;
	}
	if(a!= NULL){
		if(a == L.last)
			addLast (L,a);
		else{
			Node *p= GetNode(x);
			p->next = a->next;
			a->next->prev=p;
			a->next =p;
			p->prev = a;
			
		}
	}
}
void add_After(List &L, Node *a, Node *p){			//Chen sau Node
	Node *b= a->next;
	if (a!= NULL){
		a=a->next;
		if(b!= NULL) b->prev= p;
		p->next = b;
		p->prev=a;
		a->next=p;
		if(a== L.last) L.last=p;
	}else{
		addLast(L,p);
	}
}
void InsertAfter(List &L, Node *a, int x)	//Chen sau Node
{	Node *p = GetNode(x);
	if (p ==NULL)  return NULL;
	Add_After(L, a,p);
}
void addBefore(List &L, Node *a, Node *p){
	Node *b= a->prev;
	if(a != NULL){
		p->next=a;
		a->prev=p;
		p->prev=b;
		if (b!= NULL) b->next=p;
		if(a == L.first) L.first=p;
	}
}
int removeFirst(List &L){
	if(L.first!= NULL){
	
		Node *p = L.first;
		if(p -> next == NULL){
			L.first = L.last= NULL;
		}else{
			L.first = L.first->next;
			p->next->prev= NULL;
			
			p->next = NULL;
		}
		delete(p);
		return 1;
	}
	return 0;
}
int removeLast (List &L){
	if(L.first == NULL) return 0;
	Node *p= L.last;
	if(p ->prev == NULL){
		L.first = L.last = NULL;
	}
		
	else{
		p-> prev-> next= NULL;
		L.last = p->prev;
		p->prev= NULL;
	}
	delete(p);
}
int removeAfter(List &L, Node *a){
	
	if(a == NULL) return 0;
	Node *b= a->next;
	if(b!= NULL){
		a->next = b->next;
		if(b== L.last) L.last = a;
		else b->next->prev= a; 
		delete (b);
		return 1;
	}
	else return 0;
}
int removeBefore(List &L, Node *a){
	if(a== NULL) return 0;
	Node *b= a->prev;
	if(b!= NULL){
		a-> prev = b->prev;
		if (b == L.first) L.first = a;
		else b-> prev->next = a;
		delete (b);
		return 1;
	}
	else return 0;
}
int removeNode(List &L, int k){
	Node *a= L.first;
	while (a != NULL){
		if(a->data == k) break;
		a=a->next;
	}
	if (a== NULL) return 0;
	Node *b=a->prev;
	if (b == NULL)
		removeFirst(L);
	else
		removeAfter(L,b);
}
void remove_PreNode(List&l,Node*q){			//Xoa truoc Node
	if(l.first->data==q->data)
		{
			printf("khong xoa");return;
		}
	else
		if(l.first->next->data==q->data)
			removeFirst(l);
		else{
			Node*p=l.first;
			while(p!=NULL&&p->data!=q->data)
				p=p->next;
			if(p==NULL)
			{
				printf("khong xoa");return;
			}
			else{
				Node*t=p->pre;
				t->pre->next=p;p->pre=t->pre;
				t->next=NULL;t->pre=NULL;
				delete(t);
			}
		}		
}
void PrintListLeftToRight (List L)
{
	Node*p=L.first;
	printf("\nin danh sach:");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
		

int main(){
	List L;
	Init (L);
	create_List(L);
	PrintListLeftToRight(L);
	int x;printf("nhap gia tri cua node can xoa sau:");scanf("%d",&x);
	Node*q=GetNote(x);
	remove_After(ds,q);
	
	
}
