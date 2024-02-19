#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PhatSinhMang(int a[], int &n){
	srand(time(NULL));
	for(int i=0; i<n;i++){
		a[i]= rand()%100;
	}
}
void XuatMang (int a[], int n){
	printf("\n");
	for(int i=0; i<n;i++){
		printf("%10d", a[i]);
	}
}
int BinarySearch (int a[], int n, int x){
	int left=0;
	int right=n-1;
	int mid;
	while (left <= right){
		mid= (left + right)/2;
		if (a[mid]==x) return mid;
		else if (a[mid] >x)
			right=mid-1;
		else
			left = mid +1;
	}
	return -1;
}
int main(){
	int a[100], n,x;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while (n>100);
	PhatSinhMang(a,n);
	XuatMang(a,n);
	printf("\nNhap gia tri can tim: ");
	scanf("%d", &x);
	int kq =BinarySearch(a,n,x);
	if (kq ==-1) printf ("\nKhong tim thay x\n");
	else printf("\nTim thay x tai vi tri: %d\n", kq);
	return 0;
}
	
	
