#include <iostream>
#include <ctime>

using namespace std;
const int n1 = 10, n2 = 1000;

void fillArr(int arr[][n2]) {
	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 0; j < n2; j++) {
			arr[i][j] = rand() % 100 + 1;
		}
	}
}

void printArr(int arr[][n2]) { 
	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 0; j < n2; j++) {
			cout << "[" << i << "][" << j << "]:" << arr[i][j] << endl;
		}
	}
}

void defineTime(int arr[][n2], void(&sortFunc)(int [][n2]), string name) {
	float start_time, end_time, delta_time;
	fillArr(arr);
	start_time = clock() / float(1000);
	sortFunc(arr);
	end_time = clock() / float(1000);
	delta_time = end_time - start_time;
	cout << "Time for " << name << ":" << delta_time << endl;
}

void bubbleSort(int arr[][n2]) {
	int temp;
	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 1; j < n2; j++) {
			for (size_t k = 0; k < n2 - j; k++) {
				if (arr[i][k] > arr[i][k + 1]) {
					swap(arr[i][k], arr[i][k + 1]);
				}
			}
		}
	}
}

void insertionSort(int arr[][n2]) {
	for (size_t i = 0; i < n1; i++) {
		for (size_t j = 1; j < n2; j++) {
			for (int k = j; (k > 0 && (arr[i][k - 1] > arr[i][k])); k--) {
				swap(arr[i][k - 1], arr[i][k]);
			}
		}
	}
}

void shellSort(int arr[][n2]) {
	for (size_t i = 0; i < n1; i++) {
		for (int step = n2 / 2; step > 0; step /= 2) {
			for (int j = 0; j < n2 - step; j++) {
				for (int k = j; k >= 0 && arr[i][k] > arr[i][k + step]; k-=step) {
					swap(arr[i][k], arr[i][k + step]);
				}
			}
		}
	}
}

int main() {
	srand(time(NULL));
	int arr[n1][n2];
	defineTime(arr, bubbleSort, "bubble sort");
	defineTime(arr, insertionSort, "insertion sort");
	defineTime(arr, shellSort, "Shell sort");
	return 0;
}
