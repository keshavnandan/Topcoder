#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class AddMultiply {
        public:
        vector <int> makeExpression(int y)
        {
            vector<int> v(3);

            for(int i = -1000;  i <= 1000; i++)
                for(int j = -1000;  j <= 1000; j++)
                    for(int k = -1000;  k <= 100; k++){

                        if(i && j&& k && (i != 1) && (j != 1) && (k != 1)){
                            if((i*j + k) == y){
                                v[0] = i;
                                v[1] = j;
                                v[2] = k;
                                return v;
                            }
                        }

                    }
        }


};

