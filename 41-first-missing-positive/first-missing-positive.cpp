class Solution {
public:
    void merge(vector<int>& arr, int st, int mid, int end) {
        int i = st;
        int j = mid + 1;
        int new_arr[end - st + 1];
        int k = 0;
        while (i <= mid && j <= end) {
            if (arr[i] > arr[j]) {
                new_arr[k] = arr[j];
                j++;
            } else {
                new_arr[k] = arr[i];
                i++;
            }
            k++;
        }
        while (i <= mid) {
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        while (j <= end) {
            new_arr[k] = arr[j];
            j++;
            k++;
        }
        for (int i = 0; i < (end - st + 1); i++) {
            arr[st + i] = new_arr[i];
        }
    }

    void mergeSort(vector<int>& arr, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;
            mergeSort(arr, st, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, st, mid, end);
        }
    }
    int firstMissingPositive(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<ans) continue;
            if(nums[i]==ans) ans++;
            else return ans;
        }
        return ans;
    }
};