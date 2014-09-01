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
int M[55][55];
int v[55];
int n;

class Circuits {
        public:
        int dfs(int s, int c = 0){
            v[s] = 1;
            int rc = 0;
            for(int i = 0; i < n; i++){
                if((v[i] == 0 || v[i] == 2) && M[s][i]){
                    v[i] = 1;
                    rc = max(rc, dfs(i)+M[s][i]);
                }
            }
            v[s] = 2;
            return rc+c;
        }

        int howLong(vector <string> connects, vector <string> costs)
        {
            n = costs.size();
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    M[i][j] = 0;

            for(int i = 0; i < n; i++){
                string s = connects[i], t = costs[i];
                int j, c;
                stringstream ss(s), st(t);
                while(ss>>j){
                    st>>c;
                    M[i][j] = c;
                }
            }
            fill(v, v+55, 0);
            int c = 0;
            for(int i = 0; i < n; i++)
                if(v[i] == 0) c = max(c, dfs(i));
            return c;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2",
 "2",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 3",
 "7",
 ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, howLong(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, howLong(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1","2","3","","5","6","7",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2","2","2","","3","3","3",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, howLong(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"","2 3 5","4 5","5 6","7","7 8","8 9","10",
 "10 11 12","11","12","12",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","3 2 9","2 4","6 9","3","1 2","1 2","5",
 "5 6 9","2","5","3",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(3, Arg2, howLong(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"","2 3","3 4 5","4 6","5 6","7","5 7",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","30 50","19 6 40","12 10","35 23","8","11 20",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 105; verify_case(4, Arg2, howLong(Arg0, Arg1)); }

// END CUT HERE

 };

// BEGIN CUT HERE
int main(){

        Circuits ___test;
        ___test.run_test(-1);

}
// END CUT HERE
