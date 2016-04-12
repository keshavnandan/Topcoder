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
#include <string>
using namespace std;

template <typename T>
string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

class UserName {
public:
	string newMember(vector <string>, string);
};

string UserName::newMember(vector <string> existingNames, string newName) {

    set<string> st(existingNames.begin(), existingNames.end());
    char s[1024];
    int num = 0;
    while(1){
        if(num == 0)
            sprintf(s, "%s", newName.c_str());
        else
            sprintf(s, "%s%d", newName.c_str(), num);
        if(st.find(string(s)) == st.end())  break;
        num++;
    }
    return string(s);
}

int main(){
    string s = "TygerTyger";
    string sa[] = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",
 "TygerTyger", "WolfMan", "MrKnowItAll"};
    vector<string> vs(sa, sa+7);
    cout<<UserName().newMember(vs,s)<<endl;

}
