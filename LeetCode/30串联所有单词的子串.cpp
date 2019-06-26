#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if(words.size()==0 || s.length()==0)   // �����п�ֵ
			return result;
		// ��ͳ��words����Ϣ
		map<string,int> words_map;
		int word_len=words[0].length();  // ���ʳ���
		int word_num=words.size();		 // ��������
		if(word_len>s.length())			// ������ʳ��ȱ�s���Ȼ�����Ҳ���ؿ�
			return result; 
		for (vector<string>::iterator it = words.begin();it != words.end();it++)
		{
			if(words_map.count(*it))  // ������ڸü�����Ӧͳ�Ƴ��ִ���+1
				words_map[*it]++;
			else                      // �������һ����
				words_map[*it]=1;	
		}

		for (int i = 0;i < word_len;i++)   
		{
			int left = i, right = i;    // ˫ָ�룬��ʼʱ������ָ��ȫ�������
			int cur_num = 0;		   // �Ѿ�ƥ��ɹ��ĵ�����
			map<string, int> s_map;
			string right_str, left_string;
			while (right <= s.length() - word_len)   // ����ָ�뻹û�����һ��
			{
				right_str = s.substr(right, word_len);
				// ���right_str������������words�У���˫ָ��ͬʱ����,���һص�ͬһ���
				if (!words_map.count(right_str))
				{
					right += word_len;
					left=right;
					cur_num=0;  // �������
					s_map.clear();
				}
				else
				{
					// right_strƥ�䣬��ͳ�ƹ���
					if (!s_map.count(right_str))  // ���s_map�л�û�е�ǰ��
						s_map.insert(pair<string, int>(right_str, 1));
					else    // s_map���е�ǰ������ͳ�Ƴ��ִ���+1
						s_map[right_str] += 1;

					cur_num += 1;			// ƥ��ɹ�������+1
					right += word_len;      // ��ָ���ƶ�����������ƥ��
					
					// �����ǰ���ִ�������words�г��ִ�������Ȼ֮ǰ��ͳ�ƹ���ɾ����֮ǰ��һ����ָ������
					if (s_map[right_str] > words_map[right_str])  
					{
						// һ��ע�⣡��������Ҫ��whileѭ��������s=barfoofoothe��left=0��right=9ʱ��
						// ���foo̫�࣬����ֻ��һ�Σ���ǰƥ���foo������û����
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
						// ƥ�䵽�ͷ���������
						result.push_back(left);  
						// ����������ָ��
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