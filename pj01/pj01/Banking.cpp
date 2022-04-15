#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include "Banking.h"


Account& match_id(std::vector<Account> & account_list, unsigned id_match)
{
	for (Account& id_list : account_list)
	{
		if (id_list.account_id == id_match)	return id_list;
	}
	std::cout << "please restart\n";
	exit(1);
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

void sign_in_account(std::vector<Account>& account_list, unsigned current_back)
{
	unsigned& account_id = account_list.at(current_back).account_id;
	std::string& account_name = account_list.at(current_back).account_name;
	unsigned long long& account_money = account_list.at(current_back).account_money;
	unsigned name_leng = 8;

	try
	{
		if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
		std::cout << "[계좌개설]\n계좌ID: ";
		std::cin >> account_id;
		if (account_id < 0 || account_id < UINT_MAX) throw account_id;
		std::cout << "이름: ";
		std::cin >> account_name;
		if (account_name.length() < 0 || account_name.length() < name_leng) throw account_name.length();
		std::cout << "입금액: ";
		std::cin >> account_money;
		if (account_money < 0 || account_money < ULLONG_MAX) throw account_money;

		std::cout << std::endl;

		account_list.at(current_back).account_idx = current_back;
		current_back++;
	}
	catch (int expn)
	{
		//std::cout << "최대 개설량에 도달하였습니다. 현재 수 : \n" << expn;
		std::cout << "다시 확인부탁드립니다.\n";
		exit(1);
	}
}

void deposit_account(std::vector<Account>& account_list)
{
	try
	{
		unsigned id_match = 0;
		unsigned long long money_to_deposit = 0;
		std::cout << "[입   금]\n계좌ID : ";
		std::cin >> id_match;
		std::cout << "입금액: ";
		std::cin >> money_to_deposit;
		if (money_to_deposit <= 0 || money_to_deposit > ULLONG_MAX) throw money_to_deposit;

		Account& account_present = match_id(account_list, id_match);
		std::cout << &account_present;
		if (money_to_deposit > ULLONG_MAX - account_present.account_money) throw money_to_deposit;
		account_present.account_money += money_to_deposit;
	}
	catch (int expn)
	{
		"번호를 잘못 적으셨습니다.\n";
		exit(1);
	}
}

void withdraw_account(std::vector<Account>& account_list)
{
	try
	{
		unsigned id_match = 0;
		unsigned match_idx = 0;
		unsigned money_to_withdraw = 0;

		std::cout << "[출   금]\n계좌ID : ";
		std::cin >> id_match;
		std::cout << "출금액: ";
		std::cin >> money_to_withdraw;
		if (money_to_withdraw <= 0) throw money_to_withdraw;

		Account& account_present = match_id(account_list, id_match);
		if (account_present.account_money < money_to_withdraw) throw money_to_withdraw;
		account_present.account_money -= money_to_withdraw;
	}
	catch (int expn)
	{
		"번호를 잘못 적으셨습니다.\n";
		exit(1);
	}
}

void show_account_info(std::vector<Account>& account_list)
{
	try
	{
		unsigned id_match = 0;
		std::cout << "계좌ID : ";
		std::cin >> id_match;


		Account& account_present = match_id(account_list, id_match);
		std::cout << "이름: " << account_present.account_name << std::endl <<
			"잔액: " << account_present.account_money << std::endl;
	}
	catch (int expn)
	{
		"ID를 다시 확인 부탁드립니다.\n";
		exit(1);
	}
	
}