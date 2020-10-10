#include<bits/stdc++.h>
using namespace std;
vector<string> calculate(vector<string>& data){
    int n=data.size();
    vector<string> ans;
    float total=0,total_tax=0;
    for(int i=0;i<n;i++)
    {
        stringstream s(data[i]);
        string word,res="";
        bool import=false;
        float value=0,tax=0;
        int f=0,amount=0;
        while(s>>word)
        {
            if(f==0)
            {
                stringstream amt(word);
                amt>>amount;
                f=1;
            }
            if(word=="imported") import=true;
            if(word!="at") res+=word+" ";
            else
            {
                res+=": ";
                s>>word;
                stringstream val(word);
                val>>value;
                if(import) 
                {
                    tax=value*0.05*amount;
                }
                value*=amount;
                value+=tax;
                total+=value;
                total_tax+=tax;
                res+=to_string(value);
            }
        }
        ans.push_back(res);
    }
    ans.push_back("Sales Tax: "+to_string(total_tax));
    ans.push_back("Total: "+to_string(total));
    return ans;
}
int main(){
    vector<string>v,v2;
    string s;
    int number;
    cin>>number;
    for(int i=0;i<number;i++){
        getline(cin, s);
        v.push_back(s);
    }
    v2 = calculate(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }
   return 0; 
}
