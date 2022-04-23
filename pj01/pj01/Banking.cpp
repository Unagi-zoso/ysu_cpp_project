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
		"1. ���°���\n"
		"2. �� ��\n"
		"3. �� ��\n"
		"4. �������� ��ü ���\n"
		"5. ���α׷� ����\n";
}
void select_menu_num(unsigned & num_select)
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

void sign_in_account(std::vector<Account>& account_list, unsigned current_back)
{
	unsigned& account_id = account_list.at(current_back).account_id;
	std::string& account_name = account_list.at(current_back).account_name;
	unsigned long long& account_money = account_list.at(current_back).account_money;
	unsigned name_leng = 8;

	try
	{
		if (current_back < 0 || current_back >= UINT_MAX) throw current_back;
		std::cout << "[���°���]\n����ID: ";
		std::cin >> account_id;
		if (account_id < 0 || account_id < UINT_MAX) throw account_id;
		std::cout << "�̸�: ";
		std::cin >> account_name;
		if (account_name.length() < 0 || account_name.length() < name_leng) throw account_name.length();
		std::cout << "�Աݾ�: ";
		std::cin >> account_money;
		if (account_money < 0 || account_money < ULLONG_MAX) throw account_money;

		std::cout << std::endl;

		account_list.at(current_back).account_idx = current_back;
		current_back++;
	}
	catch (int expn)
	{
		//std::cout << "�ִ� �������� �����Ͽ����ϴ�. ���� �� : \n" << expn;
		std::cout << "�ٽ� Ȯ�κ�Ź�帳�ϴ�.\n";
		exit(1);
	}
}

void deposit_account(std::vector<Account>& account_list)
{
	try
	{
		unsigned id_match = 0;
		unsigned long long money_to_deposit = 0;
		std::cout << "[��   ��]\n����ID : ";
		std::cin >> id_match;
		std::cout << "�Աݾ�: ";
		std::cin >> money_to_deposit;
		if (money_to_deposit <= 0 || money_to_deposit > ULLONG_MAX) throw money_to_deposit;

		Account& account_present = match_id(account_list, id_match);
		std::cout << &account_present;
		if (money_to_deposit > ULLONG_MAX - account_present.account_money) throw money_to_deposit;
		account_present.account_money += money_to_deposit;
	}
	catch (int expn)
	{
		"��ȣ�� �߸� �����̽��ϴ�.\n";
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

		std::cout << "[��   ��]\n����ID : ";
		std::cin >> id_match;
		std::cout << "��ݾ�: ";
		std::cin >> money_to_withdraw;
		if (money_to_withdraw <= 0) throw money_to_withdraw;

		Account& account_present = match_id(account_list, id_match);
		if (account_present.account_money < money_to_withdraw) throw money_to_withdraw;
		account_present.account_money -= money_to_withdraw;
	}
	catch (int expn)
	{
		"��ȣ�� �߸� �����̽��ϴ�.\n";
		exit(1);
	}
}

void show_account_info(std::vector<Account>& account_list)
{
	try
	{
		unsigned id_match = 0;
		std::cout << "����ID : ";
		std::cin >> id_match;


		Account& account_present = match_id(account_list, id_match);
		std::cout << "�̸�: " << account_present.account_name << std::endl <<
			"�ܾ�: " << account_present.account_money << std::endl;
	}
	catch (int expn)
	{
		"ID�� �ٽ� Ȯ�� ��Ź�帳�ϴ�.\n";
		exit(1);
	}
	
}