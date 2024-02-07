
#include <iostream>
#include <vector>

using namespace std;

void insertionSortArr(int arr[], int size)
{
	for (int i = 1; i < size; ++i) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];

			--j;
		}

		arr[j + 1] = key;
	}

	cout << arr;
}

void insertionSortVi(vector<int>& vi)
{
	int key = vi[i];
	int j = i - 1;

	while (j >= 0 && vi[j] > key) {
		vi[j + 1] = vi[j];
		--j;
	}

	vi[j + 1] = key;
}

int binaryRecursion(vector<int>& vi, int target, int low, int high)
{
	if (low > high) {
		return -1;
	}

	int mid = low + (high - low) / 2;

	if (vi[mid] == target) {
		return mid;
	}
	else if (vi[mid] < target) {
		return binaryRecursion(vi, target, mid + 1, high);
	}
	else {
		return binaryRecursion(vi, target, low, mid - 1);
	}
}

int binarySearch(int size, int arr[], int target)
{
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			low = mid - 1;
		}
	}
}

int main()
{
	int arr[] = { 0, 3, 2, 5 };
	int size = sizeof(arr);

	vector<int> vi;

	int target;
	int low = 0;
	int high = vi.size() - 1;

	insertionSortArr(arr, size);
	insertionSortVi(vi);
}


