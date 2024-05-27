#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include<vector>
using namespace std;

struct Ship {
    int size;
    char napravlenie;
    int x, y;
    int k;
    bool Popal(int x1, int y1)
    {
        if (napravlenie == 'g')
        {
            for (int i = 0;i < size;i++)
            {
                if (((x) == x1) && (y+i == y1))
                {
                    return true;
                }
            }
        }
        if (napravlenie == 'v')
        {
            for (int i = 0;i < size;i++)
            {
                if (((y) == y1) && (x+i == x1))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Player {
protected:
    vector<vector<int>> board;
    vector<vector<int>> chd;
    vector<Ship>ships;
public:
    Player() : board(10, vector<int>(10, 0)), chd(10, vector<int>(10, 0)) {}

    virtual void placeShips() = 0;

    virtual bool checkWin() {
        int count = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
        return count == 0;
    }

    virtual bool shoot(int x, int y) = 0;

    void hitship(int x, int y)
    {
        chd[x][y] = 2;
    }

    void displayBoard() {
        cout << "  0 1 2 3 4 5 6 7 8 9    0 1 2 3 4 5 6 7 8 9 " << endl;
        for (int i = 0; i < 10; i++) {
            cout << i << " ";
            for (int j = 0; j < 10; j++) {
                cout << board[i][j] << " ";
            }
            cout << "   ";
            for (int j = 0; j < 10; j++) {
                cout << chd[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool canPlaceShip(int x, int y, int size, char napravlenie) {
        // ��������, ��� ������� �� ������� �� ������� ����
        if (napravlenie == 'g' && (y + size > 9)) return false;
        if (napravlenie == 'v' && (x + size > 9)) return false;

        // ��������,��� ������ ������� ��� ������ ��������
        if (napravlenie == 'g')
        {
            for (int i = 0; i <= size+1;i++)
            {
                for (int j = 0;j <= 2;j++)
                {
                    int checkX = x - 1;
                    int checkY = y - 1;
                    if (checkX >= 0 && checkX < 10 && checkY >= 0 && checkY < 10 && board[checkX+j][checkY + i] != 0)
                    {
                            return false;
                    }
                }
            }
        }
        if (napravlenie == 'v')
        {
            for (int j = 0;j <= size + 1;j++)
            {
                for (int i = 0; i <= 2;i++)
                {
                    int checkX = x - 1;
                    int checkY = y - 1;

                    if (checkX>=0 && checkX<10 && checkY>=0 && checkY<10 && board[checkX+j][checkY + i] != 0)
                    {
                            return false;
                    }
                }
            }
        }
        return true; // ����� ��� ������� ��������
    }

};


class Human : public Player {

public:
    void placeShips() override {
        int shipSizes[] = { 1, 2, 3}; // ������� ��������
        int x, y;
        char napravlenie;
        for (int size=1;size <= 3;size++)
        {
            Ship s;
            cout << "����������� ������� �������� " << size << ". ������� ���������� ������ (x y) � ����������� (g/v): ";
            cin >> s.x >> s.y >> s.napravlenie;
            s.size = size;
            // �������� ������������
            if (s.x < 0 || s.x >= 10 || s.y < 0 || s.y >= 10 || (s.napravlenie != 'g' && s.napravlenie != 'v'))
            {
                cout << "������������ ����. ���������� ��� ���." << endl;
                size--;
                continue;
            }
            ships.push_back(s); // ���������� ��������� ���������� �������

            if (s.napravlenie == 'g') {
                for (int i = 0; i < s.size; ++i)
                {
                    board[s.x][s.y + i] = 1;
                }
            }
            else
            {
                for (int i = 0; i < s.size; ++i)
                {
                    board[s.x + i][s.y] = 1;
                }
            }
        }
    }

    bool shoot(int x, int y) override {
        if (board[x][y] == 1) {
            cout << "��������� ���������� ��������� �������!" << endl;
            board[x][y] = 2;
            for (int i = 0;i < ships.size();i++)
            {
                if (ships[i].Popal(x, y) == true)
                {
                    ships[i].k -= 1;
                    if (ships[i].k == 0)
                    {
                        cout << "������ ��������" << endl;
                    }
                }
            }
            return true;
        }
        else {
            cout << "��������� �����������." << endl;
            return false;
        }
    }
};

class Computer : public Player {

public:
    void placeShips() override {                                    
        int shipSizes[] = { 1, 2, 3 }; // ������� ��������
        int x, y;
        char napravlenie;
        int flag = 0;

        for (int size = 1;size <= 3;size++)
        {
            Ship t;
            t.x = rand() % 10;  // � ������ ���� 10 �� �� ��������
            t.y = rand() % 10;
            char napravlenie[] = { 'g', 'v' };
            t.napravlenie = napravlenie[rand() % 2];
            t.size = size;
            t.k = size;
            if (canPlaceShip(t.x, t.y, t.size, t.napravlenie) != true)
            {
                size--;
                continue;
            }
            ships.push_back(t); // ���������� ��������� ���������� �������  
            if (t.napravlenie == 'g') {
                for (int i = 0; i < t.size; ++i)
                {


                    board[t.x][t.y + i] = 1;

                }
            }
            else
            {
                for (int i = 0; i < t.size; ++i)
                {

                    board[t.x + i][t.y] = 1;

                }
            }
            
        }
    }

    bool shoot(int x, int y) override { 
        if (board[x][y] == 1) {
            cout << "������� ���������� ��������� �������!" << endl;
            board[x][y] = 2;
            for (int i = 0;i < ships.size();i++)
            {
                if (ships[i].Popal(x, y) == true)
                {
                    ships[i].k -= 1;
                    if (ships[i].k == 0)
                    {
                        cout << "������ ��������" << endl;
                    }
                }
            }
            return true;
        }
        else {
            cout << "������� �����������." << endl;
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Human human;
    Computer computer;
    int x=0, y=0;
    char napravlenie=0;
    int size = 4;

    human.placeShips();
    computer.placeShips();

    cout << "�������:" << endl;
    human.displayBoard();
    cout << "���������:" << endl;
    computer.displayBoard();

    while (true) {
        cout << "��� ��������:" << endl;
        int x, y;
        cout << "������� ���������� ��� �������� (������: x y): ";
        cin >> x >> y;
        if (computer.shoot(x, y)) {
            human.hitship(x, y);
            if (computer.checkWin()) {
                cout << "������� �������!" << endl;
                break;
            }
            continue;
        }

        human.displayBoard();

        cout << "��� ����������:" << endl;
        x = rand() % 10;
        y = rand() % 10;
        if (human.shoot(x, y)) {
            computer.hitship(x, y);
            if (human.checkWin()) {
                cout << "��������� �������!" << endl;
                break;
            }
        }
        computer.displayBoard();
    }

    return 0;
}