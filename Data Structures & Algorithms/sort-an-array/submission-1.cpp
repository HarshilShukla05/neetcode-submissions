class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;
        int l = 0, r = nums.size() - 1;
        mergeSort(nums, l, r);
        return nums;
    }

private:
    // Notice the "&" - we are modifying the original array directly
    void merge(vector<int>& arr, int l, int m, int r) {
        // 1. Calculate the sizes of the two halves
        int n1 = m - l + 1;
        int n2 = r - m;

        // 2. Create temporary vectors for the left and right halves
        vector<int> left(n1);
        vector<int> right(n2);

        // 3. Copy the data into the temporary vectors
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[m + 1 + j];
        }

        // 4. Merge the temporary vectors back into the main arr
        int i = 0; // Initial index of left sub-array
        int j = 0; // Initial index of right sub-array
        int k = l; // Initial index of merged sub-array

        while (i < n1 && j < n2) {
            // Use <= to maintain sorting stability
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        // 5. Copy any remaining elements of left[], if any exist
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        // 6. Copy any remaining elements of right[], if any exist
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        // Base case: if the segment has 1 or 0 elements, it's already sorted
        if (l >= r) return;
        
        // Prevent potential integer overflow
        int m = l + (r - l) / 2; 
        
        // Recursively sort the left and right halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
};