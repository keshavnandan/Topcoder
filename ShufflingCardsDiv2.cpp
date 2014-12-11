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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class ShufflingCardsDiv2{ 
        public: 
        string shuffle(vector <int> p) {
           int n = p.size();
           n /= 2;
           vi c, d;
           for(int i = 0; i < 2*n && i+1 < 2*n; i = i+2){
           	  c.push_back(p[i]);
           	  d.push_back(p[i+1]);
           }
           int n1 = n/2 + n%2, n2 = n/2;
           int a = 0, b = 0;
           for(int k : c){
           	  if(k <= n) a++;
           	  else b++;
           }
           cout<<a<<" "<<b<<endl;
           if(a == n1 && b == n2) return "Possible";
           	return "Impossible";
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {1,3,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {1,4,2,5,3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {8,5,4,9,1,7,6,10,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(4, Arg1, shuffle(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        ShufflingCardsDiv2 ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
