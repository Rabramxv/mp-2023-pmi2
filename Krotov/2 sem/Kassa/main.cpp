#include<iostream>
#include"kassa.h"
#include<string>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	Check ch1;
	Sklad s;
	string name;
	int kollichestvo;
	int size;
	s.assortiment();
	cout << "------------------------------" << endl;
	ch1.parser(s);
	/*
	cout << "������� ������� ����� ������ �������� ������������" << endl;
	cin >> size;
	cout << "������� �������� ������ � ��� ����������: " << endl;
	for (int i = 0;i < size;i++)
	{
		cin >> name >> kollichestvo;
		ch1.AddTovar(name, s,kollichestvo);
	}
	*/
	cout << ch1;
	int yes_no1;
	cout << "�� ������ ������� �����? �� - 1, ��� - 0" << endl; cin >> yes_no1;
	if (yes_no1 == 1)
	{
		cout << "������� �������� � ������� ���� ������, ������� ������ ������" << endl;
		cin >> name >> kollichestvo;
		ch1.Delete_tovar(name, s, kollichestvo);
		cout << ch1;
	}
	int yes_no2;
	cout << "������������� ������ �� ����?" << endl; cin >> yes_no2;
	if (yes_no2 == 1)
	{
		ch1.sort_ch();
		cout << ch1;
	}
	cout << "��� ���:" << endl;
	ch1.vuvod(ch1);
	//	cout << "����� ����� �������: " << ch1.summ_sh() << endl;
}