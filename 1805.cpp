#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int wordLen, idx;
        std::set<std::string> mySet;
        wordLen = word.length();
        idx = 0;
        while(idx < wordLen){
            // // 越过英文字母和前导零
            // while((isalpha(word[idx]) || word[idx] == 0x30) && idx < wordLen){
            //     // 判断零是不是数字0，如果是则单独处理
            //     if(word[idx] == 0x30 && (idx==wordLen-1 || (idx<wordLen-1 && isalpha(word[idx+1])))){
            //         if(mySet.find(word.substr(idx, 1))==mySet.end()){
            //             mySet.insert(word.substr(idx, 1));
            //         }
            //     }
            //     idx += 1;
            // }

            // // 获取整个数字的字符串
            // int start = idx, len = 0;   
            // while((isdigit(word[idx])) && idx < wordLen){
            //     idx+=1; len += 1;
            // }
            // string numStr = word.substr(start, len);
            // printf("%s\n", numStr.c_str());

            // // 如果数字在集合中不存在，将数字放入集合中
            // if(len > 0 && mySet.find(numStr)==mySet.end()){
            //     mySet.insert(numStr);
            // }

            // 越过英文字母
            while(isalpha(word[idx]) && idx < wordLen){
                idx += 1;
            }

            if(idx == wordLen)  break;

            // 获取整个数字的字符串
            int start = idx;   
            while((isdigit(word[idx])) && idx < wordLen){
                idx+=1;
            }

            // 消除前导 0, 会给数字字符串至少留下一个字符
            while(word[start] == 0x30 && start < idx-1){
                start += 1;
            }
            string numStr = word.substr(start, idx-start);
            printf("%s\n", numStr.c_str());

            // 如果数字在集合中不存在，将数字放入集合中
            if(mySet.find(numStr)==mySet.end()){
                mySet.insert(numStr);
            }
        }
        return mySet.size();
    }
};