#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdio>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class LostCharacter{ 
        public: 
        vs process(vs temp){
        	for(string &s : temp){
        		for(int i = 0; i < s.size(); i++) if(s[i] == '?') s[i] = 'z';
        	}
        	return temp;
        }
        vector <int> getmins(vector <string> str) {
           int n = str.size();
           vi res(n, 0);
           for(int j = 0; j < n; j++){
           	string s = str[j];
           	vs temp = str;
           	for(int i = 0; i < s.size(); i++) if(s[i] == '?') s[i] = 'a';
           	temp[j] = s;
           	temp = process(temp);
           	int k = 0;
           	sort(temp.begin(), temp.end());
           	for(k = 0; k < n && temp[k] != s; k++);
           	res[j] = k;
           }
           return res;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"abc","bcd","cde","cdf","bbc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 2, 3, 4, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getmins(Arg0)); }
	void test_case_1() { string Arr0[] = {"?ala","ara","baba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getmins(Arg0)); }
	void test_case_2() { string Arr0[] = {"a?","a","a","ab","aa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 0, 3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getmins(Arg0)); }
	void test_case_3() { string Arr0[] = {"s?nu?ke","sm??eke","?sna?ke","so?th?e","shake??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 2, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getmins(Arg0)); }
	void test_case_4() { string Arr0[] = {"?","z?","zz?","zzz?","zzzz?","zzzzz?","zzzzzz?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getmins(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        LostCharacter ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
