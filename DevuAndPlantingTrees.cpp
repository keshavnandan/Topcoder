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
typedef long long ll;
#define sz size()
#define mp make_pair
#define pb push_back
#define ri(a, b) for(int i=((int)(a)); i < ((int)(b)); i++)                // i -> [a, b)
#define rie(a, b) for(int i=((int)(a)); i <= ((int)(b)); i++)            // i -> [a, b]
#define rj(a, b) for(int j=((int)(a)); j < ((int)(b)); j++)               // j -> [a, b)
#define rje(a, b) for(int j=((int)(a)); j <= ((int)(b)); j++)           // j -> [a, b]
#define rk(a, b) for(int k=((int)(a)); k < ((int)(b)); k++)           // k -> [a, b)
#define rke(a, b) for(int k=((int)(a)); k <= ((int)(b)); k++)       // k -> [a, b]
#define fi(b) for(int i=0; i < ((int)(b)); i++)                             // i -> [0, b)
#define fie(b) for(int i=0; i <= ((int)(b)); i++)                         // i -> [0, b]
#define fj(b) for(int j=0; j < ((int)(b)); j++)                            // j -> [0, b)
#define fje(b) for(int j=0; j <= ((int)(b)); j++)                        // j -> [0, b]
#define fk(b) for(int k=0; k < ((int)(b)); k++)                        // k -> [0, b)
#define fke(b) for(int k=0; k < ((int)(b)); k++)                      // k -> [0, b]
#define fle(b) for(int l=0; l <= ((int)(b)); l++)                        // l -> [0, b]
int n;
#define valid(x, y) ( 0 <= (x) && (x) < 2 && 0 <= (y) && (y) < n )
int A[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int B[8] = {0, 0, 1, -1, -1, 1, -1, 1};

class DevuAndPlantingTrees{
 
    public: 
    int maximumTreesDevuCanGrow(vector <string> garden){ 

        n = garden[0].size();
        vs temp = garden;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++){
                if(garden[i][j] != '*')  continue;
                fk(8){
                    int ii = i + A[k], jj = j + B[k];
                    if(valid(ii, jj) && garden[ii][jj] == '.') garden[ii][jj] = 'x';
                }
            }
        fi(2){
         fj(n) cout<<garden[i][j];
         cout<<endl;
        }
        fi(2) fj(n) {
            if(garden[i][j] != '.') continue;
            garden[i][j] = '*';
            fk(8){
                int ii = i + A[k], jj = j + B[k];
                if(valid(ii, jj) && garden[ii][jj] == '.') garden[ii][jj] = 'x';
            }            
        }
        int c = 0;
        fi(2) fj(n) if(garden[i][j] == '*') c++;
        return c;
    } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..", ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_1() { string Arr0[] = {"..", ".*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_2() { string Arr0[] = {"...",
"..*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_3() { string Arr0[] = {".....*..........",
".*.......*.*..*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_4() { string Arr0[] = {"....*.*.*...........*........",
"*..........*..*.*.*....*...*."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, maximumTreesDevuCanGrow(Arg0)); }
	void test_case_5() { string Arr0[] = {".....*..*..........*............................*",
"*..*.............*...*.*.*.*..*.....*.*...*...*.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(5, Arg1, maximumTreesDevuCanGrow(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        DevuAndPlantingTrees ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
