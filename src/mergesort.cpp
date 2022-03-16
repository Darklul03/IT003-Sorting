#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6;
vector<double> nums(N);
vector<double> L(N/2), R(N/2);

template<typename T> void mergeSort(int, int);
template<typename T> void merge(int, int, int);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mergesort.txt", "w", stdout);

    for (int t = 0; t < 10; t++) {
        ifstream f("../data/input"+to_string(t)+".txt");
        for (double& i : nums)
            f >> i;

        auto start = chrono::system_clock::now();
        mergeSort<double>(0,N-1);
        auto end = chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << elapsed.count() << '\n';
        f.clear();
        f.close();
    }

    return 0;
}

template<typename T> void mergeSort(int l, int r) {
    if (l >= r)
        return;
    
    int m = (l+r)/2;
    mergeSort<T>(l,m);
    mergeSort<T>(m+1,r);
    merge<T>(l,m,r);
}

template<typename T> void merge(int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    for (int i = l; i <= m; i++)
        L[i-l] = nums[i];
    for (int i = m+1; i<= r; i++)
        R[i-m-1] = nums[i];

    int i = l, j = 0, k = 0;
    while (j < n1 && k < n2) {
        if (L[j] < R[k])
            nums[i++] = L[j++];
        else
            nums[i++] = R[k++];
    }

    while (j < n1)
        nums[i++] = L[j++];

    while (k < n2)
        nums[i++] = R[k++];
}