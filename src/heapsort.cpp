#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6;
vector<double> nums(N);
template<typename T> void heapify(int, int);
template<typename T> void buildMaxHeap(int);
template<typename T> void heapSort(int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("heapsort.txt", "w", stdout);

    for (int t = 0; t < 10; t++) {
        ifstream f("../data/input"+to_string(t)+".txt");
        for (double& i : nums)
            f >> i;

        auto start = chrono::system_clock::now();
        heapSort<double>(N);
        auto end = chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << elapsed.count() << '\n';
        f.clear();
        f.close();
    }

    return 0;
}

template<typename T> void heapify(int i, int n) {
    int max = i;
    int l = 2*i;
    int r = 2*i+1;

    if (l < n && nums[l] > nums[max])
        max = l;
    if (r < n && nums[r] > nums[max])
        max = r;

    if (max != i) {
        swap(nums[i], nums[max]);
        heapify<T>(max,n);
    }
}

template<typename T> void buildMaxHeap(int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify<T>(i,n);
}

template<typename T> void heapSort(int n) {
    buildMaxHeap<T>(n);
    for (int i = n-1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify<T>(0,i);
    }
}
