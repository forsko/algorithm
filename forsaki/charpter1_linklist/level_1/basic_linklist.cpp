#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct Node {
    int val;
    struct Node* next;
}node;

struct Node* initList()
{
    node* head = NULL;
    node* curr = (node*)malloc(sizeof(node));
    curr->val = 0;
    curr->next = NULL;
    head = curr;
    for (int i = 1; i < 10; i++)
    {
        node* temp = (node *)malloc(sizeof(node));
        temp->val = i;
        temp->next = NULL;
        curr->next = temp;
        curr = curr->next;
    }
    return head;
}

void printList(node *head)
{
    for (node* temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->val << " ";
    }
    cout << endl;
    return;
}

int getLength(node *head)
{
    int length = 0;
    node *temp =  head;
    while (temp!=NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

struct Node* insertNode(node* head, node* nodeInsert, int position)
{
    if (head == NULL) {
        return nodeInsert;
    }

    int listSize = getLength(head);
    if (position < 1 || position > listSize + 1) {
        cout << "OVERREACH!" << endl;
    }

    if (position == 1) {
        nodeInsert->next = head;
        head = nodeInsert;
        return head;
    }

    node* prev = head;
    int cnt = 1;
    while (cnt < position - 1) {
        cnt++;
        prev = prev->next;
    }
    nodeInsert->next = prev->next;
    prev->next = nodeInsert;
    return head;
}

struct Node* monotonousInsertnode(node* head, node* nodeInsert)
{
    if (head == NULL) {
        return nodeInsert;
    }

    if (nodeInsert->val < head->val) {
        nodeInsert->next = head;
        head = nodeInsert;
        return head;
    }

    node* smaller = head;

    //
    while ((smaller->next != NULL) && (smaller->next->val < nodeInsert->val)) {
        smaller = smaller->next;
    }
    nodeInsert->next = smaller->next;
    smaller->next = nodeInsert;
    return head;
}

struct Node* deleteNode(node* head, int position)
{
    if (head == NULL) {
        return NULL;
    }

    int listSize = getLength(head);
    if (position < 1 || position > listSize) {
        cout << "INPUT ERROR" << endl;
        return head;
    }

    if (position == 1) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* prev = head;
    int cnt = 1;
    while (cnt < position - 1) {
        cnt++;
        prev = prev->next;
    }
    node* curr = prev->next;
    prev->next = curr->next;
    free(curr);
    return head;
}

void testInsert()
{
    node* head = NULL;
    node* temp = (node*)malloc(sizeof(node));
    temp->val=1;
//    插入第一个元素
    head = insertNode(head,temp,1);
    printList(head);

 //    插入第二个元素，因为前面至于一个元素，这里就是在尾部插入了
    temp = (node*)malloc(sizeof(node));
    temp->val=3;
    head=insertNode(head,temp,2);
    printList(head);


 //    插入第二个元素，后面有个三，所以这里就是中间位置插入了
    temp = (node*)malloc(sizeof(node));
    temp->val=2;
    head=insertNode(head,temp,2);
    printList(head);
}

void testMonotonousInsert()
{

    node* head = NULL;
    node* temp = (node*)malloc(sizeof(node));
    temp->val=1;

    head = monotonousInsertnode(head,temp);
    printList(head);

    temp = (node*)malloc(sizeof(node));
    temp->val=3;
    head=monotonousInsertnode(head,temp);
    printList(head);

    temp = (node*)malloc(sizeof(node));
    temp->val=2;
    head=monotonousInsertnode(head,temp);
    printList(head);

    temp = (node*)malloc(sizeof(node));
    temp->val=4;
    head=monotonousInsertnode(head,temp);
    printList(head);

    temp = (node*)malloc(sizeof(node));
    temp->val=8;
    head=monotonousInsertnode(head,temp);
    printList(head);

    temp = (node*)malloc(sizeof(node));
    temp->val=-1;
    head=monotonousInsertnode(head,temp);
    printList(head);
}

void testDelete()
{

    node* p = NULL;
    printf("create list: \t\n");
    //创建链表0~5
    p = initList();
    printList(p);

    // 删除第一个元素0
    p= deleteNode(p,1);
    printList(p);

   //删除中间元素
    p= deleteNode(p,5);
    printList(p);

   //删除末尾元素9
    p= deleteNode(p,8);
    printList(p);

}
int main()
{
    //testDelete();
    return 0;
}

