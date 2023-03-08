#include "iostream"
#include <math.h>
#include <string>
using namespace std;

class TableTest
{
public:
    TableTest()//����������� �� �������������
    {
        rows = 1;
        cols = 1;
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }
    TableTest(int r, int c) //����������� � �����������
    {
        rows = r;
        cols = c;
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~TableTest() { // ����������
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    bool operator == (const TableTest& other) {//������������
        return data == other.data;
    }

    int getRows() const { // �������� ������� �����
        return rows;
    }

    int getCols() const { // �������� ������� ��������
        return cols;
    }

    void setData(int row, int col, int value) { // ���������� ��������
        data[row][col] = value;
    }

    int getData(int row, int col) const { // �������� ��������
        return data[row][col];
    }

    bool search(int value) { // ����� � �������
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] == value) {
                    cout << "Row = " << i << " Column = " << j << endl;
                    return true;
                }
            }
        }
       cout<<"No such element"<<endl; // ���� �������� �� ��������
       return false;
    }

private:
    int rows;
    int cols;
    int** data;
};

//�����

bool Test1() {
    TableTest table(3,5);
    table.getRows();
    table.getCols();
    table.setData(0, 3, 100);
    if (table.getData(0, 3) == 100)
    {
        cout << "True" << endl;
        return true;
    }
    else
    {
        cout << "False" << endl;
        return false;
    }
}

bool Test2() {
    TableTest table(5, 5);
    table.setData(2, 2, 363);
    if (table.search(636) == false)
    {
        cout << "True" << endl;
        return true;
    }
    else
    {
        cout << "False" << endl;
        return false;
    }
}

bool Test3() {
    TableTest table(2, 5);
    table.setData(1, 2, 363);
    if (table.search(363) == true)
    {
        cout << "True" << endl;
        return true;
    }
    else
    {
        cout << "False" << endl;
        return false;
    }
}

int main() {

    Test1();
    Test2();
    Test3();

    return 0;
}











