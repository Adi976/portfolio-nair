/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int f = 0, ind;
    int upper = numsSize, lower = 0, mid;
    returnSize=(int*)malloc(sizeof(int)*2);
    while (upper > lower)
    {
        mid = lower + (upper - lower) / 2;

        if (nums[mid] == target)
        {
            f++; // found
            ind = mid;
        }
        else if (nums[mid] > target)
            upper = mid;
        else
            lower = mid;
    }
    if (f == 0)
    {
        // Not found
        returnSize[0] = -1;
        returnSize[1] = -1;
        return;
    }
    else if (f == 1)
    {
        returnSize[0] = ind;
        returnSize[1] = ind;
    }
    else
    {
        returnSize[1] = ind;
        upper = ind, lower = 0, mid = 0;
        while (upper > lower)
        {
            mid = lower + (upper - lower) / 2;

            if (nums[mid] == target)
            {
                 // found
                ind = mid;
                break;
            }
            else if (nums[mid] > target)
                upper = mid;
            else
                lower = mid;
        }
        returnSize[0] = ind;
        return returnSize;
    }
}

/*
public class Solution {
public int[] searchRange(int[] nums, int target) {
    int[] result = new int[2];
    result[0] = findFirst(nums, target);
    result[1] = findLast(nums, target);
    return result;
}

private int findFirst(int[] nums, int target){
    int idx = -1;
    int start = 0;
    int end = nums.length - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(nums[mid] >= target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        if(nums[mid] == target) idx = mid;
    }
    return idx;
}

private int findLast(int[] nums, int target){
    int idx = -1;
    int start = 0;
    int end = nums.length - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(nums[mid] <= target){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        if(nums[mid] == target) idx = mid;
    }
    return idx;
}

*/