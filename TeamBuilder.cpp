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

class TeamBuilder{ 
        public: 
        vector <int> specialLocations(vector <string> paths) {

            int n = paths.size();
            int D[55][55][55];
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++){
                    D[i][j][0] = paths[i-1][j-1] - '0';
                    if(i == j) D[i][j][0] = 1;
                }

                for(int k = 1; k <= n; k++)
                   for(int i = 1; i <= n; i++)
                        for(int j = 1; j <= n; j++)
                            D[i][j][k] = ( D[i][j][k-1] | (D[i][k][k-1] & D[k][j][k-1]) );

                vector<int> to(55, 0), from(55, 0);
                for(int i = 1; i <= n; i++)
                    for(int j = 1; j <= n; j++)
                        if(D[i][j][n] == 1){
                            to[j]++;
                            from[i]++;
                        }

                int t = 0, f = 0;
                for(int i = 1; i <= n; i++){
                    if(to[i] == n)  t++;
                    if(from[i] == n) f++;
                }

                vector<int> res;
                res.push_back(f);
                res.push_back(t);
                return res;
        } 
        
// BEGIN CUT HERE
        public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
        private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
        void test_case_0() { string Arr0[] = {"00000000001000", "00000000000000", "10000010001001", "00000000000000", "00000000011000", "00000000000000", 
        "00000000010000", "00100100000000", "10000000000000", "11000110000000", "01000000000000", "01000001000000", "00000000000000", "10000000000000"}; 
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, specialLocations(Arg0)); }
        void test_case_1() { string Arr0[] = {"0010","1000","1100","1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, specialLocations(Arg0)); }
        void test_case_2() { string Arr0[] = {"01000","00100","00010","00001","10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 5,  5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, specialLocations(Arg0)); }
        void test_case_3() { string Arr0[] = {"0110000","1000100","0000001","0010000","0110000","1000010","0001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, specialLocations(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        TeamBuilder ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
