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
int a[50], b[50];

class BadNeighbors{ 
        public: 
        int maxDonations(vector <int> d){
            int maxDonation = 1, n = d.size();
            for(int i = 0; i+1 < n; i++){
                a[i] = d[i];
                int maxa = 0;
                for(int j = 0; j+1 < i; j++) maxa = max(maxa, a[j]);
                a[i] += maxa;
                maxDonation = max(maxDonation, a[i]);
            }
            for(int i = 1; i < n; i++){
                b[i] = d[i];
                int maxb = 0;
                for(int j = 1; j+1 < i; j++) maxb = max(maxb, b[j]);
                b[i] += maxb;
                maxDonation = max(maxDonation, b[i]);
            }
            return maxDonation;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] =  { 10, 3, 2, 5, 7, 8 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxDonations(Arg0)); }
	void test_case_1() { int Arr0[] = { 11, 15 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, maxDonations(Arg0)); }
	void test_case_2() { int Arr0[] = { 7, 7, 7, 7, 7, 7, 7 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, maxDonations(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, maxDonations(Arg0)); }
	void test_case_4() { int Arr0[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2926; verify_case(4, Arg1, maxDonations(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        BadNeighbors ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
