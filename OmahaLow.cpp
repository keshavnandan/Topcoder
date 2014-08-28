#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

class OmahaLow {
        public:
        string low(string sharedCards, string playersCards)
        {
            set<int> A, B;
            for(char c : sharedCards)
                if(c <= '8') A.insert(c);
            for(char c : playersCards)
                if(c <= '8') B.insert(c);

            for(int i1 : A)
            for(int i2 : A)
            for(int i3 : A)
            for(int i4 : B)
            for(int i5 : B)
            {
                set<char> T;
                T.insert(i1);T.insert(i2);T.insert(i3);T.insert(i4);T.insert(i5);
                if(T.size() == 5){

                    string r;
                    for(char c : T) r.push_back(c);
                    sort(r.rbegin(), r.rend());
                    return r;
                }
            }
            return "";
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123QK"; string Arg1 = "45TJ"; string Arg2 = "54321"; verify_case(0, Arg2, low(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "55443"; string Arg1 = "2345"; string Arg2 = ""; verify_case(1, Arg2, low(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1357Q"; string Arg1 = "345J"; string Arg2 = "75431"; verify_case(2, Arg2, low(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "76285"; string Arg1 = "4816"; string Arg2 = "65421"; verify_case(3, Arg2, low(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "12345"; string Arg1 = "3339"; string Arg2 = ""; verify_case(4, Arg2, low(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "58463"; string Arg1 = "947K"; string Arg2 = "76543"; verify_case(5, Arg2, low(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "67521"; string Arg1 = "J859"; string Arg2 = "86521"; verify_case(6, Arg2, low(Arg0, Arg1)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        OmahaLow ___test;
        ___test.run_test(-1);

}
// END CUT HERE
