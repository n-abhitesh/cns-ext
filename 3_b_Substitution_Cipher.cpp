#include<bits/stdc++.h>
using namespace std;

string substitutionEncrypt(string str){
    string all_letters= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    map<char, char> dict1;
    int key=4;
    for ( int i=0 ; i< all_letters.length(); i++){
        dict1[all_letters[i]]=all_letters[(i+key)%all_letters.length()];
    }
    
    string PlainText = str;
    string cipherText;
    
    for (size_t i=0; i<PlainText.size();i++){
        cipherText+=dict1[PlainText[i]];
    }
    
    return cipherText;
}

string substitutionDecrypt(string str){
    string all_letters= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    map<char, char> dict1;
    int key=4;
    for ( int i=0 ; i< all_letters.length(); i++){
        dict1[all_letters[i]]=all_letters[(i-key)%all_letters.length()];
    }
    
    string cipherText = str;
    string PlainText;
    
    for (size_t i=0; i<cipherText.size();i++){
        PlainText+=dict1[cipherText[i]];
    }
    
    return PlainText;
}


int main(){
    string input, output;
    input="abhitesh";
    output=substitutionEncrypt(input);
    cout<<"the input: "<<input<<endl;
    cout<<"the output: "<<output<<endl;
    output=substitutionDecrypt(output);
    cout<<"the ouput2: "<<output<<endl;
    return 0;
}
