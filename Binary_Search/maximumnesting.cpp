int maxDepth(string s) {
 int count=0;

    int maxi=0;

    

    for(int i=0;i<s.length();i++){

         

          if(s.at(i)=='(')

            count++;

          else if(s.at(i)==')')

          count--; 

          maxi=max(maxi,count);   

          

    }

    return maxi;

    
}
