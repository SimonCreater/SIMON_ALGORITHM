#include<iostream>
#include<utility>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int board[103][103][103];
int dist[103][103][103];
queue<tuple<int, int, int>> q;
int main() {
    int m, n, h;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    q.push({ i,j,k });

                }
                if (board[i][j][k] == 0)
                    dist[i][j][k] = -1;
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nz = curZ + dz[dir];
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || nx >= n || ny >= m || ny < 0 || nz >= h || nz < 0)
                continue;
            if (dist[nz][nx][ny] >= 0)
                continue;
            dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
            q.push({ nz,nx,ny });
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                ans = max(ans, dist[i][j][k]);
            }
        }
    }
    cout << ans << '\n';



}