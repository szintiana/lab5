#include <iostream>

#include <iostream>
#include "admin.h"
#include "admin_ctrl.h"
#include "client.h"
#include "client_ctrl.h"
#include "menu.h"


using namespace std;

int menu(Repository a, Client c)
{
	Admincontrol ac = Admincontrol(a);
	Clientcontrol cc = Clientcontrol(c);
	int option;
	bool on = true;
	while (on)
	{
		cout << endl;
		cout << "1. administrator\n";
		cout << "2. user\n";
		cout << "3. exit\n";

		cin >> option;

		cout << endl;

		if (option == 1)
		{
			bool admin_on = true;
			int adminoption;
			while (admin_on)
			{
				cout << endl;
				cout << "1. all films\n";
				cout << "2. add\n";
				cout << "3. remove\n";
				cout << "4. update\n";
				cout << "5. exit";

				cin >> adminoption;

				cout << endl;

				if (adminoption == 1)
				{
					ac.printAdminGetlist();
				}
				if (adminoption == 2)
				{
					Film newfilm;
					newfilm.set_titel("random");
					ac.printAdminAdd(newfilm);
				}
				if (adminoption == 3)
				{
					Film target = a.getlist()[0];
					ac.printAdminRemove(target);
				}
				if (adminoption == 4)
				{
					Film target = a.getlist()[0];
					Film newfilm;
					newfilm.set_titel("Updated");
					ac.printAdminUpdate(target, newfilm);
				}
				if (adminoption == 5)
					cout << "back to main\n";
				admin_on = false;
				break;
			}

		}
		if (option == 2)
		{
			bool client_on = true;
			int clientoption;
			while (client_on)
			{
				cout << "\n";
				cout << "1. trailer";
				cout << "2. add to watchlist\n";
				cout << "3. remove from watchlist\n";
				cout << "4. rate\n";
				cout << "5. exit";
				cin >> clientoption;
				cout << endl;
				if (clientoption == 1)
				{
					Film film;
				}
				if (clientoption == 2)
				{
					Film newfilm;
					c.add(newfilm);
				}
				if (clientoption == 3)
				{
					Film target;
					c.remove(target);
				}
				if (clientoption == 4)
				{
					Film target;
					int i;
					cout << "rating: \n";
					cin >> i;
					vector<Film> v = c.opinion(target, i).getlist();
				}
				if (clientoption == 5)
				{
					cout << "back to main\n";
					client_on = false;
				}
			}
		}
		if (option == 3)
		{
			on = false;
		}
	}
	return 0;
}