#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string T,P;
    getline(cin,T);
    getline(cin,P);
    int j=0;
    vector<int> a(P.size());
    a[0]=0;
    for(int i=1;i<P.size();i++){
        while (j > 0 && P[i] != P[j])
			j = a[j - 1];
        if(P[j]==P[i]){
            a[i]=j+1;
            j++;
        }
    }
    int i=0;
    j=0;
    int ans=0;
    vector<int> an;
    int n=T.size();
    int m=P.size();
    for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && T[i] != P[j])
			j = a[j - 1];
		if (T[i] == P[j]) { // 일치한다면 
			if (j == m - 1) { // 검색에 성공한 경우 (그 이전의 m - 1 개도 모두 일치. 총 m 개가 일치하는 셈)
                ans++;
				an.push_back(i - m + 2); // 검색 성공한 일치 문자열의 시작 인덱스는 i - m + 1
				j = a[j]; // j = pi[m - 1] 와 같음
			}
			else j++; // 일치하면 자연스레 검색어의 다음 원소 검사하러 가면 된다.
		}
	}
    cout<<ans<<'\n';
    for(int i=0;i<an.size();i++){
        cout<<an[i]<<' ';
    }
}