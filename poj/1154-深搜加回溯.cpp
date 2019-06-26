#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_CELL 100

char map[MAX_CELL][MAX_CELL];  // ÿ�����ӵ���ĸ
bool visited[30];			  // 26��Ӣ����ĸ�Ƿ��Ѿ����ʹ�
int res=1;
int temp=1;					// ��ʼλ��Ҳ��1��
pair<int, int> direction[4];  // ��������
int r, c;					// �С�����
/*
*	˼·�������������+����
*		�����ǣ��Ե�ǰ���4������ֱ������̽(ע��߽��ж�)��
*		����һ��ȫ�ֱ���res���������������
*		4�������ĸ�������̽�Ľ�������res�󣬾����Ǹ�����
*		ÿ��������̽��󣬶��ع�ԭ����״̬��
*/
void input()
{
	memset(visited, false,sizeof(visited));
	memset(map,0, sizeof(map));
	cin>>r>>c;
	char ch;
	for (int i = 0;i < r*c;i++)
	{
		cin>>ch;
		map[i/c][i % c]=ch;
	}
	
	direction[0] = make_pair(-1, 0);
	direction[1] = make_pair(1, 0);
	direction[2] = make_pair(0, -1);
	direction[3] = make_pair(0, 1);
}

void dfs(int row, int col)
{
	for (int i = 0;i < 4;i++)
	{
		int x =row+direction[i].first;
		int y = col + direction[i].second;
		// ûԽ�粢���Ǹ����ϵ���ĸû�����ʹ�
		if (x >= 0 && x < r && y >= 0 && y < c && !visited[map[x][y]-'A'])
		{	
				visited[map[x][y] - 'A']=true;  // ����Ϊ���ʹ�
				temp++;
				dfs(x, y);

				res=max(res,temp);
				
				// ����
				temp--;
				visited[map[x][y] - 'A'] = false;  // ���±��Ϊδ����
		}
	}
}

int main()

{
	
	input();
	 
	// �����Ͻǿ�ʼ����  // ��ʼλ��Ҳ��1��
	visited[map[0][0] - 'A']=true;  
	dfs(0,0);
	cout<<res;
	return 0;
}