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

class Apothecary{ 
        public:
        int next(int x){
            int i = 1;
            while(i < x) i *= 3;
            return i;
        }
        vi balance(int W){
            vi v[2];
            int n = W, m = 1;
            while(true){
                int k = next(n);
                if(k/2 < n){
                    v[m].push_back(k);
                    if(k == n) break;
                    n = k-n;
                    m = (m+1)%2;
                }
                else{
                    v[m].push_back(k/3);
                    n = n-k/3;
                }
            }
            vi r;
            for(int p : v[0]) r.push_back(-p);
            for(int p : v[1]) r.push_back(p);     
            sort(r.begin(), r.end());
            return r;
        } 
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { int Arg0 = 17; int Arr1[] = { -9,  -1,  27 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, balance(Arg0)); }
    void test_case_1() { int Arg0 = 1; int Arr1[] = { 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, balance(Arg0)); }
    void test_case_2() { int Arg0 = 2016; int Arr1[] = { -243,  -9,  81,  2187 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, balance(Arg0)); }
    void test_case_3() { int Arg0 = 1000000; int Arr1[] = { -531441,  -59049,  -6561,  -243,  -27,  1,  81,  729,  2187,  1594323 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, balance(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Apothecary ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
