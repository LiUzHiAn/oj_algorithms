#include<iostream>
using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {

		// ����߽����
		if (k==0)
			return head;
		if (head==NULL)
			return NULL;

		// �ȶ�������б���һ�飬�õ�����ĳ���
		int len=0;
		ListNode * p=head;
		while (p != NULL)
		{
			p=p->next;
			len++;
		}

		k=k%len;

		// ˫ָ�룬leftָ������k����㣬rightָ�����һ��
		ListNode *left=head,*right= head;
		while (k)
		{
			right= right->next;
			k--;
		}
		// ͬʱ�ƶ�˫ָ�룬ֱ��right����
		while (right->next != NULL)
		{
			left=left->next;
			right=right->next;
		}
		// ��ʼ��������֮������ҷ�ʽ
		// rightָ���ӵ�head��left���NULL������ԭleft�ĺ�һ��Ԫ��
		right->next=head;
		head=left->next;
		left->next=NULL;

		return head;
	}

};


int main()
{
	// �½�һ������
	ListNode *link=new ListNode(1);
	ListNode *node1 = new ListNode(2);
	link->next=node1;
	ListNode *node2 = new ListNode(3);
	node1->next = node2;
	ListNode *node3 = new ListNode(4);
	node2->next = node3;
	ListNode *node4 = new ListNode(5);
	node3->next = node4;

	Solution s;
	ListNode *result=s.rotateRight(link,10);
	while (result)
	{
		cout<<result->val<<" ";
		result=result->next;
	}
	return 0;
}