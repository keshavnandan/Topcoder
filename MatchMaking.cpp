#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class MatchMaking {
public:
struct item{
            string name;
            string pattern;
            item(string a, string b): name(a), pattern(b){}
            bool operator<(item t){ return this->name < t.name;}
        };
	string makeMatch(vector <string>, vector <string>, vector <string>, vector <string>, string);
};

string MatchMaking::makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman) {

    list<item> men, women;
    for(int i = 0; i < namesWomen.size(); i++)
        women.push_back(item(namesWomen[i], answersWomen[i]));
    for(int i = 0; i < namesMen.size(); i++)
        men.push_back(item(namesMen[i], answersMen[i]));
    men.sort(); women.sort();

    while(1){
        item w = women.front();
        list<item>::iterator itr, it;
        int diff = 10000;
        for(it = men.begin(); it != men.end(); it++){
            int ldiff = 0;
            for(int i = 0; i < it->pattern.size(); i++)
                if(w.pattern[i] != it->pattern[i]) ldiff++;
            if(ldiff < diff) {
                itr = it;
                diff = ldiff;
            }
        }
        if(w.name == queryWoman) return itr->name;
        men.erase(itr);
        women.erase(women.begin());
    }

}

int main(){
    string s = "Delilah";
    string sa[] = {"Constance", "Alice", "Bertha", "Delilah", "Emily"},
    sb[] = {"baabaa", "ababab", "aaabbb", "bababa", "baabba"},
    ta[] = {"Ed", "Duff", "Chip", "Abe", "Biff"},
    tb[] = {"aabaab", "babbab", "bbbaaa", "abbbba", "abaaba"};

    vector<string> va(sa, sa+5), vb(sb, sb+5), vc(ta, ta+5), vd(tb, tb+5);
    cout<<MatchMaking().makeMatch(va, vb, vc, vd, s);
    }
