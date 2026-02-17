// Implement stack using linked list

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Stack {

    Node top;
    int size;

    Stack() {
        top = null;
        size = 0;
    }

    // Push
    void push(int x) {
        Node newNode = new Node(x);
        newNode.next = top;
        top = newNode;
        size++;
    }

    // Pop
    int pop() {
        if (isEmpty()) {
            return -1; // underflow
        }

        int value = top.data;
        top = top.next;
        size--;
        return value;
    }

    // Peek
    int peek() {
        if (isEmpty()) return -1;
        return top.data;
    }

    // Size
    int size() {
        return size;
    }

    // Is Empty
    boolean isEmpty() {
        return size == 0;
    }
}


// =========================================================================

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
