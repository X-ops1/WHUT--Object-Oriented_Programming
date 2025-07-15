#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;  
    float score;

public:
    Student(int i = 0, string n = "", float s = 0) {
        id = i;
        name = n;
        score = s;
    }

    friend istream& operator>>(istream& in, Student& student){
        in >> student.id >> student.name >> student.score;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& student){
        out << student.id<< " " << student.name << " " << student.score << endl;
        return out;
    }

    string getName(){
        return name;
    }

    void saveToFile(ostream& file) const {
        file.write((char*)&id, sizeof(int));
        file.write((char*)&score, sizeof(float));
        size_t len = name.length();
        file.write((char*)&len, sizeof(size_t));
        file.write((char*)name.c_str(), len*sizeof(char));
    }

    bool loadFromFile(istream& file) {
        if (!file.read((char*)&id, sizeof(int)))
            return false;
        if (!file.read((char*)&score, sizeof(float)))
            return false;
        
        size_t len;
        if (!file.read((char*)&len, sizeof(size_t)))
            return false;

        if (len > 0) {
            char* buffer = new char[len + 1];
            if (!file.read((char*)buffer, len*sizeof(char))) {
                delete[] buffer;
                return false;
            }
            buffer[len] = L'\0';
            name = buffer;
            delete[] buffer;
        } else {
            name = "";  // 当长度为0时，确保name为空
        }
        return true;
    }
};

void inputData() {
    int num;
    cout << "输入数据" << endl;
    cout << "学生人数: ";
    cin >> num;

    ofstream file("stud.dat",ios::binary|ios::app);
    if (!file) {
        cout << "无法打开文件进行写入!" << endl;
        return;
    }

    for (int i = 0; i < num; ++i) {
        cout << "第 " << i + 1 << " 个学生(学号 姓名 成绩): ";
        Student student;
        cin >> student;
        student.saveToFile(file);
    }

    file.close();
}

void outputData() {
    ifstream file("stud.dat", ios::binary);
    if (!file) {
        cout << "无法打开文件进行读取!" << endl;
        return;
    }
    cout << "输出数据" << endl;
    cout << "学号 姓名 成绩" << endl;

    Student student;
    while (student.loadFromFile(file)) {
        cout << student;
    }

    file.close();
}

void searchByName() {
    string searchName;
    cout << "请输入姓名进行查询: ";
    cin >> searchName;

    ifstream file("stud.dat", ios::binary);
    if (!file) {
        cout << "无法打开文件进行读取!" << endl;
        return;
    }

    cout << "查询结果：" << endl;
    cout << "学号 姓名 成绩" << endl;

    Student student;
    while (student.loadFromFile(file)) {
        if (student.getName().find(searchName) != wstring::npos) {
            cout << student;
        }
    }

    file.close();
}

int main() {
    int choice;

    while (true) {
        // 显示菜单
        cout << "选择(1:输入数据 2:输出数据 3:按姓名查找数据 其他退出): ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputData();
                break;
            case 2:
                outputData();
                break;
            case 3:
                searchByName();
                break;
            default:
                return 0;
        }
    }

    return 0;
}