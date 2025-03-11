#include <bits/stdc++.h>

class Employee {
protected:
    std::string id;
    std::string name;
public:
    virtual std::string getSalary() = 0;
    void setID(std::string ID) {id = ID;}
    void setName(std::string Name) {name = Name;}
};

class Manager : public Employee {
public:
    std::string getSalary() {return name + ", " + id + ", " + "200,000 dollars a year";}
};

class Engineer : public Employee {
public:
    std::string getSalary() {return name + ", " + id + ", " + "5,000 dollars a month";}
};

class Sales : public Employee {
public:
    std::string getSalary() {return name + ", " + id + ", " + "1,000 dollars a month";}
};

class IEmployeeFactory {
public:
    virtual Employee* createEmployee() = 0;
};

class EngineerFactory : public IEmployeeFactory {
public:
    Employee* createEmployee() {return new Engineer();}
};

class ManagerFactory : public IEmployeeFactory {
public:
    Employee* createEmployee() {return new Manager();}
};

class SalesFactory : public IEmployeeFactory {
public:
    Employee* createEmployee() {return new Sales();}
};

int main() 
{
    std::cout << "请输入你的职位\\姓名\\工号:\n";
    std::string pos, name, id;
    std::cin >> pos >> name >> id;
    IEmployeeFactory* iefactory = nullptr;
    //C++无专用的反射机制，因此我们这里模拟一下
    if (pos == "Manager") iefactory = new ManagerFactory();
    if (pos == "Sales") iefactory = new SalesFactory();
    if (pos == "Engineer") iefactory = new EngineerFactory();
    if (!iefactory) return 0;

    Employee* p = iefactory->createEmployee();
    p->setID(id), p->setName(name);
    std::cout << p->getSalary() << '\n';
}