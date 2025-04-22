// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < len; ++j) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;
            if (arr[i] + arr[j] == value) {
                ++cnt;
            } else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return cnt;
}

int countPairs2(int* arr, int len, int value) {
    int cnt = 0;
    int l = 0, r = len - 1;
    while (l < r) {
        int s = arr[l] + arr[r];
        if (s == value) {
            ++cnt;
            int lv = arr[l], rv = arr[r];
            while (l < r && arr[l] == lv) ++l;
            while (l < r && arr[r] == rv) --r;
        } else if (s < value) {
            ++l;
        } else {
            --r;
        }
    }
    return cnt;
}

#include <algorithm>

int countPairs3(int* arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int t = value - arr[i];
        auto pos = std::lower_bound(arr + i + 1, arr + len, t);
        if (pos != arr + len && *pos == t) {
            if (pos == arr + i + 1 || *(pos - 1) != t) {
                ++cnt;
            }
        }
    }
    return cnt;
}
