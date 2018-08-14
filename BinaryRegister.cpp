//
// Created by zhaopeng on 2017/11/18 
//
#include "BinaryRegister.h"
using namespace std;
/**
 * �Ĵ�������numλ(Ĭ�ϸ�λ��0)
 * @param num
 */
void BinaryRegister::moveRight_logic(int num) {
    moveRightWithSpecificValue(num, BINARY_ZERO);
}
/**
 * �Ĵ�������numλ(Ĭ�ϵ�λ��0)
 * @param num
 */
void BinaryRegister::moveLeft_logic(int num) {
    moveLeftWithSpecificValue(num, BINARY_ZERO);
}

/**
 * �Ĵ�������numλ����λ��supplement��1��0��
 * @param num
 * @param supplement
 */
void BinaryRegister::moveRightWithSpecificValue(int num, char supplement) {
    for (int i = count - 1; i >= num; i--) {
        this->str[i] = this->str[i - num];
    }
    for (int i = 0; i < num; i++) {
        this->str[i] = supplement;
    }
}
/**
 * �Ĵ�������numλ����λ��supplement��1��0��
 * @param num
 * @param supplement
 */
void BinaryRegister::moveLeftWithSpecificValue(int num, char supplement) {
    for (int i = 0; i < count - num; i++) {
        str[i] = str[i + num];
    }
    for (int i = count - num; i < count; i++) {
        this->str[i] = supplement;
    }
}

/**
 * �Ĵ�����������numλ��ǰһ���Ĵ����ĵ�λ�Ƶ���һ���Ĵ������ҵ�һ���Ĵ����ĸ�λ��supplement
 * @param num
 * @param anotherRegister
 * @param supplement
 */
void BinaryRegister::moveRight_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement) {
    for (int i = 0; i < num; i++) {
        anotherRegister.moveRightWithSpecificValue(1, this->str[count - i - 1]);
    }
    moveRightWithSpecificValue(num, supplement);
}

int BinaryRegister::getCount() const {
    return count;
}

/**
 * �Ĵ�����������numλ����һ���Ĵ����ĸ�λ�Ƶ�ǰһ���Ĵ������Һ�һ�����Ĵ����ĵ�λ��supplement
 * @param num
 * @param anotherRegister
 * @param supplement
 */
void BinaryRegister::moveLeft_logicToAnother(int num, BinaryRegister &anotherRegister, char supplement) {
    for (int i = 0; i < num; i++) {
        anotherRegister.moveLeftWithSpecificValue(1, this->str[i]);
    }
    moveLeftWithSpecificValue(num, supplement);
}

/**
 * ���ã���0��
 */
void BinaryRegister::reset() {
    for (int i = 0; i < count; i++) {
        this->str[i] = BINARY_ZERO;
    }
}


/**
 * ת���ɲ���
 */
void BinaryRegister::toComplement() {
    int end = 0;
    if (str[0] == BINARY_ZERO) {
        this->setType(BINARY_TYPE_COMPLEMENT_CODE);
        return;
    }
    switch (type) {
        case BINARY_TYPE_ORIGINAL_CODE:     //ԭ��ת����
            for (end = count - 1; end >= symbolBitCount; end--) {
                if (str[end] == BINARY_ONE)    //�Ӻ���ǰ�������ҵ���һ����Ϊ0��λ��
                    break;
            }
            revise(str, symbolBitCount, end - 1);
            break;
        case BINARY_TYPE_COMPLEMENT_CODE:   //��������ת
            return;
        case BINARY_TYPE_ANTI_CODE:         //����ת����
            add(*this); //�Լ�1
            break;
        default:
            break;
    }
    this->setType(BINARY_TYPE_COMPLEMENT_CODE);
}

/**
 * ת����ԭ��
 */
void BinaryRegister::toOriginalCode() {
    int end = 0;
    if (str[0] == BINARY_ZERO) {
        this->setType(BINARY_TYPE_ORIGINAL_CODE);
        return;
    }
    switch (type) {
        case BINARY_TYPE_ORIGINAL_CODE:     //ԭ������ת
            break;
        case BINARY_TYPE_ANTI_CODE:         //����תԭ��
            add(*this); //�Լ�1             //����ת�����Ժ����ִ�в���תԭ��Ĳ���
        case BINARY_TYPE_COMPLEMENT_CODE:   //����תԭ��
            for (end = count - 1; end >= symbolBitCount; end--) {
                if (str[end] == BINARY_ONE)    //�Ӻ���ǰ�������ҵ���һ����Ϊ0��λ��
                    break;
            }
            revise(str, symbolBitCount, end - 1);
            break;
        default:
            break;
    }
    this->setType(BINARY_TYPE_ORIGINAL_CODE);
}

