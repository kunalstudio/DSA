#include<iostream>
using namespace std;

class S
{ int n;
  int arr[10];

public:
  S():n(0)
  {}

  void display()
  { 
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<",";
    }
  }

  void get()
  { 
    cout<<"Enter the size of list:";
    cin>>n;

    cout<<"Enter the numbers in array:"<<endl; 
    for(int i=0;i<n;i++)
     { cin>>arr[i];
     }
  }

  void selectionsort()
  { int min,t,j;

  for(int i=0;i<n;i++)
  { min = i ;
       for( j=(i+1);j<n;j++)
       { if(arr[j]<arr[min])
          min = j ;
       }
    t = arr[min];
    arr[min] = arr[i];
    arr[i] = t;
  }
  }
};

int main()
{ S selection;
selection.get();
selection.selectionsort();
selection.display();
}
