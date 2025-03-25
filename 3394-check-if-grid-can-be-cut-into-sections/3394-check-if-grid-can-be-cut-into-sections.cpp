class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>vy;
        vector<pair<int,int>>vx;
        for(int i =0;i<r.size();i++){
            vx.push_back({r[i][0],r[i][2]});
            vy.push_back({r[i][1],r[i][3]});
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        
        int cnty=0,cntx=0;
        int maxi=vy[0].second;
        int prev_y= vy[0].first;
        for(int i=1;i<vy.size();i++){
            if(vy[i].first>=maxi && vy[i].second<=n){
                cnty++;
                maxi= vy[i].second;
                prev_y= vy[i].first;
                cout<<"i"<<i<<endl;
            }
            else if(vy[i].first>=prev_y && vy[i].second>=maxi && vy[i].second<=n){
                maxi= vy[i].second;
            }
            // else{
            //     break;
            // }

        }
        cout<<"cnty"<<cnty<<endl;
        maxi= vx[0].second;
        int prev_x= vx[0].first;
        for(int i=1;i<vx.size();i++){
            if(vx[i].first>=maxi && vx[i].second<=n){
                cntx++;
                maxi= vx[i].second;
                prev_x= vx[i].first;
                cout<<"i_x"<<i<<endl;
                
            }
            else if(vx[i].first>=prev_x && vx[i].second>=maxi && vx[i].second<=n){
                maxi= vx[i].second;
            }
            // else{
            //     break;
            // }

        }
        cout<<"cnty"<<cnty<<"cntx"<<cntx;
        if(cnty>=2 || cntx>=2)return true;
        else return false;
    }
};