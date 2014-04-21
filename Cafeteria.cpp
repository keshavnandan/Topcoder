#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Cafeteria
        {
        public:
        string latestTime(vector <int> offset, vector <int> walkingTime, vector <int> drivingTime)
            {
                int rettime = 0;
                for(int i = 0; i < offset.size(); i++){
                    int xtime = 870 - drivingTime[i], xhour = xtime/60, xmin = xtime%60;
                    if(offset[i] <= xmin){
                        while(offset[i]+10 <= xmin) offset[i] += 10;
                    }
                    else{
                        offset[i] += 50;
                        xhour--;
                    }
                    rettime = max(rettime, xhour*60+offset[i]-walkingTime[i]);
                }
                int rhour = rettime/60, rmin = rettime%60;
                if(rhour > 12) rhour -= 12;
                char s[10];
                sprintf(s, "%02d:%02d", rhour, rmin);
                return string(s);
            }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "02:28"; verify_case(0, Arg3, latestTime(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {120}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "12:17"; verify_case(1, Arg3, latestTime(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {120,121}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "12:19"; verify_case(2, Arg3, latestTime(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11,11,11,11,11,11,11,11,11,11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {190,190,190,190,190,190,190,190,190,190}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "11:09"; verify_case(3, Arg3, latestTime(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {7,4,0,0,2,1,6,7,7,0,8,6,0,5,0,6,7,9,0,2,4,8,4,7,
9,2,4,4,3,1,4,5,8,8,2,5,7,8,7,5,6,8,8,0,1,3,5,0,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26,14,1,4,16,28,16,6,4,5,21,18,5,2,21,21,28,22,5,22,26,16,14,
19,19,19,4,12,24,4,30,16,28,20,25,2,30,18,4,6,9,22,8,3,7,29,8,30,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {151,264,280,89,63,57,15,120,28,296,76,269,90,106,31,222,
291,52,102,73,140,248,44,187,76,49,296,106,54,119,54,283,263,
285,275,127,108,82,84,241,169,203,244,256,109,288,9,262,103}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "02:07"; verify_case(4, Arg3, latestTime(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        Cafeteria ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
