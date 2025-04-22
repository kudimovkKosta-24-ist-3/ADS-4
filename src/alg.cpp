// Copyright 2021 NNTU-CS
#include <algorithm>

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int* copy = new int[len];
  std::copy(arr, arr + len, copy);
  std::sort(copy, copy + len);
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = copy[left] + copy[right];
    if (sum == value) {
      if (copy[left] == copy[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int left_val = copy[left];
        int right_val = copy[right];
        int left_count = 0;
        int right_count = 0;
        while (left < len && copy[left] == left_val) {
          left++;
          left_count++;
        }
        while (right >= 0 && copy[right] == right_val) {
          right--;
          right_count++;
        }
        count += left_count * right_count;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  delete[] copy;
  return count;
}

int countOccurrences(int* arr, int left, int right, int value) {
  int low = left, high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= value) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  int first = low;

  low = left, high = right;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= value) {
      low = mid +
