void solve(int index,string mapping[],vector<string>&ans,string &output,string &str){
    if(index>=str.length()){
            ans.push_back(output);
            return;
    }
    string temp=mapping[str[index]-'0'];
    for(auto ch:temp){
        output.push_back(ch);
        solve(index+1,mapping,ans,output,str);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string mapping[]={"","","abc","def","ghi","jkl",
        "mno","pqrs","tuv","wxyz"};
        int index=0;
        vector<string>ans;
        string output="";
        solve(index,mapping,ans,output,digits);
        return ans;
    }
