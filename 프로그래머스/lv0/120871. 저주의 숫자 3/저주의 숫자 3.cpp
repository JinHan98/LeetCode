#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isthree(int k);
int solution(int n) {
    int answer = 0;
    int num=0;
    while(num<n){
        num++;
        answer++;
        while(answer%3==0||isthree(answer)){
            answer++;
        }
    }
    return answer;
}
bool isthree(int k){
    if(k==3)
        return true;
    while(k>0){
        if(k%10==3)
            return true;
        k/=10;
    }
    return false;
}