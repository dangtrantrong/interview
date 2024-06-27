#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*Leetcode - 19. Remove Nth Node From End of List*/
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    ListNode* temp = second->next;
    second->next = second->next->next;
    delete temp;

    return dummy->next;
}

/* Leetcode - 21.Merge Two Sorted Lists*/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if(list1 == NULL) {
        std::cout << "111111111111\n";
        // std::cout << "List2: " << list2->next<< "\n";
        return list2;
    }
    if(list2 == NULL) {
        std::cout << "22222222222\n";
        // std::cout << "List1: " << list1->val << "\n";
        return list1;
    }
    
    if(list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        std::cout << "List1: " << list1->val << "\n";
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        std::cout << "List2: " << list2->val << "\n";
        return list2;
    }
}

/*Leetcode - 160.Intersection of Two Linked Lists*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    map<ListNode *, int> mpp;
    for (auto p = headA ; p!=NULL ; p = p->next){
        mpp[p]++;
    }
    
    for (auto p = headB ; p!=NULL ; p = p->next){
        if (mpp[p] == 1)
        {
            return p;
        }
    }
    return nullptr;
}

/*Leetcode - 203. Remove Linked List Elements*/
ListNode *removeElements(ListNode *head, int val) {
    while (head != nullptr && head->val == val)
    {
        head = head->next;
    }
    
    auto currentNode = head;
    ListNode* preNode= nullptr;
    
    while (currentNode != NULL)
    {
        if (currentNode->val == val) {
            preNode->next = currentNode->next;    
        } else {
            preNode = currentNode;
        }

        currentNode = currentNode->next;
    }
    
    return head;
}

/*Leetcode - 206. Reverse Linked List*/
ListNode *reverseList(ListNode *head) {
    ListNode* tempNode = nullptr;
    ListNode* currNode = nullptr;

    while (head != nullptr) {
        tempNode = head;
        head = head->next;
        
        tempNode->next = currNode;
        currNode = tempNode;
        std::cout << "Node: " << currNode->val << std::endl;
    }

    return currNode;     
}

/*Leetcode - 234.Palindrome Linked List*/
bool isPalindrome(ListNode* head) {
    // Space: O(n) -> gán giá trị trong linklist vào vector -> check palindrome
    // Space: O(1) -> Reverse linklist -> check 2 linklist các giá trị có bằng nhau hay không
}

/*Leetcode - 328. Odd Even Linked List*/
ListNode * oddEvenList(ListNode *head) {
    if (!head || !head->next || !head->next->next)
        return head;
    
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *even_start = head->next;

    while (odd->next && even->next)
    {
        odd->next = even->next;
        even->next = odd->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = even_start;

    return head;
}


int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    auto output = oddEvenList(node1);
    while (output != nullptr)
    {
        cout << output->val << " ";
        output = output->next;
    }
}