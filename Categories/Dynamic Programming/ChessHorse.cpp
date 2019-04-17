#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define tr1(cont) for(auto it=cont.begin();it!=cont.end();it++)
#define tr2(cont,it) for(;it!=cont.end();it++)
#define rep(n) for(int i=0;i<n;i++)

int wdth,hgt;

struct pos{
  int y,x;
};

bool val(int x,int y){
  return( (x>=0 && x<wdth) & (y>=0 && y<hgt) );
}

int main(){
  wdth=10,hgt=10;

  // pos init={wdth/2,hgt/2};
  pos init={0,0};

  // sz=n;

  std::vector<std::vector<int> > brd(hgt,std::vector<int>(wdth,0));
  std::vector<pos> curr;

  int mx=1;

  curr.push_back(init);
  int move=1;
  while(!curr.empty()){
    int mv=curr.size();
    for(int i=0;i<mv;i++){

      int x=curr[0].x; int y=curr[0].y;
      curr.erase(curr.begin());
      if(val(x-1,y-2)){if(brd[y-2][x-1]==0){ curr.push_back({y-2,x-1}); brd[y-2][x-1]=move; } }
      if(val(x+1,y-2)){if(brd[y-2][x+1]==0){ curr.push_back({y-2,x+1}); brd[y-2][x+1]=move; } }
      if(val(x-2,y-1)){if(brd[y-1][x-2]==0){ curr.push_back({y-1,x-2}); brd[y-1][x-2]=move; } }
      if(val(x-2,y+1)){if(brd[y+1][x-2]==0){ curr.push_back({y+1,x-2}); brd[y+1][x-2]=move; } }
      if(val(x+2,y-1)){if(brd[y-1][x+2]==0){ curr.push_back({y-1,x+2}); brd[y-1][x+2]=move; } }
      if(val(x+2,y+1)){if(brd[y+1][x+2]==0){ curr.push_back({y+1,x+2}); brd[y+1][x+2]=move; } }
      if(val(x-1,y+2)){if(brd[y+2][x-1]==0){ curr.push_back({y+2,x-1}); brd[y+2][x-1]=move; } }
      if(val(x+1,y+2)){if(brd[y+2][x+1]==0){ curr.push_back({y+2,x+1}); brd[y+2][x+1]=move; } }

      // tr1(curr)cout<<"("<<it->y<<","<<it->x<<") ";
      // cout<<" -- "<<move<<endl;

    }

    if(curr.size()>mx)mx=curr.size();
    // cout<<move<<": ";
    // tr1(curr)cout<<"("<<it->x<<","<<it->y<<") ";
    // cout<<endl;

    move++;
  }

  cout<<endl<<" ";
  tr1(brd){
    rep((*it).size()){
      cout<<(*it)[i];
      if((*it)[i]<10)cout<<"  ";
      else cout<<" ";
    }
    cout<<endl<<" ";
  }

  // mx stores maximum number of possible moves at any given step
  cout<<"max_curr: "<<mx;

}
