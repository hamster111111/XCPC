#include <bits/stdc++.h>

//抽象类Operator
class Operator {
protected:
    int firstNumber;
    int secondNumber;
public:
    virtual int getResult() = 0;
    void setFirstNumber(int FirstNumber) {firstNumber = FirstNumber;}
    int getFirstNumber() {return firstNumber;}
    void setSecondNumber(int SecondNumber) {secondNumber = SecondNumber;}
    int getSecondNumber() {return secondNumber;}
};

class Add : public Operator {
public:
    int getResult() override {return firstNumber + secondNumber;}
};

class Sub : public Operator {
public:
    int getResult() override {return firstNumber - secondNumber;}
};

class Mul : public Operator {
public:
    int getResult() override {return firstNumber * secondNumber;}
};

class Div : public Operator {
public:
    int getResult() override {
        assert(secondNumber != 0);
        return firstNumber / secondNumber;
    }
};
//工厂模式
class OperatorSimpleFactory {
public:
    Operator* createOperator(std::string oper) {
        Operator* p = nullptr;
        if (oper == "+") p = new Add();
        if (oper == "-") p = new Sub();
        if (oper == "*") p = new Mul();
        if (oper == "/") p = new Div();
        return p;
    }
};

int main() 
{
    //执行输入部分
    int firstNumber = 0, secondNumber = 0;
    std::string oper;
    std::cout << "Please input the firstnumber, operation and the secondnumber\n";
    std::cin >> firstNumber >> oper >> secondNumber;

    //执行运算部分
    OperatorSimpleFactory fac;
    Operator* p = fac.createOperator(oper);
    p->setFirstNumber(firstNumber), p->setSecondNumber(secondNumber);
    
    //输出执行结果
    std::cout << "this is the final result\n";
    std::cout << p->getFirstNumber() << oper << p->getSecondNumber() << '=' << p->getResult() << '\n';
}