#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 5000

char adj[max][max];
int indegree[max], outdegree[max];

int main() {
    int sz[] = {1000, 2000, 3000, 4000, 5000};
    int sz_num = 5;
    int i, j, k;

    srand((unsigned int)time(NULL));

    // Loop for each value of n
    for (k = 0; k < sz_num; k++) {
        int n = sz[k];

        // STEP 1: Reset the used portion of the 2D array
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }

        // STEP 2: Generate random directed graph
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j) {   // no self-loop
                    if (rand() % 100 < 50) {   // Edge possibility 50%
                        adj[i][j] = 1;
                    }
                }
            }
        }

        for (i = 0; i < n; i++) {
            indegree[i] = 0;
            outdegree[i] = 0;
        }

        // Calculation
        clock_t start = clock();
        long long in_sum = 0, out_sum = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (adj[i][j] == 1) {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        for (i = 0; i < n; i++) {
            in_sum += indegree[i];
            out_sum += outdegree[i];
        }

        long long edge_c = out_sum;   // number of directed edges
        clock_t end = clock();

        double runtime = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;

        printf("\nFor n = %d, \n", n);
        printf("Number of edges       : %lld\n", edge_c);
        printf("Sum of in-degrees     : %lld\n", in_sum);
        printf("Sum of out-degrees    : %lld\n", out_sum);

        if (in_sum == out_sum && out_sum == edge_c)
            printf("Directed Graph Logic  : HOLDS\n");
        else
            printf("Directed Graph Logic  : FAILED\n");

        printf("Computational time    : %.3f ms\n", runtime);
    }

    printf("______________________\n");
    printf("Complete.\n");

    return 0;
}
