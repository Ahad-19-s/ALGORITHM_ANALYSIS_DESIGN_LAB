#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Merge Function
void merge(int a[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    vector<int> lefta(leftSize), righta(rightSize);

    for (int i = 0; i < leftSize; i++)
        lefta[i] = a[start + i];
    for (int j = 0; j < rightSize; j++)
        righta[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (lefta[i] <= righta[j])
            a[k++] = lefta[i++];
        else
            a[k++] = righta[j++];
    }
    while (i < leftSize)
        a[k++] = lefta[i++];
    while (j < rightSize)
        a[k++] = righta[j++];
}

// Recursive Merge Sort
void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

// Function to run a test case
void runTestCase(string name, int a[], int n) {
    cout << "\n" << name << ":\n";
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";

    auto start_time = high_resolution_clock::now();
    mergeSort(a, 0, n - 1);
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nExecution time: " << duration.count() << " microseconds\n";
    cout << "--------------------------------------------\n";
}

int main() {
    int n = 100;
    int bestCase[n], averageCase[n], worstCase[n];

    // Best Case: Already sorted
    for (int i = 0; i < n; i++) bestCase[i] = i;

    // Average Case: Random
    srand(time(0));
    for (int i = 0; i < n; i++) averageCase[i] = rand() % 1000;

    // Worst Case: Reverse sorted
    for (int i = 0; i < n; i++) worstCase[i] = n - i;

    // Run all test cases
    runTestCase("Best Case", bestCase, n);
    runTestCase("Average Case", averageCase, n);
    runTestCase("Worst Case", worstCase, n);

    // cout << "\nTheoretical Time Complexity of Merge Sort:\n";
    // cout << "Best Case:    O(n log n)\n";
    // cout << "Average Case: O(n log n)\n";
    // cout << "Worst Case:   O(n log n)\n";
    // cout << "Space Complexity: O(n)\n";

    return 0;
}
