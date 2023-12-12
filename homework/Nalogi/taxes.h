#pragma once
#include "headers.h"

std::shared_ptr<BaseIncome> ptr(char);

class Tax
{
public:
    std::vector<std::shared_ptr<BaseIncome>> Taxes;

    Tax() = default;
    ~Tax() = default;

    void ReadAll(std::istream &file);
    void PrintAll(std::ostream &out);
    void TotalTax();
    void sortAmount();

};

std::shared_ptr<BaseIncome> GetIncomePtr(char choise)
{
    switch (choise)
    {
        case 'm':
        {
            return std::make_shared<MainIncome>();
            break;
        }
        case 'a':
        {
            return std::make_shared<AdditionalIncome>();
            break;
        }
        case 'r':
        {
            return std::make_shared<RoyaltyIncome>();
            break;
        }
        case 'e':
        {
            return std::make_shared<EstateIncome>();
            break;
        }
        case 'g':
        {
            return std::make_shared<GiftIncome>();
            break;
        }
        case 't':
        {
            return std::make_shared<TransferIncome>();
            break;
        }
        case 'k':
        {
            return std::make_shared<KidsBenefit>();
            break;
        }
        case 'h':
        {
            return std::make_shared<FinancialHelp>();
            break;
        }
        default:
        {
            throw std::runtime_error("Can't recognize this type of income");
        }
    }
}

void Tax:: ReadAll(std::istream& file)
{
    while (!file.eof())
    {
        char choice;
        file >> choice;
        Taxes.push_back(GetIncomePtr(choice));
        std::string str;
        getline(file, str);
        std::istringstream ss(str);
        Taxes.back()->read(ss);
    }
}

void Tax:: PrintAll(std::ostream& out)
{
    std::copy(Taxes.begin(), Taxes.end(),
              std::ostream_iterator<std::shared_ptr<BaseIncome>>(out, "\n"));
}
void Tax::TotalTax() {
    double TotalTax;
        std::for_each(Taxes.begin(), Taxes.end(),[&TotalTax](const std::shared_ptr<BaseIncome>& taxes){
        TotalTax+=taxes->getAmount();
        });
    std::cout<<TotalTax<<"\n";
}

void Tax::sortAmount()
{
    std::sort(Taxes.begin(), Taxes.end(),[] (std::shared_ptr<BaseIncome> a, std::shared_ptr<BaseIncome> b)
    { return a->getTax() > b->getTax(); });
}





