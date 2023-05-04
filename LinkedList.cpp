#include <iostream>
using namespace std;

class node
{
   int data;
   node*next;
   public:
      node()
      {
          data=0;
          next=NULL;
      }
      node(int d)
      {
          data=d;
          next=NULL;
      }
      void set_data(int d)
      {
          data=d;
      }
      int get_data()
      {
          return data;
      }
      void set_next(node *n)
      {
          next=n;
      }
      node *get_next()
      {
          return next;
      }

};

class LinkedList
{
   node *head;
   public:
     LinkedList()
     {
         head=NULL;
     }
     ~LinkedList()
     {
         node *deletable;
         node *temp=head;
         while(temp!=NULL)
         {
             temp=temp->get_next();
             deletable=temp;
             delete deletable;
         }
         head==NULL;
     }

     void insert_first(int d)
     {
         node *new_node = new node(d);
         if(head==NULL)
         {
             head=new_node;
             return;
         }
         new_node->set_next(head);
         head=new_node;
         return;
     }

     void display()
     {
         node *temp=head;
         cout<<"\n";
         while(temp !=NULL)
         {
             cout<<temp->get_data()<<" ";
             temp=temp->get_next();
         }
     }

     void insert_last(int d)
     {
         node *new_node= new node(d);
         node *temp=head;
         if(head==NULL)
         {
             head=new_node;
             return;
         }
         while(temp->get_next()!=NULL)
         {
             temp=temp->get_next();
         }
         temp->set_next(new_node);
         return;
     }

     void insert_by_pos(int d, int pos)
     {
         node *new_node= new node(d);
         node *temp;
         if(head==NULL)
         {
             head=new_node;
             return;
         }
         if(pos==1)
         {
             new_node->set_next(head);
             head=new_node;
             return;
         }
         temp=head;
         for(int i=0;(i<pos-1)&&(temp->get_next()!=NULL);i++)
         {
            temp=temp->get_next();
         }

         new_node->set_next(temp->get_next());
         temp->set_next(new_node);
         return;
     }

     void delete_first()
     {
         if(head==NULL)
         {
             cout<<"List is empty..."<<endl;
             return;
         }
         node *deletable=head;
         head=head->get_next();
         delete deletable;
     }

     void delete_last()
     {
         if(head==NULL)
         {
             cout<<"List is empty..."<<endl;
             return;
         }
         node *temp= head ,*deletable;
         while(temp->get_next()->get_next()!=NULL)
         {
             temp=temp->get_next();
         }
         deletable=temp->get_next();
         temp->set_next(NULL);
         delete deletable;
     }
     
     void delete_by_pos(int pos)
     {
         node *temp=head;
         node *deletable;
         for(int i=1;i<pos-1;i++)
         {
             temp=temp->get_next();
         }
         deletable=temp->get_next();
         temp->set_next(temp->get_next()->get_next());
         delete deletable;
     }

     void insert_before(int d,int value)
     {
        node *temp=head;
        node *new_node= new node(d);
        while((temp->get_next()->get_data()!=value)&&(temp!=NULL))
        {
            temp=temp->get_next();
        }
        if(temp->get_next()->get_data()==value)
        {
            new_node->set_next(temp->get_next());
            temp->set_next(new_node);
        }
        if(temp==NULL)
        {
            cout<<"\nElement not found";
        }
     }

     void insert_after(int d, int value)
     {
         node *temp=head;
         node *new_node= new node(d);
         while((temp->get_data()!=value)&&(temp!=NULL))
         {
             temp=temp->get_next();
         }
         if(temp->get_data()==value)
         {
            new_node->set_next(temp->get_next());
            temp->set_next(new_node);
         }
         if(temp==NULL)
         {
             cout<<"\nElement not found";
         }
     }
     void reverse()
     {
         node *temp, *prev, *next;
         prev=NULL;
         temp=head;
         while(temp!=NULL)
         {
             next=temp->get_next();
             temp->set_next(prev);
             prev=temp;
             temp=next;
         }
         head=prev;
     }
     
