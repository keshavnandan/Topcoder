#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;
struct node{
    int h;
    int b;
    int w;
    node(int hh = 0, int bb = 0, int ww = 0){ h = hh; b = bb; w = ww;}
};
bool operator<(const node &l, const node &r){
        return l.h < r.h;
}
vector<node> A;
int done[1005];
int B[1005][1005];
int n;
void find_block(){

    vector<int> r(n);
    fill(r.begin(), r.end(), 0);
    for(int i = 0; i < n; i++){
        node p = A[i];
        for(int j = 0; j < n; j++){
            node q = A[j];
            if(j != i && !done[j] && (q.h < p.h) && ((q.b <= p.b && p.b <= q.w) || (q.b <= p.w && p.w <= q.w) || (p.b <= q.b && q.b <= p.w) || (p.b <= q.w && q.w <= p.w))){
                B[i][j] = 1;
                cout<<q.h<<" is blocked by "<<p.h<<endl;
            }
        }
    }
}

class FlowerGarden {
        public:
        vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
        {
            n = height.size();
            vector<int> ret;
            A.resize(n);
            memset(done, 0, sizeof(done));
            memset(B, 0, sizeof(B));
            for(int i = 0; i < n; i++) A[i] = node(height[i], bloom[i], wilt[i]);
            sort(A.rbegin(), A.rend());
            find_block();
            for(int k = 0; k < n; k++){
                int block[1005];
                memset(block, 0, sizeof(block));
                for(int i = 0; i < n; i++)
                    for(int j = i+1; j < n; j++)
                        if(B[i][j] && !done[j]){
                            block[i] = 1;
                            j = n;
                        }

                for(int i = 0; i < n; i++)
                    if(!block[i] && !done[i]){
                        ret.push_back(A[i].h);
                        done[i] = 1;
                        i = n;
                    }

            }
            return ret;
        }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {365,365,365,365,365}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  2,  3,  4,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, getOrdering(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,10,15,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,9,14,19,24}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 5,  4,  3,  2,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, getOrdering(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,10,15,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,10,15,20,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  2,  3,  4,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, getOrdering(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,10,15,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,10,14,20,25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 3,  4,  5,  1,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, getOrdering(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,1,3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,2,4,2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 2,  4,  6,  1,  3,  5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, getOrdering(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {3,2,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,11,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3,12,13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 4,  5,  2,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, getOrdering(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
     int main()
     {
        FlowerGarden ___test;
        ___test.run_test(-1);
     }
// END CUT HERE
