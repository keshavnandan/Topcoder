// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class LittleElephantAndDouble
        {
        public:
        bool isPowerOfTwo(long  long n)
        {
          return !(n&(n-1));
        }
        string getAnswer(vector <int> A)
            {
                long  long  t = *min_element(A.begin(), A.end());
                bool ret = true;
                for(long  long  i = 0; i < A.size() && ret; i++){
                    if(A[i] != t){
                        if(A[i]%t != 0 || isPowerOfTwo(A[i]/t) == 0) ret = false;
                    }
                }
                if(ret) return "YES";
                return "NO";
            }

// BEGIN CUT HERE
	public:
	void run_test(long  long Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(long  long Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long  long Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, getAnswer(Arg0)); }
	void test_case_1() { long  long Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, getAnswer(Arg0)); }
	void test_case_2() { long  long Arr0[] = {4, 8, 2, 1, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, getAnswer(Arg0)); }
	void test_case_3() { long  long Arr0[] = {94, 752, 94, 376, 1504}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(3, Arg1, getAnswer(Arg0)); }
	void test_case_4() { long  long Arr0[] = {148, 298, 1184}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, getAnswer(Arg0)); }
	void test_case_5() { long  long Arr0[] = {7, 7, 7, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(5, Arg1, getAnswer(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        LittleElephantAndDouble ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
