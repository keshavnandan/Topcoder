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
#define mp make_pair

class MLBRecord{ 
        public:
        int rank(vi v, int i){
          int count = 0;
          int val = v[i];
          for(int j = 0; j < v.size(); j++)
            if(v[j] > val) count++;
          return count;
        }
        string teamStatus(vector <int> wins, int gamesLeft, int N) {
          int n = wins.size();
          int total =  (n*gamesLeft)/2;
          cout<<"total = "<<total<<endl;
          string ans(n, '.');
          for(int i = 0; i < n; i++){
            //Best Case
            vector<pi> rem;
            int totalWin = total - gamesLeft , score = wins[i] + gamesLeft;
            cout<<"i = "<<i<<" score = "<<score<<endl;
            for(int j = 0; j < n; j++){
              if(i == j) continue;
              rem.push_back(mp(wins[j], wins[j]));
              int &t = (rem.back()).second;
              int x = min(totalWin, min(gamesLeft, score-t));
              if(wins[j] > score) x = gamesLeft;
              t += x;
              totalWin -= x;
            }
            vector<pi> rest;
            for(pi p : rem) rest.push_back(mp(p.second-p.first, p.second)); 
            sort(rest.begin(), rest.end());
            for(pi &p : rest){
              if(totalWin <= 0) break;
              int x = min(gamesLeft-p.first, totalWin);
              p.second += x;
              totalWin -= x;
            }
            int rank = 0;
            for(pi p : rest){
              if(p.second > score) rank++;
            }

            cout<<"rank = "<<rank<<endl;
            if(rank >= N){
              ans[i] = 'E';
              continue;
            }

            int done = 0;
            //Worst Case
                  {

                      vi rest;
                      int totalWin = total, score = wins[i];
                      cout<<"i = "<<i<<" score = "<<score<<endl;
                      for(int j = 0; j < n; j++){
                        if(i == j || wins[j] > score) continue;
                        rest.push_back(wins[j]);
                      }
                      int rank = n-(rest.size());
                      sort(rest.rbegin(), rest.rend());
                      for(int t : rest){
                        int x = min(totalWin, min(score-t, gamesLeft));
                        t += x;
                        if(t >= score) rank++;
                        totalWin -= x;
                      }
                      if(rank <= N){
                       ans[i] = 'C';
                       done = 1;
                     }
                  }

            if(!done) ans[i] = '.';

          }
          return ans;
        }
        
 
}; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
