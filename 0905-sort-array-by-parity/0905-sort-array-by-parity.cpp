class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // Agar left odd hai aur right even hai, to swap karein
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }

            // Pointers ko aage badhayein
            if (nums[left] % 2 == 0) {
                left++;
            }
            if (nums[right] % 2 != 0) {
                right--;
            }
        }

        return nums;
    }
};