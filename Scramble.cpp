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
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

class Scramble{ 
        public: 
        string scrambleWord(string text) {
            int n = text.size();
            string startS = string(1, text[0]), endS = string(1, text[n-1]);
            string temp = text.substr(1, n-2);
            sort(temp.begin(), temp.end());
            int start = 1;
            while(!temp.empty())  {
                string t = string(1, temp[0]);
                if(start) startS += t;
                else endS = t + endS;
                temp = temp.substr(1);
                start = (start + 1)%2;
            }
            return startS + endS;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "alphabet"; string Arg1 = "aaelphbt"; verify_case(0, Arg1, scrambleWord(Arg0)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"; string Arg1 = "aabcdefghijklmnopqrstuvwyzxwvutsrqponmlkjihgfedcbx"; verify_case(1, Arg1, scrambleWord(Arg0)); }
	void test_case_2() { string Arg0 = "aa"; string Arg1 = "aa"; verify_case(2, Arg1, scrambleWord(Arg0)); }
	void test_case_3() { string Arg0 = "abdfheca"; string Arg1 = "abdfheca"; verify_case(3, Arg1, scrambleWord(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaa"; string Arg1 = "aaaaaaaaa"; verify_case(4, Arg1, scrambleWord(Arg0)); }
	void test_case_5() { string Arg0 = "uodoutivesbegckw"; string Arg1 = "ubdeiosuvtokgecw"; verify_case(5, Arg1, scrambleWord(Arg0)); }
	void test_case_6() { string Arg0 = "zaabz"; string Arg1 = "zabaz"; verify_case(6, Arg1, scrambleWord(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Scramble ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
