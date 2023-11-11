#include "iostream"

int bin_bcd(int x){
    uint16_t i = uint16_t(x);
    int out;
    
    while(i != 0){

        if(int(out & 0xF) >= 5){
            out += 0x3;
        }

        if(int(out & 0xF0) >= 0x50){
            out += 0x30;
        }

        if(int(out & 0xF00) >= 0x500){
            out += 0x300;
        }

        if(int(out & 0xF000) >= 0x5000){
            out += 0x3000;
        }
        

        out = out << 1;

        int test = i & 0x8000 ;

        out += (int(i & 0x8000) != 0)? 1: 0;
        i = i << 1;
    }

    return out;
}

// int main(){
//     int test = bin_bcd(79);

//     while(test != 0){
//         std::cout << int(test & 0x8000);
//         test = test >> 1;
//     }

//     std::cout << std::endl;

//     // std::cout << (uint16_t(32768) & 0x8000) << std::endl;
// }