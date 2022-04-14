#include <iostream>
#include <vector>
#include <string>
#include "Banking.h"

Account& match_id(std::vector<Account> & account_list, unsigned id_match)
{
	for (Account& id_list : account_list) 
	{
		if (id_list.account_id == id_match)	return id_list;

	}
	std::cout << "please restart\n";
}

void view_menu()
{
	std::cout <<
		"-----Menu-----\n"
		"1. 계좌개설\n"
		"2. 입 금\n"
		"3. 출 금\n"
		"4. 계좌정보 전체 출력\n"
		"5. 프로그램 종료\n";
}

void select_menu_num(unsigned & num_select)
{
	std::cin >> num_select;
	std::cout << "선택: " << num_select << std::endl;
}

void sign_in_account(std::vector<Account>& account_list, unsigned current_back)
{
	std::cout << "[계좌개설]\n계좌ID: ";
	std::cin >> account_list.at(current_back).account_id;
	std::cout << "이름: ";
	std::cin >> account_list.at(current_back).account_name;
	std::cout << "입금액: ";
	std::cin >> account_list.at(current_back).account_money;
	std::cout << std::endl;

	account_list.at(current_back).account_idx = current_back;
	current_back++;
}

void deposit_account(std::vector<Account>& account_list)
{
	unsigned id_match = 0;
	unsigned long long money_to_deposit = 0;
	std::cout << "[입   금]\n계좌ID : ";
	std::cin >> id_match;
	std::cout << "입금액: ";
	std::cin >> money_to_deposit;

	Account& account_present = match_id(account_list, id_match);
	std::cout << &account_present;
	account_present.account_money += money_to_deposit;
}

void withdraw_account(std::vector<Account>& account_list)
{
	unsigned id_match = 0;
	unsigned match_idx = 0;
	unsigned money_to_withdraw = 0;
	std::cout << "[출   금]\n계좌ID : ";
	std::cin >> id_match;
	std::cout << "출금액: ";
	std::cin >> money_to_withdraw;

	Account& account_present = match_id(account_list, id_match);
	account_present.account_money -= money_to_withdraw;
}

void show_account_info(std::vector<Account>& account_list)
{
	unsigned id_match = 0;
	std::cout << "계좌ID : ";
	std::cin >> id_match;
	

	Account& account_present = match_id(account_list, id_match);
	std::cout << "이름: " << account_present.account_name << std::endl <<
			"잔액: " << account_present.account_money << std::endl;
	
}