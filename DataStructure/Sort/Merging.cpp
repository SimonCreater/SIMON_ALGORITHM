#include<iostream>
using namespace std;


int n, m;
int a[100005], b[100005], c[200005];//c는 a와 b를 합친걸 저장할 곳
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++) {
		if (ridx == en)
			tmp[i] = arr[lidx++];
		else if (lidx == mid)
			tmp[i] = arr[ridx++];
		else if (arr[lidx] > arr[ridx])
			tmp[i] = arr[ridx++];
		else
			tmp[i] = arr[lidx++];
	}
	for (int i = st; i < en; i++) {
		arr[i] = tmp[i];
	}
}

void merge_sort(int st, int en) {
	int mid = (st + en) / 2;
	if (st + 1 == en)
		return;//배열을 계속 반씩 쪼개다가 결국에는 2개만 남은 상태(두 개씩 여러 개가 있겠죠?)
	merge_sort(st, mid);//2개로 쪼개기(재귀를 이해해야 어떻게 쪼개지고 어떻게 합쳐지는지 이해함)
	merge_sort(mid, en);//2개로 쪼개기
	merge(st, en);//쪼갠 배열들 합치기
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	int aidx = 0;//배열 a의 인덱스 위치
	int bidx = 0;//배열 b의 인덱스 위치
	for (int i = 0; i < n + m; i++) {
		if (bidx == m)//배열 b에 있는 모든 데이터를 c로 옮겼으므로 a만 계속 추가해준다
			c[i] = a[aidx++];
		else if (aidx == n)//배열 a에 있는 모든 데이터를 c로 옮겼으므로 a만 계속 추가해준다
			c[i] = b[bidx++];
		else if (a[aidx] > b[bidx])//aidx가 가르키고 있는 데이터와 bidx가 가르키고 있는 데이터 비교
			c[i] = b[bidx++];//b에 있는 데이터를 c에 추가하고 b의 다음 인덱스를 가르키기 위해 bidx++를 실행
		else
			c[i] = a[aidx++];
	}
	for(int i=0;i<n+m;i++){
	   cout<<c[i]<<' ';
	}
}