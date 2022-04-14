#include <iostream>
#include <vector>
#include <string>
#pragma once
enum num_select { SIGNIN = 1, DEPOSIT, WITHDRAW, SHOWINF, EXIT };

typedef struct Account_info
{
	unsigned account_id = 0;
	std::string account_name = {};
	unsigned long long account_money = 0;
	unsigned account_idx = 99999;
} Account;

Account& match_id(const std::vector<Account>& account_list, unsigned id_match);

void view_menu();

void select_menu_num(unsigned& num_select);

void sign_in_account(std::vector<Account>& account_list, unsigned current_back);

void deposit_account(std::vector<Account>& account_list);

void withdraw_account(std::vector<Account>& account_list);

void show_account_info(std::vector<Account>& account_list);