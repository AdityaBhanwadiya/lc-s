//Brute Force
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int totalWater = 0;

//         for (int i = 0; i < n; ++i) {
//             int maxLeft = 0, maxRight = 0;

//             // Scan left
//             for (int j = i; j >= 0; --j) {
//                 maxLeft = max(maxLeft, height[j]);
//             }

//             // Scan right
//             for (int j = i; j < n; ++j) {
//                 maxRight = max(maxRight, height[j]);
//             }

//             // Water level is min of both sides
//             int waterLevel = min(maxLeft, maxRight);

//             // Water trapped = water level - current height
//             totalWater += waterLevel - height[i];
//         }

//         return totalWater;
//     }
// };


// Optimal Two pointer Approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Left is the limiting side
                if (height[left] >= leftMax) {
                    leftMax = height[left];  // update max
                } else {
                    water += leftMax - height[left];  // trap water
                }
                left++;
            } else {
                // Right is the limiting side
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }
};
