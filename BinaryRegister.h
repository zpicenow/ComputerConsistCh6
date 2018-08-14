//
// Created by zhaopeng on 2017/11/18
//

#ifndef ADDSUB_BINARYREGISTER_H
#define ADDSUB_BINARYREGISTER_H
#include <cstring>
#include <cmath>

const static char BINARY_ONE = '1';
const static char BINARY_ZERO = '0';
const static int BINARY_TYPE_ORIGINAL_CODE = 1;       //原码
const static int BINARY_TYPE_COMPLEMENT_CODE = 2;     //补码
const static int BINARY_TYPE_ANTI_CODE = 3;           //反码

const static int OPERATOR_ADDITION = 4;                 //加法操作
const static int OPERATOR_SUBTRACTION = 5;              //减法操作
const static int OPERATOR_MULTIPLY = 6;                 //乘法操作
const static int OPERATOR_DIVIDE = 7;                   //除法操作

const static int FIXED_POINT_INTEGER = 8;               //定点整数类型
const static int FIXED_POINT_DECIMAL = 9;               //定点小数类型


class BinaryRegister {
private:
    int count;          //二进制寄存器的位数
    char *str;
    int type;           //类型（原码->1、补码->2、反码->3）
    int symbolBitCount; //符号位个数
    int value_type;     //数据类型，是定点整数，还是定点小数
public:
    BinaryRegister(int count) : count(count) {
        this->str = new char[count + 1];
        for(int i = 0; i < count; i++){
            this->str[i] = '0';
        }
        this->str[count] = '\0';
        type = BINARY_TYPE_ORIGINAL_CODE;       //默认类型为原码
        value_type = FIXED_POINT_INTEGER;       //默认为定点整数
        symbolBitCount = 1;
    }

    BinaryRegister(const char *str) {
        count = strlen(str);
        this->str = new char[count + 1]{'0'};
        strcpy(this->str, str);
        type = BINARY_TYPE_ORIGINAL_CODE;       //默认类型为原码
        value_type = FIXED_POINT_INTEGER;       //默认为定点整数
        symbolBitCount = 1;
    }

    //复制构造
    BinaryRegister(const BinaryRegister &b) {
        this->count = b.getCount();
        this->symbolBitCount = b.getSymbolBitCount();
        this->type = b.getType();
        this->str = new char[count + 1];
        this->value_type = b.getValue_type();
        strcpy(this->str, b.getStr());
    }

    void resize(int size);                      //拓宽寄存器的位数（原来的n位数据在高n位, 如果新的大小更短的话，元数据低位截断）

    //逻辑右移num位，高位补0，低位移丢
    void moveRight_logic(int num);

    //逻辑左移num位， 低位补0， 高位移丢
    void moveLeft_logic(int num);

    //逻辑右移num位，高位补supplement（在两个寄存器整体逻辑右移的时候用得到）
    void moveRightWithSpecificValue(int num, char supplement);
    void moveLeftWithSpecificValue(int num, char supplement);

    //this和anotherRegister，进行整体逻辑右移
    void moveRight_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement);
    void moveLeft_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement);

    void reset();                   //寄存器置零

    int getValue_type() const;          //获取二进制串的码制

    void setValue_type(int value_type); //设置二进制串的码制

    static char getCarry(char c1, char c2, char carry);         //二进制一位加法获取进位

    static char getCurrentBit(char c1, char c2, char carry);    //二进制一位加法获取当前值

    static void revise(char *str, int start_pos, int end_pos);  //将str中的01串反置，即0置1，1置0

    static bool add(BinaryRegister &b, int num = 1);            //在原值有基础上真值加num

    static bool yCTOnYC(BinaryRegister &original, BinaryRegister &target);              //获取[-y]补

    static bool copy(BinaryRegister &original, BinaryRegister &target);                 //寄存器的值复制（要求位数一致）

    static bool add(BinaryRegister &b1, BinaryRegister &b2, BinaryRegister &result);    //二进制串进行加法操作

    static double getRealValue(BinaryRegister &b);     //根据二进制串获取真值

    //补码加减运算
    static bool ComplementCodeAdd_Sub(BinaryRegister A, BinaryRegister X, BinaryRegister &result, int flag);
    //原码一位乘
    static bool OriginalCode_OneBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //原码两位乘
    static bool OrignalCode_TwoBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //补码一位乘
    static bool ComplementCode_OneBit_Multiply_Booth(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //除法（原码加减交替法）
    static bool OrignalCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //除法（补码加减交替法）
    static bool ComplementCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);

    //码制转化操作
    void toComplement();        //转为补码
    void toOriginalCode();      //转为原码
    int getSymbolBitCount() const;

    int getCount() const;              //获取寄存器位数
    void setSymbolBitCount(int symbolBitCount);

    char *getStr() const {
        return str;
    }

    int getType() const {
        return type;
    }

    void setType(int type) {
        BinaryRegister::type = type;
    }

    ~BinaryRegister() {
        if (str != NULL) {
            delete[] str;
        }
    }
};


#endif //ADDSUB_BINARYREGISTER_H
