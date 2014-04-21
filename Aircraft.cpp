#line 115 "Aircraft.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Aircraft
        {
        public:
        string nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R)
            {
                int r[3], v[3];
                for(int i = 0; i < 3; i++){
                    r[i] = p1[i]-p2[i];
                    v[i] = v1[i]-v2[i];
                }
                int num = -(r[0]*v[0]+r[1]*v[1]+r[2]*v[2]);
                int dnum = (v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
                if((r[0]*r[0]+r[1]*r[1]+r[2]*r[2]) < R*R)
                return "YES";
                if(dnum == 0 || num < 0)   return "NO";
                double t = num/dnum;
                double rx = 0.0;
                for(int i = 0; i < 3; i++)
                rx += (p1[i]+v1[i]*t-p2[i]-v2[i]*t)*(p1[i]+v1[i]*t-p2[i]-v2[i]*t);
                if(rx <= R*R) return "YES";
                else return "NO";
            }

        };

int main(){}

// Powered by FileEdit


// Powered by FileEdit
