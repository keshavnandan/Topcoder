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

class Drbalance{
 		
 		int compute(string s){
 			int n = s.size(), count = 0, pos = 0, neg = 0;
 			fi(n){
 				if(s[i] == '+') pos++;
 				else neg++;
 				if(pos < neg) count++;
 			}
 			return count;
 		}

        public: 
        int lesscng(string s, int k) { 
            int num = 0, n = s.size();
            int count = compute(s);
            while(count > k){
            	fi(n){
            		if(s[i] == '-'){
            			s[i] = '+';
            			num++;
            			break;
            		}
            	}
            	count = compute(s);
            }
            return num;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "---"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "+-+-"; int Arg1 = 0; int Arg2 = 0; verify_case(1, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "-+-+---"; int Arg1 = 2; int Arg2 = 1; verify_case(2, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "-------++"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, lesscng(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "-+--+--+--++++----+"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, lesscng(Arg0, Arg1)); }

// END CUT HERE
         
}; 
// BEGIN CUT HERE 
int main(){

        Drbalance ___test; 
        ___test.run_test(-1); 

}
// END CUT HERE 
