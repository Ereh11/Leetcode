
class SingleLinkedList;

class Node
{
private:
    int val;
    Node *next;
    friend class MyLinkedList;
};

class MyLinkedList
{
private:
    Node *Head;
    int counter_size;

public:
    MyLinkedList() : Head(NULL)
    {
        counter_size = 0;
    }
    bool empty()
    {
        return (Head == NULL);
    }
    void addAtHead(int value)
    {
        Node *node = new Node;
        node->val = value;
        if (empty())
            node->next = NULL;
        else
            node->next = Head;
        Head = node;
        counter_size++;
    }
    void deletehead()
    {
        if (empty())
            cout << "Linked List is Empty\n";
        else
        {
            if (Head->next == NULL)
                Head = NULL;
            else
                Head = Head->next;
            counter_size--;
        }
    }
    int size()
    {
        return counter_size;
    }
    void addAtIndex(int indx, int value)
    {
        if (indx < 0 || indx > size())
            return;
        else if (indx == size())
            addAtTail(value);
        else
        {
            Node *node = new Node;
            Node *last = new Node;
            node->val = value;
            last = Head;
            int count = 0;
            if (indx == 0)
                node->next = Head, Head = node;
            else
            {
                while (count < indx - 1)
                    last = last->next, count++;
                node->next = last->next;
                last->next = node;
            }
            counter_size++;
        }
    }
    void addAtTail(int value)
    {
        if (empty())
            addAtHead(value);
        else
        {
            Node *node = new Node;
            Node *last = new Node;
            node->val = value;
            node->next = NULL;
            last->next = Head;

            while (last->next != NULL)
                last = last->next;

            last->next = node, counter_size++;
        }
    }
    int get(int indx)
    {
        if (indx < 0 || indx >= size())
            return -1;
        else
        {
            Node *last = new Node;
            last = Head;
            int count = 0;
            while (count != indx)
            {
                last = last->next, count++;
            }
            return last->val;
        }
    }
    void deleteAtIndex(int indx)
    {
        if (indx < 0 || indx >= size())
            return;

        if (indx == 0)
            Head = Head->next, counter_size--;
        else
        {
            Node *last = new Node;
            Node *prev = new Node;
            last = Head;
            prev = Head;

            int count = 0;
            while (count != indx)
            {
                prev = last;
                last = last->next, count++;
            }
            prev->next = last->next;
            counter_size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */