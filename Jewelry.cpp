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
        
 
}; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
