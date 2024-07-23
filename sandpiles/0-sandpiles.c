#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * make_stable - make a grid stable if it is unstable
 * @grid: 3x3 grid
 * 
 */
void make_stable(int grid[3][3]) {
    int i, j;
    bool isUnstable = true;

    while (isUnstable) {
        int temp[3][3];
        isUnstable = false;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                temp[i][j] = grid[i][j];
            }
        }

        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                if (grid[i][j] > 3) {
                    isUnstable = true;
                    temp[i][j] -= 4;

                    if (i > 0) {
                        temp[i - 1][j] += 1;
                    }

                    if (i < 2) {
                        temp[i + 1][j] += 1;
                    }

                    if (j > 0) {
                        temp[i][j - 1] += 1;
                    }

                    if (j < 2) {
                        temp[i][j + 1] += 1;
                    }
                }
            }
        }

        if (isUnstable) {
            printf("=\n");
            print_grid(grid);

            for (i = 0; i < 3; ++i) {
                for (j = 0; j < 3; ++j) {
                    grid[i][j] = temp[i][j];
                }
            }
        }
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 * 
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
        }
    }

    make_stable(grid1);
}
