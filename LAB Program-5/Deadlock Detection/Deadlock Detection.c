#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\n");
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n], work[m], safeSeq[n];
    int count = 0;

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    for(i = 0; i < m; i++)
        work[i] = avail[i];

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(req[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
    {
        printf("\nSystem is in safe state\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);

            if(i != n - 1)
                printf(" -> ");
        }
    }
    else
    {
        printf("\nDeadlock detected!\n");
        printf("Processes in deadlock are: ");

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
                printf("P%d ", i);
        }
    }

    return 0;
}
