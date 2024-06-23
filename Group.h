#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <typeinfo>
#include <limits>
#include <conio.h>

using namespace std;

class Group
{
public:
    string name;            //小組名字
private:
    int budget = 0;         //當前預算
    int headcount = 0;      //小組人數
    int taskcount = 0;      //任務數量
    string members[20];     //組員名稱
    string task[20];        //任務名稱
    double progress[20];    //任務進度

public:
    void Information() //顯示小組概況
    {
        cout << "當前" << name << "概況" << endl;
        cout << "<組員>";
        for (int i = 0; i < headcount; i++)
        {
            if (i % 5 == 0)
            {
                cout << endl;
            }
            cout << i + 1 << '.' << members[i] << " ";
        }
        cout << endl;
        cout << "共" << headcount << "人" << endl;

        cout << "<任務>" << endl;
        for (int i = 0; i < taskcount; i++)
        {
            cout << i + 1 << "." << task[i] << "  進度: " << progress[i] << "%" << endl;
        }
        cout << "共" << taskcount << "個任務" << endl;

        cout << "<預算>" << endl << budget << "元" << endl;
        cout << "=======================================" << endl;
    }

    void refresh()  //刷新頁面
    {
        system("cls");
        cout << "《小組管理系統》" << endl;
        Information();
    }

    void action()   //選擇要執行的行動
    {
        char choice;
        cout << "1.人事異動                     r:回前頁" << endl;
        cout << "2.編列預算" << endl;
        cout << "3.任務安排" << endl;
        cout << "請輸入欲執行之行動: ";
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');  //防止出錯
        switch (choice)     //根據對應輸入執行
        {
        case'1':
        {
            cout << "=======================================" << endl;
            manage_members();
            refresh();
            action();
            break;
        }
        case'2':
        {
            cout << "=======================================" << endl;
            Budgeting();
            refresh();
            action();
            break;
        }
        case'3':
        {
            cout << "=======================================" << endl;
            manage_tasks();
            refresh();
            action();
            break;
        }
        case'r':    //輸入r回前頁
        {
            system("cls");  //清除頁面(達成刷新頁面效果)
            break;
        }
        default:
        {
            cout << "錯誤選項，請重新輸入" << endl;
            Sleep(1000);    //讓畫面不會太突兀
            refresh();
            action();
            break;
        }
        }
    }

private:
    void manage_members()
    {
        char choice;
        cout << "1.新增組員" << endl;
        cout << "2.移除組員" << endl;
        cout << "請輸入欲執行之項目: ";
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');

        switch (choice)
        {
        case'1':
        {
            cout << "=======================================" << endl;
            add_member();
            break;
        }
        case'2':
        {
            if (headcount == 0) //偵錯(尚未有任何組員時)
            {
                cout << "當前沒有任何組員" << endl;
                Sleep(1000);
                refresh();
                cout << "1.人事異動                     r:回前頁" << endl;
                cout << "2.編列預算" << endl;
                cout << "3.任務安排" << endl;
                cout << "請輸入欲執行之行動: 3" << endl;
                cout << "=======================================" << endl;
                manage_members();
            }
            else
            {
                cout << "=======================================" << endl;
                remove_member();
            }
            break;
        }
        case'r':
        {
            refresh();
            break;
        }
        default:    //偵錯(輸入其他選項時)
        {
            cout << "無效的選項，請重新輸入" << endl;
            Sleep(1000);
            refresh();
            cout << "1.人事異動                     r:回前頁" << endl;
            cout << "2.編列預算" << endl;
            cout << "3.任務安排" << endl;
            cout << "請輸入欲執行之行動: 1" << endl;
            cout << "=======================================" << endl;
            manage_members();
            break;
        }
        }
    }

