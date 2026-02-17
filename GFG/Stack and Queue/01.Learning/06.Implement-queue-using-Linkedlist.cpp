// Implement queue using Linkedlist

class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class Queue {

    Node front, rear;
    int size;

    Queue() {
        front = null;
        rear = null;
        size = 0;
    }

    // Enqueue
    void push(int x) {
        Node newNode = new Node(x);

        if (rear == null) {   // queue empty
            front = rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }

        size++;
    }

    // Dequeue
    int pop() {
        if (isEmpty()) {
            return -1;  // underflow
        }

        int value = front.data;
        front = front.next;

        if (front == null) {  // queue becomes empty
            rear = null;
        }

        size--;
        return value;
    }

    // Peek (Front element)
    int peek() {
        if (isEmpty()) return -1;
        return front.data;
    }

    // Size
    int size() {
        return size;
    }

    // Check if empty
    boolean isEmpty() {
        return size == 0;
    }
}

// ============================================================================

class QueueNode
{
 public: 
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
       val = data;
       next = nullptr;
    }
};  
QueueNode *Front = nullptr, *Rare = nullptr;

class Queue
{
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};  

bool Queue ::  Empty()
{
    return Front == nullptr;
}  

int Queue :: Peek()
{
    if(Empty())  
     {  cout<<"Queue is Empty"<<endl;
        return -1;
     } 
    else 
      return Front->val;
}   

void Queue :: Enqueue(int value)
{
    QueueNode *Temp;
    Temp = new QueueNode(value); 
    if (Temp == nullptr)  //When heap exhausted 
        cout << "Queue is Full" << endl;
    else
    {
        if (Front == nullptr)
        {
            Front = Temp;
            Rare = Temp;
        } 
        else
        {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout<<value <<" Inserted into Queue "<<endl;
        size++;
    } 
}    

void Queue :: Dequeue() 
{
    if (Front == nullptr) 
        cout << "Queue is Empty" << endl;
    else
    { 
        cout<<Front->val <<" Removed From Queue"<<endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete Temp;
        size--;
    }  
}   
