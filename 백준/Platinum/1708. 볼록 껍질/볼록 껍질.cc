#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int dx,dy;
int N;
double dist(pair<double,double> a, pair<double,double> b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int ccw(pair<double, double>p1, pair<double, double>p2, pair<double, double>p3) {
    double s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}
struct compare
{
    bool operator()(pair<int,int> a,pair<int,int> b){
        double c=ccw({dx,dy}, a, b);
    //점이 직선 상에 있으면 가까운 점을 먼저
    if(c==0){
        return dist({dx,dy}, a)>dist({dx,dy}, b);
    }
    return c>0;
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    vector<pair<double,double> >cord(N);
    cin>>cord[0].first>>cord[0].second;
    int min_y=cord[0].second;
    int min_idx=0;
    for(int i=1;i<N;i++){
        cin>>cord[i].first>>cord[i].second;
        if(cord[i].second<=min_y){
            if((cord[i].second==min_y&&cord[i].first<cord[min_idx].first)||cord[i].second<min_y){
                min_y=cord[i].second;
                min_idx=i;
            }
        }
    }
    dx=cord[min_idx].first;
    dy=min_y;
    priority_queue<pair<double,double>,vector<pair<double,double> >,compare>k;
    for(int i=0;i<N;i++){
        if(i==min_idx)
            continue;
        k.push(cord[i]);
    }
    stack<pair<double,double> >st;
    st.push({dx,dy});
    st.push(k.top());
    k.pop();
    while(!k.empty()){
        while(st.size()>=2){
            pair<double,double> s=st.top();
            st.pop();
            pair<double,double> f=st.top();
            if(ccw(f,s,k.top())==-1){
                st.push(s);
                break;
            }
        }
        st.push(k.top());
        k.pop();
    }
    cout<<st.size();
}