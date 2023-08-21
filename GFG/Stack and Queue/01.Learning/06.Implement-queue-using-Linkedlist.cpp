// Implement queue using Linkedlist

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
