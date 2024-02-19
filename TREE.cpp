#include <stdio.h>
struct Node{
	int data;
	Node *left;
	Node *right;
};
typedef struct Node* Tree;
void Init(Tree &t);
Node* GetNode(int x);
void InsertNodeKhongDeQuy(Tree &t,int x);
int InsertNodeDeQuy(Tree &t,int x);
void CreateTree(Tree &t);
int SearchNodeDeQuy(Tree t, int x);
void Counter(Tree t, int &n1, int &n2, int &n3);
int dem_node(Tree t);
int DemSoNutNhoHonX(Tree t, int x);
int Height(Tree t);
void ShowK(Tree t, int k, int expected);
Node* SearchNodeKhongDeQuy(Tree t, int x);
int deleteNode(Tree &t, int x);
void NLR(Tree t);
void LNR(Tree t);
void LRN(Tree t);
int main(){
	int chon;
	int n1=0, n2=0, n3=0;
	int x;
	Tree t;
	Init(t);
	do{
		
		printf("\n1. Tao danh sach\n2.In danh sach\n3. Tim phan tu\n4. Dem so nut la\n5. In nut o muc K\n6. Tinh chieu cao\n7. Tong so nut\n8.So nut nho hon x\n9.Xoa nut\n10.Thoat\nNhap lua chon: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: 
				CreateTree(t);
				break;
			case 2:
				LNR(t);
				break;
			case 3:
				printf("\nNhap gia tri can tim: ");
				scanf("%d", &x);
				if(SearchNodeKhongDeQuy(t,x) !=NULL){
					printf("\nTim thay");
				}else{
					printf("\nKhong tim thay");
				}
				break;
			case 4: 
				
				Counter(t,n1, n2, n3);
				printf("\nSo nut la: %d", n1);
				printf("\nSo nut 1 cay con: %d", n2);
				printf("\nSo nut hai cay con: %d", n3);
				break;
			case 5: 
				printf("\nChieu cao cua cay la: %d", Height(t));
				break;
			case 6:
				int expected;
				printf("\nNhap muc can in: ");
				scanf("%d", &expected);
				printf("\nCac nut o muc can in: ");
				ShowK(t,-1, expected );
				break;
			case 7:
				printf("\nTong so nut: %d", dem_node(t));
				break;
			case 8:
				printf("Nhap gia tri x can so sanh: "); scanf("%d", &x);
				printf("Tong so cac nut nho hon x la: %d", DemSoNutNhoHonX(t, x));
			case 9:
				printf("\nNhap gia tri can xoa: ");
				scanf("%d", &x);
				if(deleteNode(t,x)==0){
					printf("\nKhong tim thay gia tri can xoa");
				}else{
					printf("\nDanh sach sau khi xoa:");
					LNR(t);
				}
				break;
			case 10:
				break;
		};
		if (chon ==10) break;
	}while(1);
	
}
void Init(Tree &t){
	t= NULL;
}
Node* GetNode(int x){
	Node *p= new Node;
	if(p==NULL){
		printf("Khong du bo nho"); return NULL;
	}else{
		p->data= x;
		p->left= NULL;
		p->right= NULL;
		return p;
	}
}
int InsertNodeDeQuy(Tree &t,int x){	//De quy
	if(t== NULL){
		t= GetNode(x); return 1;
	}else{
		if(t->data== x){
			return -1;
		}else if(t->data >x){
			return InsertNodeDeQuy(t->left,x);
		}else{
			return InsertNodeDeQuy(t->right,x);
		}
	}
}
//void CreateTree(Tree &t){ //De Quy
//	int x;
//	do{
//		printf("\nNhap x: ");
//		scanf("%d", &x);
//		if(x != -1){
//			int check= InsertNodeDeQuy(t,x);
//			if(check==-1) printf("Khong chen duoc");
//			
//		}
//	}while(x !=-1);
//}
void InsertNodeKhongDeQuy(Tree &t, int x){ 	//Khong de quy
	if (t== NULL){
		t= GetNode(x); 
	}else{
		Node *parent = NULL;
		Node *p= t;
		while(p != NULL && p->data != x){
			parent=p;
			if(p->data >x){
				p= p->left;
			}else{
				p= p->right;
			}
		}
		if(p== NULL){
			p= GetNode(x);
			if(parent->data >x){
				parent->left=p;
			}else{
				parent->right=p;
			}
			
		}
	}
}
void CreateTree(Tree &t){ 	//Khong De Quy
	int x;
	do{
		printf("\nNhap x: ");
		scanf("%d", &x);
		if(x != -1){
			InsertNodeKhongDeQuy(t,x);
			
		}
	}while(x !=-1);
}
//bool InsertNodeKhongDeQuy(Tree &t, int x){ 	//Khong de quy bool
//	if (t== NULL){
//		t= GetNode(x); return true;
//	}else{
//		Node *parent = NULL;
//		Node *p= t;
//		while(p != NULL && p->data != x){
//			parent=p;
//			if(p->data >x){
//				p= p->left;
//			}else{
//				p= p->right;
//			}
//		}
//		if(p== NULL){
//			p= GetNode(x);
//			if(parent->data >x){
//				parent->left=p;
//			}else{
//				parent->right=p;
//			}
//			return true;
//		}else{
//			return false;
//		}
//	}
//}
//void CreateTree(Tree &t){ 	//Khong De Quy bool
//	int x;
//	do{
//		printf("\nNhap x: ");
//		scanf("%d", &x);
//		if(x != -1){
//			bool check= InsertNodeKhongDeQuy(t,x);
//			if(check==false) printf("Khong chen duoc");
//			
//		}
//	}while(x !=-1);
//}


