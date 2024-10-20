#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    

    unordered_map<string,int>m;   //creation of map

    pair<string,int>p = make_pair("gaurav",22); // insert method 1
    m.insert(p);

    pair<string,int>p2("kumar",22);  // insertion method 2
    m.insert(p2);

    m["name"] = 12;

    //aceessing

    cout<<m["gaurav"]<<endl;
    m["gaurav"] = 25;
    cout<<m["gaurav"]<<endl;


    //search key
    cout<<m.count("gaurav")<<endl;

    if(m.find("gaurav") != m.end()){
        cout<<"gaurav found"<<endl;
    }
    else cout<<"not find"<<endl;


//iteration 
    for(auto i : m){
        cout<<i.first<<"--->"<<i.second<<endl;
    } 


    return 0;
}