#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6;
vector<double> nums(N);
template<typename T> T med3(int, int);
template<typename T> void quickSort(int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("quicksort.txt", "w", stdout);

    for (int t = 0; t < 10; t++) {
        ifstream f("../data/input"+to_string(t)+".txt");
        for (double& i : nums)
            f >> i;

        auto start = chrono::system_clock::now();
        quickSort<double>(0,N-1);
        auto end = chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << elapsed.count() << '\n';
        f.clear();
        f.close();
    }

    return 0;
}

template<typename T> T med3(int l, int r) {
    int mid = (l+r)/2;
    if (nums[l] > nums[mid])
        swap(nums[l],nums[mid]);
    if (nums[l] > nums[r])
        swap(nums[l],nums[r]);
    if (nums[r] > nums[mid])
        swap(nums[r],nums[mid]);
    return nums[r];
}

template<typename T> void quickSort(int l, int r) {
    if (l >= r)
        return;

    T pivot = med3<T>(l,r);
    int i = l, j = r-1;
    while (i < j) {
        while (nums[i] < pivot && i < j)
            i++;
        while (nums[j] > pivot && i < j)
            j--;
        swap(nums[i],nums[j]);
    }
    swap(nums[i], nums[r]);

    quickSort<T>(l,i-1);
    quickSort<T>(i+1,r);
}
