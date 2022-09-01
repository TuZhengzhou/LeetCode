#include<vector>
#include<map>
using namespace std;

/* 
    36 ms	14.1 MB
    一个不重复检查记录的方法
*/
class StreamRank {
private:
    vector<int> records = vector<int>(2000, 0);
    map<int, int> pre_count;
    map<int, int> latest_in;
    int counter;
public:
    StreamRank() {
        counter = 0;
        return;
    }
    
    void track(int x) {
        records[counter++] = x;
        return;
    }

    int getRankOfNumber(int x) {
        int sum = 0;
        for( int i = latest_in[x]; i < counter; i++ ){
            if(records[i] <= x)
                sum++;
        }
        int tmp = pre_count.find(x) == pre_count.end() ? 0 : pre_count[x];
        sum = tmp+sum;
        pre_count[x] = sum;
        latest_in[x] = counter;
        return sum;
    }

};


/*
    20 ms	19.9 MB
    采用树状数组
    参考: https://www.cnblogs.com/xenny/p/9739600.html
*/
class StreamRank {
private:
    int low = 0;                // 需要根据题目进行设置
    int high = 50000;           // 需要根据题目进行设置
    int redress = 1-low;        // 补偿, low + redress 可以将 low 修正为 1
    const int n = high+low+2;       // 数组尺寸
    vector<int> tree;

    inline int low_bit(int x){
        return x&(-x);
    }

    void update(int x){
        for( int i = x; i < n; i+=low_bit(i) ){
            tree[i] += 1;
        }
    } 

    int query(int x){
        int sum = 0;
        for( int i = x; i > 0; i-=low_bit(i) ){
            sum += tree[i];
        }
        return sum;
    }   

public:
    StreamRank() {
        tree = vector<int>(n);
    }

    void track(int x) {
        update(x+redress);
    }

    int getRankOfNumber(int x) {
        return query(x+redress);
    }

};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */