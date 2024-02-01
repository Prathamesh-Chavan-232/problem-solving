#include <stdio.h>
#include <stdlib.h>
int *buildArray(int *nums, int numsSize)
{
    int *ans, *cng;
    ans = (int *)malloc(numsSize * sizeof(int));
    cng = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        cng[i] = nums[i];
    }
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = cng[nums[i]];
    }
    return ans;
}
int main()
{
    int *ans;
    int nums[] = {0, 2, 1, 5, 3, 4};
    ans = buildArray(nums, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}