/**
 * ��ȡ����λ�ĸ���
 * @return
 */
int BinaryRegister::getSymbolBitCount() const {
    return symbolBitCount;
}

/**
 * ���÷���λ�ĸ���
 * @param symbolBitCount
 */
void BinaryRegister::setSymbolBitCount(int symbolBitCount) {
    if (symbolBitCount >= count) {
        return;
    } else {
        BinaryRegister::symbolBitCount = symbolBitCount;
    }
}

/**
 * ��str�е�01�����ã���0��1��1��0
 * @param str
 * @param start_pos
 * @param end_pos
 */
void BinaryRegister::revise(char *str, int start_pos, int end_pos) {
    if (start_pos < 0 || end_pos > strlen(str) || start_pos >= end_pos) {
        return;
    }
    for (int i = start_pos; i <= end_pos; i++) {
        if (str[i] == BINARY_ONE) {
            str[i] = BINARY_ZERO;
        } else {
            str[i] = BINARY_ONE;
        }
    }
}

/**
 * ��ԭ�л����ϼ�num
 * @param str
 * @param num
 */
bool BinaryRegister::add(BinaryRegister &b, int num) {
    for (int j = 0; j < num; j++) {
        for (int i = b.getCount() - 1; i >= b.getSymbolBitCount(); i--) {
            if (b.str[i] == BINARY_ONE) {
                b.str[i] = BINARY_ZERO;
            } else {
                b.str[i] = BINARY_ONE;
                break;
            }
        }
    }
    return true;
}

/**
 * ��[y]�� ----> [-y]��
 * @param original
 * @param target
 * @return
 */
bool BinaryRegister::yCTOnYC(BinaryRegister &original, BinaryRegister &target) {
    copy(original, target);     //�ȰѼĴ��������ݸ��Ƶ�Ŀ��Ĵ���
    target.toComplement();
    target.revise(target.str, 0, target.getCount() - 1);//������λÿλȡ��
    add(target);
    return false;
}

bool BinaryRegister::copy(BinaryRegister &original, BinaryRegister &target) {
    if (original.getCount() != target.getCount()) {   //�������������󳤶Ȳ��ȣ���������
        return false;
    }
    strcpy(target.str, original.str);
    target.setType(original.getType());
    target.setValue_type(original.getValue_type());
    target.setSymbolBitCount(original.getSymbolBitCount());
    return true;
}

/**
 * ���붨��Ӽ���
 * @param A
 * @param X
 * @param result �����洢���
 * @param flag   ��������Ǽӷ����Ǽ���
 * return �����Ƿ����
 */
bool BinaryRegister::ComplementCodeAdd_Sub(BinaryRegister A, BinaryRegister X, BinaryRegister &result, int flag) {
    //�����������ܺͶ���С����������
    if (A.getValue_type() != X.getValue_type()) {
        return false;
    }
    //��ת��Ϊ����
    A.toComplement();
    X.toComplement();

    if (flag == OPERATOR_ADDITION) {//�ӷ�����
        add(A, X, result);
    } else if (flag == OPERATOR_SUBTRACTION) {//��������
        yCTOnYC(X, X);         //���ݲ���ø����Ĳ���
        add(A, X, result);
    } else {
        return false;
    }
    //��������Ϊ����
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    result.setValue_type(A.getValue_type());
    //һλ����λ�������
    //��ʵ�ʲ���������������Ϊ�����Ļ���������Ϊ�为�����룩�ķ���λ��ͬ��������Ľ������������ķ��Ų�ͬ����Ϊ���
    return A.str[0] == X.str[0] && result.str[0] != A.str[0];
}


/**
 * �ӷ�������
 * @param b1
 * @param b2
 * @return �����Ƿ���ӳɹ�
 */
bool BinaryRegister::add(BinaryRegister &b1, BinaryRegister &b2, BinaryRegister &result) {
    //Ҫ��λ����һ�������������
    if (b1.getCount() != b2.getCount()) {
        return false;
    }
    char carry = BINARY_ZERO;
    char temp = '0';
    for (int i = b1.getCount() - 1; i >= 0; i--) {
        temp = getCurrentBit(b1.str[i], b2.str[i], carry);
        carry = getCarry(b1.str[i], b2.str[i], carry);
        result.str[i] = temp;
    }
    return true;
}


/**
 * ����������λ�����жϣ����Ƿ������λ
 * @param c1
 * @param c2
 * @return
 */
