#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

 struct ListNode {
      int val;
      struct ListNode *next;
 };

//1����ת����
//��תһ��������
//ʾ��:
//����: 1->2->3->4->5->NULL
//���: 5->4->3->2->1->NULL
 typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head) {
    ListNode* node;
    ListNode* new = NULL;
    while(head != NULL){
        node = head;
        head = head->next;
        node->next = new;
        new = node;
    }
    return new;
}

//2����ת����II
//��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת��
//˵��:
//1 �� m �� n �� �����ȡ�
//ʾ��:
//����: 1->2->3->4->5->NULL, m = 2, n = 4
//���: 1->4->3->2->5->NULL
typedef struct ListNode ListNode;
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    ListNode* new = NULL;
    int l = 0;
    ListNode* node = head;
    while(node != NULL){
        l++;
        node = node->next;
    }
    if(m >= l || n > l || m >= n || m < 1 || n < 1){
        return head;
    }
    node = head;
    ListNode* ttail = node;
    int num = m;
    while(num-1){
        ttail = node;
        node = node->next;
        num--;
    }
    ListNode* tnew = node;
    node = head;
    ListNode* newtail;
    while(n){
        newtail = node;
        node = node->next;
        n--;
    }
    ListNode* thead = node;
    if(m-1 != 0){
        ttail->next = NULL;
    }
    newtail->next = NULL;
    int flag = 1;
    ListNode* last;
    while(tnew !=NULL){
        node = tnew;
        tnew = tnew->next;
        node->next = new;
        new = node;
        if(flag){
            last = node;
            flag = 0;
        }
    }
    if(m-1 != 0){
        ttail->next = new;
        last->next = thead;
    }
    else{
        head = new;
        last->next = thead;
    }
    return head;
}

//3����������
//����һ�������ж��������Ƿ��л���
typedef struct ListNode ListNode;
bool hasCycle(struct ListNode *head) {
    if(head == NULL){
        return false;
    }
    if(head == head->next){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL && slow != NULL){
        if(fast == slow){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

//4����������II
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//˵�����������޸ĸ���������
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }
    if(head == head->next){
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(1){
        if(fast->next != NULL){
            fast = fast->next;
        }
        else{
            return NULL;
        }
        if(fast->next != NULL){
            fast = fast->next;
        }
        else{
            return NULL;
        }
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    fast = head;
    while(1){
        if(fast == slow){
            return slow;
        }
        fast = fast->next;
        slow = slow->next;
    }
}

