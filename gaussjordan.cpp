#include<bits/stdc++.h>
using namespace std;

const int n = 100;
double augment[n][n+1], value[n];

void convertuppertriangle(double augment[][n+1], int n)
{ 
   for(int i = 0 ; i<n ; i++)
   {
      for(int j = 0 ; j<n ; j++)
      if(i!=j)
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
    for(int i = 2 ; i>=0 ; i--)
    {
        value [i] = augment[i][n]/augment[i][i] ;
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
