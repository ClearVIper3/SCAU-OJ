#include <iostream>
#include <vector>
using namespace std;

typedef struct node{
    int val = 0;
    struct node* next = NULL;
    struct node* pre = NULL;
}Node;

Node* initial(int val)
{
    Node* node = new Node;
    node -> val = val;
    return node;
}

void show(Node* head)
{
    Node* ptr = head -> next;
    while(ptr -> next)
    {
        cout << ptr -> val << ' ';
        ptr = ptr -> next;
    }
    cout << ptr -> val;
}

void del(Node* head)
{
    Node* ptr = head;
    while(ptr)
    {
        Node* temp = ptr;
        ptr = ptr -> next;
        delete temp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<Node*> mp(N + 1,nullptr);
    Node* nod = initial(1);
    mp[1] = nod;
    Node* head = initial(0);
    mp[0] = head;
    nod -> pre = head;
    head -> next = nod;
    for(int i = 2; i <= N; i++)
    {
        Node* node = initial(i);
        mp[i] = node;
        int x,p;
        cin >> x >> p;
        Node* ptr = mp[x];

        if (!ptr)
        {
            cout << "Error: " << x << " not found!" << endl;
            delete node;
            continue;
        }
        if(p)
        {
            Node* ptr1 = ptr -> next;
            if (ptr1)
                ptr1 -> pre = node;
            node -> next = ptr1;
            node -> pre = ptr;
            ptr -> next = node;
        }
        else
        {
            Node* ptr1 = ptr -> pre;
                if (ptr1)
                    ptr1 -> next = node;
            node -> pre = ptr1;
            node -> next = ptr;
            ptr -> pre = node;
        }
    }
    show(head);
    del(head);
    return 0;
}
