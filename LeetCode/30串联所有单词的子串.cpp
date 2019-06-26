#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if(words.size()==0 || s.length()==0)   // 输入有空值
			return result;
		// 先统计words的信息
		map<string,int> words_map;
		int word_len=words[0].length();  // 单词长度
		int word_num=words.size();		 // 单词数量
		if(word_len>s.length())			// 如果单词长度比s长度还长，也返回空
			return result; 
		for (vector<string>::iterator it = words.begin();it != words.end();it++)
		{
			if(words_map.count(*it))  // 如果存在该键，对应统计出现次数+1
				words_map[*it]++;
			else                      // 否则添加一个键
				words_map[*it]=1;	
		}

		for (int i = 0;i < word_len;i++)   
		{
			int left = i, right = i;    // 双指针，开始时，左右指针全在最左侧
			int cur_num = 0;		   // 已经匹配成功的单词数
			map<string, int> s_map;
			string right_str, left_string;
			while (right <= s.length() - word_len)   // 当右指针还没到最后一个
			{
				right_str = s.substr(right, word_len);
				// 如果right_str根本不存在于words中，那双指针同时右移,并且回到同一起点
				if (!words_map.count(right_str))
				{
					right += word_len;
					left=right;
					cur_num=0;  // 清空重来
					s_map.clear();
				}
				else
				{
					// right_str匹配，做统计工作
					if (!s_map.count(right_str))  // 如果s_map中还没有当前键
						s_map.insert(pair<string, int>(right_str, 1));
					else    // s_map中有当前键，则统计出现次数+1
						s_map[right_str] += 1;

					cur_num += 1;			// 匹配成功的数量+1
					right += word_len;      // 右指针移动，继续往下匹配
					
					// 如果当前出现次数多于words中出现次数，必然之前曾统计过，删除掉之前的一个，指针右移
					if (s_map[right_str] > words_map[right_str])  
					{
						// 一定注意！！！这里要是while循环，例如s=barfoofoothe，left=0，right=9时，
						// 如果foo太多，可能只移一次，当前匹配的foo次数并没减少
						while (s_map[right_str] > words_map[right_str])
						{
							string left_str = s.substr(left, word_len);
							s_map[left_str]--;
							cur_num--;
							left += word_len;
						}
						
					}

					if (cur_num == word_num)
					{
						// 匹配到就放入结果集合
						result.push_back(left);  
						// 继续右移左指针
						s_map[s.substr(left,word_len)]--;
						left+=word_len;
						cur_num--;
					}
				}
			}
		}
		
		return result;
	}
};


int main()
{
	Solution solution;
	
	string s = "wordgoodgoodgoodbestword";
	vector<string> word;
	word.push_back("word");
	word.push_back("good");
	word.push_back("best");
	word.push_back("good");


	vector<int> rs=solution.findSubstring(s,word);
	for (vector<int>::iterator it = rs.begin();it != rs.end();it++)
	{
		cout<<*it<<" ";
	}
	return 0;
}