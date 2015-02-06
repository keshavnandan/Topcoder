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
#include <numeric>
using namespace std;
typedef pair<int,int> pi;
typedef set<int> si;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;

ll nck(int n, int k){
    if (k == 0) return 1;
    return (n * nck(n - 1, k - 1)) / k;
}

class Jewelry{ 
        public:
        vl findWays(vi v){
            vl ways(30005);
            ways[0] = 1;
            int k = v.size();
            for(int i = 0; i < k; i++)
                for(int s = 30005; s >= v[i]; s--)
                    ways[s] += ways[s-v[i]];
            return ways;
        }
        long long howMany(vector <int> values) {
           sort(values.begin(), values.end());
           int n = values.size(), sum = accumulate(values.begin(), values.end(), 0);
           long long count = 0;
           vi ways(sum);
           vector<pair<int, vi> > groups;
           int gi = 0, curr = values[0];
           vi group;
           for(int i = 0; i < n; i++){
            if(curr == values[i]) group.push_back(values[i]);
            else{
                groups.push_back(make_pair(gi, group));
                gi = i;
                curr = values[i];
                group = vi(1, values[i]);
            }
           }
           groups.push_back(make_pair(gi, group));

           for(auto p : groups){
            int i = p.first, G = p.second.size();
            vi w1;
            for(int j = 0; j < i; j++) w1.push_back(values[j]);
            vl waysBelow = findWays(w1);
            for(int g =  1; g <= G; g++){
                vi w2;
                for(int j = i+g; j < n; j++) w2.push_back(values[j]);
                vl waysAbove = findWays(w2);
                for(int s = g*values[i]; s <= sum; s++)
                    count += nck(G, g) * waysBelow[s - g*values[i]] * waysAbove[s];
            }
           }
           return count;
        }
        
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,2,5,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 9LL; verify_case(0, Arg1, howMany(Arg0)); }
    void test_case_1() { int Arr0[] = {1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000,
 1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18252025766940LL; verify_case(1, Arg1, howMany(Arg0)); }
    void test_case_2() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, howMany(Arg0)); }
    void test_case_3() { int Arr0[] = {7,7,8,9,10,11,1,2,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 607LL; verify_case(3, Arg1, howMany(Arg0)); }
    void test_case_4() { int Arr0[] = {123,217,661,678,796,964,54,111,417,526,917,923}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE
 
}; 

// BEGIN CUT HERE 
int main(){

        Jewelry ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE     
