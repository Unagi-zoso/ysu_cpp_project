#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#pragma once

enum { ksign = 1, kDeposit, kWithdraw, kShow_All, kExit } e_Num_Select;
typedef int Num_Select;

class AccountInfo
{
public:
    AccountInfo() = default;
    AccountInfo(unsigned& current_back);
    virtual ~AccountInfo();
    
    unsigned ReturnAccountId() const;
    std::string ReturnAccountName() const;
    unsigned long long ReturnAccountMoney() const;

    void InputAccountId(unsigned& account_id_input);
    void InputAccountName(std::string& account_name_input);
    void InputAccountMoney(unsigned long long& account_money_input);
   
    void IncreaseAccountMoney(unsigned long long& money_to_increase); 
    void DecreaseAccountMoney(unsigned long long& money_to_decrease);

    static AccountInfo& MatchId(std::vector<AccountInfo> & account_list, unsigned id_match);
    
    static unsigned GetId();
    
    void DepositAccount();

    void WithdrawAccount();
    
    void ShowAccountInfo() const; 

private:
    unsigned account_id;
    std::string account_name;
    unsigned long long account_money;
    static unsigned g_current_back;
};

void ViewMenu();

void SelectMenuNum(unsigned & num_select);

void SignInAccount(std::vector<AccountInfo>& account_list, unsigned& current_back);
