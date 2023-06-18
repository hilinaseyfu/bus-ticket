/* dear mr.yasabneh this is our project sorry for our late. the passcode is 2121.
group members are hilina seyfu,hana abayneh,hewan solomon,frehiwot wendimagegn,helen ayen.
thank you*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int i = 0;
string passcode = "2121";

int  psg;
double allsell;

struct bus {

	char from[20], to[20], psgname[99];
	double arv, busn, dprt, tseat, s;

	void install();
	void Aveliable_Bus();
	void book();
	void st();
	void dt();
	void resv();
	void sr();
	void dr();
	void exit();

}b[100];

void bus::install()
{
	ofstream busdata;
	busdata.open("bus_data.txt");

	cout << endl << "---------------------------------------" << endl;
	cout << "\nEnter Bus No: "; cin >> busn;
	cout << "\nLocation From: "; cin >> from;
	cout << "\nLocation To: "; cin >> to;
	cout << "\nDeparture: "; cin >> dprt;
	cout << "\nExpected Arriving Time: "; cin >> arv;
	cout << "\nTotal seats: "; cin >> tseat;


	busdata << "\nBus No - ";
	busdata << b[i].busn << endl;
	busdata << "\nLocation From - " << from << endl;
	busdata << "Location To - " << to << endl;
	busdata << "Departure Time - " << dprt << endl;
	busdata << "Expected Arriving Time - " << arv << endl;
	busdata << "Total seats - " << tseat << endl << endl;

	busdata.close();

	psg++;
	cout << "\n\n    |+++++ Bus Information Added +++++|\n\n" << endl;

	system("PAUSE");
	system("CLS");
}

void bus::Aveliable_Bus()
{
	ifstream avdata;
	avdata.open("bus_data.txt");
	string line;

	cout << endl << "\t Total Bus Available " << endl;
	cout << "###==================================###" << endl;

	while (getline(avdata, line)) {
		cout << line << endl;
	}
		avdata.close();
	
	system("PAUSE");
	system("CLS");
}

void bus::book()
{
	cout << endl << " --------------------------------------" << endl;
	cout << "\n\t   1. Single Trip" << endl;
	cout << "\t   2. Double Trip" << endl;
	cout << endl << " --------------------------------------" << endl;
	cout << "\n Choose Trip: ";

}

void bus::st()
{
	ofstream singl;
	singl.open("single_trip.txt");
	int num;
	float fee;

	ifstream sin;
	sin.open("bus_data.txt");

	cout << "\nEnter Bus No: ";
	cin >> num;

	for (int i = 0; i < psg; i++)
	{
		if (num == b[i].busn)
		{
			if (b[i].tseat <= 0)
			{
				cout << "\tSORRY!" << endl << "\tNo  Seat Available\t";
			}
			else
			{
				cout << endl << "Total seat available: " << b[i].tseat << endl;
				cout << endl << "Enter Passenger's Name: "; cin >> psgname;
				cout << endl << "Dear " << psgname << " Please Enter Your Phone Number : "; cin >> num;
				cout << endl << psgname << " How many seats did you want: "; cin >> s;

				singl << endl << "Passenger Name: " << psgname << endl;
				singl << "Passenger Phone_Number: " << "0" << num << endl;

				while ((b[i].tseat = b[i].tseat - s) < 0) {
					cout << endl << "Limit Exceed...Please re-enter ";
					b[i].tseat = b[i].tseat + s;
					cin >> s;
				}
				cout << endl << " ----------------------------------------------" << endl;
				cout << endl << "Dear " << psgname << " your purchase is Successfully complete" << endl;
				cout << "==================================================" << endl;
				cout << "\nBus No. : " << b[i].busn << endl;
				cout << "\nLocation From: " << b[i].from << endl;
				cout << "Location To: " << b[i].to << endl;
				cout << "Departure Time: " << b[i].dprt << " O'clock" << endl;
				cout << "Expected Arriving Time: " << b[i].arv << " O'clock" << endl;
				cout << "Total seat: " << s << endl;
				fee = 200 * s;
				fee = fee + (fee * .7);
				allsell = allsell + fee;
				cout << "Total Fee: " << fee << endl;
				cout << "\n==================================================" << endl;
				cout << "Thank You" << endl << endl;

				singl << endl << "_______________ Reservation _______________" << endl;
				singl << "\nBus No: " << b[i].busn << endl << endl;
				singl << "Location From: " << b[i].from << endl;
				singl << "Location To: " << b[i].to << endl;
				singl << "Departure: " << b[i].dprt << " O'clock" << endl;
				singl << "Expected Arriving Time: " << b[i].arv << " O'clock" << endl;
				singl << "Total seat: " << s << endl;
				singl << "Total Fee: " << fee << endl;
				singl << endl << "__________ Successfully Completed __________" << endl << endl;

				singl.close();

			}
		}
	}
	system("PAUSE");
	system("CLS");
}

void bus::dt()
{
	ofstream doubl;
	doubl.open("double_trip.txt");

	int num, rd, rm, ry;
	float fee;

	cout << "\nEnter Bus No: ";
	cin >> num;
	int i;

	for (i = 0; i < psg; i++)
	{
		if (b[i].busn == num)
		{
			if (b[i].tseat <= 0)
			{
				cout << "\tSORRY!" << endl << "\tNo  Seat Available\t";
			}
			else
			{
				cout << endl << "Total seat available: " << b[i].tseat << endl;
				cout << endl << "Enter Passenger's Name: "; cin >> psgname;
				cout << endl << "Dear " << psgname << " Please Enter Your Phone Number : "; cin >> num;
				cout << endl << psgname << " How many seats did you want: "; cin >> s;
				cout << endl << "Return date: "; cin >> rd >> rm >> ry;

				doubl << endl << "Passenger Name: " << psgname << endl;
				doubl << "Passenger Phone_Number: " << "0" << num << endl;

				while ((b[i].tseat = b[i].tseat - s) < 0) {
					cout << endl << "Limit Exceed...Please re-enter ";
					b[i].tseat = b[i].tseat + s;
					cin >> s;
				}
				cout << endl << " --------------------------------------------" << endl;
				cout << endl << "Dear " << psgname << " your purchase is Successfully complete" << endl;
				cout << "==================================================" << endl;
				cout << "\nBus No. : " << b[i].busn << endl;
				cout << "\nLocation From: " << b[i].from << endl;
				cout << "Location To: " << b[i].to << endl;
				cout << "Departure: " << b[i].dprt << " O'clock" << endl;
				cout << "Expected Arriving Time: " << b[i].arv << " O'clock" << endl;
				cout << "Returning date : " << rd << "/ " << rm << "/ " << ry << endl;

				cout << "Total seat: " << s << endl;
				fee = (200 * 2) * s;
				fee = fee + (fee * .3);
				allsell = allsell + fee;
				cout << "Total Fee: " << fee << endl;
				cout << "\n==================================================" << endl;
				cout << "Thank You" << endl << endl;

				doubl << endl << "_______________ Reservation _______________" << endl;
				doubl << "\nBus No: " << b[i].busn << endl << endl;
				doubl << "Location From: " << b[i].from << endl;
				doubl << "Location To: " << b[i].to << endl;
				doubl << "Departure: " << b[i].dprt << " O'clock" << endl;
				doubl << "Expected Arriving Time: " << b[i].arv << " O'clock" << endl;
				doubl << "Returning date will be: " << rd << "/ " << rm << "/ " << ry << endl;
				doubl << "Total seat: " << s << endl;
				doubl << "Total Fee: " << fee << endl;
				doubl << endl << "__________ Successfully Completed __________" << endl << endl;

				doubl.close();
			}
		}
	}
	system("PAUSE");
	system("CLS");
}

void bus::resv() {
	cout << endl << " --------------------------------------" << endl;
	cout << "\n   1. Single Trip Reservation info_" << endl;
	cout << "   2. Double Trip Reservation info_" << endl;
	cout << endl << " --------------------------------------" << endl;
	cout << "\n Choose : ";

}

void bus::sr() 
{
	ifstream stinfo;
	stinfo.open("single_trip.txt");
	string line1;

	while (getline(stinfo, line1)) {
		cout << line1 << endl;
	}
	stinfo.close();

	system("PAUSE");
	system("CLS");
}

void bus::dr()
{
	ifstream dtinfo;
	dtinfo.open("double_trip.txt");
	string line2;

	while (getline(dtinfo, line2)) {
		cout << line2 << endl;
	}
	dtinfo.close();

	system("PAUSE");
	system("CLS");
}

void bus::exit(void)
{
	cout << endl << " --------------------------------------" << endl;
	cout << "|*    Thank you for using our system   *|" << endl;
	cout << " --------------------------------------" << endl;
}

int main()
{
	string pcode;
	int w, g = 1;
	int trip;

line1:
	cout << "\n\n\t #####  Passcode Required  ##### " << endl;
	cout << "\n\n\t Enter Passcode: ";
	cin >> pcode;
	cout << "\n\n";

	if (pcode == passcode) {

	line:
		do
		{
			cout << "==================================================" << endl;
			cout << "\t\tBus Ticketing System\n";
			cout << "==================================================" << endl;

			cout << "\n\t 1 -> Register bus" << endl;
			cout << "\t 2 -> Available Bus List" << endl;
			cout << "\t 3 -> Book Ticket" << endl;
			cout << "\t 4 -> Reservation Information" << endl;
			cout << "\t 5 -> Exit" << endl;
			cout << "\n\n\t Enter your choice: ";
			cin >> w;

			switch (w) {

			case 1:
				b[psg].install();
				break;
			case 2:
				b[0].Aveliable_Bus();
				break;
			case 3:
				b[psg].book();
				do
				{
					cin >> trip;
					switch (trip)
					{
					case 1:
						b[psg].st();
						break;
					case 2:
						b[psg].dt();
						break;
					default:
						cout << "\t\n!!!Invalid choice!!!\n\n";

						system("PAUSE");
						system("CLS");
					}
					goto line;
				} while (g != 0);

			case 4:
				b[psg].resv();
				do
				{
					cin >> trip;
					switch (trip)
					{
					case 1:
						b[psg].sr();
						break;
					case 2:
						b[psg].dr();
						break;
					default:
						cout << "\t\n!!!Invalid choice!!!\n\n";

						system("PAUSE");
						system("CLS");
					}
					goto line;
				} while (g != 0);

			case 5:
				b[0].exit();
				{
					g = 0;
					cout << endl << "Total Sales = " << allsell << endl;
					cout << endl << " *********** End Of Program ***********" << endl << endl;
					break;
				}
			default:
				cout << "\t\n!!!Invalid choice!!!\n \tTry again\n";

				system("PAUSE");
				system("CLS");
			}
		} while (g != 0);
	}
	else {
		while (pcode != passcode)
		{
			cout << "\n\t\t\t *****  Passcode Is Incorect  ***** " << endl;
			cout << "\n\t\t\t Please Try Again..... " << "\n\n";
			goto line1;
		}
	}
	return 0;
}
