#include<bits/stdc++.h>
using namespace std;

struct edge{
    int a,b;
};
int main(){
    int n,m,k,e,x;
    scanf("%d %d",&n,&m);
    vector<edge> g(m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&g[i].a,&g[i].b);
    }
    cin>>k;
    while(k--){
        cin>>e;
        set<int> s;
        for(int j=0;j<e;j++){
            scanf("%d",&x);
            s.insert(x);
        }
        bool f=true;
        for(int i=0;i<m;i++){
            if(s.count(g[i].a) == 0 && s.count(g[i].b) == 0){
                cout<<"No"<<endl;
                f=false;
                break;
            }
        }
        if(f) cout<<"Yes"<<endl;
    }
}