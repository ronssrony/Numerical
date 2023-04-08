#include<bits/stdc++.h>
using namespace std;
#define epsilon .001 
const int n = 100;
double augment[n][n+1], value[n];

void printvalue(int iteration ,double  value_new[])
{
   cout<<"iteration"<<iteration<<" " ;
   for(int  i = 0  ; i<3 ; i++) 
   {
      cout<<"x"<<i+1<<" = "<<value_new[i]<<" ";
   }
   cout<<endl;
}
double findsum(int i , double augment[][n+1])
{
      double sum = 0 ;
      for(int j  = 0 ; j<n  ;j++)
      {
          if(i!=j)
          {
            sum+=augment[i][j] ;
          }
      }
      return sum ;
}

bool validornot(double augment[][n+1] , int n)
 {
      for(int i  = 0 ; i<n  ;i++)
      {
         for(int j  = 0 ; j<n  ;j++)
         {
            if(fabs(augment[i][i])>findsum(i,augment))
            break; 

            else 
            return false ;
         }
      }
      return true ;
 }
 void findvalues(double augment[][n+1], int m, double value_old[], int n) 
{        
  int iteration;
  int flag = 0;
  double sum = 0;
  double value_new[n];
  for (int i = 0; i < n; i++) 
  {
    value_new[i] = 0;
  }

  for (iteration = 1; iteration <= m; iteration++) 
  {
    bool found_error = false;

    for (int i = 0; i < n; i++) 
    {
      sum = 0;
      for (int j = 0; j < n; j++) 
      {
        if (i != j) 
        {
          sum += augment[i][j] * value_old[j];
        }
      }
      value_new[i] = (augment[i][n] - sum) / augment[i][i];
    }

    for (int k = 0; k < n; k++) 
    {
      if (fabs(value_old[k] - value_new[k]) < epsilon) 
      {
        continue;
      }
      else 
      {
        found_error = true;
        break;
      }
    }

    if (!found_error) 
    {
      printvalue(iteration, value_new);
      return;
    }

    printvalue(iteration, value_new);

    for (int i = 0; i < n; i++) 
    {
      value_old[i] = value_new[i];
    }
  }

  printvalue(iteration, value_new);
}


int main()
{
  
   int n , m; 
   cout<<"Enter number of unknowns : " ; 
   cin>> n ;
   cout<<endl; 
   cout<<"Enter maximum iteration no: " ;
   cin>>m  ;
   cout<<endl;
   
   for(int i  = 0 ; i<n ; i++)
   {
      for(int j =  0 ;j<n+1 ; j++)
      {
         cin>>augment[i][j] ; 
      }
   }

   if(validornot(augment , n))
   {
      cout<<"Gauss jacobi method cannot be applied " ;
      return 0 ;
   }
   cout<<"Gauss jacobi method is applicable "<<endl;
   for(int i  = 0 ; i<n ; i++)
   {
      value[i] = 0 ;
   }
   findvalues(augment,m,value , n) ;

  

   return 0 ;
}
