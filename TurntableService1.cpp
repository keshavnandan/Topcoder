#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <ctime>
using namespace std;
void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
struct node{
    vector<int> done;
    int cost;
    int x;
    set<int> visited;

};
bool operator<(const node &p, const node &q){
    if(p.cost == q.cost)
    return (p.done.size() < q.done.size());
    return p.cost > q.cost;
}

class TurntableService
        {
        public:
        int calculateTime(vector <string> favorites)
        {
            int n = favorites.size();
            vector<vector<int> > fav(n);
            for(int i = 0; i < n; i++){
                stringstream ss(favorites[i]);
                int j;
                while(ss>>j) fav[i].push_back(j);
            }
            priority_queue<node> Q;
            node s;
            s.cost = 0;
            s.x = 0;
            s.done.resize(n);
            fill(s.done.begin(), s.done.end(), 0);
            Q.push(s);
            for(int i = 1; i < n; i++){
                s.x = i;
                int cost = min(i, n-i)+1;
                s.cost = cost;
                Q.push(s);
                cout<<"pushed with cost = "<<cost<<endl;
            }
//            Q.push(make_pair(s, 4));

            while(!Q.empty()){
                node p = Q.top();
                int  j = p.x;
                cout<<"size = "<<Q.size()<<endl;
                Q.pop();
                p.visited.insert(j);
//                sleep(900);
                cout<<"j = "<<j<<" cost = "<<p.cost<<" done = ";
                for(int i = 0; i < n; i++) if(p.done[i]) cout<<i<<" ";
                cout<<endl;
                bool ok = false;
                for(int i = 0; i < n; i++){
                    //k is the position of turntable for ith person
                    int k = (j+i)%n;
                    vector<int> v = fav[i];
                    //find if the ith is satisfied if not then look if can satisfied or not
                    if(!p.done[i] && find(v.begin(), v.end(), k) != v.end()){
                        p.done[i] = 1;
                        if(!ok){
                            p.cost += 15;
                            ok = true;
                        }
                        cout<<i<<" is satisfied with "<<k<<endl;
                    }
                }
                //if all the positions are visited then return cost
                if(accumulate(p.done.begin(), p.done.end(), 0) == n) return p.cost;
                for(int i = 1; i < n; i++){
                    int k = (j+i)%n;
                    if(p.visited.find(k) == p.visited.end()){
                        p.x = k;
                        int cost = min(n-abs(k-j), abs(k-j))+1;
                        p.cost += cost;
                        Q.push(p);
                        cout<<"node with cost "<<p.cost<<" and front "<<k<<" is inserted in queue"<<endl;
                        p.cost -= cost;
                    }
                }

            }
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 2", "1", "0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, calculateTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"2 8", "10 7 0", "12 2", "1 6", "5 4", "14 9", "7 8 1", "6 11 14", "13 10", "9 13", "3 5", "11 1", "8 13 2", "0 3", "4 12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 119; verify_case(1, Arg1, calculateTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"4", "1", "2", "3", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(2, Arg1, calculateTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 004", "2 3", "0 01", "1 2 3 4", "1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 35; verify_case(3, Arg1, calculateTime(Arg0)); }

// END CUT HERE

        };

// BEGIN CUT HERE
     int main()
     {
        TurntableService ___test;
        ___test.run_test(1);
     }
// END CUT HERE
