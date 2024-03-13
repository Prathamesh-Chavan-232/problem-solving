#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *nums;
    int numsSize;
    int returnSize;
    int count = 0;
    printf("Enter numsSize : ");
    scanf("\n%d", &numsSize);

    nums = (int *)malloc(numsSize * sizeof(int));

    printf("Enter elements for Nums : ");
    for (int i = 0; i < numsSize; i++)
    {
        scanf("\n%d", &nums[i]);
    }

    returnSize = 2 * numsSize;
    int *ans = (int *)malloc((returnSize) * sizeof(int));

    for (int i = 0; i < (2 * numsSize); i++)
    {

        if (i == numsSize)
        {
            count = 0;
        }
        ans[i] = nums[count];
        count++;
    }

    for (int i = 0; i < (2 * numsSize); i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}