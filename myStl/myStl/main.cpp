#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。


//输入：head = [3, 2, 0, -4], pos = 1
//输出：返回索引为 1 的链表节点
//解释：链表中有一个环，其尾部连接到第二个节点。


struct ListNode {
    int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* fast = head;
		ListNode* slow = head;
		if (fast == NULL) return NULL;
		do {
			if ((fast->next == NULL) || (fast->next->next == NULL)) return NULL;
			fast = fast->next->next;
			slow = slow->next;
		} while (fast != slow);
		fast = head;
		while (slow != fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}

};

int main()
{
	vector<int> nums = { 1,2,3,4,4,9,56,90 };
	vector<int> sortPeo;
	Solution solu;
	sortPeo=solu.detectCycle(nums,8);
	//cout << sortPeo<<endl;
	system("pause");
	return 0;

}