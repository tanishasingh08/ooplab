#include<iostream>
using namespace std;
int main()
{
    int ch,i;
    char a[50];
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            for(i=0;i<50;i++)
            {
                cin>>a[i];
            }
        }
        break;
    case 2:
        {
            for(i=0;i<49;i++)
            {
                cout<<endl<<a[i]<<"\n";
            }
        }
        break;
   /* case 3:
        {
            for()
        }
    }*/
}
