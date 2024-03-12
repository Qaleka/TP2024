//2_2.Дан массив целых чисел А[0..n - 1].Известно, что на интервале[0, m] значения массива строго возрастают, а на интервале[m, n - 1] строго убывают.Найти m за O(log m).
//Требования:  Время работы O(log m).Внимание!В этой задаче сначала нужно определить диапазон для бинарного поиска размером порядка m с помощью экспоненциального поиска, а потом уже в нем делать бинарный поиск.
//
//2 ≤ n ≤ 10000.

#include <iostream>
#include <cassert>

int binarySearch(int arr[], int left, int right) {
    while (left < right) {
        int middle = (right + left) / 2;
        if (arr[middle - 1] > arr[middle] && arr[middle + 1] < arr[middle]) {
            right = middle;
        }
        else if (arr[middle - 1] < arr[middle] && arr[middle + 1] > arr[middle]) {
            left = middle + 1;
        }
        else if (arr[middle - 1] < arr[middle] && arr[middle + 1] < arr[middle]) {
            return middle;
        }
    }
    return (left == right) ? -1 : left;
}

int expSearch(int arr[], int size) {
    assert(size > 0);
    int boundLeft = 1, boundRight = 2;
    while (arr[boundLeft] < arr[boundRight]) {
        boundLeft = boundRight;
        if (boundRight * 2 > size) {
            boundRight = size;
        }
        else {
            boundRight *= 2;
        }
    }
    return binarySearch(arr, boundLeft, boundRight);
}

int main()
{
    int n = 0;
    std::cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    std::cout << expSearch(A, n) << std::endl;
    delete[] A;
    return 0;
}
