

#include <iostream>
#include "clsQueueLine.h"
using namespace std;
int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintAllTickets();

	cout << "After Serving one Client \n\n";
	PayBillsQueue.ServeNextClient();

	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintAllTickets();

}

