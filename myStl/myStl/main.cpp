#include<iostream>
#include<vector>
#include<unordered_map>
#include <numeric>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* reverseList(ListNode* head) {
	ListNode* traver;
	ListNode* list;
	traver = list;
	while (head != NULL)
	{
		traver->val = head->val;
		traver = list->next;
		head = head->next;
	}
	return list;
}


int main()
{
	ListNode head;
	reverseList();

	int i = 0;
	system("pause");
	return 0;

}