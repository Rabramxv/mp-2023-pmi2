#include <iostream>

class Field {
private:
	char** field;
	int n, m;
public:
	//Field();
	Field(int n_ = 1, int m_ = 1);
	~Field();

	void FieldZeroFill();	
	void FieldCompFill(char** field);
	void FieldPlayerFill();
	void fieldOut();
};

// �������� ������������ �������� �������
// ������� �������� ���������
// ������� ��������� �������� ������
// ������� ���� � ������������ �������� � ������� �� �� -
// �������� ������� ��������
// ������� ���� ����������
// ��� ��������� ������������ �����?
// 
//