char BinaryRegister::getCarry(char c1, char c2, char carry) {
    int num_temp = 0;
    if (c1 == BINARY_ONE) {
        num_temp++;
    }
    if (c2 == BINARY_ONE) {
        num_temp++;
    }
    if (carry == BINARY_ONE) {
        num_temp++;
    }
    if (num_temp >= 2) {
        return BINARY_ONE;
    }
    return BINARY_ZERO;
}

/**
 * ����������λ����Ժ�ǰλ��ֵ
 * @param c1
 * @param c2
 * @param carry
 * @return
 */
char BinaryRegister::getCurrentBit(char c1, char c2, char carry) {
    int num_temp = 0;
    if (c1 == BINARY_ONE) {
        num_temp++;
    }
    if (c2 == BINARY_ONE) {
        num_temp++;
    }
    if (carry == BINARY_ONE) {
        num_temp++;
    }
    if (num_temp == 1 || num_temp == 3) {
        return BINARY_ONE;
    }
    return BINARY_ZERO;
}

/**
 * ���ݶ����ƴ������ֵ�����ò����ʾ���ɶ��ʾһλ��
 * @param b
 * @return
 */
double BinaryRegister::getRealValue(BinaryRegister &b) {
    double value = 0;
    double weight;
//    int type = b.getType();
    b.toOriginalCode();
    if (b.getValue_type() == FIXED_POINT_INTEGER) {
        weight = 1;
        for (int i = b.getCount() - 1; i >= b.getSymbolBitCount(); i--) {
            value += (weight * (b.str[i] - 48));
            weight *= 2;
        }
        //����������Զ��ʾ����һλ�Ĵ���
        if (value - 0 < 10e-6) {
            return pow(2.0, b.getCount() - b.getSymbolBitCount());
        }
    } else if (b.getValue_type() == FIXED_POINT_DECIMAL) {
        weight = 0.5;
        for (int i = b.getSymbolBitCount(); i < b.getCount(); i++) {
            value += (weight * (b.str[i] - 48));
            weight *= 0.5;
        }
        //����������Զ��ʾ����һλ�Ĵ���
        if (value - 0 < 10e-6) {
            return -1;
        }
    }

    if (b.str[0] == BINARY_ONE) {
        value = value * -1;

    }
    return value;
}

int BinaryRegister::getValue_type() const {
    return value_type;
}

/**
 * ���ö����������ͣ������������Ƕ���С����
 * @param value_type
 */
void BinaryRegister::setValue_type(int value_type) {
    //�������Ѷ����ö��������Ȼ�����������������Ͳ���
    if (value_type == FIXED_POINT_INTEGER || value_type == FIXED_POINT_DECIMAL) {
        BinaryRegister::value_type = value_type;
    }
}

/**
 * ԭ��һλ�ˣ�a * b��
 * @param a     ������(ԭ��)
 * @param b     ������ԭ�룩
 * @param result ������Ž��
 * @return  ԭ��һλ�˲���������ʷ��ص�boolֵ�����ж�ִ�г˷������Ƿ�ɹ�
 *
 * ����ֵ����==>��x*��y*�������㣬����λ����
 * ����λ�Ĵ����жϳ˷��Ƿ����==>��n�Σ�nΪ��ֵ���ֵ�λ����
 * �߼���λ==>�ƶ�����0
 */
bool BinaryRegister::OriginalCode_OneBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != 2 * a.getCount() - 1)
        return false;
    if (a.getValue_type() != b.getValue_type())
        return false;

    BinaryRegister A(a.getCount());
    A.setType(BINARY_TYPE_ORIGINAL_CODE);
    A.setValue_type(a.getValue_type());

    BinaryRegister X(a);
    BinaryRegister Q(b);
    X.toOriginalCode();         //תΪԭ��
    Q.toOriginalCode();         //תΪԭ��
    int C = A.getCount() - 1;   //����λ��������ǽ���
    char S = X.str[0] ^ Q.str[0] ? '1' : '0';       //����
    //��Ϊ����ֵ
    X.str[0] = Q.str[0] = '0';
    //��ȡ���ұߵĶ�����λ����������Qn
    int n = Q.getCount() - 1;
    while (C != 0) {
        if (Q.str[n] == '1') {  //���Qnλ��1�Ļ����ϱ�����������ֱ�������߼�����һλ
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
        }
        //A->Q�����߼�����һλ����λ��0����λ�ƶ�
        A.moveRight_logicToAnother(1, Q, '0');
        C--;
    }
    //���ɳ˷���������
    result.str[0] = S;
    for (int i = 1; i < A.getCount(); i++) {
        result.str[i] = A.str[i];
    }
    for (int i = 0; i < Q.getCount() - 1; i++) {
        result.str[i + A.getCount()] = Q.str[i];
    }

    return true;
}

