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
struct interval{
	int s, f;
	interval(int s, int f) : s(s), f(f) {}
};

bool operator<(interval a, interval b){
	return a.f < b.f || (a.f == b.f && a.s < b.s);
}

class Boxing{ 
        public: 
        int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) { 
        	set<interval> S;
        	string s = "00111";
        	do{
        		vvi t(3);
        		int k = 0;
        		for(int i = 0; i < 5; i++){
        			if(s[i] == '1'){
        				switch(i){
        					case 0:
        					t[k] = a;
        					break;
							case 1:
        					t[k] = b;
        					break;
        					case 2:
        					t[k] = c;
        					break;
        					case 3:
        					t[k] = d;
        					break;
        					case 4:
        					t[k] = e;        					
      						break;
        				}
        				k++;
        			}
				}

    			for(int x : t[0])
    				for(int y : t[1])
    					for(int z : t[2]){
    						int mi = min(x, min(y, z)), mx = max(x, max(y, z));
    						if(mx - mi <= 1000)
    							S.insert(interval(mi, mx));
    					}
        	}
        	while(next_permutation(s.begin(), s.end()));
        	int lf = -1, r = 0;
        	for(interval t : S)
        		if(lf < t.s){
        			lf = t.f;
        			r++;
        		}
        	
        	return r;
        } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3,4,5,6,7,8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 6; verify_case(0, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {100,200,300,1200,6000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {900,902,1200,4000,5000,6001}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,2000,6002}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2,3,4,5,6,7,8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(1, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {5000,6500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6500}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,5800,6000}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(2, Arg5, maxCredit(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Boxing ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
