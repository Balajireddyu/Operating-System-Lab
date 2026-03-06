#include<stdio.h>
int main()
{
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\n");
    int p[100],at[100],bt[100],ct[100],tat[100],wt[100],rt[100],n,g[100],c=0,a=0,b=0,f[100]={0},completed=0;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    printf("Enter Arrival time and Burst time of processes  (AT BT) \n ");
    for(int j=0;j<n;j++){
        printf("Process %d \n",j);
        scanf("%d%d",&at[j],&bt[j]);
        rt[j]=bt[j];
    }
    while(completed<n){
        int Remainingtime=1000,index=-1;
        for(int i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=c){
                if (rt[i]<Remainingtime){
                    Remainingtime=rt[i];
                    index=i;
                }
            }
        }
        if(index==-1){
            c++;
        }
        else{
            int i=index;
            rt[i]--;
            c++;
            if (rt[i]==0){
                ct[i]=c;
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
                completed++;
            }
        }
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
