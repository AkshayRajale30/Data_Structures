// Doubly Circular Linked List

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:    
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets Created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)   // Empty list
            {
                first = last = newn;
                first->next = first;
                first->prev = first;
            }
            else
            {
                newn->next = first;
                newn->prev = last;
                first->prev = newn;
                last->next = newn;
                first = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = last = newn;
                first->next = first;
                first->prev = first;
            }
            else
            {
                last->next = newn;
                newn->prev = last;
                newn->next = first;
                first->prev = newn;
                last = newn;
            }
            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE temp = first;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                PNODE newn = new NODE;
                newn->data = no;

                newn->next = temp->next;
                newn->prev = temp;
                temp->next->prev = newn;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                first = first->next;
                delete first->prev;
                first->prev = last;
                last->next = first;
            }
            iCount--;
        }

        void DeleteLast()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = last = NULL;
            }
            else
            {
                last = last->prev;
                delete last->next;
                last->next = first;
                first->prev = last;
            }
            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid Position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = first;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                PNODE targated = temp->next;
                temp->next = targated->next;
                targated->next->prev = temp;
                delete targated;

                iCount--;
            }
        }

        void Display()
        {
            if(first == NULL)
            {
                cout<<"Linked List is empty\n";
                return;
            }

            PNODE temp = first;
            cout<<"<=> ";
            do
            {
                cout<<"| "<<temp->data<<" | <=> ";
                temp = temp->next;
            } while(temp != first);
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    return 0;
}