#include<bits/stdc++.h>
using namespace std;


double funt (double x)
{
    double res = 3*x-cos(x)-1 ;
    return res ;
}
double dfunt(double x)
{
    double res = 3+sin(x) ;
    return res  ;
}


int main()
{
  double x[100] ;
  for(int i = 0 ; i<100 ;i++)

  {
        x[i] = 0 ;
  }
  double fa , fb  ;
  double error = 100 ;

   

   while(1)
   {
      cout<<"Enter Two real number's a and b "<<endl;
      cin>>x[0]>>x[1] ;
       fa = funt(x[0]); 
       fb = funt(x[1]) ;
      if(fa*fb<0)
      {
        cout<<"THE ROOT LIES BETWEEN THE INTERVAL"<<endl<<endl;
        break;
      }
      cout<<"THE ROOT DOESN'T LIES INTO THE INTERVAL PLEASE " ;
   }
   
  
 
 for( int i = 1; i<100 ; i++)
 {
        x[i+1] = x[i] - (((x[i])-(x[i-1]))/(funt(x[i])-funt(x[i-1])))*funt(x[i]) ;
        
                error=((x[i] - x[i-1])/x[i])*100;
                if(error<5)
                {       
                        cout<<setprecision(5)<<"ROOT "<<x[i+1]<<endl;
                        return 0 ;
                }
        
       
 }
    

    
    return 0 ;
}