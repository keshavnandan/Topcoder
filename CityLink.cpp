#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <climits>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

class CityLink {
        public:
        int timeTaken(vector <int> x, vector <int> y)
        {
            int n = x.size();
            int d[55][55];
            set<int> A, B;
            for(int i = 0; i < n; i++){
                B.insert(i);
                for(int j = 0; j < n; j++){
                    int a = abs(x[i]-x[j]), b = abs(y[i]-y[j]);
                    if(a && b)  d[i][j] = max(a, b);
                    else if(a) d[i][j] = (a+1)/2;
                    else if(b) d[i][j] = (b+1)/2;
                }
            }
            A.insert(0); B.erase(0);
            int maxv = 0;
            while(!B.empty()){
                int a, b;
                int minv = INT_MAX;
                for(set<int>::iterator it = A.begin(); it != A.end(); it++){
                    int u = *it;
                    for(set<int>::iterator itr = B.begin(); itr != B.end(); itr++){
                        int v = *itr;
                        if(d[u][v] < minv){
                            a = u; b = v;
                            minv = d[u][v];
                        }
                    }
                }
                A.insert(b); B.erase(b);
                maxv = max(maxv, minv);
            }
            return maxv;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5}	; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, timeTaken(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30,-59}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(1, Arg2, timeTaken(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,
 27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,
 27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, timeTaken(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, timeTaken(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1593,-88517,14301,3200,6,-15099,3200,5881,-2593,11,57361,-92990}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {99531,-17742,-36499,1582,46,34001,-19234,1883,36001,0,233,485}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 73418; verify_case(4, Arg2, timeTaken(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        CityLink ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
