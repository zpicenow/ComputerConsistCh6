//
// Created by zhaopeng on 2017/11/18 
//
#include "BinaryRegister.h"
using namespace std;
/**
 * 寄存器右移num位(默认高位补0)
 * @param num
 */
void BinaryRegister::moveRight_logic(int num) {
    moveRightWithSpecificValue(num, BINARY_ZERO);
}
/**
 * 寄存器左移num位(默认低位补0)
 * @param num
 */
void BinaryRegister::moveLeft_logic(int num) {
    moveLeftWithSpecificValue(num, BINARY_ZERO);
}

/**
 * 寄存器右移num位，高位补supplement（1或0）
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
 * 寄存器左移num位，低位补supplement（1或0）
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
 * 寄存器整体右移num位，前一个寄存器的低位移到后一个寄存器。且第一个寄存器的高位补supplement
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
 * 寄存器整体左移num位，后一个寄存器的高位移到前一个寄存器。且后一个个寄存器的低位补supplement
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
 * 重置（置0）
 */
void BinaryRegister::reset() {
    for (int i = 0; i < count; i++) {
        this->str[i] = BINARY_ZERO;
    }
}


/**
 * 转换成补码
 */
void BinaryRegister::toComplement() {
    int end = 0;
    if (str[0] == BINARY_ZERO) {
        this->setType(BINARY_TYPE_COMPLEMENT_CODE);
        return;
    }
    switch (type) {
        case BINARY_TYPE_ORIGINAL_CODE:     //原码转补码
            for (end = count - 1; end >= symbolBitCount; end--) {
                if (str[end] == BINARY_ONE)    //从后往前遍历，找到第一个不为0的位置
                    break;
            }
            revise(str, symbolBitCount, end - 1);
            break;
        case BINARY_TYPE_COMPLEMENT_CODE:   //补码无需转
            return;
        case BINARY_TYPE_ANTI_CODE:         //反码转补码
            add(*this); //自加1
            break;
        default:
            break;
    }
    this->setType(BINARY_TYPE_COMPLEMENT_CODE);
}

/**
 * 转换成原码
 */
