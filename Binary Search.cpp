//Program for BINARY SEARCH

#include <iostream>
using namespace std;

int main() {
int n, i, j, first=0, last, mid,temp,search;

cout<<"enter the size of list: ";
cin>>n;

int arr[n];
last = n-1;


//inserting elements
cout<<"enter "<<n<<" elements of the list"<<endl;
for(i=0; i<n; i++)  
{
   cin>>arr[i];
}


//sorting
for(i=0; i<n; i++)
{
    for(j=i+1; j < n; j++)
    {
        if(arr[i] > arr[j]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}


cout<<endl<<"enter the element you want to search: ";
cin>>search;

i=0;


//searching
while(first <= last)
{
    mid = (first + last)/2;
    
    if(arr[mid] == search)
    {
        cout<<endl<<arr[mid]<<" is available in the list ";
exit(1);        
    }
    
    else if(arr[mid] < search)
    {
        first = mid+1;
    }

    else if(arr[mid] > search)
    {
        last = mid-1;
    } 

}
    cout<<"element is not available in the list";


    return 0;
}
