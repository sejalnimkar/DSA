#include <iostream>
using namespace std;
void display(int *,int);
int sum_of_even(int);
int factorial(int);

// int main()
// {
//    int num,fact;
//    cout<<"Enter number for factorial: ";
//    cin>>num;
//    fact=factorial(num);
//    cout<<"\n Factorial: "<<fact;
//    return 0;
// }

// int factorial(int n)
// {
//     if(n==0)
//        return 1;
//     else
//        return n*factorial(n-1);
// }


int main()
{
//   int arr[]={10,20,30,40,50,60,70,80,100};
//   display(arr,0);
  int sum=sum_of_even(198);
  cout<<"\n Sum of even numbers from 198: "<<sum;
  return 0;
}

void display(int* ptr,int num)
{
    int i=num;
    if(i==9)
    {
       return;
    }
    else
    {
       cout<<"\n "<<ptr[i];
       display(ptr,i+1);
    }
}

int sum_of_even(int num)
{
    int even;
    if(num==200)
    {
        return 200;
    }
    else
    {
        if(num%2==0)
        {
            even=num+sum_of_even(num+2);
        }
        else
        {
            num=num+1;
            even=num+sum_of_even(num+2);
        }
    }
    return even;
}