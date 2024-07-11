#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_capacity = 0;

    while (left < right) {
        int width = right - left;
        int height_min = min(height[left], height[right]);
        int capacity = width * height_min;

        if (capacity > max_capacity) {
            max_capacity = capacity;
        }

        // Move the pointer pointing to the shorter bar
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_capacity;
}

/*
#define min(a, b) ((a) < (b) ? (a) : (b))

int main()
{
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);
    
    int max_capacity = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int width = j - i;
            int height_min = min(height[i], height[j]);
            int capacity = width * height_min;
            if (capacity > max_capacity)
            {
                max_capacity = capacity;
            }
        }
    }
    printf("Max_capacity = %d\n", max_capacity);
    return 0;
}*/


//Java Solution

/*class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
}*/
