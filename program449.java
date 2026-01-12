//  Doubly Circular Linked List

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCL
{
    private node first;
    private node last;
    private int iCount;

    public DoublyCL() 
    {
        System.out.println("Object of DoublyCL get created.");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null)
        {
            first = last = newn;
            first.next = first;
            first.prev = first;
        }
        else
        {
            newn.next = first;
            newn.prev = last;
            first.prev = newn;
            last.next = newn;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null)
        {
            first = last = newn;
            first.next = first;
            first.prev = first;
        }
        else
        {
            last.next = newn;
            newn.prev = last;
            newn.next = first;
            first.prev = newn;
            last = newn;
        }
        iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid position");
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
            node temp = first;

            for(int i = 1; i < pos - 1; i++)
            {
                temp = temp.next;
            }

            node newn = new node(no);

            newn.next = temp.next;
            newn.prev = temp;
            temp.next.prev = newn;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }
        iCount--;
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position");
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
            node temp = first;

            for(int i = 1; i < pos; i++)
            {
                temp = temp.next;
            }

            temp.prev.next = temp.next;
            temp.next.prev = temp.prev;

            iCount--;
        }
    }

    public void Display()
    {
        if(first == null)
        {
            System.out.println("Linked list is empty");
            return;
        }

        node temp = first;

        System.out.print("<=> ");
        do
        {
            System.out.print("| " + temp.data + " | <=> ");
            temp = temp.next;
        }
        while(temp != first);

        System.out.println("NULL");
    }

    public int Count()
    {
        return this.iCount;
    }
}

class program449
{
    public static void main(String A[]) 
    {
        int iRet = 0;
        DoublyCL obj = null;
       
        obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();
       
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();
       
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertAtPos(105, 4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj = null;
        System.gc();
    }    
}