/**
 * Դ����λ��
 * @param a
 * @param b
 * @param result
 * @return
 *
 * ԭ��ˣ�����λ����ֵ���ַֿ�����
 * ��λ�ˣ�һ������λ���ж�
 */
bool BinaryRegister::OrignalCode_TwoBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != 2 * a.getCount() - 1)
        return false;
    if (a.getValue_type() != b.getValue_type())
        return false;

    BinaryRegister A(a.getCount() + 2);//���ֻ������ĸ�nλ��������λȡ��λ
    A.setType(BINARY_TYPE_COMPLEMENT_CODE);
    A.setValue_type(a.getValue_type());
    A.setSymbolBitCount(3);             //����λȡ��λ

    BinaryRegister X(a);        //������
    BinaryRegister Q(b);        //���������ĵ�nλ��
    int Cj = 0;                 //���λ
    X.toOriginalCode();
    Q.toOriginalCode();
    char S = X.str[0] ^ Q.str[0] ? '1' : '0';       //����
    //��Ϊ����ֵ����x*��y*�����㣬������������
    X.str[0] = Q.str[0] = '0';
    X.resize(X.count + 2);      //3λ����λ
    X.moveRight_logic(2);
    X.setSymbolBitCount(3);
    Q.resize(Q.count + 1);      //��λ����λ
    Q.moveRight_logic(1);
    Q.setSymbolBitCount(1);
    int C = (a.getCount() - a.getSymbolBitCount()) / 2 + 1;   //ͬ��Ҳ����λ�������ж��Ƿ���������������λ��������

    //��ȡ���ұߵĶ�����λ����������Qn
    int n = Q.getCount() - 1;
    int judge = 0;
    while (C != 0) {
        if(Q.str[n - 1] == '1'){
            judge += 4;
        }
        if(Q.str[n] == '1'){
            judge += 2;
        }
        //������ĩ��λ�ĳ����ж�λ��Cj������Ҫִ�еĲ���
        switch (judge + Cj){
            case 0:     //000��ֱ�����岹��������λ
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 1:     //001, +x*��Cj = 0, �ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 0;
                break;
            case 2:     //010�� +x*���ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 3:     //011, +2x*��Cj = 0, �ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 0;
                break;
            case 4:     //100, +2x*���ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 5:     //101, +[-x*], Cj����1���ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 6:     //110, +[-x*], Cj = 1���ٲ���������λ
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 1;
                break;
            case 7:     //111, Cj ���� 1���ٲ���������λ
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            default:
                break;
        }
        judge = 0;
        C--;
    }
    //�����ֵ����������λ����Ҫ��������
    if((a.getCount() - a.getSymbolBitCount()) % 2 != 0){
        A.moveRight_logicToAnother(1, Q, A.str[0]);
    }
    //���ɳ˷���������
    result.str[0] = S;
    for (int i = A.getSymbolBitCount(); i < A.getCount(); i++) {
        result.str[i - 2] = A.str[i];
    }
    for (int i = 0; i < Q.getCount() - 2; i++) {
        result.str[i + A.getCount() - 2] = Q.str[i];
    }
    return true;
}

/**
 * �ؿ�Ĵ�����λ����ԭ����nλ�����ڸ�nλ, ����µĴ�С���̵Ļ���Ԫ���ݵ�λ�ضϣ�
 * @param size
 */
void BinaryRegister::resize(int size) {
    char *temp = str;
    str = new char[size + 1];
    for (int i = 0; i < size; i++) {
        if (i < count) {
            str[i] = temp[i];
        }else{
            str[i] = '0';
        }
    }
    delete[] temp;
    str[size] = '\0';
    count = size;
}


/**
 * ��Booth�㷨ʵ�ֵĲ���һλ��
 * @param a  ������
 * @param b  ����
 * @param result  ������Ž��
 * @return
 */
