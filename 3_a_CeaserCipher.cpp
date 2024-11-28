#include<bits/stdc++.h>

using namespace std;

string encryptCeaser(string str, int shift){
    
    string inputText;
    inputText=str;
    for (size_t i=0; i < inputText.size(); i++){
        inputText[i]=inputText[i]+shift;
    }
    
    return inputText;
}

string decryptCeaser(string str, int shift){
    string inputText;
    inputText=str;
    for (size_t i=0; i < inputText.size(); i++){
        inputText[i]=inputText[i]-shift;
    }
    
    return inputText;
}


int main()
{
    string str, strOutput;
    str = "Abhitesh Nandipati";
    int i=3;
    strOutput=encryptCeaser(str, i);
    cout<<strOutput<<endl;
    strOutput=decryptCeaser(strOutput, i);
    cout<<strOutput<<endl;
    
    
    
    
}
