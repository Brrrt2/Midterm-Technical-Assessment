#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

//Create a function for merge sort algorithm
void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

       
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

     
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; ++i) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
}

//Create a bubble sort algorithm function
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void print_array(const vector<int>& arr) {
    for (int time : arr) {
        cout << time << " ";
    }
    cout << endl;
}

// Function: Analyze and compare sorting algorithms
void analysis(vector<int> dt) {
    // Chrono: Measure time
    // Bubble Sort
    vector<int> bubbleSortedTimes = dt;
    auto startBubble = chrono::high_resolution_clock::now();
    bubble_sort(bubbleSortedTimes);
    auto endBubble = chrono::high_resolution_clock::now();
    chrono::duration<double> bubbleDuration = endBubble - startBubble;

    // Merge Sort
    vector<int> mergeSortedTimes = dt;
    auto startMerge = chrono::high_resolution_clock::now();
    merge_sort(mergeSortedTimes, 0, mergeSortedTimes.size() - 1);
    auto endMerge = chrono::high_resolution_clock::now();
    chrono::duration<double> mergeDuration = endMerge - startMerge;

    //Output of difference of bubble sort and merge sort after function.
    cout << "\n===BUBBLE SORT===" << endl;
    cout << "Sorted delivery times: ";
    print_array(bubbleSortedTimes);
    cout << "Time taken: " << bubbleDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n^2)\n";

    cout << "\n===MERGE SORT===" << endl;
    cout << "Sorted delivery times: ";
    print_array(mergeSortedTimes);
    cout << "Time taken: " << mergeDuration.count() << " seconds\n";
    cout << "Time Complexity: O(n log n)\n";
}

// Main Program
int main() {
    // Variable Instantiation
    int N; // Number of deliveries

    // Enter the number of deliveries
    cout << "Number of deliveries: ";
    cin >> N;

    // we can check if N is a positive integer; else repeat input until value is a positive number
    while (N <= 0) {
        cout << "Please enter a positive number for the number of deliveries: ";
        cin >> N;
    }

    // Input: Delivery times
    vector<int> dt(N);
    cout << "Enter the delivery times (in minutes)." << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Delivery Time (" << i + 1 << "): ";
        cin >> dt[i];
    }

    // Function Call: Analyze bubble and merge sort algorithms 
    analysis(dt);

    return 0;
}

/*
DIFFERENCE OF BUBBLE SORT AND MERGE SORT

    Bubble sort can become less efficent when sorting larger datasets but
    merge sort becomes more efficient when it comes to large datasets. 
    Since bubble sort is good with smaller datasets, bubble sort has a time
    complexity of O(n) and for worst case scenario O(n^2) which is not good,
    and for the merge sort has a consistent time complexity of O(n log(n))
    which is better and faster.

*/
