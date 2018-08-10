#include <stdio.h>
#include <stdlib.h>

int amax(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n;
    int* length;

    printf("input a nubmer of sticks: ");
    scanf("%d", &n);
    printf("%d\n", n);

    length = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
    {
        printf ("%d : ", i + 1);
        scanf("%d", &length[i]);
    }

    int max = 0;
    int s1 = 0, s2 = 0, s3 = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                int all = length[i] + length[j] + length[k];
                int a = amax(length[i], amax(length[j], length[k]));

                int rest = all - a;

                if (a < rest)
                {
                    s1 = length[i];
                    s2 = length[j];
                    s3 = length[k];
                    max = all;
                }
            }
        }
    }

    // answer
    printf("max = %d (when %d %d %d)\n", max, s1, s2, s3);

    return 0;
}
