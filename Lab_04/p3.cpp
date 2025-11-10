#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Recursive Binary Search
int binarySearch(int a[], int low, int high, int target) {
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == target)
        return mid;
    else if (a[mid] > target)
        return binarySearch(a, low, mid - 1, target);
    else
        return binarySearch(a, mid + 1, high, target);
}

// First occurrence
int findFirstOccurrence(int a[], int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            res = mid;
            high = mid - 1;
        } else if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

// Last occurrence
int findLastOccurrence(int a[], int n, int target) {
    int low = 0, high = n - 1, res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            res = mid;
            low = mid + 1;
        } else if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}

int main() {
    int n = 100; 
    int a[n];


    for (int i = 0; i < n; i++)
        a[i] = i + 1; // 1, 2, 3, ..., 100

    /* -------- User input option --------
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    ----------------------------------- */

    int target;
    cout << "Enter target element to search: ";
    cin >> target;

    cout << "\nArray: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    // Measure execution time
    auto start_time = high_resolution_clock::now();
    int index = binarySearch(a, 0, n - 1, target);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    if (index == -1)
        cout << "\nElement not found!\n";
    else {
        cout << "\nElement " << target << " found at index: " << index << "\n";

        int first = findFirstOccurrence(a, n, target);
        int last = findLastOccurrence(a, n, target);
        int count = last - first + 1;

        cout << "First occurrence index: " << first << "\n";
        cout << "Last occurrence index: " << last << "\n";
        cout << "Total occurrences: " << count << "\n";
    }

    // cout << "\n===== Time Complexity Summary =====\n";
    // cout << "Best Case: O(1)\n";
    // cout << "Average Case: O(log n)\n"; 
    // cout << "Worst Case: O(log n)\n";
    // cout << "Space Complexity (Recursive): O(log n)\n";

    cout << "Practical Execution Time: " << duration.count() << " microseconds\n";

    return 0;
}
