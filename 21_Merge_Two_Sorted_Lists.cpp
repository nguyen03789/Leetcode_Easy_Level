#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){};
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list2 == NULL && list1) return list1;
//         if(list1 == NULL && list2) return list2;
//         if(list1 == NULL && list2 == NULL) return 0;
//         ListNode* ptr1 = NULL;
//         ListNode* ptr2 = NULL;
//         ListNode* ptr3 = NULL;
//         if(list1->val <= list2->val){
//             ListNode* dummy = new ListNode(0);
//             dummy->next = list1;
//             list1 = dummy; // add temp Node into list1
//             ptr1 = list1->next;
//             ptr2 = ptr1->next;
//             ptr3 = list2->next;
//             while (list2)
//             {
//                 if(ptr2){
//                     if(list2->val >= ptr2->val) {
//                         ptr1 = ptr1->next;
//                         ptr2 = ptr2->next;
//                     }
//                     else {
//                         ptr1->next = list2;
//                         list2->next = ptr2;
//                         list2 = ptr3;
//                         if(ptr3) ptr3 = ptr3->next;
                        
//                         ptr1 = ptr1->next;
//                     }
//                 }
//                 else {
//                     ptr1->next = list2;
//                     list2 = NULL;
//                 }
//             }
//             return list1->next;
//         }
//         else{
//             ListNode* dummy = new ListNode(0);
//             dummy->next = list2;
//             list2 = dummy; // add temp Node into list1
//             ptr1 = list2->next;
//             ptr2 = ptr1->next;
//             ptr3 = list1->next;
//             while (list1)
//             {
//                 if(ptr2){
//                     if(list1->val >= ptr2->val) {
//                         ptr1 = ptr1->next;
//                         ptr2 = ptr2->next;
//                     }
//                     else {
//                         ptr1->next = list1;
//                         list1->next = ptr2;
//                         list1 = ptr3;
//                         if(ptr3) ptr3 = ptr3->next;
//                         ptr1 = ptr1->next;
//                     }
//                 }
//                 else {
//                     ptr1->next = list1;
//                     list1 = NULL;
//                 }
//             }
//             return list2->next;
//         }
//     }
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return 0;
        ListNode* res = new ListNode(0);
        ListNode* ptr1 = res;
        while (list1 || list2)
        {
            if(list1 == NULL){
                ptr1->next = list2;
                return res->next;
            }
            if(list2 == NULL){
                ptr1->next = list1;
                return res->next;
            }
            if(list1->val <= list2->val){
                ptr1->next = list1;
                list1 = list1->next;
                ptr1 = ptr1->next;
            }
            else{
                ptr1->next = list2;
                list2 = list2->next;
                ptr1 = ptr1->next;
            }
        }
        return res->next;
    }
};

int main(){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int i :{1,2,4}){
        tail->next = new ListNode(i);
        tail = tail->next;
    }
    ListNode* input1 = dummy.next;

    ListNode dummy2(0);
    ListNode* tail2 = &dummy2;
    for(int i :{1,3,4}){
        tail2->next = new ListNode(i);
        tail2 = tail2->next;
    }
    ListNode* input2 = dummy2.next;

    Solution a;
    ListNode* output = a.mergeTwoLists(input1,input2);
    while(output){
        cout << output->val << " ";
        output = output->next;
    }
    return 0;
}