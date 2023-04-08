#include<bits/stdc++.h>
using namespace std;

//for y=a+bx
int main()
{
  
  int n ; 

  cout<<"Entered the no. of data pairs to be entered : " ; 
  cin>>n ;
  cout<<endl;
  double x[n] ,  y[n] , a, b;
  cout<<"Entered the X-axis values "<<endl; 
  for(int i = 0 ; i<n ; i++)
  {
     cin>>x[i] ;
  }
  cout<<"Entered the Y-axix values "<<endl; 
  for(int  i = 0 ; i<n  ; i++)
  {
   cin>>y[i] ;
  }
  double xsum = 0 , x2sum = 0 , ysum = 0 , xysum = 0 ;
  for(int i  =  0 ; i<n  ; i++)
  {
     xsum +=x[i] ;
     ysum +=y[i] ;
     x2sum +=(x[i]*x[i]) ; 
     xysum +=(x[i]*y[i]) ;
  }
  a = (x2sum*ysum-xsum*xysum)/(x2sum*n-xsum*xsum) ;//intersect
  b = (n*xysum-xsum*ysum) / (n*x2sum - xsum*xsum) ; //slop 

  cout<<"The linear fit line is of the form : " ;
  cout<<endl;
  cout<<endl;
  cout<<"y = "<<a<<" + "<<b<<"x"<<endl;

   
   return 0 ;
}
