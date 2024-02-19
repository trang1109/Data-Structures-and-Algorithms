#include <stdio.h>
struct Node{
	int data;
	Node *left,*right;
};
typedef struct Node* Tree;
void Init(Tree &r);
Node *GetNode(int x);
void creat_tree(Tree &r);
void LNR(Tree r);
int dem_node_la(Tree r);
int tim_kiem(Tree r,int x);
int dem_node(Tree r);
int chieucao(Tree r);
int xoa_node(Tree &r,int x);
int main(int argc, char *argv[])
{
	Tree root;//Node *root
	Init(root);
	creat_tree(root);
	LNR(root);
	int x,chon;
	while(1){
	printf("nhap gia tri can xoa:");scanf("%d",&x);
	if(xoa_node(root,x)==1)
		printf("da xoa!");
	else
		printf("khong co node nay!");
	LNR(root);
	printf("co xoa nua k?");scanf("%c",&chon);
	if(chon==0)
		break;
	}
	
/*
	int x;
	printf("nhap gia tri can tim:");scanf("%d",&x);
	if(tim_kiem(root,x)==1)
		printf("thay!");
	else
		printf("khong!");
		
	printf("\ntong so node:%d va co %d note la",dem_node(root),dem_node_la(root));
	printf("\nchieu cao cua cay:%d",chieucao(root));
	*/
	return 0;
}
void Init(Tree &r){
	r=NULL;
}

Node *GetNode(int x){
	Node *p;
	p=new Node;
	if(p==NULL){
		printf("khong du bo nho de tao!");return NULL;
	}
	p->data=x;p->left=NULL;p->right=NULL;
	return p;
}
int insert_Node(Tree &r,int x){
	if(r==NULL){
		r=GetNode(x);return 1;
	}
	else
		if(r->data==x)
			return -1;
		else
			if(r->data>x)
				return insert_Node(r->left,x);
			else
				return insert_Node(r->right,x);
}
void creat_tree(Tree &r){
	int x;
	do{
		printf("nhap x:");scanf("%d",&x);
		if(x!=0){
			int kt=insert_Node(r,x);
			if(kt==-1)
				printf("khong chen dc!");
		}			
	}while(x!=0);
}
void LNR(Tree r){
	if(r!=NULL){
		LNR(r->left);
		printf("%d ",r->data);
		LNR(r->right);
	}
}
int dem_node_la(Tree r){
	if(r!=NULL){
		if(r->left==NULL&&r->right==NULL)
			return 1;
		return dem_node_la(r->left)+dem_node_la(r->right);
	}	
	else
		return 0;	
}
int tim_kiem(Tree r,int x){
	if(r!=NULL)
		if(r->data==x)
			return 1;
		else
			if(x<r->data)
				return tim_kiem(r->left,x);
			else
				return tim_kiem(r->right,x);
	else
		return -1;
}
int dem_node(Tree r){
	if(r!=NULL)
		return 1+dem_node(r->left)+dem_node(r->right);
	else
		return 0;
}
int chieucao(Tree r){
	if(r==NULL)
		return 0;
	int a=chieucao(r->left);
	int b=chieucao(r->right);
	if(a>b)
		return a+1;
	else
		return b+1;
}
int xoa_node(Tree &r,int x){
	if(r==NULL) return 0;
	else if(r->data>x) return xoa_node(r->left,x);
	else if(r->data<x) return xoa_node(r->right,x);
	else{//r->data=x, xoa r
		Node *p=r;
		if(r->left==NULL) {r=r->right;return 1;}//node xoa chi co cay co phai			
		else if(r->right==NULL) {r=r->left;return 1;}//node chi co cay con trai
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
// 6 9 7 2 3 4 5 1 14 12 10

