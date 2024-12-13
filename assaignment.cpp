#include<bits/stdc++.h>
using namespace std;
 vector<string>arr[4];
    vector<string> keywords = {
        "int", "float", "double", "char", "bool", "void", "while", "for",
        "return", "if", "else", "switch", "case", "break", "continue", 
        "namespace", "using", "class", "private", "public", "protected", 
        "new", "delete", "try", "catch"
    };

    vector<char> arithmeticOperators = {'+', '-', '*', '/', '%'};

    vector<char> punctuators = {
        '{', '}', '[', ']', '(', ')', '<', '>', '.', ',', ';', ':', '?', '#',
        '&', '*', '+', '-', '/', '%', '=', '!', '|', '^', '~'
    };
int main()
{
    /* array of vector er 
    arr[0]->keywords
    arr[1]->identifier
    arr[2]->constant
    arr[3]->arithmetic operator
    arr[4]->puntuation
    
    */ 
  string s;
  getline(cin,s);
  stringstream ss(s);
  string word;
  while (ss>>word){
    auto Key =find(keywords.begin(),keywords.end(),word);
    if(Key!=keywords.end()){
        arr[0].push_back(word);
    }
    else{
    auto Op =find(arithmeticOperators.begin(),arithmeticOperators.end(),word);
    if(Op!=arithmeticOperators.end()){
        arr[3].push_back(word);
    }
    }
  
    
    // auto pn =find(punctuators.begin(),punctuators.end(),word);
    // if(pn!=punctuators.end()){
    //     arr[4].push_back(word);
    // }
   
  }
 
for(string c:arr[0]) {cout<<c<<" ";}
for(string c:arr[3]) {cout<<c<<" ";}





// auto it =find(keywords.begin(),keywords.end(),"for");
//  if(it!=keywords.end()){
//     cout<<"Paisi"<<endl;
//  }
//  else{
//     cout<<"Paini"<<endl;
//  }

    return 0;
}