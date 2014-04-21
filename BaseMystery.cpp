// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

 class BaseMystery { 
        public: 
        vector <int> getBase(string equation) { 

          } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "1+1=2"; int Arr1[] = { 3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getBase(Arg0)); }
	void test_case_1() { string Arg0 = "1+1=10"; int Arr1[] = { 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getBase(Arg0)); }
	void test_case_2() { string Arg0 = "1+1=3"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getBase(Arg0)); }
	void test_case_3() { string Arg0 = "ABCD+211=B000"; int Arr1[] = { 14 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getBase(Arg0)); }
	void test_case_4() { string Arg0 = "ABCD+322=B000"; int Arr1[] = { 15 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getBase(Arg0)); }
	void test_case_5() { string Arg0 = "1+0=1"; int Arr1[] = { 2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getBase(Arg0)); }
	void test_case_6() { string Arg0 = "GHIJ+1111=HJ00"; int Arr1[] = { 20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getBase(Arg0)); }
	void test_case_7() { string Arg0 = "1234+8765=9999"; int Arr1[] = { 10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(7, Arg1, getBase(Arg0)); }

// END CUT HERE
 
 }; 

    // BEGIN CUT HERE 
int main(){
        BaseMystery ___test; 
        ___test.run_test(-1); 
} 
    // END CUT HERE 
