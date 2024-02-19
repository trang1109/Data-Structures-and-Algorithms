void addFirst(List &L, Node *a){
	if(L.first == NULL){
		L.first = L.last =a;
		L.last ->next= L.first;
	}
	else{
		a->next = L.first;
		L.last ->next= a;
		L.first = a;
	}
}
void addLast(List &L, Node *a){
	
	if(L.last== NULL){
		L.last= L.first=a;
		L.last->next= a;
	}else{
		L.last->next= a;
		a->next= L.first;
		L.last= a;
	}
}
void InsertLast(List &L, int x){
	Node *a = GetNode(x);
	if(a==NULL){
		printf("\nKhong du bo nho"); return;
	}else{
		addLast(L,a);
	}
	
}

void addAfter(List &L, Node *a, Node *p){
	if(L.first != NULL){
		p->next = a->next;
		a->next =p;
		if(a = L.last) L.last= p;
	}else return;
}
int removeFirst(List &L){
	if(L.first == NULL) return 0;
	Node *p= L.first;
	if(L.first = L.last)
		L.first = L.last = NULL;
	else{
		L.first = p->next;
		p->next = NULL;
		if(p== L.Last){
			L.last->next = L.first;
		}
		
	}
	delete(p);
	return 1;
}
int removeAfter(List L, Node *a){
	
	if(a == NULL) return 0;
	Node *b= a->next;
	if(a==b) {
		L.last= L.first = NULL;
	}
		
	else{
		a->next= b->next;
		b->next= NULL;
		if(b == L.last) L.last=a;
	}
	delete (b);
	return 1;
}
void outPut(const List L){
	if(L.first != NULL){
		Node *a= L.first;
		do{
			printf("%d\t",a->data);
			a=a->next;
		}while (a != L.first);
	}
}
