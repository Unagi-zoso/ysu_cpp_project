#include <iostream>
#include <string>
#include <vector>
#include "Banking.h"

int main()
{
	std::vector<Account> account_list(100);
	unsigned current_back = 0;
	unsigned num_select = 0;

	while (1)
	{
		view_menu();
		select_menu_num(num_select);
		
		switch (num_select)
		{
		case SIGNIN : 
			sign_in_account(account_list, current_back);
			break;
		case DEPOSIT:
			deposit_account(account_list);
			break;
		case WITHDRAW:
			withdraw_account(account_list);
			break;
		case SHOWINF:
			show_account_info(account_list);
			break;
		case EXIT:
			return 0;
		default:
			break;
		} 
	}
	
	return 0;
}

