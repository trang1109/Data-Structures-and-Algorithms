#include <stdio.h>

void XuatMang(int a[], int n){
    printf("\n");
    for(int i=0; i<n;i++){
        printf("%5d", a[i]);

    }
}
void InsertionSort(int a[], int n){
	int pos, x;
	for(int i=1; i<n; i++){
		x= a[i];
		pos=i-1;
		
		while(pos>=0 && a[pos]>x){
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}
int main(){
	int a1[]= {10, 3,7,4,2,8,5,12};
	int n= sizeof (a1)/ sizeof (a1[0]);
	XuatMang(a1,n);
	printf("\nMang sau khi sap xep la:\n");
	InsertionSort (a1,n);
	XuatMang(a1,n);
	printf("\nMang a2:\n");
	int a2[]= {14,33,27,10,35,19,42,44};
	int k= sizeof(a2)/ sizeof(a2[0]);
	XuatMang(a2,k);
	printf("\nMang sau khi sap xep la:\n");
	InsertionSort (a2,k);
	XuatMang(a2,k);
}
