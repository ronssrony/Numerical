#include<bits/stdc++.h>
using namespace std;

const int n = 100;
double augment[n][n+1], value[n];

void convertuppertriangle(double augment[][n+1], int n)
{ 
   for(int i = 0 ; i<n ; i++)
   {
      for(int j = 0 ; j<n ; j++)
      if(j>i)
      {
         double ratio = augment[j][i]/augment[i][i] ; 
         for(int k =  0 ; k<n+1 ; k++)
         {
            augment[j][k] = augment[j][k] - (ratio*augment[i][k]) ;
         }
      }
   }
}

void applybacksub(double augment[][n+1], double value[], int n)
{
    double sum ;
    value[n-1] = augment[n-1][n]/augment[n-1][n-1] ; 

    for(int i = n-2  ;i>=0 ;--i)
    {
         sum = 0 ; 
         for(int  j = i+1 ; j<n ; j++)
         {
            sum += augment[i][j]*value[j]; 
         }
         value[i] = (augment[i][n]-sum)/augment[i][i] ;
    }
}

int main()
{
   double sum , ratio ;
   int n ; 
   cout<<"Enter number of unknowns : " ; 
   cin>> n ;
   cout<<endl; 

   for(int i  = 0 ; i<n ; i++)
   {
      for(int j =  0 ;j<n+1 ; j++)
      {
         cin>>augment[i][j] ; 
      }
   }

   convertuppertriangle(augment,n) ;
   applybacksub(augment,value,n) ;

   for(int i = 0; i < n; i++)
   {
       cout << "x" << i+1 << " = " << value[i] << endl;
   }

   return 0 ;
}
