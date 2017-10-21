Node *head = NULL;
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};


void Print(Node *head)
{
    Node *curr = head;
    cout << head->data << endl;
    if (head)
    {
        while (curr != NULL)
        {
            cout << "I am in here and I shoudlnt be!" << endl;
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
    else
    {
        cout << "The list is empty!" << endl;
    }
}

Node *insert_tail(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *curr = new Node;
        Node *prev = new Node;
        prev->next = NULL;
        curr->next = NULL;
        curr = head;
        while (curr)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }
    return newNode;
}

Node *insert_head(Node *head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        cout << "I'm in here" << endl;
        cout << head -> data << endl;
    }
    else
    {
        // cout << "I'm in the right place" << endl;
        newNode->next = head;
        head = newNode;
        cout << head->data << endl;
    }
    return head;
}

Node *insert_nth(Node *head, int data, int posisiton)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *curr = new Node;
        Node *prev = new Node;
        curr = head;
        if (curr == NULL)
        {
            cout << "The List does not have that many inputs";
            return head;
        }
        else if (posisiton == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 0; i < posisiton; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = newNode;
            newNode->next = curr;
        }
    }

    return head;
}

Node *Delete(Node *head, int position)
{

    if (head == NULL)
    {
        cout << "List is empty, you cannot delete from an empty list" << endl;
        return head;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        for (int i = 0; i < position; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL && curr == NULL)
        {
            cout << "postion is out of the lists scope!" << endl;
            return head;
        }
        else if (prev == NULL)
        {
            head = curr->next;
            delete curr;
            return head;
        }
        else if (curr == NULL)
        {
            delete prev;
            return head;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
            return head;
        }
    }
}

void Reverse_print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Reverse_print(head->next);
    cout << head->data << endl;
    return;
}

//first node will point to itself -> can solve with if statmnet at start to set it to null
Node *Revers(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = NULL;
    Node *next = NULL;
    curr = head;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int compare_lists(Node *headA, Node *headB)
{

    if (headA == NULL)
    {
        if (headB == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (headB == NULL)
    {
        return 0;
    }
    while (headA != NULL || headB != NULL)
    {
        if (headA == NULL)
        {
            return 0;
        }
        if (headB == NULL)
        {
            return 0;
        }
        else
        {
            if (headA->data != headB->data)
            {
                return 0;
            }
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
    }

    return 1;
}

// When given two linkedlist sorted in accending order -> merge the two list in one list iun accending order
// COME BACK TO!!

Node *merge_list(Node *headA, Node *headB)
{
    Node *new_head = new Node;
    new_head = NULL;
    Node *curr = new_head;
    if (headA == NULL && headB == NULL)
    {
        return new_head;
    }
    else
    {
        while (headA != NULL || headB != NULL)
        {
            if (headA == NULL)
            {
                if (new_head == NULL)
                {
                    new_head = headB;
                }
                else
                {
                    curr->next = headB;
                    curr = curr->next;
                }
                return new_head;
            }
            else if (headB == NULL)
            {
                if (new_head == NULL)
                {
                    new_head = headA;
                }
                else
                {
                    curr->next = headA;
                    curr = curr->next;
                }
                return new_head;
            }
            else if (headA->data > headB->data)
            {
                if (new_head == NULL)
                {
                    new_head = headB;
                    headB = headB->next;
                }
                else
                {
                    curr->next = headB;
                    curr = curr->next;
                }
                headB = headB->next;
            }
            else
            {
                if (new_head == NULL)
                {
                    new_head = headA;
                }
                else
                {
                    curr->next = headA;
                    curr = curr->next;
                }
                headA = headA->next;
            }
        }
    }
    return new_head;
}

int Vaule(Node *head, int posistino_from_tail)
{
    Node *curr = head;
    int count = 0;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    curr = head;
    for (int i = 0; i < (count - posistino_from_tail); i++)
    {
        curr = curr->next;
    }
    return curr->data;
}

// Given the list is sortred!
Node *RemoveDuplicate(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev, *curr;
    curr = head;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
        if (prev->data == curr->data)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev;
        }
    }
    return head;
}

//check that there is no loop given that there can be max 100 items in the list
bool has_cycle(Node *head)
{
    Node *curr = head;
    int counter = 0;
    if (head == NULL)
    {
        return false;
    }
    else
    {
        while (curr)
        {
            counter++;
            curr = curr->next;
            if (counter == 100)
            {
                return true;
            }
        }
    }
    return false;
}

// finding where two list merge
int FindMergeNode(Node *headA, Node *headB)
{
    Node *curr_a = headA;
    Node *curr_b = headB;
    if (headA == NULL && headB == NULL)
    {
        cout << "Did not Merge!" << endl;
        return 0;
    }
    else
    {
        while (curr_a)
        {
            while (curr_b)
            {
                if (curr_a == curr_b)
                {
                    return curr_a->data;
                }
                curr_b = curr_b->next;
            }
            curr_a = curr_a->next;
            curr_b = headB;
        }
    }
    cout << "Did not Merge!" << endl;
    return 0;
}

int main()
{

    Node* head = NULL;
    
    insert_tail(head, 3);
    Print(head);
}