#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstdio>
using namespace std;

class WalkingHome
        {
        public:
        typedef pair<int, int> pi;
        void msearch(vector<string> M, pi p, int level, int nval[51][51]){
            int n = M.size(), m = M[0].size();
            queue<pi> Q;
            Q.push(p);
            nval[p.first][p.second] = level;
            while(!Q.empty()){
                pi q = Q.front();
                Q.pop();
                int x = q.first, y = q.second;
                if(0 <= x && x < n && 0 <= y && y < m && (M[x][y] == '.' || M[x][y] == 'S' || M[x][y] == 'H')){
                    nval[x][y] = level;
                    M[x][y] = 'x';
                    Q.push(make_pair(x+1, y));
                    Q.push(make_pair(x-1, y));
                    Q.push(make_pair(x, y+1));
                    Q.push(make_pair(x, y-1));
                }
            }
            print(M);
        }

        int fewestCrossings(vector <string> M)
            {
                int val;
//                cin>>val;
                int nval[51][51];
                pi S, H;
                pi seed[255];
                int n = M.size(), m = M[0].size();
                for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    nval[i][j] = -1;
                int c = 0;
                print(M);
                for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                {
                    if(M[i][j] == 'S'){
                        S = make_pair(i, j);
                        if(nval[i][j] == -1){
                            seed[c] = S;
                            msearch(M, S, c++, nval);
                        }
                    }
                    else if(M[i][j] == 'H'){
                        H = make_pair(i, j);
                        if(nval[i][j] == -1){
                            seed[c] = H;
                            msearch(M, H, c++, nval);
                        }
                    }
                    else if(M[i][j] == '.' && nval[i][j] == -1){
                        seed[c] = make_pair(i, j);
                        msearch(M, make_pair(i, j), c++, nval);
                    }
                }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)
                    printf("%3d ", nval[i][j]);
                cout<<endl;
            }
            cout<<endl;
            int src = nval[S.first][S.second], dest = nval[H.first][H.second];
            cout<<"src = "<<src<<" dest = "<<dest<<endl;
            if(nval[S.first][S.second] == nval[H.first][H.second]) return 0;
//                bool visited[255];
                int level[1000];
                int adj[1000][1000];
                fill(level, level+1000, -1);
                for(int i = 0; i <= c; i++)
                for(int j = 0; j <= c; j++)
                    adj[i][j] = 0;
                //sweeping row-wise
                for(int i = 0; i < n; i++){
                    vector<int> v;
                    for(int j = 0; j < m; j++)
                        if(M[i][j] != '|') v.push_back(nval[i][j]);
                    for(int k = 1; k < v.size(); k++){
                        while(k < v.size() && (v[k] == -1 || v[k-1] == -1 || v[k] == v[k-1])) k++;
                        if(k < v.size()) adj[v[k]][v[k-1]] = adj[v[k-1]][v[k]] = 1;
                    }
                }
                //sweeping column-wise
                for(int j = 0; j < m; j++){
                    vector<int> v;
                    for(int i = 0; i < n; i++)
                        if(M[i][j] != '-') v.push_back(nval[i][j]);
                    for(int k = 1; k < v.size(); k++){
                        while(k < v.size() && (v[k] == -1 || v[k-1] == -1 || v[k] == v[k-1])) k++;
                        if(k < v.size()) adj[v[k]][v[k-1]] = adj[v[k-1]][v[k]] = 1;
                    }
                }

            for(int i = 0; i <= c; i++)
                for(int j = i+1; j <= c; j++)
                    if(adj[i][j] == 1) cout<<i<<" "<<j<<endl;
            cout<<endl;
            if(adj[nval[S.first][S.second]][nval[H.first][H.second]] == 1) return 1;

            queue<int> Q;
            Q.push(src);
            int visited[1000];
            fill(visited, visited+1000, -1);
            visited[src] = 0;
            while(!Q.empty()){
                int p = Q.front();
                Q.pop();
                cout<<p<<" visited at level "<<visited[p]<<endl;
                if(p == dest) return visited[dest];
                for(int j = 0; j <= c; j++)
                    if(adj[p][j] == 1 && visited[j] == -1){
                        Q.push(j);
                        visited[j] = visited[p]+1;
                    }
            }
                return -1;
        }

        void print(vector<string> v){
            int n = v.size();
            int m = v[0].size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++)
                    cout<<v[i][j];
                cout<<endl;
            }
            cout<<endl;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--------*-*-*----*-------*--*--------", "...FFFFF|F|F|FFFFH.......|..|........", ".......F..S......|..F.......|........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, fewestCrossings(Arg0)); }
	void test_case_1() { string Arr0[] = {"S.|..",
 "..|.H",
 "..|..",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, fewestCrossings(Arg0)); }
	void test_case_2() { string Arr0[] = {"S.||...",
 "..||...",
 "..||...",
 "..||..H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, fewestCrossings(Arg0)); }
	void test_case_3() { string Arr0[] = {"S|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", "*************************************************-", ".||.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.", "-*************************************************", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||.", ".|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|.||H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 624; verify_case(3, Arg1, fewestCrossings(Arg0)); }
	void test_case_4() { string Arr0[] = {"S.F..",
 "..F..",
 "--*--",
 "..|..",
 "..|.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, fewestCrossings(Arg0)); }
	void test_case_5() { string Arr0[] = {"H|.|.|.|.|.|.|.|.|.|.|.|.|.",
 "F|F|F|F|F|F|F|F|F|F|F|F|F|-",
 "S|.|.|.|.|.|.|.|.|.|.|.|.|."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(5, Arg1, fewestCrossings(Arg0)); }
	void test_case_6() { string Arr0[] = {"S-H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, fewestCrossings(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        WalkingHome ___test;
        ___test.run_test(3);
     }
// END CUT HERE
