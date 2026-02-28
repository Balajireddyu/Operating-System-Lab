#include<stdio.h>
int main()
{
    int a[100];
    int n,k,f=0;
    printf("Enter no of numbers : ");
    scanf("%d",&n);
    printf("Enter numbers : \n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to search : ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(a[i]==k){
            printf("Element found.");
            return 0;
        }
    }
    printf("Element not found.");
    return 0;
}