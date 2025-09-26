class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> list;
        ListNode* temp = head;

        while (temp != nullptr) {
            list.push_back(temp->val);
            temp = temp->next;
        }

        mergeSort(&list, 0, list.size() - 1);

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = list[i];
            i++;
            temp = temp->next;
        }

        return head;
    }

    void merge(vector<int>* arr, int st, int mid, int end) {
        int i = st, j = mid + 1, k = 0;
        vector<int> new_arr(end - st + 1);

        while (i <= mid && j <= end) {
            if ((*arr)[i] > (*arr)[j]) {
                new_arr[k] = (*arr)[j];
                j++;
            } else {
                new_arr[k] = (*arr)[i];
                i++;
            }
            k++;
        }
        while (i <= mid) {
            new_arr[k] = (*arr)[i];
            i++;
            k++;
        }
        while (j <= end) {
            new_arr[k] = (*arr)[j];
            j++;
            k++;
        }

        for (int i = 0; i < (end - st + 1); i++) {
            (*arr)[st + i] = new_arr[i];
        }
    }

    void mergeSort(vector<int>* arr, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;
            mergeSort(arr, st, mid);
            mergeSort(arr, mid + 1, end);
            merge(arr, st, mid, end);
        }
    }
};
