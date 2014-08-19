#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <climits>
#define cmpl(A, X) for(int i = 1; i <= 9; i++) if(find((A).begin(), (A).end(), i) == (A).end()) (X).push_back(i);
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef set<int> si;
int maxv = 1000000;
int pd[4] = {0, 2, 4, 8};
int pp[4] = {1, 3, 5, 7};
vi v = {1,2,3,4,5,6,7,8,9};

class Fifteen {
        public:
        //P plays maxv means P lose and win otherwise
        int f(vi A, int p){
            vi M;
            for(int i = p; i < A.size(); i+=2)
                M.push_back(A[i]);
            sort(M.begin(), M.end());
            for(int a : M)
                for(int b : M)
                    for(int c : M)
                        if(a != b && b != c && c != a && a+b+c == 15) return 1;
            int q = (p == 0 ? 1 : 0);
            if(A.size() == 9) return q;

            vi X, XX;
            cmpl(A, X);
            XX = A;
            for(int r : X){
                XX.push_back(r);
                if(f(XX, q)) return 0;
                XX.pop_back();
            }

            return 1;
        }

        string outcome(vector <int> moves)
        {
            vi X;
            cmpl(moves, X);
            vi XX = moves;
            for(int r : X){
                XX.push_back(r);
                if(f(XX, 1)) return "WIN "+to_string(r);
                XX.pop_back();
            }
            return "LOSE";
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7, 5, 9, 6, 8, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 4"; verify_case(0, Arg1, outcome(Arg0)); }
	void test_case_1() { int Arr0[] = {4, 8, 6, 5, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(1, Arg1, outcome(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 4, 7, 6, 9, 8, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 1"; verify_case(2, Arg1, outcome(Arg0)); }
	void test_case_3() { int Arr0[] = {9, 2, 1, 6, 3, 4, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 5"; verify_case(3, Arg1, outcome(Arg0)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LOSE"; verify_case(4, Arg1, outcome(Arg0)); }
	void test_case_5() { int Arr0[] = {6, 3, 7, 8, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WIN 2"; verify_case(5, Arg1, outcome(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        Fifteen ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
