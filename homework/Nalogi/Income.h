#pragma once

#include <memory>
#include "headers.h"

class BaseIncome
{
private:
    std::string name;
    double amount; //cумма
    double rate; //ставка
    double tax; //налог
public:
    BaseIncome() = default;
    virtual ~BaseIncome() = default;
    std::string getName() const { return name; }
    double getAmount() const { return amount; }
    double getTax() const { return tax; }

    void setName(std::string _name) { name = _name; }
    void setRate(double _rate) { rate = _rate; }
    void setTax()  {
        tax=amount*rate;
    }

    virtual std::istream& read(std::istream& in)
    {
        in >> amount;
        return in;
    }


    virtual std::ostream& print(std::ostream& out)
    {
        setTax();
        out << std::left  << std::setw(20) << name << "| amount " << std::setw(10) << amount << "| tax rate " << std::setw(6) << rate << "| tax " << std::setw(6) << tax;
        return out;
    }
};

//перегрузка << нужна для потокового итератора
std::ostream& operator<<(std::ostream& out, std::shared_ptr<BaseIncome> ptr)
{
    ptr->print(out);
    return out;
}
