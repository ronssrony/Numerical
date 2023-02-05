#include<bits/stdc++.h>
using namespace std;


double funt (double x)
{
    double res = 3*x-cos(x)-1 ;
    return res ;
}
double gfunt(double x)
{
    double res = (1+cos(x))/3 ;
    return res  ;
}


int main()
{
   double a , b , c=0 ;
   double  fa , fb ,fc ;
   double error=100 ;
  

   

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
   c = (a+b)/2 ;
   double x1 = gfunt(c) ;
   double xn ;
   
    while(error>5)
    {   
         
        xn = gfunt(x1) ;
        error = fabs((xn-x1)/xn)*100;
        x1 = xn ;
        cout<<"iterative "<<iter<<" Root "<<xn<<" error "<<error<<endl;
        iter++;
       
    }
    cout<<endl;
    cout<<"The root is "<<setprecision(4)<<xn<<endl;

    
    return 0 ;
}