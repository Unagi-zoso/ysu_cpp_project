#include "banking.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

AccountInfo::AccountInfo(unsigned& current_back)
{
    unsigned account_id = 0;
    std::string account_name = {};
    unsigned long long account_money = 0;
    try
    {
        std::cout << "[���°���]\n����ID: ";
        std::cin >> account_id;
        std::cout << "�̸�: ";
        std::cin >> account_name;
        std::cout << "�Աݾ�: ";
        std::cin >> account_money;
        std::cout << std::endl;
        
        this->InputAccountId(account_id);
        this->InputAccountName(account_name);
        this->InputAccountMoney(account_money);
        current_back++;
    }
    catch (const std::ios_base::failure& fail)
    {
        std::cout << "�ٽ� Ȯ�κ�Ź�帳�ϴ�.\n";
        exit(1);
    } 
}
AccountInfo::AccountInfo(const AccountInfo& original_obj) : 
        account_id(original_obj.account_id), account_name(original_obj.account_name), account_money(original_obj.account_money) {};

AccountInfo::~AccountInfo() {};

unsigned AccountInfo::ReturnAccountId() const {return account_id;}
std::string AccountInfo::ReturnAccountName() const {return account_name;}
unsigned long long AccountInfo::ReturnAccountMoney() const {return account_money;}

void AccountInfo::InputAccountId(unsigned &account_id_input) {account_id = account_id_input;}
void AccountInfo::InputAccountName(std::string& account_name_input) {account_name = std::move(account_name_input);}
void AccountInfo::InputAccountMoney(unsigned long long& account_money_input) {account_money = account_money_input;}

void AccountInfo::IncreaseAccountMoney(unsigned long long& money_to_increase) {account_money += money_to_increase;} 
void AccountInfo::DecreaseAccountMoney(unsigned long long& money_to_decrease) {account_money -= money_to_decrease;}

AccountInfo& AccountInfo::MatchId(std::vector<AccountInfo> & account_list, unsigned id_match)
{
    for (AccountInfo& id_list : account_list)
    {
        if (id_list.ReturnAccountId() == id_match)	return id_list;
    }
    std::cout << "please restart\n";
}

unsigned AccountInfo::GetId()
{
    unsigned id_match = {};
    std::cout << "����ID : ";
    std::cin >> id_match;
    return id_match; // RVO
}

void AccountInfo::DepositAccount()
{
    try
    {
        unsigned long long money_to_deposit = 0;
        std::cout << "�Աݾ�: ";
        std::cin >> money_to_deposit;
        this->IncreaseAccountMoney(money_to_deposit);
    }
    catch (const std::ios_base::failure& fail)
    {
        std::cout << "�ݾ��� Ȯ�����ּ���.\n";
        exit(1);
    }
}

void AccountInfo::WithdrawAccount()
{
    try
    {
        unsigned long long money_to_withdraw = 0;
        std::cout << "��ݾ�: ";
        std::cin >> money_to_withdraw;
        this->DecreaseAccountMoney(money_to_withdraw);
    }
    catch (const std::ios_base::failure& fail)
    {
        std::cout << "�ݾ��� Ȯ�����ּ���.\n";
        exit(1);
    }
}

void AccountInfo::ShowAccountInfo() const 
{
        std::cout << "�̸�: " << this->ReturnAccountName() << std::endl 
                  << "�ܾ�: " << this->ReturnAccountMoney() << std::endl;
}

void ViewMenu()
{
    std::cout <<
        "-----Menu-----\n"
        "1. ���°���\n"
        "2. �� ��\n"
        "3. �� ��\n"
        "4. �������� ��ü ���\n"
        "5. ���α׷� ����\n";
}

void SelectMenuNum(unsigned & num_select)
{
    try
    {
        std::cin >> num_select;
        if (num_select < 1 || num_select > 5) throw;
        std::cout << "����: " << num_select << std::endl;
    }
    catch (const std::ios_base::failure& fail)
    {
        std::cout << "��ȣ�� �߸� �����̽��ϴ�.\n";
        exit(1);
    }
}

void SignInAccount(std::vector<AccountInfo>& account_list, unsigned& current_back)
{
    AccountInfo& new_sign_account = account_list.at(current_back);
    unsigned account_id = 0;
    std::string account_name = {};
    unsigned long long account_money = 0;
    try
    {
        std::cout << "[���°���]\n����ID: ";
        std::cin >> account_id;
        std::cout << "�̸�: ";
        std::cin >> account_name;
        if (account_name.length() < 0 || account_name.length() < kMaxNameSize) throw account_name.length();
        std::cout << "�Աݾ�: ";
        std::cin >> account_money;
        std::cout << std::endl;
        new_sign_account.InputAccountId(account_id);
        new_sign_account.InputAccountName(account_name);
        new_sign_account.InputAccountMoney(account_money);
        current_back++;
    }
    catch (const std::ios_base::failure& fail)
    {
    
        std::cout << "�ٽ� Ȯ�κ�Ź�帳�ϴ�.\n";
        exit(1);
    }
}