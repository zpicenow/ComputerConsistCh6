#include <iostream>
#include "BinaryRegister.h"

void test();

using  namespace std;

void Example_6_8() {
    BinaryRegister b1("01011");
    BinaryRegister b2("10101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.8(p237): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "==============================================" << endl;
}

void Example_6_9() {
    BinaryRegister b1("11001");
    BinaryRegister b2("10101");
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.9(p238): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "==============================================" << endl;
}

void Example_6_10() {
    BinaryRegister b1("00001111");
    BinaryRegister b2("00011000");
    BinaryRegister result(8);
    cout << "==============================================" << endl;
    cout << "课本例题6.10(p238): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_SUBTRACTION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A - B]补 = " << result.getStr() << endl;
    cout << "所以 A - B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_11() {
    BinaryRegister b1("11011101");
    BinaryRegister b2("00101101");
    BinaryRegister result(8);
    cout << "==============================================" << endl;
    cout << "课本例题6.11(p238): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_SUBTRACTION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A - B]补 = " << result.getStr() << endl;
    cout << "所以 A - B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_12() {
    BinaryRegister b1("11011");
    BinaryRegister b2("10111");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.12(p239): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "所以 A - B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_13() {
    BinaryRegister b1("11000");
    BinaryRegister b2("11000");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.13(p240): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "所以 A + B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}
void Example_6_14() {
    BinaryRegister b1("01011");
    BinaryRegister b2("00011");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.14(p240): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "所以 A + B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_15() {
    BinaryRegister b1("01011");
    BinaryRegister b2("00111");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.15(p241): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "所以 A + B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_16() {
    BinaryRegister b1("11011");
    BinaryRegister b2("10111");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(5);
    cout << "==============================================" << endl;
    cout << "课本例题6.16(p241): " << endl;
    bool isOut = BinaryRegister::ComplementCodeAdd_Sub(b1, b2, result, OPERATOR_ADDITION);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "是否溢出: " << (isOut ? "true" : "false") << endl;
    cout << "[A + B]补 = " << result.getStr() << endl;
    cout << "所以 A + B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_17() {
    BinaryRegister b1("11110");
    BinaryRegister b2("11101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(9);
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.17(p245): " << endl;
    BinaryRegister::OriginalCode_OneBit_Multiply(b1, b2, result);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_18() {
    BinaryRegister b1("0111111");
    BinaryRegister b2("1111001");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.18(p245): " << endl;
    BinaryRegister::OrignalCode_TwoBit_Multiply(b1, b2, result);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "[A * B]原 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

/**
 * 当数据位位奇数时的情况测试
 */
void Example_6_18_odd() {
    BinaryRegister b1("011011");
    BinaryRegister b2("111101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本作业题6.20.(4): " << endl;
    BinaryRegister::OrignalCode_TwoBit_Multiply(b1, b2, result);
    cout << "A = " << b1.getStr() << '\t' << "B = " << b2.getStr() << endl;
    cout << "[A * B]原 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_19() {
    BinaryRegister b1("10101");
    BinaryRegister b2("01101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    b1.setType(BINARY_TYPE_COMPLEMENT_CODE);
    b2.setType(BINARY_TYPE_COMPLEMENT_CODE);

    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    cout << "==============================================" << endl;
    cout << "课本例题6.19(p251): " << endl;
    BinaryRegister::ComplementCode_OneBit_Multiply_Booth(b1, b2, result);
    cout << "[A]补 = " << b1.getStr() << '\t' << "[B]补 = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_20() {
    BinaryRegister b1("01101");
    BinaryRegister b2("10101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    b1.setType(BINARY_TYPE_COMPLEMENT_CODE);
    b2.setType(BINARY_TYPE_COMPLEMENT_CODE);

    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    cout << "==============================================" << endl;
    cout << "课本例题6.20(p251): " << endl;
    BinaryRegister::ComplementCode_OneBit_Multiply_Booth(b1, b2, result);
    cout << "[A]补 = " << b1.getStr() << '\t' << "[B]补 = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_21() {
    BinaryRegister b1("01101");
    BinaryRegister b2("01011");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    b1.setType(BINARY_TYPE_COMPLEMENT_CODE);
    b2.setType(BINARY_TYPE_COMPLEMENT_CODE);

    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    cout << "==============================================" << endl;
    cout << "课本例题6.21(p254): " << endl;
    BinaryRegister::ComplementCode_OneBit_Multiply_Booth(b1, b2, result);
    cout << "[A]补 = " << b1.getStr() << '\t' << "[B]补 = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_22() {
    BinaryRegister b1("10101");
    BinaryRegister b2("10011");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    b1.setType(BINARY_TYPE_COMPLEMENT_CODE);
    b2.setType(BINARY_TYPE_COMPLEMENT_CODE);

    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    cout << "==============================================" << endl;
    cout << "课本例题6.22(p254): " << endl;
    BinaryRegister::ComplementCode_OneBit_Multiply_Booth(b1, b2, result);
    cout << "[A]补 = " << b1.getStr() << '\t' << "[B]补 = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_23() {
    BinaryRegister b1("00101");
    BinaryRegister b2("10101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);
    b1.setType(BINARY_TYPE_COMPLEMENT_CODE);
    b2.setType(BINARY_TYPE_COMPLEMENT_CODE);

    BinaryRegister result(b1.getCount() * 2 - 1);
    result.setValue_type(b1.getValue_type());
    result.setType(BINARY_TYPE_COMPLEMENT_CODE);
    cout << "==============================================" << endl;
    cout << "课本例题6.23(p257): " << endl;
    BinaryRegister::ComplementCode_OneBit_Multiply_Booth(b1, b2, result);
    cout << "[A]补 = " << b1.getStr() << '\t' << "[B]补 = " << b2.getStr() << endl;
    cout << "[A * B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}
void Example_6_24() {
    BinaryRegister b1("11011");
    BinaryRegister b2("11101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);

    BinaryRegister result(b1.getCount());
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.24(p259): " << endl;
    BinaryRegister::OrignalCode_Alternation_of_ADD_SUB(b1, b2, result);
    cout << "[A]原 = " << b1.getStr() << '\t' << "[B]原 = " << b2.getStr() << endl;
    cout << "[A / B]原 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_25() {
    BinaryRegister b1("11011");
    BinaryRegister b2("01101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);

    BinaryRegister result(b1.getCount());
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.25(p261): " << endl;
    BinaryRegister::OrignalCode_Alternation_of_ADD_SUB(b1, b2, result);
    cout << "[A]原 = " << b1.getStr() << '\t' << "[B]原 = " << b2.getStr() << endl;
    cout << "[A / B]原 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}


void Example_6_26() {
    BinaryRegister b1("01001");
    BinaryRegister b2("01101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);

    BinaryRegister result(b1.getCount());
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.26(p266): " << endl;
    BinaryRegister::ComplementCode_Alternation_of_ADD_SUB(b1, b2, result);
    cout << "[A]原 = " << b1.getStr() << '\t' << "[B]原 = " << b2.getStr() << endl;
    cout << "[A / B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}

void Example_6_27() {
    BinaryRegister b1("11001");
    BinaryRegister b2("01101");
    b1.setValue_type(FIXED_POINT_DECIMAL);
    b2.setValue_type(FIXED_POINT_DECIMAL);

    BinaryRegister result(b1.getCount());
    result.setValue_type(b1.getValue_type());
    cout << "==============================================" << endl;
    cout << "课本例题6.27(p266): " << endl;
    BinaryRegister::ComplementCode_Alternation_of_ADD_SUB(b1, b2, result);
    cout << "[A]原 = " << b1.getStr() << '\t' << "[B]原 = " << b2.getStr() << endl;
    cout << "[A / B]补 = " << result.getStr() << endl;
    cout << "所以 A * B = " << BinaryRegister::getRealValue(result) << endl;
    cout << "==============================================" << endl;
}
int main() {

    //加法运算部分(补码加法，用一位符号位判溢出)
//    Example_6_8();
//    Example_6_9();
//    Example_6_10();
//    Example_6_11();
//    Example_6_12();
//    Example_6_13();
//    Example_6_14();
//    Example_6_15();
//    Example_6_16();
//    Example_6_17();
//    Example_6_18();
//    Example_6_18_odd();
//    Example_6_19();
//    Example_6_20();
//    Example_6_21();
//    Example_6_22();
//    Example_6_23();
//    Example_6_25();
//    Example_6_26();
    Example_6_27();

//    BinaryRegister b("110111");
//    cout << b.getStr() << endl;
//    b.resize(8);
//    b.moveRight_logic(2, '0');
//    cout << b.getStr() << endl;

//    Example_6_24();
//    BinaryRegister b2("0011001");
//    cout << b.str << endl;
//    cout << b2.str << endl;
//    b.moveRight_logicToAnother(4, b2, BINARY_ONE);
//    cout << b.str << endl;
//    cout << b2.str << endl;
    return 0;
}

