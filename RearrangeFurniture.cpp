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

class RearrangeFurniture{ 
        public: 
        int lowestEffort(vi weights, vi finalPositions) {
            int total = 0, n = weights.size();
            int m = *min_element(weights.begin(), weights.end());
            int done[55];
            fill(done, done+50, 0);
            for(int i = 0; i < n; i++){
                if(done[i]) continue;
                int cost = 0, j = i, cm = weights[i], c = 0;

                while(true){
                    c++;
                    done[j] = 1;
                    cm = min(cm, weights[j]);
                    cost += weights[j];
                    j = finalPositions[j];
                    if(j == i) break;
                }
                total += min(cost + (c-2)*cm, cm + m + cost + c*m);
            }
            return total;
        }
        
// BEGIN CUT HERE
        public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
        private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { int Arr0[] = {5, 4, 7, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 0, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 33; verify_case(0, Arg2, lowestEffort(Arg0, Arg1)); }
        void test_case_1() { int Arr0[] = {3, 6, 2, 4, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, lowestEffort(Arg0, Arg1)); }
        void test_case_2() { int Arr0[] = {10, 3, 123, 498, 12, 13, 14, 45, 32, 67,
 111, 234, 543, 2, 12, 1, 56, 67, 78, 89,
 12, 90, 23, 77, 345, 543, 242, 560, 121, 232,
 980, 10000, 12, 1, 6, 98, 67, 44, 21, 456,
 3231, 456, 23, 14, 678, 65, 45, 23, 99, 23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {49, 48, 47, 46, 45, 44, 43, 42, 41, 40,
 39, 38, 37, 36, 35, 34, 33, 32, 31, 30,
 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,
 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20597; verify_case(2, Arg2, lowestEffort(Arg0, Arg1)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        RearrangeFurniture ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
