#include<stdio.h>
int main()
{
    int a[100];
    int n,k=0;
    printf("Enter no of numbers : ");
    scanf("%d",&n);
    printf("Enter numbers : \n");
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<=n;j++){
            if (a[i]==a[j]){
                printf("Yes,There are duplicates");
                return 0;
            }
        }
    }
    printf("NO Duplicates");
    return 0;
}
