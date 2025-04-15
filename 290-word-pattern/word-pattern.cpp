class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> x;
        string y;
        for(char i:s){
            if(i!=' ') y.push_back(i);
            else{
                x.push_back(y);
                y.clear();}}
        x.push_back(y);      
        int j=0; 
        bool ans=true;
        if(pattern.size()!=x.size()) return false;
        map<char,string> a;
        for(char i:pattern){
            if(a[i].size()==0) a[i]=x[j];
            else{
                if(a[i]!=x[j]){
                    ans=false;
                    break;}}
            j++;}
        map<string,int> w;
        for(auto i:a) w[i.second]++;
        for(auto i:w) {
            if(i.second>1){
                ans=false;
                break;}}
        return ans;
    }
};