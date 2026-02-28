#include<stdio.h>
int main()
{
    int a[100];
    int n,k=0,m,h,l;
    printf("Binary search\n")
    printf("Enter no of numbers : ");
    scanf("%d",&n);
    printf("Enter numbers : \n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to search : ");
    scanf("%d",&k);
    l=0;
    h=n-1;
    while(l<=h){
        m=l+h/2;
        if(a[m]==k){
            printf("Element found.");
            return 0;
        }
        else if (a[m]>k){
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    printf("Element not found");
    return 0;
}
