#include<bits/stdc++.h>
using namespace std;
class Node
{
public :
    int value;
    Node *Next;
    //constructor creation
    Node(int val)
    {
        value=val;
        Next=NULL;
    }
};
struct Duplicate // we are declaring a struct because we can't return an array from function.
{
    int position[1000];
};
void display(Node *h)
{
    while(h!=NULL)
    {
        cout<<h->value<<endl;
        h=h->Next;

    }
}
void insertAtTail(Node* &head, int v )
{
        Node *NewNode = new Node(v);
        if(head==NULL)
        {
            head=NewNode; // holding the address of new node
        }
        else
        {
            Node *temp = head;
            while(temp->Next!=NULL)
            {
                temp=temp->Next;
            }
            temp->Next=NewNode; // holding the address of new node
        }
}
void insertAtHead(Node* &head, int v)
{
    Node * newnode = new Node(v);
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        Node * temp = head;
        head=newnode;
        head->Next=temp;
      /*
        // or we can do
        // s1: new node creation
       Node * newnode = new Node(v);
        // update of new node => to head
        newnode->Next = head;
        // update of head
        head=newnode; */
    }
}
int length(Node *&head)
{
    int c=0;
    Node * newnode = head;
    while(newnode!= NULL)
    {
        c++;
        newnode=newnode->Next;
    }
    return c;
}

void insertAtSpecificPosition(Node *&head, int pos, int val)
{
    Node *newnode= new Node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node *temp=head; // by following this way we can't add value at position 1. we have to use position at head function to insert position at 1
        if(pos==1)
        {
            insertAtHead(head,val);
        }
        else
        {
       for(int i=1;i<pos-1;i++) // if i==0, then i<pos-2;i++
       {
           temp=temp->Next;
       }
        Node * NextNode = temp->Next; // we have to set temp->next  to our new node. that is why we are keeping temp-next value in nextnode. other wise the current value of temp->next will be lost.
        temp->Next=newnode; // we are keeping newnode to temp->next . temp is indicating the pos-1.
       newnode->Next=NextNode; // now we are connecting newnode next to the nextnode . nextnode was the
       /*
       newnode->Next = temp->Next;
       temp->Next= newNode;
       */
        }
    }
}

int searchUnique(Node *&head,int sv)
{
        if(head==NULL)
        {
            return -1;
        }
    else
    {
        int c=1;
        Node *temp = head;
        while(temp->value!=sv) // when temp value is not match then loop will working
        {
            if(temp->Next==NULL) // when it will be at end position
            {
                return -1;
            }
            c++;
            temp=temp->Next;
        }
        return c;
    }
}
void searchDuplicate(Node*head, int sv)
{

        Node *temp=head;
        int siz = length(head);// we are calling length function which we have created previously. Here, I have measuring the size of linked list.
        int position[siz+1],k=1; // all value can  be duplicate, and index number 0 will hold total size of  duplicate. that is why we are taking size+1
        int c=1;
        int f=0;
        while(temp!=NULL)
        {
            if(temp->value==sv)
            {
                position[k]=c;
                k++;
                f++;
            }
            c++;
            temp=temp->Next;
        }

        if(f==0)
        {
            cout<<"Searched value is not found"<<endl;
        }
        else
        {
            position[0]=k;
            cout<<"The value is found at position: "<<endl;
            for(int i=1;i<position[0];i++)// or i<k
            {
                cout<<position[i];
                if(i<position[0]-1) cout<<",";
            }
            cout<<endl;
        }


}
Duplicate search_duplicateValue_Return (Node *&head, int val) // type will be struct type because we will return struct
{
        Node *temp=head;
        Duplicate D;
        int k=1;
        int c=1;

        while(temp!=NULL)
        {
            if(temp->value==val)
            {
                D.position[k]=c;
                k++;
            }
            c++;
            temp=temp->Next;
        }
        D.position[0]=k; // 0 number index will hold total size that how much duplicate element we have . we will need it when we will print value from main function
        return D;
}

void insert_After_before_A_Specific_Value(Node *&head, int wantedv, int insertedv)
{
    Node *temp = head;
    /*int c=1;
    while(temp->value!=wantedv)
    {
        c++;
        temp=temp->Next;
    }*/
    // or we can just call search unique function which will return us position of searched value
    int pos= searchUnique(head,wantedv);
    insertAtSpecificPosition(head,pos+1,insertedv);
    // if we want to insert before just we can do pos-1;
}