int SearchNodeDeQuy(Tree t, int x){	//de quy
	if(t==NULL) return -1;
	else{
		if(t->data == x){
			return 1;
		}else if(t->data >x){
			return SearchNodeDeQuy(t->left, x);
		}else{
			return SearchNodeDeQuy(t->right, x);
		}
			
	}
}
Node* SearchNodeKhongDeQuy(Tree t, int x){
	
	while(t!= NULL && t->data!=x){
		if(t->data>x){
			t=t->left;
		}else{
			t=t->right;
		}
	}
	return t;
}
void Counter(Tree t, int &n1, int &n2, int &n3){
	if(t != NULL){
		Counter(t->left, n1, n2,n3);
		if(t->left == NULL && t->right== NULL){
			n1++;
		}else if(t->left == NULL || t->left == NULL){
			n2++;
		}else{
			n3++;
		}
		Counter(t->right, n1,n2, n3);
		
	}
}
int dem_node(Tree t){
	if(t!=NULL)
		return 1+dem_node(t->left)+dem_node(t->right);
	else
		return 0;
}
int DemSoNutNhoHonX(Tree t, int x){
	if(t!=NULL){
		if(t->data <x){
			return 1+DemSoNutNhoHonX(t->left,x)+DemSoNutNhoHonX(t->right,x);
		}
		else
			return 0;
	}
		
	
}
int Height(Tree t){
	if(t!= NULL){ 
		int left= 1+ Height(t->left);
		int right= 1+ Height(t->right);
		return left> right? left: right;
	}
	return 0;
}
void ShowK(Tree t, int k, int expected){
	if(t!= NULL){
		k++;
		ShowK(t->left, k, expected);
		if(k== expected){
			printf("%d ", t->data);
		} 
		ShowK(t->right, k, expected);
	}
}
int deleteNode(Tree &t, int x){
	if(t==NULL) return 0;
	else if(t->data>x) return deleteNode(t->left,x);
	else if(t->data<x) return deleteNode(t->right,x);
	else{
		Node *p=t;
		if(t->left==NULL) {t=t->right;return 1;}//node xoa chi co cay co phai			
		else if(t->right==NULL) {t=t->left;return 1;}//node chi co cay con trai
		else{//node co ca 2 con
			Node *s=p,*q=p->left;
			if(q->right!=NULL){
				while(q->right!=NULL){
					s=q;
					q=q->right;
				}
				p->data=q->data;s->right=q->left;
				delete q;
				return 1;
			}
			else{
				p->data=q->data;p->left=q->left;delete q;return 1;
			}			
			
		}
			
	}
		
}
//void deleteNode(Tree &t, int x){
//	if(t!= NULL){
//		Node *p=t;
//		Node *parent= NULL;
//		while(p!= NULL && p->data!=x){
//			parent=p;
//			if(p->data>x){
//				p=p->left;
//			}else{
//				p=p->right;
//			}
//		}
//		if(p!= NULL){
//			//Xoa nut 2 con
//			if(p->left != NULL && p->right != NULL){
//				Node *r= p->right;
//				while(r->left != NULL){
//					parent=r;
//					r=r->left;
//				}
//				p->data=r->data;
//				p=r;
//			}
//			//xoa nut la hoac nut co mot cay con 
//			Node *t;
//			if(p->right==NULL){
//				t=p->left;
//			}else if(p->left==NULL){
//				t=p->right;
//			}
//			if(parent->data> p->data){
//				parent->left=t;
//			}else{
//				parent->right=t;
//			}
//			delete(p);
//		}
//	}
//}
void NLR(Tree t){
	if(t != NULL){
		printf("%d ", t->data);
		NLR(t->left);
		NLR(t->right);
	}
}
void LNR(Tree t){
	if(t != NULL){
		
		LNR(t->left);
		printf("%d ",  t->data);
		LNR(t->right);
	}
}
void LRN(Tree t){
	if(t != NULL){
		
		LRN(t->left);
		LRN(t->right);
		printf("%d ",  t->data);
	}
}

