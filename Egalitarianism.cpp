#include <vector>
#include <string>
#include <numeric>
#include <queue>
using namespace std;
vector<string> M;
int visited[55], n;

class Egalitarianism {

    int bfs(int s){

      queue<pair<int, int> > Q;
      Q.push(make_pair(s, 0));
      int maxl = 0;

      while(!Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        int i = p.first, l = p.second;
        maxl = max(l, maxl);
        for(int j = 0; j < n; j++)
          if(!visited[j] && M[i][j] == 'Y'){
            visited[j] = 1;
            Q.push(make_pair(j, l+1));
          }
      }
      return maxl;
    }

public:
    int maxDifference(vector<string> const &isFriend,
                      int d) {
        M = isFriend;
        n = M.size();
        int maxv = 0;
        for(int i = 0; i < n; i++){
           fill(visited, visited+50, 0);
           visited[i] = 1;
           maxv = max(maxv, bfs(i));
           int count = accumulate(visited, visited+n, 0);
           if(count < n) return -1;
         }
        if(maxv == 0) return -1;
        return maxv*d;
    }
};
