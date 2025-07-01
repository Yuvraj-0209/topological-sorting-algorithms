 vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>vis(V , 0);
        vector<int> adj[V];
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            
        }
        
        // now we have our adjaceny list ready for us
        // now we neeed to perform all of this indefinitely till all the elements are not placed
        while(st.size()!=V){
            int initialSize = st.size();
            
            for(int i =0;i<V;i++){
                if(vis[i]){
                    continue;
                }
                int check = true;
                for(int j=0;j<adj[i].size();j++){
                
                    if(!vis[adj[i][j]]){
                    // we mark that as falsec
                        check = false;
                    }
                }
                if(check==false){
                // meens ki koi na koi neighbour was not alreaday placed
                    continue;
                }
                else{

                // we need to place ye wali node adj[i]
                // jo bhi value aaegi we should store it in stack only
                    st.push(i);
                    vis[i]=1;
                
                
                }
            }
            if(initialSize == st.size()){
                // this means no progress was made and we likely have a cycle 
                break;
            }
            
        }
        
        // now we need to take out the ele,ents from the stack 
        // and push them to the ans walaa vector
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
