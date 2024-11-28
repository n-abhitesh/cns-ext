#include<bits/stdc++.h>

using namespace std;

string XORwith127(string inputStr){
    string result;
    
    for (size_t i=0; i< inputStr.size(); i++){
        result += inputStr[i] ^ 127;
        
    }
    
    return result;
}

string ANDwith127(string inputStr){
    string result;
    
    for (size_t i=0; i< inputStr.size(); i++){
        result += inputStr[i] & 127;
        
    }
    
    return result;
}



int main(){
    string inputString = "Hello World";
    string result, result2;
    result = XORwith127(inputString);
    result2= ANDwith127(inputString);
    
    cout<<"The Input String is: "<<inputString<<endl;
    cout<<"The Ouput String after XOR is: "<<result<<endl;
    cout<<"The Ouput String after AND: "<<result2<<endl;
    
    
    return 0;
}
