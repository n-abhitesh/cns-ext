#include<bits/stdc++.h>

using namespace std;

string XORwithzero(string inputStr){
    string result;
    
    for (size_t i=0; i< inputStr.size(); i++){
        result += inputStr[i] ^ 0;
        
    }
    
    return result;
}

int main(){
    string inputString = "Hello World";
    string result, result2;
    result = XORwithzero(inputString);
    
    cout<<"The Input String is: "<<inputString<<endl;
    cout<<"The Ouput String is: "<<result<<endl;
    
    
    return 0;
}
