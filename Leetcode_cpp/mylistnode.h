#ifndef MYLISTNODE_H_INCLUDED
#define MYLISTNODE_H_INCLUDED
#include <algorithm>
#include <climits>
using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

class LZ
{
public:

    ListNode* revOnPlace(ListNode *head)
    {
        ListNode dummy(-1);
        ListNode *curr = head;

        head = &dummy;
        while(curr)
        {
            ListNode *tmp = curr->next;
            curr->next = head->next;
            head->next = curr;
            curr = tmp;
        }

        return dummy.next;
    }

    ///
    void showList(ListNode *head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    ///
    void showTree(TreeNode *root){
        if(root){
            cout<<root->val<<" ";
            showTree(root->left);
            showTree(root->right);
        }
    }
    void showTreeInorder(TreeNode *root){
        if(root->left) showTreeInorder(root->left);
        cout<<root->val<<" ";
        if(root->right) showTreeInorder(root->right);

    }

    void reorderList(ListNode* head)
    {
        if(head==nullptr || head->next==nullptr) return;
        ListNode *slow, *fast;
        ListNode *prev;
        slow = fast = head;
        prev = nullptr;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = prev->next;
        prev->next = nullptr;

        head2 = revOnPlace(head2);
        cout<<"head1: ";showList(head);
        cout<<"head2: ";showList(head2);

        ListNode *head1 = head;
        slow = head1;
        fast = head2;
        while(slow && fast){
            ListNode *t1 = slow->next;
            ListNode *t2 = fast->next;
            head1->next = slow;
            head1->next->next = fast;
            head1 = fast;
            slow = t1;
            fast = t2;
        }
        cout<<"done";showList(head);
    }


    ///
    TreeNode* sortedListToBST2(ListNode* head) {
        TreeNode *root = nullptr;
        if(head==nullptr) return root;
        root = new TreeNode(head->val);

        ListNode *curr = head->next;
        while(curr){
            ///find the insert localtion
            TreeNode *f = root;
            TreeNode *parent = nullptr;
            while(f){
                parent = f;
                if(curr->val < f->val) f = f->left;
                if(curr->val >= f->val) f = f->right;
            }
            if(curr->val < parent->val){
                parent->left = new TreeNode(curr->val);
            }else{
                parent->right = new TreeNode(curr->val);
            }

            curr = curr->next;
        }
        return root;
    }

    ///
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }else if(head->next==nullptr){
            return new TreeNode(head->val);
        }

        ListNode *slow,*fast,*prev;
        slow = fast = head;
        prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        showList(head);
        showList(slow);
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }///


    ///
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        int carray = 0;
        ListNode *prev = nullptr;
        ListNode *head = l1;
        showList(l1);
        showList(l2);
        while(l1 && l2){
            int tmp = l1->val + l2->val + carray;
            carray = tmp>9 ? 1:0;
            l1->val = tmp%10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int tmp = l1->val+carray;
            carray = tmp>9 ? 1:0;
            l1->val = tmp%10;
            prev = l1;
            l1 = l1->next;
        }
        while(l2){
            int tmp = l2->val+carray;
            carray = tmp>9 ? 1:0;
            l2->val = tmp%10;
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }
        if(carray==1) prev->next = new ListNode(1);
        return head;
    }


    ///
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *head1,*head2;
        ListNode *p1,*p2,*curr;
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        curr = head;
        p1 = head1 = &dummy1;
        p2 = head2 = &dummy2;

        while(curr){
            if(curr->val < x){
                p1->next = curr;
                p1 = p1->next;
                //p1->next = nullptr;
            }else{
                p2->next = curr;
                p2 = p2->next;
                //p2->next = nullptr;
            }
            curr = curr->next;
        }
        p1->next = nullptr;
        p2->next = nullptr;
        showList(head1->next);
        showList(head2->next);

        p1->next = head2->next;
        return head1->next;
    }

    ///
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        return head;
    }

    void test(ListNode *head){
        cout<<"begin test...\n";
        ListNode n1(2),n2(1),n3(3),n4(2),n5(5),n6(2);
        n1.next = &n2;
        //n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
    ListNode *head2 = &n1;
        head2 = insertionSortList(head2);
        //showList(head2);

        cout<<"end test...\n";
    }

};


#endif // MYLISTNODE_H_INCLUDED
