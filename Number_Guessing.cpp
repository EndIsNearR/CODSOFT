#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    int ran=0 , in = 0;
    srand(time(0));
    ran = rand() % 1000;
    
    
    cout<<"Enter your number"<<endl;
    
    while(true)
    {
        
        cin>>in;
        
        if(in==ran)
        {
            cout<<"You have guessed it!!!!"<<endl;
            break;
        }
        else if(ran>in)
        {
            cout<<"Number is too low"<<endl;
            
        }
        else if(ran<in)
        {
            cout<<"Number is too high"<<endl;
            
        }
    }
    
    
    
    
    
    
}
