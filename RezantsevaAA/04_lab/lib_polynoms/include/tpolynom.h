#ifndef __TPOLYNOM_H__
#define __TPOLYNOM_H__

#include "tringlist.h"
#include "tmonom.h"
#include <string>
class TPolinom {

private: 
	TRingList<TMonom> monoms;
	std::string formula;
	std::map<char, double> uniques;
	void sumEqual();
	void deleteZero();
	void Sort();

	bool isMonomOperator(char op) const;
	bool isSeparator(char op) const;
	bool isOperator(char op) const;
	bool isVariable(char var) const;
	void fillUniques(const std::string& f);
	
	void getListOfMonoms(const std::string& input);
	double getCoeff(const std::string& input, int& pos);
	void updateDegree(int& degree, char variable, int degreeOfVar);

	void fillVariables(); // ��������� ���������� ��� ����������
	double getValue(const char& variable);  // ������ �������� ��� ���� ����������
public: 
	TPolinom();
	TPolinom(const string& stringPolynom);
	TPolinom(const TRingList<TMonom>& m); 
	TPolinom(const TPolinom& p);
	~TPolinom();
	std::string getStringMonoms() const;
	std::string getFormula() const;

	TPolinom operator+(const TPolinom& p);
	TPolinom operator-(const TPolinom& p);
	TPolinom operator*(const TPolinom& p); 
	TPolinom operator*(const double c); //�������� �������� �� �����

	const TPolinom& operator=(const TPolinom& p);
	
	TPolinom defX() const; //����������� �� x
	TPolinom defY() const; //����������� �� y
	TPolinom defZ() const; //����������� �� z
	double calculate();
	friend std::ostream& operator<<(std::ostream& out,TPolinom& p);
};
#endif
