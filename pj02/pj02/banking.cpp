#include "banking.hpp"

// AccountInfo::AccountInfo() {};
AccountInfo::AccountInfo(unsigned& current_back)
{
    unsigned account_id = 0;
    std::string account_name = {};
    unsigned long long account_money = 0;
    const unsigned kMaxNameSize = 20;
    try
    {
        if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
        std::cout << "[계좌개설]\n계좌ID: ";
        std::cin >> account_id;
        if (account_id < 0 || account_id > UINT_MAX) throw account_id;
        std::cout << "이름: ";
        std::cin >> account_name;
        if (account_name.length() < 0 || account_name.length() > kMaxNameSize) throw account_name.length();
        std::cout << "입금액: ";
        std::cin >> account_money;
        if (account_money < 0 || account_money > ULLONG_MAX) throw account_money;

        std::cout << std::endl;
        
        this->InputAccountId(account_id);
        this->InputAccountName(account_name);
        this->InputAccountMoney(account_money);
        current_back++;
    }
    catch (int expn)
    {
        std::cout << "다시 확인부탁드립니다.\n";
        exit(1);
    } 
}

AccountInfo::~AccountInfo() {};

unsigned AccountInfo::ReturnAccountId() const {return account_id;}
std::string AccountInfo::ReturnAccountName() const {return account_name;}
unsigned long long AccountInfo::ReturnAccountMoney() const {return account_money;}
void AccountInfo::InputAccountId(unsigned &account_id_input) {account_id = account_id_input;}
void AccountInfo::InputAccountName(std::string& account_name_input) {account_name = std::move(account_name_input);}
void AccountInfo::InputAccountMoney(unsigned long long& account_money_input) {account_money = account_money_input;}

void AccountInfo::IncreaseAccountMoney(unsigned long long& money_to_increase)
{
    
    if (money_to_increase > ULLONG_MAX - account_money) throw money_to_increase;
    account_money += money_to_increase;
} 

void AccountInfo::DecreaseAccountMoney(unsigned long long& money_to_decrease)
{
    if (money_to_decrease > account_money) throw money_to_decrease;
    account_money -= money_to_decrease;
}

AccountInfo& AccountInfo::MatchId(std::vector<AccountInfo> & account_list, unsigned id_match)
{
    for (AccountInfo& id_list : account_list)
    {
        if (id_list.ReturnAccountId() == id_match)	return id_list;
    }
    std::cout << "please restart\n";
    exit(1);
}

unsigned AccountInfo::GetId()
{
    unsigned id_match = {};
    std::cout << "계좌ID : ";
    std::cin >> id_match;

    return id_match; // RVO
}

void AccountInfo::DepositAccount()
{
    try
    {
        unsigned long long money_to_deposit = 0;
        std::cout << "입금액: ";
        std::cin >> money_to_deposit;
        if (money_to_deposit <= 0 || money_to_deposit > ULLONG_MAX) throw money_to_deposit;

        this->IncreaseAccountMoney(money_to_deposit);
    }
    catch (int expn)
    {
        std::cout << "번호를 잘못 적으셨습니다.\n";
        exit(1);
    }
}

void AccountInfo::WithdrawAccount()
{
    try
    {
        unsigned long long money_to_withdraw = 0;
        std::cout << "출금액: ";
        std::cin >> money_to_withdraw;
        if (money_to_withdraw <= 0) throw money_to_withdraw;

        this->DecreaseAccountMoney(money_to_withdraw);
    }
    catch (int expn)
    {
        exit(1);
    }
}

void AccountInfo::ShowAccountInfo() const 
{
    try
    {
        std::cout << "이름: " << this->ReturnAccountName() << std::endl 
                  << "잔액: " << this->ReturnAccountMoney() << std::endl;
    }
    catch (int expn)
    {
        exit(1);
    }
}

void ViewMenu()
{
    std::cout <<
        "-----Menu-----\n"
        "1. 계좌개설\n"
        "2. 입 금\n"
        "3. 출 금\n"
        "4. 계좌정보 전체 출력\n"
        "5. 프로그램 종료\n";
}

void SelectMenuNum(unsigned & num_select)
{
    try
    {
        std::cin >> num_select;
        if (num_select < 1 || num_select > 5) throw num_select;
        std::cout << "선택: " << num_select << std::endl;
    }
    catch (unsigned expn)
    {
        std::cout << "번호를 잘못 적으셨습니다.\n";
        exit(1);
    }
}

void SignInAccount(std::vector<AccountInfo>& account_list, unsigned& current_back)
{
    AccountInfo& new_sign_account = account_list.at(current_back);
    unsigned account_id = 0;
    std::string account_name = {};
    unsigned long long account_money = 0;
    const unsigned kMaxNameSize = 20;
    try
    {
        if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
        std::cout << "[계좌개설]\n계좌ID: ";
        std::cin >> account_id;
        if (account_id < 0 || account_id < UINT_MAX) throw account_id;
        std::cout << "이름: ";
        std::cin >> account_name;
        if (account_name.length() < 0 || account_name.length() < kMaxNameSize) throw account_name.length();
        std::cout << "입금액: ";
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
    
        std::cout << "다시 확인부탁드립니다.\n";
        exit(1);
    }
}