    void sort()
    {
        node *p1,*p2;int temp;
        for(p1=head;p1->get_next()!=NULL;p1=p1->get_next())
        {
            for(p2=p1->get_next() ; p2!=NULL ; p2=p2->get_next())
            {
               if(p1->get_data()>p2->get_data())
               {
                   temp=p1->get_data();
                   p1->set_data(p2->get_data());
                   p2->set_data(temp);
               }
            }
        }
    }

    void merge(LinkedList l)
    {
        node* temp=head;
        while(temp->get_next() != NULL)
        {
            temp=temp->get_next();
        }
        temp->set_next(l.head);
    }
    
    LinkedList(LinkedList &l1)
    {
        node *temp=l1.head;
        this->head=NULL;
        while(temp!=NULL)
        {
            this->insert_last(temp->get_data());
            temp=temp->get_next();
        }
    }

    void operator = (LinkedList &l)
    {
        node *deletable=this->head;
        node*temp=this->head;
        while(temp!=NULL)
        {
            deletable=temp->get_next();
            temp=temp->get_next();
            delete deletable;
        }
        this->head=NULL;
        temp= l.head;
        while(temp!=NULL)
        {
            this->insert_last(temp->get_data());
            temp=temp->get_next();
        }
    }

    void even_data()
    {
        int data=0;
        node *temp=head;
        while(temp!=NULL)
        {
            data=temp->get_data();
            if(data%2==0){
                cout<<" "<<data;
            }
            temp=temp->get_next();
        }
        cout<<"\n";
    }

    void odd_data()
    {
        int data=0;
        node *temp=head;
        while(temp!=NULL)
        {
            data=temp->get_data();
            if((data)%2==1){
                cout<<" "<<data;
            }
            temp=temp->get_next();
        }
        cout<<"\n";
    }

    void sum_of_even_data()
    {
        int sum, data;
        node *temp=head;
        sum=data=0;
        while(temp!=NULL)
        {
            data=temp->get_data();
            if(data%2==0){
                sum=sum+data;
            }
            temp=temp->get_next();
        }
        cout<<"\nSum of even nodes: "<<sum;
    }

    void sum_of_odd_data()
    {
        int data,sum;
        data=sum=0;
        node *temp=head;
        while(temp!=NULL)
        {
            data=temp->get_data();
            if(data%2==1){
                sum=sum+data;
            }
            temp=temp->get_next();
        }
        cout<<"\nSum of odd nodes: "<<sum;
    }
};

int main()
{
   LinkedList train;
//    LinkedList airplane;
//    LinkedList bus;
   train.insert_first(10);
   train.insert_last(30);
   train.insert_last(20);
   train.insert_last(40);
   train.insert_last(60);
   train.insert_last(50);
   train.insert_last(37);
   train.insert_last(43);
   train.display();

   cout<<"\nEven nodes in train";
   train.even_data();
   cout<<"\nOdd nodes in train";
   train.odd_data();
   train.sum_of_even_data();
   train.sum_of_odd_data();
//    train.insert_last(8);
//    cout<<"\nInsert by pos function";
//    train.insert_by_pos(2,3);
//    train.delete_first();
//    cout<<"\n";
//    train.display();
//    train.delete_last();
//    cout<<"\n";
//    train.reverse();
//    cout<<"\nSorting train";
//    train.sort();
//    train.display();

//    bus.insert_first(1);
//    bus.insert_first(2);
//    bus.insert_first(3);
//    bus.insert_first(4);
//    bus.insert_first(5);
//    bus.insert_first(6);

//    cout<<"\nNew linked list bus";
//    bus.display();
//    airplane=train;

//    train.merge(bus);
//    train.insert_after(7,20);
//    cout<<"\nTrain insert_after func called ";
//    train.display();

//    bus.insert_before(70,3);
//    cout<<"\nBus insert_before func called";
//    cout<<"\nDeleting 4th position node in train and bus";
//    train.delete_by_pos(4);
//    bus.delete_by_pos(4);
//    train.display();
//    bus.display();
// cout<<"\nAirplane:-";
// airplane.display();
   return 0;
}