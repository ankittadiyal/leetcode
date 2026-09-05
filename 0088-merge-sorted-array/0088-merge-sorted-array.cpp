class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;      // pointer for the last valid element in nums1
        int j = n - 1;      // pointer for the last element in nums2
        int k = m + n - 1;  // pointer for the last available slot in nums1

        // merge in reverse order
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};