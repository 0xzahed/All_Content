#include <stdio.h>
#include <stdbool.h>

#define P 5
#define R 3

bool isSafe(int available[], int max[P][R], int allocation[P][R])
{
    int work[R];
    bool finished[P] = {0};
    int safeSequence[P];
    int index = 0;

    for (int i = 0; i < R; i++)
        work[i] = available[i];

    int processCount = 0;
    while (processCount < P) {
        bool found = false;

        for (int p = 0; p < P; p++)
            {
            if (!finished[p])
             {
                bool canProceed = true;

                for (int r = 0; r < R; r++) {
                    if (max[p][r] - allocation[p][r] > work[r]) {
                        canProceed = false;
                        break;
                    }
                }

                if (canProceed)
                    {
                    for (int r = 0; r < R; r++)
                        work[r] += allocation[p][r];

                    safeSequence[index++] = p;
                    finished[p] = true;
                    found = true;
                    processCount++;
                }
            }
        }

        if (!found)
            {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");

    return true;
}

int main() {
    int available[R] = {3, 3, 2};
    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };
    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(available, max, allocation);

    return 0;
}
