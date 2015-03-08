#include <vector>
#include <string>
#include <numeric>
#include <queue>
#define inf 10000000
using namespace std;
int D[55][55];


class Egalitarianism {

public:
    int maxDifference(vector<string> const M,
                      int d) {
        int n = M.size();
        // memset(D, 0, sizeof(D));
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
            if(i == j) D[i][j] = 0;
            else D[i][j] = (M[i][j] == 'Y' ? 1 : inf);

        for(int k = 0; k < n; k++)
          for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
              D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

        int maxv = 0;
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
            maxv = max(maxv, D[i][j]);

        cout<<"maxv = "<<maxv<<endl;
        if(maxv == inf) return -1;
        return maxv*d;
    }
};
