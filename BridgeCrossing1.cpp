
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class BridgeCrossing
        {
        multiset<int> AA, BB;
        public:
        int fA(multiset<int> A, multiset<int> B, int cost){
            int n = A.size();
//            cout<<n<<endl;
            if(n == 1) return *A.begin();
            if(n == 2) return *max_element(A.begin(), A.end()) + cost;
            vector<int> v(A.begin(), A.end());
            int minv = 1000000000;
            for(int i = 0; i < n-1; i++){
                for(int j = i+1; j < n; j++){
                    int a  = v[i], b = v[j];
                    A.erase(A.find(a)); A.erase(A.find(b));
//                    A.erase(a);  A.erase(b);
                    B.insert(a); B.insert(b);
                    minv = min(minv, fB(A, B, cost + max(a, b)));
                    A.insert(a); A.insert(b);
                    B.erase(B.find(a)); B.erase(B.find(b));
//                    B.erase(a); B.erase(b);
                }
            }
            return minv;
        }
        int fB(multiset<int> A, multiset<int> B, int cost){
            int n = B.size();
//            cout<<endl;
            int minv = 1000000000;
            vector<int> v(B.begin(), B.end());
            for(int i = 0; i < n; i++){
                int a = v[i];
                A.insert(a); //B.erase(a);
                B.erase(B.find(a));
                minv = min(minv, fA(A, B, cost + a));
                A.erase(A.find(a)); //A.erase(a);
                B.insert(a);
            }
            return minv;
        }
        int minTime(vector <int> times)
        {
            multiset<int> AA(times.begin(), times.end());
            multiset<int> BB;
            return fA(AA, BB, 0);
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 2, 5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { int Arr0[] = { 100, 100, 100, 100, 100, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }

// END CUT HERE
        };

// BEGIN CUT HERE
     int main()
     {
        BridgeCrossing ___test;
        ___test.run_test(-1);
     }
// END CUT HERE


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
