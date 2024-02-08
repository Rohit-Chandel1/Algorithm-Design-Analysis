#include <iostream>
using namespace std;

int main() {

int r1,c1, r2,c2, i , j , k;

cout<<"enter the size of A matrix row: ";
cin>>r1;
cout<<"enter the size of A martix columns: ";
cin>>c1;

cout<<"enter the size of B matrix row: ";
cin>>r2;
cout<<"enter the size of B martixcolumns: ";
cin>>c2;

int a[r1][c1], b[r2][c2], m[r1][c2];

//entering values for a matrix
cout<<"enter the values of a matrix";

for(i=0; i<r1; i++)
{
    for(j=0; j<c1; j++)
    {
        cin>>a[i][j];
    }
}

//displaying matrix
for(i=0; i<r1; i++)
{
    for(j=0; j<c1; j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
}




//entering values for b matrix
cout<<"enter the values of b matrix";

for(i=0; i<r2; i++)
{
    for(j=0; j<c2; j++)
    {
        cin>>b[i][j];
    }
}

//displying b matrix
for(i=0; i<r2; i++)
{
    for(j=0; j<c2; j++)
    {
        cout<<b[i][j]<<" ";
    }
    cout<<"\n";
}

//done

// square matrix multiplicaion

if(r1=c1){
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
    {
        m[i][j] = 0;
        for(k=0; k<c2; k++)
        {
            m[i][j] = m[i][j] + (a[i][k] * b[k][j]); 
        }
    }
}
}

//if the matrix is not square
if(r1!=c1){
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
    {
        m[i][j] = 0;
        for(k=0; k<=c2; k++)
        {
            m[i][j] = m[i][j] + (a[i][k] * b[k][j]); 
        }
    }
}
}
//dislay
for(i=0; i<r1; i++)
{
    for(j=0; j<c2; j++)
    {
        cout<<m[i][j]<<" ";
    }
    cout<<"\n";
}
    return 0;
}
