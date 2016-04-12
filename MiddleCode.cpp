#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class MiddleCode
        {
        public:
        string encode(string s)
            {
                string t;
                while(!s.empty()){
                    int n = s.size();
                    if(n % 2){
                        int k = n/2;
                        t += s.substr(k, 1);
                        s = s.substr(0, k) + s.substr(k+1);
                    }
                    else{
                        int k = n/2;
                        if(s[k-1] < s[k]) k = k-1;
                        t += s.substr(k, 1);
                        s = s.substr(0, k) + s.substr(k+1);
                    }
                }
                return t;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "word"; string Arg1 = "ordw"; verify_case(0, Arg1, encode(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaa"; string Arg1 = "aaaaa"; verify_case(1, Arg1, encode(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "caabbaa"; verify_case(2, Arg1, encode(Arg0)); }
	void test_case_3() { string Arg0 = "shjegr"; string Arg1 = "ejghrs"; verify_case(3, Arg1, encode(Arg0)); }
	void test_case_4() { string Arg0 = "adafaaaadafawafwfasdaa"; string Arg1 = "afawadafawafaafsadadaa"; verify_case(4, Arg1, encode(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        MiddleCode ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
