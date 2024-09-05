#include<iostream>
#include<vector>
using namespace std;
int ternary(vector<int> &v,int key,int n)
  {
     int s=0;
     int e=n-1;
     int m1=s+(e-s)/3;
     int m2=e-(e-s)/3;
     
     while(s<=e)
       {
         if(v[m1]==key)
         {
            return m1;
         }
         if(v[m2]==key)
          {
            return m2;
          }
         if(v[m1]>key)
          {
            e=m1-1;
          }
         if(v[m2]<key)
          {
            s=m2+1;
          }
         if(v[m1]<key && v[m2]>key)
          {
            s=m1+1;
            e=m2-1;
          }
       m1=s+(e-s)/3;
       m2=e-(e-s)/3;
         
       }
       
       return -1;
  
 }
  
int main()
 {
   int n,ele,key;
   cout<<"Enter the size of vector :";
   cin>>n;
   
   vector<int> v(n);
  
   cout<<"enter the element of vector :"<<endl;
   for(int i=0;i<n;i++)
   
    {
      cin>>v[i];
    }
    
    cout<<"enter the key : ";
    cin>>key;
    
    int ans=ternary(v,key,n);
    
    if(ans!= -1)
     {
       cout<<"element found at index : "<<ans<<endl;
     }
    else
     {
       cout<<"element not found"<<endl;
      }
    
  /*
   for(auto i : v)
     {
     
      cout<<i<<" ";
      }
      */
 }
