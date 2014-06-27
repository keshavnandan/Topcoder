#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
long long A[100][100];
long long B[100][100];

class ChessMetric {
        public:
        long long howMany(int n, vector <int> start, vector <int> end, int numMoves)
        {
            int s[16][2] = {1,1,-1,1,1,-1,-1,-1,1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1,0,1,0,-1,1,0,-1,0};

            memset(A, 0, sizeof(A));
            memset(B, 0, sizeof(B));
            int i = end[0], j = end[1];
            for(int k = 0; k < 16; k++)
            {
                int x = i+s[k][0], y = j+s[k][1];
                if(x < n && y < n && x >= 0 && y >= 0){
                    A[x][y] = 1ll;
//                                cout<<x<<" "<<y<<endl;
                }
            }


            if(numMoves == 1) return A[start[0]][start[1]];

            for(int ss = 2; ss <= numMoves; ss++){
                if(ss%2) memset(A, 0, sizeof(A));
                 else    memset(B, 0, sizeof(B));

                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        for(int k = 0; k < 16; k++)
                        {
                            int x = i+s[k][0], y = j+s[k][1];
                            if(x < n && y < n && x >= 0 && y >= 0){
//                                cout<<x<<" "<<y<<endl;
                                if(ss%2 && B[x][y]) A[i][j] += B[x][y];
                                else if(!(ss%2) && A[x][y]) B[i][j] += A[x][y];
                            }
                        }
            }

            if(numMoves%2)
                return A[start[0]][start[1]];
            return B[start[0]][start[1]];

        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(0, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 1LL; verify_case(1, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; long long Arg4 = 0LL; verify_case(2, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; long long Arg4 = 5LL; verify_case(3, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,99}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; long long Arg4 = 243097320072600LL; verify_case(4, Arg4, howMany(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        ChessMetric ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
