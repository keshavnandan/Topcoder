#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
using namespace std;

class MNS
        {
        public:
        long fun(vector<int> v){
            long sum = 0;
            for(int i = 0; i < v.size(); i++) sum = 10*sum + v[i];
            return sum;
        }
        int combos(vector <int> numbers)
        {
            set<long> S;
            int sum = accumulate(numbers.begin(), numbers.end(), 0);
            sort(numbers.begin(), numbers.end());
            do{
                int k = sum/3;
                int a1 = numbers[0], b1 = numbers[1], c1 = numbers[2];
                int a2 = numbers[3], b2 = numbers[4], c2 = numbers[5];
                int a3 = numbers[6], b3 = numbers[7], c3 = numbers[8];
                if(a1 + a2 + a3 == k && b1 + b2 + b3 == k && c1 + c2 + c3 == k && a1 + b1 + c1 == k && a2 + b2 + c2 == k && a3 + b3 + c3 == k) S.insert(fun(numbers));
            }
            while(next_permutation(numbers.begin(), numbers.end()));
            return S.size();
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,3,2,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, combos(Arg0)); }
	void test_case_1() { int Arr0[] = {4,4,4,4,4,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, combos(Arg0)); }
	void test_case_2() { int Arr0[] = {1,5,1,2,5,6,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(2, Arg1, combos(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,6,6,6,4,2,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, combos(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        MNS ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
