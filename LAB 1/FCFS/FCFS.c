#include<stdio.h>
int main()
{
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\n");
    int p[100],at[100],bt[100],ct[100],tat[100],wt[100],rt[100],n,g[100],c=0,a=0,b=0;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    printf("Enter Arrival time and Burst time of processes  (AT BT) \n ");
    for(int j=0;j<n;j++){
            printf("Process %d \n",j);
        scanf("%d%d",&at[j],&bt[j]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                int t;
                t=at[i];
                at[i]=at[j];
                at[j]=t;
                t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;
                t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    c=0;

    for (int i=0;i<n;i++){
        if(c<at[i]){
            c=at[i];
        }
        ct[i]=c+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        c=ct[i];

    }
   printf(" Pid\tat\tbt\tct\ttat\twt\n");
   for(int i=0;i<n;i++){
    printf(" %d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
   }
   for(int i=0;i<n;i++){
    a=a+tat[i];
    b=b+wt[i];
   }

   printf("Avg Turn around time : %d \n Avg waiting time : %d",a/n,b/n);
    return 0;
}


