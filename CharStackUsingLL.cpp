#include <iostream>
using namespace std;


class node
{
   char data;
   node*next;
   public:
      node()
      {
          data='0';
          next=NULL;
      }
      node(char d)
      {
          data=d;
          next=NULL;
      }
      void set_data(char d)
      {
          data=d;
      }
      char get_data()
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

class char_stack
{
   node *top;
   public: 
   char_stack()
   {
      top=NULL;
   }

   ~char_stack()
   {
      node *deletable=top;
      node *temp=top;
      while(temp!=top)
      {
         deletable=top;
         temp=temp->get_next();
         delete deletable;
      }
         top=NULL;
   }
   
   void push(char d)
   {
      node *new_node = new node(d);
      if(top==NULL)
      {
         top=new_node;
         return;
      }
      new_node->set_next(top);
      top=new_node;
      return;
   }

   void pop() 
   {
      node *deletable;
      if(top==NULL)
      {
         cout<<"List is empty..."<<endl;
         return;
      }
      deletable=top;
      top=top->get_next();
      cout<<"\n"<<deletable->get_data()<<" deleted";
      delete deletable;
      return;
   }

   void peek() 
   {
      if(top==NULL)
      {
         cout<<"List is empty..."<<endl;
          return;
      }
      cout<<"\nTopmost element is "<<top->get_data();
      return;
   }

   bool isFull() 
   {
       if(top==NULL)
          return false;
       else
          return true;
   }

   bool isEmpty() 
   {
       if(top==NULL)
          return true;
       else
          return false;
   }

   void display()
   {
      node *temp = top;
      cout<<"\n";
      while(temp != NULL)
      {
         cout<<" "<<temp->get_data();
         temp=temp->get_next();
      }
   }
};

int main()
{
   char_stack obj;
  obj.push('!');
  obj.push('O');
  obj.push('L');
  obj.push('L');
  obj.push('E');
  obj.push('H');

  obj.display();

  obj.pop();
  obj.pop();
  obj.display();

  obj.peek();

  cout<<"\nStack is full? : "<<obj.isFull()<<endl;
   return 0;
}