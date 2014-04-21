#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class WinterAndReindeers
        {
        public:
        void lcs(string x, string y, int c[51][51]){
            int m = x.size(), n = y.size();
            for(int i = 1; i <= max(m, n); i++) c[i][0] = c[0][i] = 0;
            for(int i = 1; i <= m; i++)
            for(int j = 0; j <= n; j++)
                if(x[i] == y[j])
                    c[i][j] = c[i-1][j-1] + 1;
                else c[i][j] = max(c[i-1][j], c[i][j-1]);
            return;
        }

        set<string> backtrack(int c[51][51], string x, string y, int i, int j){
            set<string> s;
            if(i == 0 || j == 0) return s;
            else if(x[i] == y[j]){
                set<string> s1 = backtrack(c, x, y, i-1, j-1);
                for(set<string>::iterator it = s1.begin(); it != s1.end(); it++) s.insert(x[i]+(*it));
            }
            set<string> s1 = backtrack(c, x, y, i-1, j);
            s = backtrack(c, x, y, i, j-1);
            s.insert(s1.begin(), s1.end());
            return s1;
        }

        int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)
            {
                int c[51][51];
                string x, y, z;
                for(int i = 0; i < allA.size(); i++) x += allA[i];
                for(int i = 0; i < allB.size(); i++) y += allB[i];
                for(int i = 0; i < allC.size(); i++) z += allC[i];
                lcs(x, y, c);
                set<string> s = backtrack(c, x, y, x.size(), y.size());
                int mval = 0;
                for(set<string>::iterator it = s.begin(); it != s.end(); it++){
                    string st = *it;
                    if(st.find(z) != st::npos && st.size() > mval) mval = st.size();
                }
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABCXD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BCDEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"WE", "LOVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WORKING", "FOR", "SANTA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CDEAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AXBADXBBAB", "CDD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        WinterAndReindeers ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
