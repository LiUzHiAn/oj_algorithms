
#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
      int val;
      ListNode*  next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		// �¿�������������ͷ���-1��
		ListNode *h1=new ListNode(-1), *h2 = new ListNode(-1), *p1=h1, *p2=h2,*q=head;
		ListNode *del;  // ɾ���Ľ��
		while (q!=NULL)
		{
			if (q->val < x) // ��С���Ϲ�
			{
				p1->next=new ListNode(q->val);
				p1=p1->next;
			}
			else // �������Ϲ�
			{
				p2->next = new ListNode(q->val);
				p2 = p2->next;
			}
			del=q;
			q=q->next;
			delete del;
		}
		p1->next=h2->next;
		return h1->next;
	}
};


int main()
{
	// �½�һ������
	ListNode *link = new ListNode(1);
	ListNode *node1 = new ListNode(4);
	link->next = node1;
	ListNode *node2 = new ListNode(3);
	node1->next = node2;
	ListNode *node3 = new ListNode(2);
	node2->next = node3;
	ListNode *node4 = new ListNode(5);
	node3->next = node4;
	ListNode *node5 = new ListNode(2);
	node4->next = node5;

	Solution s;
	ListNode *result = s.partition(link, 3);
	while (result)
	{
		cout << result->val << " ";
		result = result->next;
	}
	return 0;
}