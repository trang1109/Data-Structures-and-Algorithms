#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PhatSinhMang(int a[], int &n){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        a[i]= rand()%100;
    }
    
}
void XuatMang(int a[], int n){
    printf("\n");
    for(int i=0; i<n;i++){
        printf("%10d", a[i]);

    }
}
void BubbleSort (int a[],int n){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[j]<a[j-1]){
				int temp = a[j];
				a[j]= a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
int main(){
	int a[100],n,x;
	printf("Nhap so phan tu cua mang: "); 
	scanf("%d", &n);
	PhatSinhMang(a,n);
	XuatMang(a,n);
	BubbleSort(a,n);
	printf("\nMang sau khi sap xep:\n");
	XuatMang(a,n);
    
}
