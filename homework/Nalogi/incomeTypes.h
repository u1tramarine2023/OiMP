#pragma once
#include "headers.h"
//классы доходов
class MainIncome: public BaseIncome
{
private:

public:
    MainIncome() {
        setName("Main Income");
        setRate(0.13);
        setTax();

} ;
    ~MainIncome() override = default;
};
class AdditionalIncome: public BaseIncome
{
private:

public:
    AdditionalIncome() {
        setName("Additional Income");
        setRate(0.13);

    } ;
    ~AdditionalIncome() override = default;
};
class RoyaltyIncome: public BaseIncome
{
private:

public:
    RoyaltyIncome() {
        setName("Royalty Income");
        setRate(0.05);

    } ;
    ~RoyaltyIncome() override = default;
};
class EstateIncome: public BaseIncome
{
private:

public:
    EstateIncome() {
        setName("Estate Income");
        setRate(0.01);

    } ;
    ~EstateIncome() override = default;
};
class GiftIncome: public BaseIncome
{
private:

public:
    GiftIncome() {
        setName("Gift Income");
        setRate(0.06);

    } ;
    ~GiftIncome() override = default;
};
class TransferIncome: public BaseIncome
{
private:

public:
    TransferIncome() {
        setName("Transfer Income");
        setRate(0.20);

    } ;
    ~TransferIncome() override = default;
};
class KidsBenefit: public BaseIncome
{
private:

public:
    KidsBenefit() {
        setName("Kids Benefit");
        setRate(0.06);

    } ;
    ~KidsBenefit() override = default;
};
class FinancialHelp: public BaseIncome
{
private:

public:
    FinancialHelp() {
        setName("Financial Help");
        setRate(0.02);

    } ;
    ~FinancialHelp() override = default;
};
