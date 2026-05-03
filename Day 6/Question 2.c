void moveZeroes(int *nums, int numsSize)
{
    int k = 0; // position to place next non-zero

    // Move all non-zero elements forward
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            nums[k++] = nums[i];
        }
    }

    // Fill the remaining positions with 0
    while (k < numsSize)
    {
        nums[k++] = 0;
    }
}