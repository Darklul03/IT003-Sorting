#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1e6;
vector<double> nums(N);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("stdsort.txt", "w", stdout);

    for (int t = 0; t < 10; t++) {
        ifstream f("../data/input"+to_string(t)+".txt");
        for (double& i : nums)
            f >> i;

        auto start = chrono::system_clock::now();
        sort(nums.begin(),nums.end());
        auto end = chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << elapsed.count() << '\n';
        f.clear();
        f.close();
    }

    return 0;
}
