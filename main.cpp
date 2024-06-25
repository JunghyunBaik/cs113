//
//  main.cpp
//  Lab2_prof
//
//  Created by 백정현 on 2/14/23.
//

#include <iostream>
#include <vector>
using namespace std;

enum INPUT {
    IN1 = '1',
    IN2 = '2',
    IN3 = '3',
    IN4 = '4',
    IN5 = '5',
    IN6 = '6',
    IN7 = '7',
    IN8 = '8',
    IN9 = '9'
};
enum MULTIPLEX_4_1 {
    _A = 0b01000001,
    _B = 66,
    _c = 0x43,
    _D ='D'
};

struct Pair {
    bool x;
    bool y;
};//for two input and two output.

int menu();
bool doNot(bool);
bool doAnd(bool, bool);
bool doOr(bool, bool);
bool doNand(bool, bool);
bool doNor(bool, bool);
bool doHalfAdder(Pair& xy, bool, bool);   // two input, two ouput.
bool doFullAdder(Pair& xy, bool, bool, bool); //three input, two output.

int doMultiplexe4to1(bool, bool);  //4to1 meaning: 다이어그램에 보면, 

MULTIPLEX_4_1 doMultiplexer (Pair& xy);


struct VAR2 {      //2월 16일
    int p,
        q,
        p_or_q,
        p_and_q,    //output ccarry
        not_p_and_q,
        p_or_q__p_and_q; //output sum
};
void generateHalf(VAR2& _x);    //2/16

int main() {
    int input = -1;
    bool p=0, q=0, r=0;
    Pair pair;
    do {
        input = menu();
        switch (input) {
            case 1:
                doNot(p);
                //아웃풋으로 그림 1의 not 세모 옆에있는 표 나와야 함..
                break;
            case 2:
                doAnd(p, q);
                break;
            case 3:
                doOr(p, q);
                break;
            case 4:
                doNand(p, q);
                break;
            case 5:
                doNor(p, q);
                break;
            case 6:
                doHalfAdder(pair, p, q);
                break;
            case 7:
                doFullAdder(pair, p, q, r);
                break;
            case 8:
                int out = doMultiplexer(pair);
                break;
            case 9:
                break;
        }
    } while (input >= 1 && input <= 9); //입력값이 1보다 같거나 크고 9보다 같거나 클 때까지
    
    std::vector<std::string> words1{"the", "frogurt", "is", "also", "cursed"};  //2월 16일
    vector<VAR2> truth_table_half_adder{
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0}
    };
    for (int i = 0; i <= 4; i++){
        VAR2 var2;
        var2.p = 0;
        truth_table_half_adder;
    }
}



int menu() {
    //enum 사용해도 되고, int와 char를 모두 쓸 수 있는거,, string convert to num
    
    cout << "Basic Digital Logic Gates" << endl;
    cout << "=========================" << endl;
    cout << " 1 - NOT gate" << endl;
    cout << " 2 - AND gate" << endl;
    cout << " 3 - OR gate" << endl;
    cout << " 4 - NAND gate" << endl;
    cout << " 5 - NOR gate" << endl;
    cout << " 6 - Half-adder (see diagram)" << endl;
    cout << " 7 - Full-adder (see diagram)" << endl;
    cout << " 8 - Multiplexer 4 to 1 (2 switch variables as selectors for 4 inputs and 1 output; see diagram)" << endl;
    cout << " 9 - Exit" << endl;
    
    int input;
    cout << "\n Enter choice: ";
    cin >> input;
    
    return input;
}


bool doNot(bool){
    return true;
    
}
bool doAnd(bool, bool){
    return true;
    
}
bool doOr(bool, bool){
    return true;
    
}
bool doNand(bool, bool){
    return true;
}
bool doNor(bool, bool){
    return true;
}
bool doHalfAdder(Pair& xy, bool, bool){
    return true;
}  // two input, two ouput.

bool doFullAdder(Pair& xy, bool, bool, bool){
    return true;
} //three input, two output.

int doMultiplexe4to1(bool, bool){
    //return 1 for A, 2 for B, 3 for C, 4 for D
    
    return -1;
}  //4to1 meaning: 다이어그램에 보면,

MULTIPLEX_4_1 doMultiplexer(Pair& xy){
    //return 1 for A, 2 for B, 3 for C, 4 for D
    char Q = static_cast <char>(65);    //i.e (int) 65
    if (!xy.x && !xy.y) { //FF
        Q = 65;
    }
    else if (!xy.x && xy.y) {   //FT
        Q = 66;
    }
    else if (xy.x && !xy.y) {   //TF
        Q = 0b01000011; //원래 67이었음. FTFFFFTT
    }
    else if (xy.x && xy.y) { //TT
        Q =68;
    }
    
    return (MULTIPLEX_4_1) Q;
}
