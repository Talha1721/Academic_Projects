#include<bits/stdc++.h>
using namespace std;

struct hash
{
    int value;
    int key;
};
int main()
{
    int i,temp,size,x;
    cin>>size;
    struct hash arr[size];
    for(i=0 ; i<size ; i++)
    {
        cin >>temp;
        x=temp%size;
        arr[x].value=temp;
        arr[x].key=x;
    }
    for(i=0 ; i<size ; i++)
    {
        printf("%d    %d    \n",arr[i].value,arr[i].key);
    }


    return 0;
}
