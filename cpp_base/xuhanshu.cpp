//
// Created by 26247 on 5/30/2024.
//
// 虚函数：virtual关键字声明，用在函数上子类可以重新该函数，实现多态。
// 原理：每一个含有虚函数的类实例，都有一个指向相应虚函数表(一个函数指针数组)的指针,该表包含该类及其基类的所有虚函数，使得运行时能够根据对象的实际类型找到正确的函数地址并调用。
// 构造函数 析构函数 静态成员函数 内联函数
#include "iostream"
#include "string"

class Animal {
protected:
    static std::string name;
    // 静态成员函数

    static void who() {
        std::cout << name << "!" << std::endl;
    }

public:
    // 虚函数
    virtual void shout() {
        std::cout << name << " shout! " << std::endl;
    }

    // 构造函数
    Animal() {
        name = "animal";
        std::cout << "I am " << name << "! " << std::endl;
    }

    // 析构函数
    ~Animal() {
        std::cout << name << "销毁中…………" << std::endl;
        std::cout << "销毁完毕" << std::endl;
    }

    // 内联函数，函数调用处直接展开函数，减少函数调用
    inline int add(int a, int b) {
        return a + b;
    }

};

std::string Animal::name = "";

class Dog : public Animal {
public:
    Dog() {
        Animal::name = "dog";
        std::cout << "I am " << name << "! " << std::endl;
    }

    void shout() override {
        std::cout << name << " shout!!! " << std::endl;
    }
};

int main() {
    Animal *animal = new Dog();
    animal->shout();
    std::cout << "1+2=" << animal->add(1, 2);
    delete animal;
    return 0;
}