
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
int LinearSearch(int a[], int n,int x){
	
 
	int i=0;
	while (i<n && a[i] !=x){										
		i++;
	}if (i<n) return i;
    return -1;
}
int main(){
	int a[100],n,x;
	printf("Nhap so phan tu cua mang: "); 
	scanf("%d", &n);
	PhatSinhMang(a,n);
	XuatMang(a,n);
	printf("\nNhap gia tri can tim: ");
	scanf("%d", &x);
	if(LinearSearch(a,n,x) == -1) 
		printf("Khong tim thay");
    else
		printf("Tim thay tai vi tri: %d",LinearSearch(a,n,x));
    
}
