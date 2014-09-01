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
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;
int M[35][35];
int l[35];
int n;

class Marketing {
        public:
        int dfs(int s){
            int x = l[s];
            for(int p = 0; p < n; p++){
                if(M[s][p]){
                    if(l[p] == x) return -1;
                    if(l[p] == -1){
                        l[p] = (x^1);
                        if(dfs(p) == -1) return -1;
                    }
                }
            }
            return 1;
        }

        long long howMany(vector <string> comp)
        {
            n = comp.size();
            fill(l, l+n+1, -1);
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    M[i][j] = 0;

            for(int i = 0; i < n; i++){
                string s = comp[i];
                stringstream ss(s);
                int j;
                while(ss>>j) M[i][j] = M[j][i] = 1;
            }
            int c = 1;
            for(int i = 0; i < n; i++)
            if(l[i] == -1){
                l[i] = 1;
                if(dfs(i) == -1) return -1;
                c *= 2;
            }
            return c;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 4","2","3","0",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1","2","0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"1","2","3","0","0 5","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"","","","","","","","","","",
 "","","","","","","","","","",
 "","","","","","","","","",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1073741824LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"1","2","3","0","5","6","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = -1LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        Marketing ___test;
        ___test.run_test(-1);

}
// END CUT HERE
