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
#include <cctype>
using namespace std;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

class TranspositionKey{ 
        public: 
        vector <int> makeKey(string text) { 
           string s;
           for(char c : text)
            if(isalpha(c)) s.push_back(tolower(c));
            int start = 0, n = s.size();
            vi res(n);
            cout<<s<<endl;
            for(int i = 'a'; i <= 'z'; i++){
                char c = char(i);
                for(int j = 0; j < n; j++)
                    if(s[j] == c) res[j]  = ++start;
            }
            return res;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "aaa"; int Arr1[] = {1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeKey(Arg0)); }
	void test_case_1() { string Arg0 = "ywedkcjs"; int Arr1[] = {8, 7, 3, 2, 5, 1, 4, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeKey(Arg0)); }
	void test_case_2() { string Arg0 = "Quoth the raven, Nevermore."; int Arr1[] = {14, 20, 12, 18, 7, 19, 8, 2, 15, 1, 21, 3, 10, 11, 4, 22, 5, 16, 9, 13, 17, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeKey(Arg0)); }
	void test_case_3() { string Arg0 = "Fuzzy wuzzy was a bear."; int Arr1[] = {6, 9, 15, 16, 13, 11, 10, 17, 18, 14, 12, 1, 8, 2, 4, 5, 3, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, makeKey(Arg0)); }
	void test_case_4() { string Arg0 = "UCC Event"; int Arr1[] = {7, 1, 2, 3, 8, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, makeKey(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        TranspositionKey ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
