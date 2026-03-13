#include<stdio.h>
int main()
{
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\nLower number ,Higher Priority\n");
    int p[100],at[100],bt[100],ct[100],tat[100],wt[100],n,c=0,a=0,b=0,pr[100],completed=0,rt[100];
    printf("Enter no of processes : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i]=i+1;
    }
    printf("Enter Arrival time,Burst  and priority of processes  (AT BT PR) \n ");
    for(int j=0;j<n;j++){
        printf("Process %d \n",j+1);
        scanf("%d%d%d",&at[j],&bt[j],&pr[j]);
        rt[j]=bt[j];
    }
    while(completed<n){
        int hp=1000,index=-1;
        for(int i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=c){
                if (pr[i]<hp){
                    hp=pr[i];
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
    printf(" Pid\tat\tbt\tpr\tct\ttat\twt\n");
   for(int i=0;i<n;i++){
    printf(" %d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
   }
   for(int i=0;i<n;i++){
    a=a+tat[i];
    b=b+wt[i];
   }

   printf("Avg Turn around time : %f \n Avg waiting time : %f",(float)a/n,(float)b/n);
    return 0;
}
