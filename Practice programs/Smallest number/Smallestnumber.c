#include<stdio.h>
int main()
{
    int a[100];
    int n,k,p;
    printf("Enter no of numbers : ");
    scanf("%d",&n);
    printf("Enter numbers : \n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    k=a[0];
    for (int i=0;i<n;i++){
        if(a[i]<k){
            k=a[i];
            p=i;
        }
    }
    printf("The smallest number : %d \nAt pos : %d",k,p);
    return 0;
}
