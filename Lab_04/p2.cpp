#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Partition function
int partition(vector<int>& arr, int st, int end) {
    int pivot = arr[end];
    int i = st - 1;
    for (int j = st; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

// Quicksort recursive
void quicksort(vector<int>& arr, int st, int end) {
    if (st < end) {
        int pivln = partition(arr, st, end);
        quicksort(arr, st, pivln - 1);
        quicksort(arr, pivln + 1, end);
    }
}

// Function to run a test case
void runTestCase(string name, vector<int> arr) {
    cout << "\n" << name << ":\n";
    cout << "Original array: ";
    for (int val : arr) cout << val << " ";
    cout << "\n";

    auto start_time = high_resolution_clock::now();
    quicksort(arr, 0, arr.size() - 1);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Sorted array:   ";
    for (int val : arr) cout << val << " ";
    cout << "\nExecution time: " << duration.count() << " microseconds\n";
    cout << "--------------------------------------------\n";
}

int main() {
    int n = 100; // default size, change if needed
    vector<int> bestCase(n), averageCase(n), worstCase(n);

    // Best Case: Already sorted
    for (int i = 0; i < n; i++) bestCase[i] = i;

    // Average Case: Random
    srand(time(0));
    for (int i = 0; i < n; i++) averageCase[i] = rand() % 1000;

    // Worst Case: Reverse sorted
    for (int i = 0; i < n; i++) worstCase[i] = n - i;

    // Run all test cases
    runTestCase("Best Case", bestCase);
    runTestCase("Average Case", averageCase);
    runTestCase("Worst Case", worstCase);

    // cout << "\nTheoretical Time Complexity of Quicksort:\n";
    // cout << "Best Case:    O(n log n)\n";
    // cout << "Average Case: O(n log n)\n";
    // cout << "Worst Case:   O(n^2)\n";
    // cout << "Space Complexity: O(log n)\n";

    return 0;
}
