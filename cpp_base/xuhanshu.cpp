//
// Created by 26247 on 5/30/2024.
//
// �麯����virtual�ؼ������������ں���������������¸ú�����ʵ�ֶ�̬��
// ԭ��ÿһ�������麯������ʵ��������һ��ָ����Ӧ�麯����(һ������ָ������)��ָ��,�ñ�������༰�����������麯����ʹ������ʱ�ܹ����ݶ����ʵ�������ҵ���ȷ�ĺ�����ַ�����á�
// ���캯�� �������� ��̬��Ա���� ��������
#include "iostream"
#include "string"

class Animal {
protected:
    static std::string name;
    // ��̬��Ա����

    static void who() {
        std::cout << name << "!" << std::endl;
    }

public:
    // �麯��
    virtual void shout() {
        std::cout << name << " shout! " << std::endl;
    }

    // ���캯��
    Animal() {
        name = "animal";
        std::cout << "I am " << name << "! " << std::endl;
    }

    // ��������
    ~Animal() {
        std::cout << name << "�����С�������" << std::endl;
        std::cout << "�������" << std::endl;
    }

    // �����������������ô�ֱ��չ�����������ٺ�������
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