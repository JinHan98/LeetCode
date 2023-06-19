#include <iostream>
#include <string>
using namespace std;

string S, T;
int N;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    if(N==0){
        cout<<"";
        return 0;
    }
    for(int i=0;i<N;i++){
        char temp;
        cin>>temp;
        S.push_back(temp);
    }
    int start = 0, end = N - 1;
    while (start <= end) {
        bool left = false;
        for (int i = 0; start + i <= end-i; i++) {
            if (S[start + i] < S[end - i]) {
                left = true;
                break;
            }
            else if (S[start + i] > S[end - i]) {
                left = false;
                break;
            }
        }
        if (left) {
            T += S[start++];
        }
        else {
            T += S[end--];
        }
    }
    for (int i = 0; i < T.size(); i++) {
        cout << T[i];
        if ((i + 1) % 80 == 0) {
            cout << "\n";
        }
    }
    return 0;
}