void BinaryRegister::toOriginalCode() {
    int end = 0;
    if (str[0] == BINARY_ZERO) {
        this->setType(BINARY_TYPE_ORIGINAL_CODE);
        return;
    }
    switch (type) {
        case BINARY_TYPE_ORIGINAL_CODE:     //原码无需转
            break;
        case BINARY_TYPE_ANTI_CODE:         //反码转原码
            add(*this); //自加1             //反码转补码以后接着执行补码转原码的操作
        case BINARY_TYPE_COMPLEMENT_CODE:   //补码转原码
            for (end = count - 1; end >= symbolBitCount; end--) {
                if (str[end] == BINARY_ONE)    //从后往前遍历，找到第一个不为0的位置
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
 * 获取符号位的个数
 * @return
 */
int BinaryRegister::getSymbolBitCount() const {
    return symbolBitCount;
}

/**
 * 设置符号位的个数
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
 * 将str中的01串反置，即0置1，1置0
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
 * 在原有基础上加num
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
 * 由[y]补 ----> [-y]补
 * @param original
 * @param target
 * @return
 */
bool BinaryRegister::yCTOnYC(BinaryRegister &original, BinaryRegister &target) {
    copy(original, target);     //先把寄存器的数据复制到目标寄存器
    target.toComplement();
    target.revise(target.str, 0, target.getCount() - 1);//带符号位每位取反
    add(target);
    return false;
}

bool BinaryRegister::copy(BinaryRegister &original, BinaryRegister &target) {
    if (original.getCount() != target.getCount()) {   //拷贝的两个对象长度不等，不允许复制
        return false;
    }
    strcpy(target.str, original.str);
    target.setType(original.getType());
    target.setValue_type(original.getValue_type());
    target.setSymbolBitCount(original.getSymbolBitCount());
    return true;
}

/**
 * 补码定点加减法
 * @param A
 * @param X
 * @param result 用来存储结果
 * @param flag   用来标记是加法还是减法
 * return 返回是否溢出
 */
bool BinaryRegister::ComplementCodeAdd_Sub(BinaryRegister A, BinaryRegister X, BinaryRegister &result, int flag) {
    //定点整数不能和定点小数进行运算
    if (A.getValue_type() != X.getValue_type()) {
        return false;
    }
    //先转化为补码
    A.toComplement();
    X.toComplement();

    if (flag == OPERATOR_ADDITION) {//加法操作
        add(A, X, result);
    } else if (flag == OPERATOR_SUBTRACTION) {//减法运算
        yCTOnYC(X, X);         //根据补码得负数的补码
        add(A, X, result);
    } else {
        return false;
    }
    //设置码制为补码
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    result.setValue_type(A.getValue_type());
    //一位符号位判溢出法
    //若实际操作的两个数（若为减法的话，减数即为其负数补码）的符号位相同，计算出的结果又与操作数的符号不同，则为溢出
    return A.str[0] == X.str[0] && result.str[0] != A.str[0];
}


/**
 * 加法器操作
 * @param b1
 * @param b2
 * @return 返回是否相加成功
 */
bool BinaryRegister::add(BinaryRegister &b1, BinaryRegister &b2, BinaryRegister &result) {
    //要是位数不一样，不允许操作
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
 * 两个二进制位进行判断，看是否产生进位
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
 * 两个二进制位相加以后当前位的值
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
 * 根据二进制串获得真值（采用补码表示，可多表示一位）
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
        //补码制里可以多表示的那一位的处理
        if (value - 0 < 10e-6) {
            return pow(2.0, b.getCount() - b.getSymbolBitCount());
        }
    } else if (b.getValue_type() == FIXED_POINT_DECIMAL) {
        weight = 0.5;
        for (int i = b.getSymbolBitCount(); i < b.getCount(); i++) {
            value += (weight * (b.str[i] - 48));
            weight *= 0.5;
        }
        //补码制里可以多表示的那一位的处理
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
 * 设置定点数的类型（定点整数还是定点小数）
 * @param value_type
 */
void BinaryRegister::setValue_type(int value_type) {
    //必须是已定义的枚举量，不然不允许设置数据类型操作
    if (value_type == FIXED_POINT_INTEGER || value_type == FIXED_POINT_DECIMAL) {
        BinaryRegister::value_type = value_type;
    }
}

/**
 * 原码一位乘（a * b）
 * @param a     被乘数(原码)
 * @param b     乘数（原码）
 * @param result 用来存放结果
 * @return  原码一位乘不会溢出，故返回的bool值用于判断执行乘法操作是否成功
 *
 * 绝对值运算==>用x*和y*进行运算，符号位另求
 * 用移位的次数判断乘法是否结束==>移n次（n为数值部分的位数）
 * 逻辑移位==>移丢、添0
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
    X.toOriginalCode();         //转为原码
    Q.toOriginalCode();         //转为原码
    int C = A.getCount() - 1;   //用移位次数来标记结束
    char S = X.str[0] ^ Q.str[0] ? '1' : '0';       //积符
    //变为绝对值
    X.str[0] = Q.str[0] = '0';
    //获取最右边的二进制位的索引，即Qn
    int n = Q.getCount() - 1;
    while (C != 0) {
        if (Q.str[n] == '1') {  //如果Qn位是1的话加上被乘数，否则直接整体逻辑右移一位
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
        }
        //A->Q整体逻辑右移一位，高位补0，低位移丢
        A.moveRight_logicToAnother(1, Q, '0');
        C--;
    }
    //生成乘法的运算结果
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
 * 源码两位乘
 * @param a
 * @param b
 * @param result
 * @return
 *
 * 原码乘：符号位和数值部分分开运算
 * 两位乘：一次用两位来判断
 */
bool BinaryRegister::OrignalCode_TwoBit_Multiply(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != 2 * a.getCount() - 1)
        return false;
    if (a.getValue_type() != b.getValue_type())
        return false;

    BinaryRegister A(a.getCount() + 2);//部分积（积的高n位），符号位取三位
    A.setType(BINARY_TYPE_COMPLEMENT_CODE);
    A.setValue_type(a.getValue_type());
    A.setSymbolBitCount(3);             //符号位取三位

    BinaryRegister X(a);        //被乘数
    BinaryRegister Q(b);        //乘数（积的低n位）
    int Cj = 0;                 //标记位
    X.toOriginalCode();
    Q.toOriginalCode();
    char S = X.str[0] ^ Q.str[0] ? '1' : '0';       //积符
    //变为绝对值（用x*和y*来计算，符号另作处理）
    X.str[0] = Q.str[0] = '0';
    X.resize(X.count + 2);      //3位符号位
    X.moveRight_logic(2);
    X.setSymbolBitCount(3);
    Q.resize(Q.count + 1);      //两位符号位
    Q.moveRight_logic(1);
    Q.setSymbolBitCount(1);
    int C = (a.getCount() - a.getSymbolBitCount()) / 2 + 1;   //同样也用移位次数来判断是否结束（如果是奇数位，跳出）

    //获取最右边的二进制位的索引，即Qn
    int n = Q.getCount() - 1;
    int judge = 0;
    while (C != 0) {
        if(Q.str[n - 1] == '1'){
            judge += 4;
        }
        if(Q.str[n] == '1'){
            judge += 2;
        }
        //利用最末两位的乘数判断位和Cj来决定要执行的操作
        switch (judge + Cj){
            case 0:     //000，直接整体补码右移两位
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 1:     //001, +x*，Cj = 0, 再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 0;
                break;
            case 2:     //010， +x*，再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 3:     //011, +2x*，Cj = 0, 再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 0;
                break;
            case 4:     //100, +2x*，再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 5:     //101, +[-x*], Cj保持1，再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                break;
            case 6:     //110, +[-x*], Cj = 1，再补码右移两位
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                if(C != 1){
                    A.moveRight_logicToAnother(2, Q, A.str[0]);
                }
                Cj = 1;
                break;
            case 7:     //111, Cj 保持 1，再补码右移两位
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
    //如果数值部分是奇数位，需要再做处理
    if((a.getCount() - a.getSymbolBitCount()) % 2 != 0){
        A.moveRight_logicToAnother(1, Q, A.str[0]);
    }
    //生成乘法的运算结果
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
 * 拓宽寄存器的位数（原来的n位数据在高n位, 如果新的大小更短的话，元数据低位截断）
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
 * 用Booth算法实现的补码一位乘
 * @param a  被乘数
 * @param b  乘数
 * @param result  用来存放结果
 * @return
 */
bool BinaryRegister::ComplementCode_OneBit_Multiply_Booth(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != 2 * a.getCount() - 1)
        return false;
    if (a.getValue_type() != b.getValue_type()){    //不计算整数和小数的乘积
        return false;
    }


    //寄存器A
    BinaryRegister A(a.getCount() + 1);
    A.setType(BINARY_TYPE_COMPLEMENT_CODE);
    A.setValue_type(a.getValue_type());


    BinaryRegister X(a);
    BinaryRegister Q(b);
    //都转为补码形式运算
    X.toComplement();
    Q.toComplement();

    //用两位符号位来计算
    X.resize(X.getCount() + 1);
    X.moveRightWithSpecificValue(1, X.str[0]);

    int C = A.getCount() - 1;      //用移位次数来标记结束
    char y = '0';                  //附加位 Yn+1，出初始时置为0

    //获取最右边的二进制位的索引，即yn
    int n = Q.getCount() - 1;
    while (C != 0) {
        switch ((Q.str[n] - 48) * 2 + y - 48){
            case 0:     //00
            case 3:     //11
                y = Q.str[n];
                //整体补码右移一位
                if(C != 1){ //最后一步不移
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
            case 1:     //01  +[x]补
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
                y = Q.str[n];
                //整体补码右移一位
                if(C != 1){
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
            case 2:     //10   -[x]补
                ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
                y = Q.str[n];
                //整体补码右移一位
                if(C != 1){
                    A.moveRight_logicToAnother(1, Q, A.str[0]);
                }
                break;
        }
        C--;
    }
    //生成乘法的运算结果
    for (int i = 0; i < A.getCount() - 1; i++) {
        result.str[i] = A.str[i + 1];
    }
    for (int i = 0; i < Q.getCount() - 1; i++) {
        result.str[i + A.getCount() - 1] = Q.str[i];
    }

    return true;
}

/**
 * 原码加减交替除法
 * @param a     被除数
 * @param b     除数
 * @param result    存放结果
 * @return
 */
bool BinaryRegister::OrignalCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != a.getCount())
        return false;
    if (a.getValue_type() != b.getValue_type()){    //不计算整数和小数的商
        return false;
    }


    //寄存器Q，初始时赋全0
    BinaryRegister Q(a.getCount());
    Q.setType(BINARY_TYPE_ORIGINAL_CODE);
    Q.setValue_type(a.getValue_type());

    int n = Q.getCount() - 1;

    BinaryRegister A(a);
    BinaryRegister X(b);
    //都转为原码形式运算
    X.toOriginalCode();
    Q.toOriginalCode();

    //商符另外处理
    char S = X.str[0] ^ A.str[0] ? BINARY_ONE : BINARY_ZERO;
    A.str[0] = BINARY_ZERO;
    X.str[0] = BINARY_ZERO;

    //用移位次数来标记结束
    int C = A.getCount();
    //第一次先做一次减法
    ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
    while(C != 0){
        if(A.str[0] == BINARY_ZERO){
            if(A.str[0] == BINARY_ZERO){    //余数为正，上商1
                Q.str[n] = BINARY_ONE;
            }else{                          //余数为负，上商0
                Q.str[n] = BINARY_ZERO;
            }
            if(C != 1){
                Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);
            }
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
        }else{
            if(A.str[0] == BINARY_ZERO){    //余数为正，上商1
                Q.str[n] = BINARY_ONE;
            }else{                          //余数为负，上商0
                Q.str[n] = BINARY_ZERO;
            }
            if(C != 1){
                Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);
            }
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
        }
        C--;
    }

    //生成结果
    result.str[0] = S;
    for(int i = 1; i < Q.getCount(); i++){
        result.str[i] = Q.str[i];
    }
    //原码除的结果仍然为原码
    result.setType(BINARY_TYPE_ORIGINAL_CODE);
    return true;
}


/**
 * 补码的加减交替除法
 * @param a     被除数
 * @param b     除数
 * @param result    存放结果
 * @return
 */
bool BinaryRegister::ComplementCode_Alternation_of_ADD_SUB(BinaryRegister &a, BinaryRegister &b, BinaryRegister &result) {
    if (a.getCount() != b.getCount()) {
        return false;
    }
    if (result.getCount() != a.getCount())
        return false;
    if (a.getValue_type() != b.getValue_type()){    //不计算整数和小数的商
        return false;
    }

    //寄存器Q，初始时赋全0
    BinaryRegister Q(a.getCount());
    Q.setType(BINARY_TYPE_COMPLEMENT_CODE);
    Q.setValue_type(a.getValue_type());

    int C = Q.getCount();

    BinaryRegister A(a);
    BinaryRegister X(b);
    //都转为补码形式运算
    X.toComplement();
    Q.toComplement();
    if(A.str[0] == X.str[0]){       //同号减
        ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);
    }else{          //异号加
        ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);
    }
    while(C != 0){
        if(A.str[0] == X.str[0]){
            Q.moveLeft_logicToAnother(1, A, BINARY_ONE);        //同号上商1，并整体左移一位
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_SUBTRACTION);   //同号减
        }else{
            Q.moveLeft_logicToAnother(1, A, BINARY_ZERO);    //异号上商0，并整体左移一位
            ComplementCodeAdd_Sub(A, X, A, OPERATOR_ADDITION);      //异号加
        }
        C--;
    }
    Q.str[Q.getCount() - 1] = BINARY_ONE;  //末尾恒置一
    for(int i = 0; i < Q.getCount(); i++){
        result.str[i] = Q.str[i];
    }
    result.setValue_type(a.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    return true;
}