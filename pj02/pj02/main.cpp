#include "banking.hpp"


int main()
{
	std::vector<AccountInfo> account_list(100);
	unsigned num_select = 0;
	unsigned current_back = 0;

	while (1)
	{
		ViewMenu();
		SelectMenuNum(num_select);
		
		switch (num_select)
		{
		case ksign: 
		//	SignInAccount(account_list, current_back);
       		account_list.at(current_back) = AccountInfo(current_back);
			break;
		case kDeposit:
            BankingServiceInstructor::MatchId(account_list, BankingServiceInstructor::GetId()).DepositAccount();
			break;
		case kWithdraw:
            BankingServiceInstructor::MatchId(account_list, BankingServiceInstructor::GetId()).WithdrawAccount();
			break;
		case kShow_All:
			//ShowAccountInfo(account_list);
            BankingServiceInstructor::MatchId(account_list, BankingServiceInstructor::GetId()).ShowAccountInfo();
			break;
		case kExit:
			return 0;
		default:
			break;
		} 
	}
	
	return 0;
}










