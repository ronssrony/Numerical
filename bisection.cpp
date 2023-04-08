#include<bits/stdc++.h>
using namespace std;
#define epsilon .0001 


double funt (double x)
{
    double res = 3*x-cos(x)-1 ;
    return res ;
}


int main()
{
   double a , b , c ;
   double  fa , fb ,fc ;
  
  

   

   while(1)
   {
      cout<<"Enter Two real number's a and b "<<endl;
      cin>>a>>b ;
       fa = funt(a); 
       fb = funt(b) ;
      if(fa*fb<0)
      {
        cout<<"THE ROOT LIES BETWEEN THE INTERVAL"<<endl<<endl;
        break;
      }
      cout<<"THE ROOT DOESN'T LIES INTO THE INTERVAL PLEASE " ;
   }
   int iter = 1 ;
   cout<<"[iteration]"<<"  "<<"a"<<"  "<<"b"<<"  "<<"fa"<<"  "<<"fb"<<"  "<<"c"<<"  "<<"fc"<<"  "<<"error"<<endl<<endl;
    while(fabs(a-b)>epsilon)
    {
        c = (a+b)/2 ;
        fc = funt(c) ;
        if(fc<0)
        {
            a = c ;
        }
        else 
        {
            b = c ;
        }
      
        cout<<iter<<"  "<<a<<"  "<<b<<"  "<<fa<<"  "<<fb<<"  "<<c<<"  "<<fc<<"  "<<error<<endl;
        iter++;
    }
    cout<<endl;
    cout<<"The root is "<<setprecision(4)<<c<<endl;

    
    return 0 ;
}
