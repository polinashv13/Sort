#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
int part(T arr[], int l, int h) {
    T pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[h]);
    return i + 1;
}

template <typename T>
int randPart(T arr[], int l, int h) {
    srand(time(0));
    int r = l + rand() % (h - l);
    std::swap(arr[r], arr[h]);
    return part(arr, l, h);
}

template <typename T>
void quickSort(T arr[], int l, int h) {
    if (l < h) {
        int pivot = randPart(arr, l, h);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, h);
    }
}
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1 ; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T curr = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = curr;
            }
        }
    }
}

template <typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T curr = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}

int main()
{
    int arr[] = { 78, 56, 3, 13, 7, 25, 2, 65 };
    int size = sizeof(arr) / sizeof(arr[0]);

    //quickSort(arr, 0, size - 1);
    bubbleSort(arr, size);
    //insertionSort(arr, size);


    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


