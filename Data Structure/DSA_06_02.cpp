#include <iostream>
#include <vector>
using namespace std;

int linearSearchIterative(const vector<int>& arr, int key);
int linearSearchRecursive(const vector<int>& arr, int key, int index);

int binarySearchIterative(const vector<int>& arr, int key);
int binarySearchRecursive(const vector<int>& arr, int key, int left, int right);

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    int key = 50;

    // Linear Search (Iterative)
    int result = linearSearchIterative(arr, key);
    if (result != -1) {
        cout << "Linear Search (Iterative): Element found at index " << result << endl;
    } else {
        cout << "Linear Search (Iterative): Element not found" << endl;
    }

    // Linear Search (Recursive)
    result = linearSearchRecursive(arr, key, 0);
    if (result != -1) {
        cout << "Linear Search (Recursive): Element found at index " << result << endl;
    } else {
        cout << "Linear Search (Recursive): Element not found" << endl;
    }

    // Binary Search (Iterative)
    result = binarySearchIterative(arr, key);
    if (result != -1) {
        cout << "Binary Search (Iterative): Element found at index " << result << endl;
    } else {
        cout << "Binary Search (Iterative): Element not found" << endl;
    }

    // Binary Search (Recursive)
    result = binarySearchRecursive(arr, key, 0, arr.size() - 1);
    if (result != -1) {
        cout << "Binary Search (Recursive): Element found at index " << result << endl;
    } else {
        cout << "Binary Search (Recursive): Element not found" << endl;
    }

    return 0;
}

// Definitions of the search functions (as shown above)
int linearSearchIterative(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(const vector<int>& arr, int key, int index) {
    if (index >= arr.size()) {
        return -1; // Key not found
    }
    if (arr[index] == key) {
        return index;
    }
    return linearSearchRecursive(arr, key, index + 1);
}

int binarySearchIterative(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(const vector<int>& arr, int key, int left, int right) {
    if (left > right) {
        return -1; // Key not found
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] < key) {
        return binarySearchRecursive(arr, key, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, key, left, mid - 1);
    }
}
