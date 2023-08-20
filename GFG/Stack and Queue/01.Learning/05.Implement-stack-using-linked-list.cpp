// Implement stack using linked list

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    //Write your code here

public:

    Node *head;
    int size;

    Stack()
    {
        //Write your code here
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        //Write your code here
        return size;
    }

    bool isEmpty()
    {
        //Write your code here
        return size == 0;
    }

    void push(int data)
    {
        //Write your code here
        if(size == 0) {
            head= new Node(data);
        }
        else {
            Node* newHead = new Node(data);
            newHead->next = head;
            head = newHead;
        }
        size++;
    }

    void pop()
    {
        //Write your code here
        if(size == 0) return;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete(temp);
        size--;
    }

    int getTop()
    {
        //Write your code here
        if(size == 0) return -1;
        return head->data;
    }
};
