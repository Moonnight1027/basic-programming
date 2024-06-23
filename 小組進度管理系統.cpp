// 小組進度管理系統.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
#include <iostream>
#include <string>
#include <windows.h>
#include <typeinfo>
#include <limits>
#include "Group.h"
#include <conio.h>
using namespace std;

int main()
{
    Group introduce, Art, project;
    introduce.name = "介紹組";
    Art.name = "美宣組";
    project.name = "專案組";

    char choice;
    while (true)
    {
        system("cls");
        cout << "《進度管理系統》" << endl;
        cout << "1.介紹組" << endl;
        cout << "2.美宣組" << endl;
        cout << "3.專案組" << endl;
        cout << "4.顯示所有小組概況" << endl;
        cout << "請輸入欲管理之小組: ";
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        switch (choice)
        {
        case '1':
        {
            system("cls");
            cout << "《進度管理系統》" << endl;
            introduce.Information();
            introduce.action();
            break;
        }
        case '2':
        {
            system("cls");
            cout << "《進度管理系統》" << endl;
            Art.Information();
            Art.action();
            break;
        }
        case '3':
        {
            system("cls");
            cout << "《進度管理系統》" << endl;
            project.Information();
            project.action();
            break;
        }
        case '4':
        {
            system("cls");
            cout << "《小組管理系統》" << endl;
            introduce.Information();
            Art.Information();
            project.Information();
            cout << "輸入任意鍵以退出..." << endl;
            _getch();
            break;
        }
        default:
        {
            cout << "輸入有誤，請重新輸入" << endl;
            Sleep(1000);
            break;
        }
        }
    }
    return 0;
}





// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