    void add_member() //新增組員
    {
        string name;
        while (true)
        {
            cout << "輸入組員名字: ";
            cin >> name;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (name == "r")
            {
                cout << "所有變更已儲存" << endl;
                break;
            }
            members[headcount] = name;
            cout << "新增成功" << endl;
            headcount++;
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }

    void remove_member()    //移除組員
    {
        string member_number;
        int member_number_int;
        while (true)
        {
            cout << "請輸入欲移除之組員編號: ";
            cin >> member_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            try
            {
                if (member_number == "r")
                {
                    cout << "所有變更已儲存" << endl;
                    break;
                }
                member_number_int = stoi(member_number) - 1;
                if (member_number_int >= 0)
                {
                    members[member_number_int] = "";
                    headcount--;
                    cout << "移除成功" << endl;
                    break;
                }
                else
                {
                    cout << "無效的組員編號，請重新輸入" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "無效的組員編號，請重新輸入" << endl;
            }
        }
        for (int k = member_number_int; k < headcount; k++) //整理陣列
        {
            if (members[k] == "")
            {
                members[k] = members[k + 1];
                members[k + 1] = "";
            }
        }
        Sleep(2500);
        refresh();
    }

    void Budgeting() //變更預算
    {
        string budget_str;
        while (true)
        {
            cout << "輸入金額以修改預算: ";
            cin >> budget_str;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (budget_str == "r")
            {
                break;
            }
            else
            {
                try
                {
                    int budget_test = stoi(budget_str);
                    if (budget_test >= 0)
                    {
                        budget = stoi(budget_str);
                        cout << "修改成功，當前預算為" << budget << "元" << endl;
                        cout << "=======================================" << endl;
                        Sleep(2500);
                        break;
                    }
                    else
                    {
                        cout << "金額須為0或正整數，請重新輸入" << endl;
                        Sleep(1000);
                        refresh();
                        cout << "1.人事異動                     r:回前頁" << endl;
                        cout << "2.編列預算" << endl;
                        cout << "3.任務安排" << endl;
                        cout << "請輸入欲執行之行動: 2" << endl;
                        cout << "=======================================" << endl;
                        Budgeting();
                        break;
                    }
                }
                catch (invalid_argument)
                {
                    cout << "金額須為0或正整數，請重新輸入" << endl;
                    Sleep(1000);
                    refresh();
                    cout << "1.人事異動                     r:回前頁" << endl;
                    cout << "2.編列預算" << endl;
                    cout << "3.任務安排" << endl;
                    cout << "請輸入欲執行之行動: 2" << endl;
                    cout << "=======================================" << endl;
                    Budgeting();
                    break;
                }
            }
        }
        refresh();
    }

    void manage_tasks() //更動任務
    {
        char choice;
        cout << "1.新增任務" << endl;
        cout << "2.移除任務" << endl;
        cout << "3.更新進度" << endl;
        cout << "請輸入欲執行之項目: ";
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "=======================================" << endl;

        switch (choice)
        {
        case'1':
        {
            add_task();
            break;
        }
        case'2':
        {
            if (taskcount == 0)
            {
                cout << "當前沒有任何任務" << endl;
                Sleep(1000);
                refresh();
                cout << "1.人事異動                     r:回前頁" << endl;
                cout << "2.編列預算" << endl;
                cout << "3.任務安排" << endl;
                cout << "請輸入欲執行之行動: 3" << endl;
                cout << "=======================================" << endl;
                manage_tasks();
            }
            else
            {
                remove_task();
            }
            break;
        }
        case'3':
        {
            if (taskcount == 0)
            {
                cout << "當前沒有任何任務" << endl;
                Sleep(1000);
                refresh();
                cout << "1.人事異動                     r:回前頁" << endl;
                cout << "2.編列預算" << endl;
                cout << "3.任務安排" << endl;
                cout << "請輸入欲執行之行動: 3" << endl;
                cout << "=======================================" << endl;
                manage_tasks();
            }
            else
            {
                update_progress();
            }
            break;
        }
        case'r':
        {
            refresh();
            break;
        }
        default:
        {
            cout << "無效的選項，請重新輸入" << endl;
            Sleep(1000);
            refresh();
            cout << "1.人事異動                     r:回前頁" << endl;
            cout << "2.編列預算" << endl;
            cout << "3.任務安排" << endl;
            cout << "請輸入欲執行之行動: 3" << endl;
            cout << "=======================================" << endl;
            manage_tasks();
            break;
        }
        }
    }

    void add_task() //新增任務
    {
        string taskName;
        while (true)
        {
            cout << "請輸入欲新增之任務名稱: ";
            cin >> taskName;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (taskName == "r")
            {
                cout << "所有變更已儲存" << endl;
                break;
            }
            task[taskcount] = taskName;
            progress[taskcount] = 0;
            taskcount++;
            cout << "新增成功" << endl;
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }

    void remove_task() //移除任務
    {
        string task_number;
        int task_number_int;
        while (true)
        {
            cout << "請輸入欲移除之任務號碼: ";
            cin >> task_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            try
            {
                if (task_number == "r")
                {
                    cout << "所有變更已儲存" << endl;
                    break;
                }
                task_number_int = stoi(task_number) - 1;
                if (task_number_int >= 0 && task_number_int < taskcount)
                {
                    task[task_number_int] = "";
                    progress[task_number_int] = 0;
                    taskcount--;
                    cout << "移除成功" << endl;
                    break;
                }
                else
                {
                    cout << "無效的任務號碼，請重新輸入" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "無效的任務號碼，請重新輸入" << endl;
            }
        }
        for (int k = task_number_int; k <= taskcount; k++)
        {
            if (task[k] == "")
            {
                task[k] = task[k + 1];
                progress[k] = progress[k + 1];
            }
            task[k + 1] = "";
            progress[k + 1] = 0;
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }

    void update_progress()  //更新進度
    {
        string task_number;
        float new_progress;
        while (true)
        {
            cout << "請輸入欲更新進度之任務編號: ";
            cin >> task_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (task_number == "r")
            {
                cout << "所有變更已儲存" << endl;
                break;
            }
            try
            {
                int task_number_int = stoi(task_number) - 1;
                if (task_number_int >= 0 && task_number_int < taskcount)
                {
                    cout << "請輸入當前任務進度(%): ";
                    cin >> new_progress;
                    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                    if (new_progress >= 0 && new_progress <= 100)
                    {
                        progress[task_number_int] = new_progress;
                        cout << "更新進度成功" << endl;
                    }
                    else
                    {
                        cout << "輸入的任務進度無效" << endl;
                    }
                }
                else
                {
                    cout << "輸入的任務進度無效" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "輸入的任務進度無效" << endl;
            }
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }
};


