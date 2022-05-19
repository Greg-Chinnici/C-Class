
#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma(unsigned long n){
    
    unsigned long sum = 0;
    
    try{
         for(int i ; i <= n ; i++){
            sum += i;
        }
        
        if(!(n >= 1)){
            sum = 0;
            std::string strMessage = "PreCondition of n >= 1 not satisfied. invalid argument for n: " + std::to_string(n) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
            throw std::runtime_error(strMessage);
        }
        
        if (!(sum == ( n * ( n + 1 ) ) / 2 ) ){
            
            std::string strMessage = "PostCondition of (n(n+1)/2 not satisfied. sum: " + std::to_string(sum) + "is not equal to " + std::to_string(( n * ( n + 1 ) ) / 2 ) + "(Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")" ;
            sum = 0;
            throw std::runtime_error(strMessage);
        }
        
        return sum;
    }catch (std::runtime_error & err){
        
        std::cout << "Exception: " << err.what() << std::endl;
        std::cout << "cant make sum, returning 0" << std::endl;
       
        sum = 0;
    }
        return (int)sum;
        
}

int main(){
    
    int total = sigma(5);
    std::cout << "sigma 5: " << total << std::endl;
    
    total = sigma(0);
    std::cout << "sigma 0: " << total << std::endl;
    
    return 0;
}
        
        
        
        
        
