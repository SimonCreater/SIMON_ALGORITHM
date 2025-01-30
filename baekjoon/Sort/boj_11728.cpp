#include<iostream>
using namespace std;
int n, m;
int a[1000005];
int b[1000005];
int c[2000005];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    int aidx = 0;
    int bidx = 0;

    for (int i = 0; i < n + m; i++) {
        if (aidx == n)
            c[i] = b[bidx++];
        else if (bidx == m)
            c[i] = a[aidx++];
        else if (a[aidx] <= b[bidx])
            c[i] = a[aidx++];
        else
            c[i] = b[bidx++];
    }
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
}