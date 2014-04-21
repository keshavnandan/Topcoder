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
	int pos = 0;
	string pattern = "";
	for(pos = newName.size()-1; pos > 0 && isdigit(newName[pos]); pos--); pos++;
		pattern = newName.substr(0, pos);
		vector<int> l;
		for(int i = 0; i < existingNames.size(); i++){
            string s = existingNames[i];
            if(s.size() >= pos)
			if(s.substr(0, pos) == pattern){
				int num = 0;
				if(s.size() != pos)
					num = atoi((s.substr(pos, s.size()-pos)).c_str());
				l.push_back(num);
			}
		}
		sort(l.begin(), l.end());
		if(l.size() == 0 || l[0] != 0)     return pattern;
		if(l.size() == 1) return pattern + "1";
		int i = 0;
		for(;i < l.size()-1 && (l[i+1]-l[i]) == 1; i++);
			return pattern + NumberToString((l[i]+1));
}

int main(){
    string s = "TygerTyger";
    string sa[] = {"MasterOfDisaster", "TygerTyger1", "DingBat", "Orpheus",
 "TygerTyger", "WolfMan", "MrKnowItAll"};
    vector<string> vs(sa, sa+7);
    cout<<UserName().newMember(vs,s)<<endl;

}
//Powered by [KawigiEdit] 2.0!
