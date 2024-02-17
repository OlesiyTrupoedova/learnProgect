void quick_sort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int left = start;
    int right = end;
    int pivot = arr[(left + right) / 2];
    int temp = 0;
    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right) {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    quick_sort(arr, start, right);
    quick_sort(arr, left, end);
}

