#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std;

int binSearch1(int arr[], int, int, int);
int binSearch2(int arr[], int, int, int);
int jumpSearch1(int arr[], int, int);
void swap(int *, int *);
void selectionSort(int arr[], int);
void printArray(int arr[], int);
void merge(int arr[], int, int, int);
void mergeSort(int arr[], int, int);
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();

int main(int argc, char** argv) {
    cout << "Problem 1" << endl << endl;
    prob1();
    cout << endl << endl;

    cout << "Problem 2" << endl << endl;
    prob2();
    cout << endl << endl;

    cout << "Problem 3" << endl << endl;
    prob3();
    cout << endl << endl;

    cout << "Problem 4" << endl << endl;
    prob4();
    cout << endl << endl;

    cout << "Problem 5" << endl << endl;
    prob5();
    cout << endl << endl;

    cout << "Problem 6" << endl << endl;
    prob6();
    cout << endl << endl;

    return 0;
}

int binSearch1(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        // It's in middle
        if (arr[m] == x) {
            return m;
        }
        //  Don't bother with left
        if (arr[m] < x) {
            l = m + 1;
        }
        //  Don't bother with right
        else {
            r = m - 1;
        }
    }
    //  Item was not there
    return -1;
}


int binSearch2(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid =1 + (r - 1) / 2;

        //  It's in middle
        if (arr[mid] == x) {
            return mid;
        }

        //  Smaller than mid, it must be in left
        if (arr[mid] > x) {
            return binSearch2(arr, l, mid - 1, x);
        }

        //  Otherwise, in right
        return binSearch2(arr, mid + 1, r, x);
    }
    //  Element not in array
    return -1;
}

int jumpSearch1(int arr[], int x, int n) {
    int step = sqrt(n);
    int prev = 0;

    //  Locate element, get place
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    //  Linear Search
    while (arr[prev] < x) {
        prev++;

        if (prev == min(step, n)) {
            return -1;
        }
    }

    //  Element located
    if (arr[prev] == x) {
        return prev;
    }

    return -1;
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }

            swap(&arr[min_idx], &arr[i]);
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //  Temp arrays
    int L[n1], R[n2];

    //  Copy to temp
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    //  Merge
    //  First subarray idx, Second subarray idx, indx merged subarray
    i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    //  Copy rest if they exist
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        //  Prevent overflow
        int m = l + (r - l) / 2;

        //  Sort
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void prob1() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binSearch1(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result << endl;


    cout << "A. T(n) = log2 n "<< endl;
    cout << "A. T(n) = log2 5 = (ln5/ln2) = 2.3219" << endl << endl;
    cout << "B. First pass: Cut half, get middle, left & right parts. Compare"
         << " right to middle, " << endl << "if right is bigger than middle,"
         << " right is used next. Now right is middle, then checked." << endl;
}

void prob2() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binSearch1(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result << endl;


    cout << "A. This one is recursion, the other is a while loop/iterative."
         << endl;
    cout << "B. Non-recursion example is more efficient, less function calls, " 
         << "for example." << endl;
}

void prob3() {
    int arr[] = {0, 10, 18, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch1(arr, x, n);
    cout << "\n" << "Number " << x << " is at index " << index << endl;
    cout << "A. C = sqrt(n) = sqrt(16) = 4" << endl;
    cout << "B. 2 * sqrt(16) = 8" << endl;
    cout << "C. Searchs an already sorted array by taking shortcuts 'jumping'"
         << " around, using less operations." << endl;
}

void prob4() {
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof (arr[0]);

    sort(arr, arr+n);
    cout << "\n" << "Array after sorting using default sort is: " << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "B. Utilize address, put them in order. (Move values)" << endl;
}

void prob5() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: " << "\n";
    printArray(arr, n);

    cout << "A. It tries to find the smallest element from the nonsorted, and"
         << " places it at the start." << endl << "One place for unsorted and"
         << " another for sorted." << endl;
    cout << "B. If n is 5...T(n) = n^2 = 5^2 = 25" << endl;
}

void prob6() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << ("Given array is: ");
    printArray(arr, arr_size);
    mergeSort(arr, 0,  arr_size - 1);

    cout << ("\nSorted array is: ");
    printArray(arr, arr_size);

    cout << "A. 7 * log7" << endl;
    cout << "B. We take the middle and seperate from there into two halves. Next,"
         << " call mSort for both parts, then merge parts." << endl;
}
