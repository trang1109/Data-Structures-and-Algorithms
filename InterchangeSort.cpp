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
void InterchangeSort (int a[],int n){
	for (int i=0; i<n-1;i++){
		for (int j=i+1; j<n;j++){
			if(a[i]> a[j]){
				int temp = a[i];
				a[i]= a[j];
				a[j] = temp;
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
	InterchangeSort(a,n);
	printf("Mang sau khi sap xep:\n");
	XuatMang(a,n);
    
}

