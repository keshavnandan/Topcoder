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
#include <stack>
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

stack<ll> s;

class Suminator{
 
 		ll cal(vi &vv){

 			stack<ll> v;
 			v.push(0);

 			for(int k : vv){

				ll x = 0;

				if(k == 0){
		 			if(!v.empty()){

		 				ll t = v.top();
			 			cout<<"top element is "<<t<<endl;
			 			if(t != -1) x += t;
		 				v.pop();
		 			}
		 			if(!v.empty()){

		 				ll t = v.top();
			 			cout<<"next top element is "<<t<<endl;
			 			if(t != -1) x += t;
		 				v.pop();
		 			}
		 			v.push(x);
	 			}
	 			else {
	 				v.push(k);
	 			}
	 			// cout<<"[ ";
	 			// for(int i : v) cout<<i<<" ";
	 			// cout<<"]\n";
 			}
 			return v.top();

 		}

 		bool isReachable(vi v){
 			
 			s.push(0);
 			for(int i : v){
 				if(i == 0){
 					ll t = 0;
 					if(!s.empty()){
 						if(s.top() == -1) return true;
 						t += s.top();
 						s.pop();
 					}
					if(!s.empty()){
						if(s.top() == -1) return true;
 						t += s.top();
						s.pop();
					}
					s.push(t);
 				}
 				else {
 					s.push(i);
 				}
 			}
 			// if(s.top() == -1) return true;
 			// return false;	
 		
 			vi a = v, b = v;
 			replace(a.begin(), a.end(), -1, 100);
 			replace(b.begin(), b.end(), -1, 200);
 			if(cal(a) == cal(b)) return false;
 			return true;

 		}

        public: 
        int findMissing(vector <int> program, int wantedResult) { 
            
        	if(!isReachable(program)){
        		cout<<"Not Reachable"<<endl;
    			return s.top() == wantedResult ? 0 : -1;
        	}
        	vi temp = program;
        	replace(program.begin(), program.end(), -1, 0);
        	if(cal(program) == wantedResult) return 0;
        	program = temp;
        	ll t = cal(program);
    		if(t == -1) return wantedResult;
        	if(t >= wantedResult || abs((ll)wantedResult - t) >= 1000000000) return -1;
        	return wantedResult - t;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {7,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(0, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {100, 200, 300, 0, 100, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 600; int Arg2 = 0; verify_case(1, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 7, 3, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 0; verify_case(2, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 8, 4, 0, 1, 2, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = -1; verify_case(3, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; int Arg2 = -1; verify_case(4, Arg2, findMissing(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7, -1, 3, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(5, Arg2, findMissing(Arg0, Arg1)); }

// END CUT HERE
         
}; 
// BEGIN CUT HERE 
int main(){

        Suminator ___test; 
        ___test.run_test(-1); 

}
// END CUT HERE 
