#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void fun(vector< vector <int> > *v1,vector< vector <int> > *v2,int n,int h,int x,int y,int x1,int y1)
{
     if(x == x1 && y == y1)
     return;
      if(x != 0 && abs((*v1)[x-1][y] - (*v1)[x][y])<= h && ((*v2)[x-1][y] > ((*v2)[x][y] + 1)))
      {
       (*v2)[x-1][y] = 1 + (*v2)[x][y];
       fun(v1,v2,n,h,x-1,y,x1,y1);
       }
      if(x != n-1 && abs((*v1)[x+1][y]-(*v1)[x][y])<= h && ((*v2)[x+1][y] > ((*v2)[x][y] + 1)))
      {
       (*v2)[x+1][y] = 1 + (*v2)[x][y];
       fun(v1,v2,n,h,x+1,y,x1,y1);
       }
       if(y != 0 && abs((*v1)[x][y-1]-(*v1)[x][y])<= h && ((*v2)[x][y-1] > ((*v2)[x][y] + 1)))
      {
       (*v2)[x][y-1] = 1 + (*v2)[x][y-1];
       fun(v1,v2,n,h,x,y-1,x1,y1);
       }
       if(y != n-1 && abs((*v1)[x][y+1]-(*v1)[x][y])<= h && ((*v2)[x][y+1] > ((*v2)[x][y] + 1)))
       {
       (*v2)[x][y+1] = 1 + (*v2)[x][y];
       fun(v1,v2,n,h,x,y+1,x1,y1);
       }
}
int main()
{
    vector<int> v1,v2;
    vector< vector <int> > vov1,vov2;
    int t,n,h,x,y,x1,y1;
    cin>>t;
    int x11;
    for(int i=0;i<t;i++)
    {
            cin>>n>>h>>x>>y>>x1>>y1;
            for(int k=0;k<n;k++)
            {
            for(int j=0;j<n;j++)
            {
                            cin>>x11;
                            v1.push_back(x11);
                            v2.push_back(10001);
            }
            vov1.push_back(v1);
            vov2.push_back(v2);
            v1.clear();
            v2.clear();
            }
            vov2[x][y] = 0;
            fun(&vov1,&vov2,n,h,x,y,x1,y1);
            if(vov2[x1][y1] != 10001)
            cout<<vov2[x1][y1]<<endl;
            else
            cout<<"-1\n";
    }
    return 0;
}
                   
                    
            
    
    
    
