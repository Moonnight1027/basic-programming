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
    string name;            //�p�զW�r
private:
    int budget = 0;         //��e�w��
    int headcount = 0;      //�p�դH��
    int taskcount = 0;      //���ȼƶq
    string members[20];     //�խ��W��
    string task[20];        //���ȦW��
    double progress[20];    //���ȶi��

public:
    void Information() //��ܤp�շ��p
    {
        cout << "��e" << name << "���p" << endl;
        cout << "<�խ�>";
        for (int i = 0; i < headcount; i++)
        {
            if (i % 5 == 0)
            {
                cout << endl;
            }
            cout << i + 1 << '.' << members[i] << " ";
        }
        cout << endl;
        cout << "�@" << headcount << "�H" << endl;

        cout << "<����>" << endl;
        for (int i = 0; i < taskcount; i++)
        {
            cout << i + 1 << "." << task[i] << "  �i��: " << progress[i] << "%" << endl;
        }
        cout << "�@" << taskcount << "�ӥ���" << endl;

        cout << "<�w��>" << endl << budget << "��" << endl;
        cout << "=======================================" << endl;
    }

    void refresh()  //��s����
    {
        system("cls");
        cout << "�m�p�պ޲z�t�Ρn" << endl;
        Information();
    }

    void action()   //��ܭn���檺���
    {
        char choice;
        cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
        cout << "2.�s�C�w��" << endl;
        cout << "3.���Ȧw��" << endl;
        cout << "�п�J�����椧���: ";
        cin >> choice;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');  //����X��
        switch (choice)     //�ھڹ�����J����
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
        case'r':    //��Jr�^�e��
        {
            system("cls");  //�M������(�F����s�����ĪG)
            break;
        }
        default:
        {
            cout << "���~�ﶵ�A�Э��s��J" << endl;
            Sleep(1000);    //���e�����|�Ӭ�a
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
        cout << "1.�s�W�խ�" << endl;
        cout << "2.�����խ�" << endl;
        cout << "�п�J�����椧����: ";
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
            if (headcount == 0) //����(�|��������խ���)
            {
                cout << "��e�S������խ�" << endl;
                Sleep(1000);
                refresh();
                cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
                cout << "2.�s�C�w��" << endl;
                cout << "3.���Ȧw��" << endl;
                cout << "�п�J�����椧���: 3" << endl;
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
        default:    //����(��J��L�ﶵ��)
        {
            cout << "�L�Ī��ﶵ�A�Э��s��J" << endl;
            Sleep(1000);
            refresh();
            cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
            cout << "2.�s�C�w��" << endl;
            cout << "3.���Ȧw��" << endl;
            cout << "�п�J�����椧���: 1" << endl;
            cout << "=======================================" << endl;
            manage_members();
            break;
        }
        }
    }

    void add_member() //�s�W�խ�
    {
        string name;
        while (true)
        {
            cout << "��J�խ��W�r: ";
            cin >> name;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (name == "r")
            {
                cout << "�Ҧ��ܧ�w�x�s" << endl;
                break;
            }
            members[headcount] = name;
            cout << "�s�W���\" << endl;
            headcount++;
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }

    void remove_member()    //�����խ�
    {
        string member_number;
        int member_number_int;
        while (true)
        {
            cout << "�п�J���������խ��s��: ";
            cin >> member_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            try
            {
                if (member_number == "r")
                {
                    cout << "�Ҧ��ܧ�w�x�s" << endl;
                    break;
                }
                member_number_int = stoi(member_number) - 1;
                if (member_number_int >= 0)
                {
                    members[member_number_int] = "";
                    headcount--;
                    cout << "�������\" << endl;
                    break;
                }
                else
                {
                    cout << "�L�Ī��խ��s���A�Э��s��J" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "�L�Ī��խ��s���A�Э��s��J" << endl;
            }
        }
        for (int k = member_number_int; k < headcount; k++) //��z�}�C
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

    void Budgeting() //�ܧ�w��
    {
        string budget_str;
        while (true)
        {
            cout << "��J���B�H�ק�w��: ";
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
                        cout << "�ק令�\�A��e�w�⬰" << budget << "��" << endl;
                        cout << "=======================================" << endl;
                        Sleep(2500);
                        break;
                    }
                    else
                    {
                        cout << "���B����0�Υ���ơA�Э��s��J" << endl;
                        Sleep(1000);
                        refresh();
                        cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
                        cout << "2.�s�C�w��" << endl;
                        cout << "3.���Ȧw��" << endl;
                        cout << "�п�J�����椧���: 2" << endl;
                        cout << "=======================================" << endl;
                        Budgeting();
                        break;
                    }
                }
                catch (invalid_argument)
                {
                    cout << "���B����0�Υ���ơA�Э��s��J" << endl;
                    Sleep(1000);
                    refresh();
                    cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
                    cout << "2.�s�C�w��" << endl;
                    cout << "3.���Ȧw��" << endl;
                    cout << "�п�J�����椧���: 2" << endl;
                    cout << "=======================================" << endl;
                    Budgeting();
                    break;
                }
            }
        }
        refresh();
    }

    void manage_tasks() //��ʥ���
    {
        char choice;
        cout << "1.�s�W����" << endl;
        cout << "2.��������" << endl;
        cout << "3.��s�i��" << endl;
        cout << "�п�J�����椧����: ";
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
                cout << "��e�S���������" << endl;
                Sleep(1000);
                refresh();
                cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
                cout << "2.�s�C�w��" << endl;
                cout << "3.���Ȧw��" << endl;
                cout << "�п�J�����椧���: 3" << endl;
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
                cout << "��e�S���������" << endl;
                Sleep(1000);
                refresh();
                cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
                cout << "2.�s�C�w��" << endl;
                cout << "3.���Ȧw��" << endl;
                cout << "�п�J�����椧���: 3" << endl;
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
            cout << "�L�Ī��ﶵ�A�Э��s��J" << endl;
            Sleep(1000);
            refresh();
            cout << "1.�H�Ʋ���                     r:�^�e��" << endl;
            cout << "2.�s�C�w��" << endl;
            cout << "3.���Ȧw��" << endl;
            cout << "�п�J�����椧���: 3" << endl;
            cout << "=======================================" << endl;
            manage_tasks();
            break;
        }
        }
    }

    void add_task() //�s�W����
    {
        string taskName;
        while (true)
        {
            cout << "�п�J���s�W�����ȦW��: ";
            cin >> taskName;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (taskName == "r")
            {
                cout << "�Ҧ��ܧ�w�x�s" << endl;
                break;
            }
            task[taskcount] = taskName;
            progress[taskcount] = 0;
            taskcount++;
            cout << "�s�W���\" << endl;
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }

    void remove_task() //��������
    {
        string task_number;
        int task_number_int;
        while (true)
        {
            cout << "�п�J�����������ȸ��X: ";
            cin >> task_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            try
            {
                if (task_number == "r")
                {
                    cout << "�Ҧ��ܧ�w�x�s" << endl;
                    break;
                }
                task_number_int = stoi(task_number) - 1;
                if (task_number_int >= 0 && task_number_int < taskcount)
                {
                    task[task_number_int] = "";
                    progress[task_number_int] = 0;
                    taskcount--;
                    cout << "�������\" << endl;
                    break;
                }
                else
                {
                    cout << "�L�Ī����ȸ��X�A�Э��s��J" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "�L�Ī����ȸ��X�A�Э��s��J" << endl;
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

    void update_progress()  //��s�i��
    {
        string task_number;
        float new_progress;
        while (true)
        {
            cout << "�п�J����s�i�פ����Ƚs��: ";
            cin >> task_number;
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            if (task_number == "r")
            {
                cout << "�Ҧ��ܧ�w�x�s" << endl;
                break;
            }
            try
            {
                int task_number_int = stoi(task_number) - 1;
                if (task_number_int >= 0 && task_number_int < taskcount)
                {
                    cout << "�п�J��e���ȶi��(%): ";
                    cin >> new_progress;
                    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                    if (new_progress >= 0 && new_progress <= 100)
                    {
                        progress[task_number_int] = new_progress;
                        cout << "��s�i�צ��\" << endl;
                    }
                    else
                    {
                        cout << "��J�����ȶi�׵L��" << endl;
                    }
                }
                else
                {
                    cout << "��J�����ȶi�׵L��" << endl;
                }
            }
            catch (invalid_argument)
            {
                cout << "��J�����ȶi�׵L��" << endl;
            }
        }
        cout << "=======================================" << endl;
        Sleep(2500);
        refresh();
    }
};


