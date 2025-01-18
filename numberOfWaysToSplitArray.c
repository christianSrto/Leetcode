/**
 * You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.
 */
int checkSplitSums(int *nums, int length, int offset)
{
    int sum = 0;
    for (int i = offset; i < length; i++)
    {
        sum += nums[i];
    }
    return sum;
}

int waysToSplitArray(int *nums, int numsSize)
{
    int validSplit = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int firstSplit = checkSplitSums(nums, i + 1, 0);
        int secSplit = checkSplitSums(nums, numsSize, i + 1);

        if ((firstSplit >= secSplit) && i < numsSize - 1)
        {
            validSplit = validSplit + 1;
        }
    }

    return validSplit;
}