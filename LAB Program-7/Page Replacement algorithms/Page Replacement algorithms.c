#include <stdio.h>

void simulate(int p[], int n, int c, int mode)
{
    int f[20], faults = 0, next_fifo = 0;
    int last_used[20];

    for(int i = 0; i < c; i++)
    {
        f[i] = -1;
        last_used[i] = 0;
    }

    printf("\n%s Page Replacement:\n",
           mode == 0 ? "FIFO" :
           mode == 1 ? "Optimal" : "LRU");

    for(int i = 0; i < n; i++)
    {
        int found = -1, empty = -1;

        for(int j = 0; j < c; j++)
        {
            if(f[j] == p[i])
                found = j;

            if(f[j] == -1 && empty == -1)
                empty = j;
        }

        if(found != -1)
        {
            if(mode == 2)
                last_used[found] = i;
        }
        else
        {
            faults++;

            int rep = empty;

            if(rep == -1)
            {
                if(mode == 0)      /* FIFO */
                {
                    rep = next_fifo;
                    next_fifo = (next_fifo + 1) % c;
                }
                else if(mode == 1) /* Optimal */
                {
                    int farthest = -1;
                    rep = 0;

                    for(int j = 0; j < c; j++)
                    {
                        int next_use = 9999;

                        for(int k = i + 1; k < n; k++)
                        {
                            if(f[j] == p[k])
                            {
                                next_use = k;
                                break;
                            }
                        }

                        if(next_use > farthest)
                        {
                            farthest = next_use;
                            rep = j;
                        }
                    }
                }
                else               /* LRU */
                {
                    rep = 0;

                    for(int j = 1; j < c; j++)
                    {
                        if(last_used[j] < last_used[rep])
                            rep = j;
                    }
                }
            }

            f[rep] = p[i];

            if(mode == 2)
                last_used[rep] = i;
        }

        printf("Page %d -> ", p[i]);

        for(int j = 0; j < c; j++)
        {
            if(f[j] == -1)
                printf("- ");
            else
                printf("%d ", f[j]);
        }

        if(found == -1)
            printf("(Fault)");

        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);
}

int main()
{
    int p[50], n, frames;
    printf("Name : UPPALURI BALAJI REDDY\nUSN : 1BF24CS323\n\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(int m = 0; m < 3; m++)
        simulate(p, n, frames, m);

    return 0;
}
