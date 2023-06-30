#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
bool isbig(int t_y,int t_m, int t_d,int y,int m,int d);
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int t_year=stoi(today.substr(0,4));
    int t_month=stoi(today.substr(5,2));
    int t_day=stoi(today.substr(8,2));
    int each_terms[26]={0,};
    for(int i=0;i<terms.size();i++){
        each_terms[terms[i][0]-'A']=stoi(terms[i].substr(2));
    }
    for(int i=0;i<privacies.size();i++){
        int year=stoi(privacies[i].substr(0,4));
        int month=stoi(privacies[i].substr(5,2));
        int day=stoi(privacies[i].substr(8,2));
        if(day==1){
            day=28;
            month--;
        }
        else
            day--;
        month+=each_terms[privacies[i][11]-'A'];
        if(month%12!=0){
            year+=(month/12);
            month%=12;
        }
        else{
            year+=(month/12-1);
            month=12;
        }
        if(isbig(t_year,t_month,t_day,year,month,day)){
            answer.push_back(i+1);
        }
    }
    return answer;
}
bool isbig(int t_y,int t_m, int t_d,int y,int m,int d){
    if(t_y>y){
        return 1;
    }
    else if(t_y<y){
        return 0;
    }
    else{
        if(t_m>m){
            return 1;
        }
        else if(t_m<m){
            return 0;
        }
        else{
            if(t_d>d){
                return 1;
            }
            else
                return 0;
        }
    }
}