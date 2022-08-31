// 40 ms	14.5 MB
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        bool visited[200] = {0};
        list<short> my_list;
        list<short>::iterator iter;

        my_list.clear();
        iter = my_list.begin();

        int start, from, to, counter = 0, n = isConnected.size();
        while(true){
            
            for( start = 0; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            my_list.clear();
            my_list.push_back(start);
            while( !my_list.empty() ){
                from = my_list.front();
                visited[from] = true;
                my_list.pop_front();
                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !visited[to] && from != to ){
                        my_list.push_back(to);
                    }
                }
            }
            counter++;
        }

        return counter;
    }
};

// 28 ms	14.5 MB
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        bool visited[200] = {0};
        list<short> my_list;
        int start = -1, from, to, counter = 0, n = isConnected.size();

        while(true){
            
            for( start++; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            my_list.clear();
            my_list.push_back(start);
            while( !my_list.empty() ){
                from = my_list.front();
                my_list.pop_front();
                visited[from] = true;

                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !visited[to] && from != to ){        
                        my_list.push_back(to);
                    }
                }
            }
            counter++;
        }
        return counter;
    }
};

// 24 ms	13.2 MB
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        bool visited[200] = {0};
        short my_list[40000];
        int start = -1;
        int from, to;
        int low = 0, high = 0;
        int counter = 0;
        int n = isConnected.size();

        while(true){
            
            for( start++; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            my_list[high++] = start;
            while( low < high ){
                from = my_list[low++];
                visited[from] = true;
                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !visited[to] && from != to ){        
                        my_list[high++] = to;
                    }
                }
            }
            counter++;
        }
        return counter;
    }
};

// 12 ms	13.3 MB
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        bool visited[200] = {0};
        short my_list[40000];
        int start = -1;
        int from, to;
        int low = 0, high = 0;
        int counter = 0;
        int n = isConnected.size();

        while(true){
            
            for( start++; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            low = 0; 
            high = 0;
            my_list[high++] = start;
            while( low < high ){
                from = my_list[low++];
                if( !visited[from] ){
                    visited[from] = true;
                    for( to = 0; to < n; to++ ){
                        if( isConnected[from][to] && !visited[to] && from != to ){        
                            my_list[high++] = to;
                        }
                    }
                }
            }
            counter++;
        }
        return counter;
    }
};

// 12 ms	13.5 MB
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        bool visited[200] = {0};
        set<short> my_set;

        int start, from, to, counter = 0, n = isConnected.size();
        while(true){
            
            for( start = 0; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start = n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            my_set.clear();
            my_set.insert(start);
            while( !my_set.empty() ){
                from = *(my_set.begin());
                visited[from] = true;
                my_set.erase(from);
                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !visited[to] && from != to ){
                        my_set.insert(to);
                    }
                }
            }
            counter++;
        }

        return counter;
    }
};

// 20 ms	13.5 MB, 频繁的写入写出比较慢
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        bool visited[200] = {0}, in_list[200] = {0};
        list<short> my_list;

        int start, from, to, counter = 0, n = isConnected.size();
        while(true){
            
            for( start = 0; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            my_list.clear();
            my_list.push_back(start);
            while( !my_list.empty() ){
                from = my_list.front();
                visited[from] = true;
                my_list.pop_front();
                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !visited[to] && !in_list[to] && from != to ){
                        my_list.push_back(to);
                        in_list[to] = true;
                    }
                }
            }
            counter++;
        }

        return counter;
    }
};

// 16 ms	13.2 MB
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        bool visited[200] = {0}, in_list[200] = {0};
        short my_list[200];

        int start, from, to, counter = 0, n = isConnected.size();
        int low, high;

        while(true){
            
            for( start = 0; start < n; start++ ){
                if( !visited[start] ){
                    break;
                }
            }
            if( start == n ){
                break;  // 如果均 visited 了, 跳出循环
            }

            low = high = 0;
            my_list[high++] = start;
            while( low < high ){
                from = my_list[low++];
                visited[from] = true;
                for( to = 0; to < n; to++ ){
                    if( isConnected[from][to] && !in_list[to] && from != to ){
                        my_list[high++] = to;
                        in_list[to] = true;
                    }
                }
            }
            counter++;
        }

        return counter;
    }
};