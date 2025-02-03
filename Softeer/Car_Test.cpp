#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bs(vector<int> v,int ans) {
    int n = v.size();
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (v[mid] > ans)
            end = mid - 1;
        else if (v[mid] < ans)
            start = mid + 1;
        else
            return mid;

    }
    return -1;

}
int main(int argc, char** argv)
{
    int n, q;
    vector<int> arr;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        int idx = bs(arr, tmp);
        if (idx > 0)
            cout << idx * ((n - 1) - idx) << endl;
        else
            cout << 0<<'\n';
    }
}