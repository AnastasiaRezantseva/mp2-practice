//main

#include "ScanTable.h"
#include "TArrayHash.h"
#include "Polynom.h"
#include "SortTable.h"

void main()
{

	//ScanTable<std::string, Polynom> S(5);
	//string K1 = "3";
	//string K2 = "2";
	//Polynom Q("2x-xyz");
	//Polynom Z("3x^2+5");
	//S.InsRecord(K1,Q);
	//S.InsRecord(K2, Z);
	//cout << S;

	//TArrayHash<std::string, double> TH(3);
	//TH.InsRecord("1", 2);
	//TH.InsRecord("2", 8);
	//TH.InsRecord("4", 12);
	//cout << TH;

	//TArrayHash<std::string, double> S(5);
	//string K2 = "1";
	//S.InsRecord(K2, 7.89);
	//S.InsRecord("2", 10.51);
	//S.InsRecord("3", 51.25);
	//S.InsRecord("34", 5541.25);
	//cout << S << endl;
	//S.DelRecord("3");
	//cout << S<<endl;
	//cout << *(S.FindRecord("2"));

	//cout << endl<<"_________________" << endl;
	//TArrayHash<std::string, double> SS(S);
	//S.DelRecord("34");
	////S.InsRecord("82", 150.51);
	////S.InsRecord("35", 551.25);
	//cout << SS;

	ScanTable<std::string, double> S(10);
	string K2 = "1";


	//cout << stoi(K2)<<endl;
	S.InsRecord("2", 10.51);
	S.InsRecord("3", 51.25);
	S.InsRecord(K2, 7.89);
	S.InsRecord("9", 51.25);
	S.InsRecord("568", 5.25);
	S.InsRecord("6", 5.3);
	S.InsRecord("10", 9.1);
	S.InsRecord("5", 1.1);
	//S.DelRecord("3");
	cout << S << endl;

	SortTable<std::string, double> SS(S);
	cout << SS;
	cout << "DFDSFSDF";
	//cout << "---------------> Liveeee" << endl;
	//cout << S;
	//cout << SS;
	//cout << "---------------> Liveeee" << endl<<endl<<endl;
	//SS.DelRecord("1");
	//cout << S;
	//cout << SS;





	//TArrayHash<std::string, double> S(3);

	//S.InsRecord("1", 2);
	//S.InsRecord("9", 8);
	//S.InsRecord("4", 12);
	//cout << S;
}