bool BinaryRegister::ComplementCode_OneBit_Multiply_Booth(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != 2 * a.getCount() - 1)
        return false;
    if (a.getValue_type() != b.getValue_type()){    //������������С���ĳ˻�
        return false;
    }


    //�Ĵ���A
    BinaryRegister A(a.getCount() + 1);
    A.setType(BINARY_TYPE_COMPLEMENT_CODE);
    A.setValue_type(a.getValue_type());


    BinaryRegister X(a);
    BinaryRegister Q(b);
    //��תΪ������ʽ����
    X.toComplement();
    Q.toComplement();

    //����λ����λ������
    X.resize(X.getCount() + 1);
    X.moveRightWithSpecificValue(1, X.str[0]);

    int C = A.getCount() - 1;      //����λ��������ǽ���
    char y = '0';                  //����λ Yn+1������ʼʱ��Ϊ0

    //��ȡ���ұߵĶ�����λ����������yn
    int n = Q.getCount() - 1;
    while (C != 0) {
        switch ((Q.str[n] - 48) * 2 + y - 48){
            case 0:     //00
            case 3:     //11
                y = Q.str[n];
                //���岹������һλ
                if(C != 1){ //���һ������
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
            case 1:     //01  +[x]��
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                y = Q.str[n];
                //���岹������һλ
                if(C != 1){
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
            case 2:     //10   -[x]��
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                y = Q.str[n];
                //���岹������һλ
                if(C != 1){
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
        }
        C--;
    }
    //���ɳ˷���������
    for (int i = 0; i < A.getCount() - 1; i++) {
        result.str[i] = A.str[i + 1];
    }
    for (int i = 0; i < Q.getCount() - 1; i++) {
        result.str[i + A.getCount() - 1] = Q.str[i];
    }

    return true;
}

/**
 * ԭ��Ӽ��������
 * @param a     ������
 * @param b     ����
 * @param result    ��Ž��
 * @return
 */
bool BinaryRegister::OrignalCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != a.getCount())
        return false;
    if (a.getValue_type() != b.getValue_type()){    //������������С������
        return false;
    }


    //�Ĵ���Q����ʼʱ��ȫ0
    BinaryRegister Q(a.getCount());
    Q.setType(BINARY_TYPE_ORIGINAL_CODE);
    Q.setValue_type(a.getValue_type());

    int n = Q.getCount() - 1;

    BinaryRegister A(a);
    BinaryRegister X(b);
    //��תΪԭ����ʽ����
    X.toOriginalCode();
    Q.toOriginalCode();

    //�̷����⴦��
    char S = X.str[0] ^ A.str[0] ? BINARY_ONE : BINARY_ZERO;
    A.str[0] = BINARY_ZERO;
    X.str[0] = BINARY_ZERO;

    //����λ��������ǽ���
    int C = A.getCount();
    //��һ������һ�μ���
    ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
    while(C != 0){
        if(A.str[0] == BINARY_ZERO){
            if(A.str[0] == BINARY_ZERO){    //����Ϊ��������1
                Q.str[n] = BINARY_ONE;
            }else{                          //����Ϊ��������0
                Q.str[n] = BINARY_ZERO;
            }
            if(C != 1){
                Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);
            }
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
        }else{
            if(A.str[0] == BINARY_ZERO){    //����Ϊ��������1
                Q.str[n] = BINARY_ONE;
            }else{                          //����Ϊ��������0
                Q.str[n] = BINARY_ZERO;
            }
            if(C != 1){
                Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);
            }
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
        }
        C--;
    }

    //���ɽ��
    result.str[0] = S;
    for(int i = 1; i < Q.getCount(); i++){
        result.str[i] = Q.str[i];
    }
    //ԭ����Ľ����ȻΪԭ��
    result.setType(BINARY_TYPE_ORIGINAL_CODE);
    return true;
}


/**
 * ����ļӼ��������
 * @param a     ������
 * @param b     ����
 * @param result    ��Ž��
 * @return
 */
bool BinaryRegister::ComplementCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != a.getCount())
        return false;
    if (a.getValue_type() != b.getValue_type()){    //������������С������
        return false;
    }

    //�Ĵ���Q����ʼʱ��ȫ0
    BinaryRegister Q(a.getCount());
    Q.setType(BINARY_TYPE_COMPLEMENT_CODE);
    Q.setValue_type(a.getValue_type());

    int C = Q.getCount();

    BinaryRegister A(a);
    BinaryRegister X(b);
    //��תΪ������ʽ����
    X.toComplement();
    Q.toComplement();
    if(A.str[0] == X.str[0]){       //ͬ�ż�
        ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
    }else{          //��ż�
        ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
    }
    while(C != 0){
        if(A.str[0] == X.str[0]){
            Q.moveLeft_logicToAnother(1, A, BINARY_ONE);        //ͬ������1������������һλ
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);   //ͬ�ż�
        }else{
            Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);    //�������0������������һλ
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);      //��ż�
        }
        C--;
    }
    Q.str[Q.getCount() - 1] = BINARY_ONE;  //ĩβ����һ
    for(int i = 0; i < Q.getCount(); i++){
        result.str[i] = Q.str[i];
    }
    result.setValue_type(a.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    return true;
}