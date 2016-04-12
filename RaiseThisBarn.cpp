// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class RaiseThisBarn
        {
        public:
        int calc(string str)
            {
                int count = 0;
                for(int i = 0; i < str.size(); i++)
                    if(str[i] == 'c') count++;
                if(count%2) return 0;
                if(count == 0) return str.size()-1;
                int id = 0; int nc = 0;
                while(true){
                    if(nc == count/2) break;
                    if(str[id++] == 'c') nc++;
                }
                int n = 1;
                while(str[id++] == '.') n++;
                cout<<n<<endl;
                return n;
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cc..c.c"; int Arg1 = 3; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arg0 = "c....c....c"; int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arg0 = "............"; int Arg1 = 11; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc"; int Arg1 = 3; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        RaiseThisBarn ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
