#include <stdio.h>
#include <iostream>
using namespace std;

class linkedlist
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_back(int n)
    {
        node* temp = new node;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove_back()
    {
        node* temp = head;
        if (head == NULL)
        {
            return;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            tail = temp;
        }
    }

    void insert_front(int n)
    {
        node* temp = new node;
        temp->data = n;
        if (head == NULL)
        {
            temp->next = NULL;
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void remove_front()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node* temp = head;
            head = temp->next;
            delete temp;
        }
    }

    void printlist()
    {
        node* temp = head;
        if (head == NULL)
        {
            return;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    void reverse()
    {
        node* temp = NULL;
        node* previous = NULL;
        node* current = head;
        while (current != NULL)
        {
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        head = previous;
    }

    int smallest()
    {
        node* temp = head;
        int small = temp->data;
        while (temp != NULL)
        {
            if (small > temp->data)
            {
                small = temp->data;
            }
            temp = temp->next;
        }
        return small;
    }

    int largest()
    {
        node* temp = head;
        int large = temp->data;
        while (temp != NULL)
        {
            if (large < temp->data)
            {
                large = temp->data;
            }
            temp = temp->next;
        }
        return large;
    }

    int listsize()
    {
        node* temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void deletegiven(int n)
    {
        node* temp = head;
        node* prev = temp;
        if (temp != NULL && temp->data == n)
        {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != NULL && temp->data != n)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }
        else
        {
            if (temp->next == NULL && temp->data == n)
            {
                prev->next = temp->next;
                delete temp;
                tail = prev;
                return;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
};

int main()
{
    linkedlist l;
    for (int i = 0; i < 5; i++)
    {
        l.enqueue(i);
    }

    l.deletegiven(0);
    l.printlist();

   

    return 0;
}