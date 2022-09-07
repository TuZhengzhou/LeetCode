#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        vector<pair<int, int>> record;
        int n, ch_idx, start, len, space_counter, word_counter;

        ch_idx = 0;
        n = text.length();
        space_counter = 0;
        word_counter = 0;
        while(ch_idx < n){
            // 跳过空格
            while(ch_idx < n && text[ch_idx] == ' '){
                ch_idx++;
                space_counter++;
            }
            if( ch_idx < n ){
                word_counter++;
                len = 0;
                start = ch_idx;
                while(ch_idx < n && text[ch_idx] != ' '){
                    ch_idx++;
                    len++;
                }
                record.push_back(pair(start, len));
            }
        }
        // printf("%d, %d\n", word_counter, space_counter);
        int space_mid, space_tail;
        space_mid = word_counter == 1 ? 0 : space_counter/(word_counter-1);
        space_tail = space_counter-(word_counter-1)*space_mid;

        string ans, mid_space, tail_space;
        for( int i = 0; i < space_mid; i++ )    mid_space+=" ";
        for( int i = 0; i < space_tail; i++ )   tail_space+=" ";

        for( int i = 0; i < word_counter-1; i++ ){
            ans += text.substr(record[i].first, record[i].second);
            ans += mid_space;
        }
        ans += text.substr(record[word_counter-1].first, record[word_counter-1].second);
        ans += tail_space;
        return ans;
    }
};

using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        vector<pair<int, int>> record;
        int n = text.length();
        int ch_idx = 0; 
        int space_counter = 0;
        int word_counter = 0;
        int start, len;

        while(ch_idx < n){
            // 跳过空格
            while(ch_idx < n && text[ch_idx] == ' '){
                ch_idx++;
                space_counter++;
            }
            if( ch_idx < n ){
                len = 0;
                start = ch_idx;
                while(ch_idx < n && text[ch_idx] != ' '){
                    ch_idx++;
                    len++;
                }
                word_counter++;
                record.push_back(pair(start, len));
            }
        }
        // printf("%d, %d\n", word_counter, space_counter);
        int space_mid, space_tail;
        space_mid = word_counter == 1 ? 0 : space_counter/(word_counter-1);
        space_tail = space_counter-(word_counter-1)*space_mid;

        string ans;
        string mid_space = string(space_mid, ' ');
        string tail_space = string(space_tail, ' ');
        
        for( int i = 0; i < word_counter-1; i++ ){
            ans += text.substr(record[i].first, record[i].second);
            ans += mid_space;
        }
        ans += text.substr(record[word_counter-1].first, record[word_counter-1].second);
        ans += tail_space;

        return ans;
    }
};