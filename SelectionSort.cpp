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
void SelectionSort (int a[], int n)
{

    for (int i=0; i<n-1; i++)
    {

        int min=i;
        for (int j=i+1; j<n; j++)
            if(a[j]<a[min])
                min=j;

        if(min!=i)
        {
            int temp = a[i];
            a[i]= a[min];
            a[min]= temp;


        }

    }
}
int main()
{
    int a[100],n,x;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    PhatSinhMang(a,n);
    XuatMang(a,n);
    SelectionSort(a,n);
    printf("\nMang sau khi sap xep:\n");
    XuatMang(a,n);

}