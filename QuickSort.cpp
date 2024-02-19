#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void PhatSinhMang(int a[], int &n)
{
    srand(time(NULL));
    for (int i=0; i<n; i++)
    {
        a[i]= rand()%100;
    }

}
void XuatMang(int a[], int n)
{
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("%10d", a[i]);

    }
} 
void swap (int &a, int &b){
	int temp= a;
	a=b;
	b=temp;
}
void QuickSort(int a[], int left, int right){
	
	int pilot= a[(left+right)/2];
	int l= left, r= right;
	do{
		while (a[l]<pilot)
			l++;
		while (a[r]>pilot)
			r--;
		if(l<=r){
			swap (a[l],a[r]);
			l++;
			r--;
			
		}	
		
	}while (l<=r);
	if(left<r) QuickSort(a,left,r);
	if(l<right) QuickSort (a, l,right);
}
int main()
{
    int a[100],n,x;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    PhatSinhMang(a,n);
    XuatMang(a,n);
    QuickSort(a,0,n-1);
    printf("\nMang sau khi sap xep:\n");
    XuatMang(a,n);
	printf("\n");
}