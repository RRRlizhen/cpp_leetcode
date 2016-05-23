#ifndef MYLISTNODE_H_INCLUDED
#define MYLISTNODE_H_INCLUDED
#include <algorithm>
#include <climits>
#include <stdlib.h>
#include <limits.h>
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
    ListNode *findLocationInsert(ListNode *head,int x){
        for(;head->next;head = head->next){
            if(head->next->val >= x) break;
        }
        return head;
    }
    ListNode *insertionSortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy(-1);
        ListNode *curr,*in;
        curr = head;
        for(;curr;curr->next){
            in = &dummy;
            in = findLocationInsert(in,curr->val);
            ListNode *tmp = curr->next;
            curr->next = in->next;
            in->next = curr;
            curr = tmp;
        }
        return dummy.next;
    }


    ///
    ListNode *mergeList(ListNode *l1, ListNode *l2){
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(l1 || l2){
            int val1 = l1==nullptr? INT_MAX : l1->val;
            int val2 = l2==nullptr? INT_MAX : l2->val;
            if(val1<=val2){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        cout<<"---";showList(dummy.next);

        return dummy.next;
    }
    ListNode *sortList(ListNode *head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;

        //showList(head);
        //showList(slow);cout<<endl;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        head = mergeList(l1,l2);

        return head;
    }


    ///
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ///
        if(lists.empty()) return nullptr;

        ListNode *p = lists[0];
        for(int i = 1;i<(int)lists.size();i++){
            p = mergeList(p,lists[i]);
        }
        return p;
    }



    ///
    void CountingSort(int *A,int *B,int *Order,int N,int K){
        int *C = new int[K+1];
        int i;
        memset(C,0,sizeof(int)*(K+1));
        for(i = 1;i<=N;i++){///
            C[A[i]]++;
        }


        for(i = 2;i<=K;i++){
            C[i] += C[i-1];
        }
        cout<<endl;
        for(int i = 1;i<(K+1);i++){
            cout<<C[i]<<" ";
        }cout<<endl;

        for(i=N;i>=1;i--){
            B[C[A[i]]] = A[i];
            Order[C[A[i]]] = i;
            C[A[i]]--;
        }
    }

    void testCS(){
        ///=============
    int *A,*B,*Order,N = 15,K = 10,i;
    A = new int[N+1];
    B = new int[N+1];
    Order = new int[N+1];
    for(i = 1;i<=N;i++){
        A[i] = rand()%K+1;
    }
    printf("Before cs: \n");
    for(i = 1;i<=N;i++){
        printf("%d ",A[i]);
    }
    CountingSort(A,B,Order,N,K);
    printf("\nafter cs:\n");
    for(i = 1;i<=N;i++){
        printf("%d ",B[i]);
    }
    printf("\nOrder:\n");
    for(i = 1;i<=N;i++){
        printf("%d ",Order[i]);
    }
    cout<<"done"<<endl;
    ///================
    }

    ///
    const int BUCKET_NUM = 10;
    ListNode *insert(ListNode *head, int val){
        ListNode dummyNode(-1);
        ListNode *newNode = new ListNode(val);
        ListNode *prev,*curr;
        dummyNode.next = head;
        prev = &dummyNode;
        curr = head;
        while(curr && curr->val <= val){
            prev = curr;
            curr = curr->next;
        }///find location to insert; prev->next
        newNode->next = curr;
        prev->next = newNode;
        return dummyNode.next;
    }

    ListNode *mergebucket(ListNode *head1,ListNode *head2){
        ListNode dummy(-1);
        ListNode *h = &dummy;
        while(head1 && head2){
            if(head1->val <= head2->val){
                h->next = head1;
                head1 = head1->next;
            }else{
                h->next = head2;
                head2 = head2->next;
            }
            h = h->next;
        }
        if(head1) h->next = head1;
        if(head2) h->next = head2;
        return dummy.next;
    }

    void BucketSort(int n,int arr[]){
        vector<ListNode*> buckets(BUCKET_NUM,nullptr);
        for(int i = 0;i<n;i++){
            int index = arr[i]%BUCKET_NUM;
            ListNode *head = buckets[index];
            buckets[index] = insert(head,arr[i]);
        }///
        ListNode *head = buckets[0];
        for(int i = 1;i<BUCKET_NUM;i++){
            head = mergebucket(head,buckets[i]);
        }

        for(int i = 0;i<n;i++){
            arr[i] = head->val;
            head = head->next;
        }
    }///

    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy1(-1);
        ListNode dummy2(-2);
        ListNode *h1 = &dummy1;
        ListNode *h2 = &dummy2;
        int k = 1;
        while(head){
            if(k%2==0){
                h1->next = head;
                h1 = h1->next;
            }else{
                h2->next = head;
                h2 = h2->next;
            }
            k++;
            head = head->next;
        }
        h2->next = dummy1.next;
        h1->next = nullptr;
        return dummy2.next;
    }

    void test(ListNode *head){
        cout<<"begin test...\n";
        ListNode n1(6),n2(2),n3(4),n4(3),n5(5),n6(1);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        n5.next = &n6;
        ListNode *head2 = &n1;
        head2 = oddEvenList(head2);
        showList(head2);

        cout<<"end test...\n";
    }

};


#endif // MYLISTNODE_H_INCLUDED
