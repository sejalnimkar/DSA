#include <iostream>
using namespace std;

class node
{
   float coeff;
   int exponent;
   node *next;
   public:
     node()
     {
         coeff=0.0f;
         exponent=0;
         next=NULL;
     }
     node(float co, int expo)
     {
         coeff=co;
         exponent=expo;
         next=NULL;
     }
     void set_coefficient(float co)
     {
        coeff=co;
     }
     void set_exponent(int expo)
     {
         exponent=expo;
     }
     void set_next(node *n)
     {
         next=n;
     }
     float get_coefficient()
     {
         return coeff;
     }
     int get_exponent()
     {
         return exponent;
     }
     node *get_next()
     {
         return next;
     }
};

class polynomial
{
   node *start;
   public: 
      polynomial()
      {
          start=NULL;
      }
      ~polynomial()
      {
          node *deletable,*temp;
          temp=start;
          while(temp!=NULL)
          {
             deletable=temp;
             temp=temp->get_next();
             delete deletable;
          }
      }
      void insert(float co, int ex)
      {
          node *new_node=new node(co,ex);
          if((start==NULL)||ex>start->get_exponent())
          {
              new_node->set_next(start);
              start=new_node;
              return;
          }

          node *ptr=start;
          while((ptr->get_next()!=NULL)&&(ptr->get_next()->get_exponent()>=ex))
          {
              ptr=ptr->get_next(); 
          }
          
          if(ptr->get_exponent()==ex)
          {
              ptr->set_coefficient(ptr->get_coefficient()+co);
          }
          else
          {
             new_node->set_next(ptr->get_next());
             ptr->set_next(new_node);
          }
      }

      void display()
      {
          if(start==NULL)
          {
              cout<<"\nZero Polynomial";
              return;
          }

          node *ptr=start;
          while(ptr!=NULL)
          {
              cout<<ptr->get_coefficient()<<"x^"<<ptr->get_exponent();
              if(ptr->get_next()!=NULL){
                  cout<<" + ";
              }
              ptr=ptr->get_next();
          }
          cout<<"\n";
      }

    node * operator = (const polynomial &poly)
    {
        node *deletable=this->start;
        node *temp=this->start;
        while(temp!=NULL)
        {
            deletable=temp->get_next();
            temp=temp->get_next();
            delete deletable;
        }

        this->start=NULL;
        temp= poly.start;
        while(temp!=NULL)
        {
            this->insert(temp->get_coefficient(),temp->get_exponent());
            temp=temp->get_next();
        }
        return poly.start;
    }

    polynomial (polynomial &poly)
    {
        node *temp=poly.start;
        this->start=NULL;
        while(temp!=NULL)
        {
            this->insert(temp->get_coefficient(),temp->get_exponent());
            temp=temp->get_next();
        }
    }

    polynomial operator +(polynomial &poly2)
    {
          node *temp1, *temp2;
          polynomial res;
          temp1=start; 
          temp2=poly2.start;
          while(temp1!=NULL && temp2!=NULL)
          {
              if(temp1->get_exponent()>temp2->get_exponent())
              {
                  res.insert(temp1->get_coefficient(),temp1->get_exponent());
                  temp1=temp1->get_next();
              }
              else if(temp2->get_exponent()>temp1->get_exponent())
              {
                  res.insert(temp2->get_coefficient(),temp2->get_exponent());
                  temp2=temp2->get_next();
              }
              else
              {
                  res.insert(temp1->get_coefficient()+temp2->get_coefficient(),temp1->get_exponent());
                  temp1=temp1->get_next();
                  temp2=temp2->get_next();
              }
          }
          while(temp1!=NULL)
          {
              res.insert(temp1->get_coefficient(),temp1->get_exponent());
              temp1=temp1->get_next();
          }
          while(temp2!=NULL)
          {
              res.insert(temp2->get_coefficient(),temp2->get_exponent());
              temp2=temp2->get_next();
          }
          return res;
    }

    polynomial operator *(const polynomial &poly)
    {
        polynomial res;
        node *temp1, *temp2;
        temp1=start;
        temp2=poly.start;
        while(temp1!=NULL)
        {
           while(temp2!=NULL)
           {
               res.insert(temp1->get_coefficient()*temp2->get_coefficient(), temp1->get_exponent()+temp2->get_exponent());
               temp2=temp2->get_next();
           }
           temp1=temp1->get_next();
           temp2=poly.start;
        }
        return res;
    }
};

int main()
{
   polynomial obj1,obj2,res;
   obj1.insert(2,3);
   obj1.insert(5,1);
   obj1.insert(4,2);
   obj1.insert(4,0);
   obj1.insert(2,4);
   cout<<"\nFirst polynomial: ";
   obj1.display();
  
   obj2.insert(1,4);
   obj2.insert(3,3);
   obj2.insert(3,5);
   cout<<"\nSecond polynomial: ";
   obj2.display();
   
   res=obj1*obj2;
   cout<<"\nResult of multiplication: ";
//    res=obj1+obj2;
//    cout<<"\nResult of addition: ";
   res.display();

   return 0;
}