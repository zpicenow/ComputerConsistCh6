//
// Created by zhaopeng on 2017/11/18
//

#ifndef ADDSUB_BINARYREGISTER_H
#define ADDSUB_BINARYREGISTER_H
#include <cstring>
#include <cmath>

const static char BINARY_ONE = '1';
const static char BINARY_ZERO = '0';
const static int BINARY_TYPE_ORIGINAL_CODE = 1;       //ԭ��
const static int BINARY_TYPE_COMPLEMENT_CODE = 2;     //����
const static int BINARY_TYPE_ANTI_CODE = 3;           //����

const static int OPERATOR_ADDITION = 4;                 //�ӷ�����
const static int OPERATOR_SUBTRACTION = 5;              //��������
const static int OPERATOR_MULTIPLY = 6;                 //�˷�����
const static int OPERATOR_DIVIDE = 7;                   //��������

const static int FIXED_POINT_INTEGER = 8;               //������������
const static int FIXED_POINT_DECIMAL = 9;               //����С������


class BinaryRegister {
private:
    int count;          //�����ƼĴ�����λ��
    char *str;
    int type;           //���ͣ�ԭ��->1������->2������->3��
    int symbolBitCount; //����λ����
    int value_type;     //�������ͣ��Ƕ������������Ƕ���С��
public:
    BinaryRegister(int count) : count(count) {
        this->str = new char[count + 1];
        for(int i = 0; i < count; i++){
            this->str[i] = '0';
        }
        this->str[count] = '\0';
        type = BINARY_TYPE_ORIGINAL_CODE;       //Ĭ������Ϊԭ��
        value_type = FIXED_POINT_INTEGER;       //Ĭ��Ϊ��������
        symbolBitCount = 1;
    }

    BinaryRegister(const char *str) {
        count = strlen(str);
        this->str = new char[count + 1]{'0'};
        strcpy(this->str, str);
        type = BINARY_TYPE_ORIGINAL_CODE;       //Ĭ������Ϊԭ��
        value_type = FIXED_POINT_INTEGER;       //Ĭ��Ϊ��������
        symbolBitCount = 1;
    }

    //���ƹ���
    BinaryRegister(const BinaryRegister &b) {
        this->count = b.getCount();
        this->symbolBitCount = b.getSymbolBitCount();
        this->type = b.getType();
        this->str = new char[count + 1];
        this->value_type = b.getValue_type();
        strcpy(this->str, b.getStr());
    }

    void resize(int size);                      //�ؿ�Ĵ�����λ����ԭ����nλ�����ڸ�nλ, ����µĴ�С���̵Ļ���Ԫ���ݵ�λ�ضϣ�

    //�߼�����numλ����λ��0����λ�ƶ�
    void moveRight_logic(int num);

    //�߼�����numλ�� ��λ��0�� ��λ�ƶ�
    void moveLeft_logic(int num);

    //�߼�����numλ����λ��supplement���������Ĵ��������߼����Ƶ�ʱ���õõ���
    void moveRightWithSpecificValue(int num, char supplement);
    void moveLeftWithSpecificValue(int num, char supplement);

    //this��anotherRegister�����������߼�����
    void moveRight_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement);
    void moveLeft_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement);

    void reset();                   //�Ĵ�������

    int getValue_type() const;          //��ȡ�����ƴ�������

    void setValue_type(int value_type); //���ö����ƴ�������

    static char getCarry(char c1, char c2, char carry);         //������һλ�ӷ���ȡ��λ

    static char getCurrentBit(char c1, char c2, char carry);    //������һλ�ӷ���ȡ��ǰֵ

    static void revise(char *str, int start_pos, int end_pos);  //��str�е�01�����ã���0��1��1��0

    static bool add(BinaryRegister &b, int num = 1);            //��ԭֵ�л�������ֵ��num

    static bool yCTOnYC(BinaryRegister &original, BinaryRegister &target);              //��ȡ[-y]��

    static bool copy(BinaryRegister &original, BinaryRegister &target);                 //�Ĵ�����ֵ���ƣ�Ҫ��λ��һ�£�

    static bool add(BinaryRegister &b1, BinaryRegister &b2, BinaryRegister &result);    //�����ƴ����мӷ�����

    static double getRealValue(BinaryRegister &b);     //���ݶ����ƴ���ȡ��ֵ

    //����Ӽ�����
    static bool ComplementCodeAdd_Sub(BinaryRegister A, BinaryRegister X, BinaryRegister &result, int flag);
    //ԭ��һλ��
    static bool OriginalCode_OneBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //ԭ����λ��
    static bool OrignalCode_TwoBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //����һλ��
    static bool ComplementCode_OneBit_Multiply_Booth(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //������ԭ��Ӽ����淨��
    static bool OrignalCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);
    //����������Ӽ����淨��
    static bool ComplementCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result);

    //����ת������
    void toComplement();        //תΪ����
    void toOriginalCode();      //תΪԭ��
    int getSymbolBitCount() const;

    int getCount() const;              //��ȡ�Ĵ���λ��
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
