#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int sol[10][100];
vector<int> m;
int col[10];

class WeirdRooks {
        public:
        void fun(int r, int nr, int ns){

            if(r < 0){
                sol[nr][ns] = 1;
                return;
            }

            int ts = 0;
            for(int j = m[r]-1; j >= 0; j--){
                if(!col[j]){
                    col[j] = 1;
                    fun(r-1, nr+1, ns+ts);
                    col[j] = 0;
                    ts++;
                }
            }
            fun(r-1, nr, ns+ts);
        }

        string describe(vector <int> cols)
        {
            memset(sol, 0, 1000*sizeof(int));
            m = cols;
            string ret = "";
            fun(cols.size()-1, 0, 0);
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 100; j++)
                if(sol[i][j]){
                    char s[10];
                    sprintf(s, "%d,%d", i, j);
                    if(ret.size()) ret += ' ';
                    ret += s;
                }
            }

            return ret;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,9 1,4 1,5 1,6 1,7 1,8 2,1 2,2 2,3 2,4 2,5 2,6 3,0 3,1 3,2 3,3"; verify_case(0, Arg1, describe(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,6 1,3 1,4 1,5 2,1 2,2 2,3 3,0"; verify_case(1, Arg1, describe(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,1 1,0"; verify_case(2, Arg1, describe(Arg0)); }
	void test_case_3() { int Arr0[] = {2,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0,11 1,2 1,3 1,4 1,5 1,6 1,7 1,8 1,9 1,10 2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7 2,8"; verify_case(3, Arg1, describe(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        WeirdRooks ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
