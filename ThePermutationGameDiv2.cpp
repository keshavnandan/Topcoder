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
#define mp(x, y) make_pair(x, y)
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

class ThePermutationGameDiv2{ 
        public: 
        ll gcd(ll a, ll b)
        {
            for (;;)
            {
                if (a == 0) return b;
                b %= a;
                if (b == 0) return a;
                a %= b;
            }
        }

        ll lcm(ll a, ll b)
        {
            ll temp = gcd(a, b);
            return  (max(a, b) / temp) * min(a, b);
        }
        ll findMin(int N){ 
            ll res = 1;
            for(ll i = 1; i <= N; i++){
                res = lcm(res, i);
            }
            return res;
        } 
        
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 2LL; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 6LL; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 6; long long Arg1 = 60LL; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 11; long long Arg1 = 27720LL; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 25; long long Arg1 = 26771144400LL; verify_case(4, Arg1, findMin(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){
        
       ThePermutationGameDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE 
