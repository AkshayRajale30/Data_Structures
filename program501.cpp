/////////////////////////////////////////////////////////////////////////////
//        Final Correct Code of Queue using Generic Approach
/////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            data = no;
            next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T>* first;
        Queuenode<T>* last;
        int iCount;

    public:
        Queue();
        ~Queue();

        void enqueue(T no);
        bool dequeue(T &Value);
        void Display();
        int Count();
};

template <class T>
Queue<T>::Queue()
{
    cout<<"Queue gets created successfully...\n";
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
Queue<T>::~Queue()
{
    T temp;
    while(first != NULL)
    {
        dequeue(temp);
    }
}

template <class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T>* newn = new Queuenode<T>(no);

    if(first == NULL)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    iCount++;
}

template <class T>
bool Queue<T>::dequeue(T &Value)
{
    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return false;
    }

    Queuenode<T>* temp = first;
    Value = temp->data;

    first = first->next;

    if(first == NULL)   // queue becomes empty
    {
        last = NULL;
    }

    delete temp;
    iCount--;
    return true;
}

template <class T>
void Queue<T>::Display()
{
    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    Queuenode<T>* temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

int main()
{
    Queue<int>* qobj = new Queue<int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(true)
    {
        cout<<"--------------------------------------------------\n";
        cout<<"1 : Insert element into Queue\n";
        cout<<"2 : Remove element from Queue\n";
        cout<<"3 : Display Queue\n";
        cout<<"4 : Count elements\n";
        cout<<"0 : Exit\n";
        cout<<"--------------------------------------------------\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter element to insert : ";
                cin>>Value;
                qobj->enqueue(Value);
                cout<<"Element inserted successfully\n";
                break;

            case 2:
                if(qobj->dequeue(iRet))
                {
                    cout<<"Removed element is : "<<iRet<<"\n";
                }
                break;

            case 3:
                cout<<"Elements of Queue are :\n";
                qobj->Display();
                break;

            case 4:
                cout<<"Total elements in Queue : "<<qobj->Count()<<"\n";
                break;

            case 0:
                cout<<"Thank you for using the application\n";
                delete qobj;
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
    return 0;
}
