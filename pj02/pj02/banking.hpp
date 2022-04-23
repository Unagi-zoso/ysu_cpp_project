#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

enum { ksign = 1, kDeposit, kWithdraw, kShow_All, kExit } e_Num_Select;
typedef int Num_Select;

class AccountInfo
{
public:
    AccountInfo() = default;
    AccountInfo(unsigned& current_back)
    {
        unsigned account_id = 0;
        std::string account_name = {};
        unsigned account_money = 0;
        const unsigned kMaxNameSize = 20;
        try
        {
            if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
            std::cout << "[���°���]\n����ID: ";
            std::cin >> account_id;
            if (account_id < 0 || account_id > UINT_MAX) throw account_id;
            std::cout << "�̸�: ";
            std::cin >> account_name;
            if (account_name.length() < 0 || account_name.length() > kMaxNameSize) throw account_name.length();
            std::cout << "�Աݾ�: ";
            std::cin >> account_money;
            if (account_money < 0 || account_money > ULLONG_MAX) throw account_money;
    
            std::cout << std::endl;
            
            this->InputAccountId(account_id);
            this->InputAccountName(std::move(account_name));
            this->InputAccountMoney(account_money);
            current_back++;
        }
        catch (int expn)
        {
            //std::cout << "?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��. ?��?��?��?��?��?�� ?��?��?�� : \n" << expn;
            std::cout << "�ٽ� Ȯ�κ�Ź�帳�ϴ�.\n";
            exit(1);
        } 
    }

    virtual ~AccountInfo() {};
    
    unsigned ReturnAccountId() const {return account_id;}
    std::string ReturnAccountName() const {return account_name;}
    unsigned ReturnAccountMoney() const {return account_money;}
    void InputAccountId(unsigned account_id_input) {account_id = account_id_input;}
    void InputAccountName(std::string account_name_input) {account_name = account_name_input;}
    void InputAccountMoney(unsigned account_money_input) {account_money = account_money_input;}
   
    void IncreaseAccountMoney(unsigned money_to_increase)
    {
        
        if (money_to_increase > ULLONG_MAX - account_money) throw money_to_increase;
        account_money += money_to_increase;
    } 

    void DecreaseAccountMoney(unsigned money_to_decrease)
    {
        if (money_to_decrease > account_money) throw money_to_decrease;
    }

        static AccountInfo& MatchId(std::vector<AccountInfo> & account_list, unsigned id_match)
    {
        for (AccountInfo& id_list : account_list)
        {
            if (id_list.ReturnAccountId() == id_match)	return id_list;
        }
        std::cout << "please restart\n";
        exit(1);
    }
    
    static unsigned GetId()
    {
        unsigned id_match = {};
        std::cout << "����ID : ";
        std::cin >> id_match;

        return id_match; // RVO
    }

    void DepositAccount()
    {
        try
        {
            unsigned long long money_to_deposit = 0;
            std::cout << "�Աݾ�: ";
            std::cin >> money_to_deposit;
            if (money_to_deposit <= 0 || money_to_deposit > ULLONG_MAX) throw money_to_deposit;
    
            this->IncreaseAccountMoney(money_to_deposit);
        }
        catch (int expn)
        {
            std::cout << "��ȣ�� �߸� �����̽��ϴ�.\n";
            exit(1);
        }
    }

    void WithdrawAccount()
    {
        try
        {
            unsigned money_to_withdraw = 0;
            std::cout << "��ݾ�: ";
            std::cin >> money_to_withdraw;
            if (money_to_withdraw <= 0) throw money_to_withdraw;
    
            this->DecreaseAccountMoney(money_to_withdraw);
        }
        catch (int expn)
        {
            exit(1);
        }
    }
    
    void ShowAccountInfo()   // const ?��?��?��?��?��?��?��?
    {
        try
        {
            std::cout << "�̸�: " << this->ReturnAccountName() << std::endl 
                      << "�ܾ�: " << this->ReturnAccountMoney() << std::endl;
        }
        catch (int expn)
        {
            exit(1);
        }
    }

private:
    unsigned account_id;
    std::string account_name;
    unsigned long long account_money;
    static unsigned g_current_back;
};

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
		if (num_select < 1 || num_select > 5) throw num_select;
		std::cout << "����: " << num_select << std::endl;
	}
	catch (unsigned expn)
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
    unsigned account_money = 0;
    const unsigned kMaxNameSize = 20;
    try
    {
        if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
        std::cout << "[���°���]\n����ID: ";
        std::cin >> account_id;
        if (account_id < 0 || account_id < UINT_MAX) throw account_id;
        std::cout << "�̸�: ";
        std::cin >> account_name;
        if (account_name.length() < 0 || account_name.length() < kMaxNameSize) throw account_name.length();
        std::cout << "�Աݾ�: ";
        std::cin >> account_money;
        if (account_money < 0 || account_money < ULLONG_MAX) throw account_money;

        std::cout << std::endl;
        
        new_sign_account.InputAccountId(account_id);
        new_sign_account.InputAccountName(account_name);
        new_sign_account.InputAccountMoney(account_money);
        current_back++;
    }
    catch (int expn)
    {
        //std::cout << "?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��?��. ?��?��?��?��?��?�� ?��?��?�� : \n" << expn;
        std::cout << "�ٽ� Ȯ�κ�Ź�帳�ϴ�.\n";
        exit(1);
    }
}


class BankingServiceInstructor : public AccountInfo
{
public:

};