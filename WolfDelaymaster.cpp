// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class WolfDelaymaster
        {
        public:
        string check(string str)
            {
//                cout<<str<<endl;
                int n = str.size();
                if(n < 4) return "INVALID";
                int i = 0;
                while(i < n && str[i] != 'f') i++;
                int j = 0;
                while(i < n && str[i] == 'f') {
                i++; j++;
                }
                if(j == 0) return "INVALID";
//                cout<<"i = "<<i<<", j = "<<j<<endl;
                int k = 0;
                for(int l = 0; l < j; l++, k++) {if(str[k] != 'w') return "INVALID";}
                for(int l = 0; l < j; l++, k++) {if(str[k] != 'o') return "INVALID";}
                for(int l = 0; l < j; l++, k++) {if(str[k] != 'l') return "INVALID";}
                for(int l = 0; l < j; l++, k++) {if(str[k] != 'f') return "INVALID";}
                if(i < n){
                    if(check(str.substr(i)) == "INVALID") return "INVALID";
                }
                return "VALID";

            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wolf"; string Arg1 = "VALID"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "wwolfolf"; string Arg1 = "INVALID"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff"; string Arg1 = "VALID"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "flowolf"; string Arg1 = "INVALID"; verify_case(3, Arg1, check(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        WolfDelaymaster ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