void deletionAtHead(Node *&head)
{
    if(head==NULL)
    {
        cout<<"There is no value in the Linked List"<<endl;
    }
    else
    {
         Node *temp=head;
        head=temp->Next;
        delete temp;
        cout<<"Delete from head is successfully completed"<<endl;
        cout<<"Linked list after deletion"<<endl;
        display(head);
    }

}

void deletionAtTail(Node *&head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"There is no value in the Linked List"<<endl;
    }
    else
    {
        if(temp->Next==NULL)
        {
            delete temp; // or we can call delete from head function because here, head and tail is same basically
            // deletionAtHead(head);
             cout<<"Delete from tail is successfully completed"<<endl;
        }
        else
        {
            while(temp->Next->Next!=NULL) // we will traverse up to 2nd last element
            {
                temp=temp->Next;
            }
            Node * delNode = temp->Next;
            temp->Next=NULL;
            delete delNode;
             cout<<"Delete from tail is successfully completed"<<endl;
             cout<<"Linked list after deletion"<<endl;
                display(head);
        }

    }

}


int main()
{
    Node *head=NULL;
    int len;
    int choice;
    cout<<"Give your choice:  "<<endl;
    cout<<"Choice 1:  Insert at head  "<<endl;
    cout<<"Choice 2:  Insert at tail  "<<endl;
    cout<<"Choice 3: Insert at specific position "<<endl;
    cout<<"Choice 4: Searching value from unique valued linked list"<<endl<<"any value for exist "<<endl;
    cout<<"Choice 5:  Searching value from duplicate valued linked list"<<endl;
    cout<<"Choice 6:  Insert a value after a specific position"<<endl;
    cout<<"Choice 7: Delete from head "<<endl;
  cout<<"Choice 8: Delete from Tail "<<endl;
    cin>>choice;
    while(choice!=0)
    {
        int value, position;

        if(choice==1)
        {
            cout<<"enterValue: ";
            cin>>value;
            insertAtHead(head,value);
        }
        else if(choice ==2)
        {
            cout<<"enterValue: ";
            cin>>value;
            insertAtTail(head,value);
        }
        else if( choice==3)
        {
            cout<<"enter position: ";
            cin>>position;
            cout<<"enterValue: ";
            cin>>value;
            insertAtSpecificPosition(head,position,value);
        }
        else if(choice ==4)
        {
            cout<<"enterValue to search: ";
            cin>>value;
            int position= searchUnique(head,value);
            if(position==-1)
            {
                cout<<"This value is not exist"<<endl;
            }
            else
                cout<<"Position of searched value is: "<<position<<endl;
        }
        else if(choice==5)
        {

             cout<<"enterValue to search duplicate position: ";
            cin>>value;
           // searchDuplicate(head,value);
           Duplicate DD;
           DD=search_duplicateValue_Return(head,value); // for calling a struct, we need to declare another struct
           int len = DD.position[0];
           if(len==1)
           {
               cout<<"The searched value is not found"<<endl;
           }
           else
           {
                cout<<"The value is found at position: "<<endl;
               for(int i=1;i<len;i++)
               {
                   cout<<DD.position[i];
                   if(i<len-1)
                    cout<<",";
               }
               cout<<endl;
           }

        }
        else if(choice==6)
        {
            int wantvalue;
            cout<<"You want to insert after which value?  ";
            cin>>wantvalue;
            cout<<"enterValue which you want to insert:  " ;
            cin>>value;
            insert_After_before_A_Specific_Value(head,wantvalue,value);
        }

       else if(choice==7)
       {
           deletionAtHead(head);
       }
       else if(choice==8)
       {
           deletionAtTail(head);
       }
        else
        {
            break;
        }
        cout<<"Next Choice: ";
        cin>>choice;
    }
    cout<<endl;
    cout<<"Linked List: "<<endl;
    display(head);/// we are not passing here address of head because linked list work like an array. array does not need address when we pass array.
    cout<<endl<<"Length of Linked List:"<<endl;
    len= length(head);
   cout<<len;




}





