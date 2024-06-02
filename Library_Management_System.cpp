#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
void menu();
void register_user();
void name_not_found();
int no_of_students = 0;
int no_of_teachers = 0;
int no_of_staff = 0;
struct Details 
  {
    string name;
    long acc_no;
    string list_books_issued[5];
    int issued_books, fine[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    long long return_date[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  } Students[10], Teachers[10], Staff[10];
struct BooksDetails 
  {
  public:
    string name[5][3] = 
      {
        {
          "The Art of Assembly Language, 2nd Edition",
          "Writing for Computer Science",
          "C++ Plus Data Structures"
        },
        {
          "An Introduction to Architectural Engineering",
          "Encyclopedia of Architectural and Engineering Feats",
          "Structure As Architecture"
        },
        {
          "Shigley's Mechanical Engineering Design - Volume 10",
          "Mechanical Engineering Design",
          "A History of Mechanical Engineering"
        },
        {
          "The Capital One",
          "Armistan",
          "English Fyle"
        },
        {
          "Chatur",
          "A walk to bed",
          "Fashion"
        }
      };
    string ISBN[5][3] = 
    {
      {
        "WIUFH43043689",
        "HG8PG9043URE5",
        "LBC8T8B67V87T"
      },
      {
        "BVT6943URBFC3",
        "YBV8T34BVY09V",
        "38TVB9534YC43"
      },
      {
        "C8N5P9T349843",
        "CI7BT6Y4398TY",
        "85YTU4C0N4C94"
      },
      {
        "1 Jan 2023",
        "12 Dec 2022",
        "31 Oct 2019"
      },
      {
        "1 Sept 2020",
        "09 Feb 2023",
        "11 May 2021"
      }
    };
    string category[5] = 
        {
          "Computer Science",
          "Architectural Engineering",
          "Mechanical Engineering",
          "Newspapers",
          "Magazines"
        };
    string authors[3][3][3] = 
      {
        {
          {"Randall Hyde"},
          {"Justin Zobel"},
          {"Nell B. Dale"}
        },
        {
          {"J Paul Guyer"},
          {"Donald Langmead", "Christine Garnaut"},
          {"Andrew Charleson"}
        },
        {
          {"Joseph Edward Shigley", "Charles R. Mischke"},
          {"Ce Zhang", "Jianming Yang"},
          {"Infamous author."}
        }
      };
    string code[5][3] = 
      {
        {
          "123",
          "456",
          "764"
        },
        {
          "583",
          "834",
          "021",
        },
        {
          "832",
          "943",
          "983"
        }
      };
    int copies[5][3] = 
        {
          {
            2, 4, 2
          },
          {
            1, 3, 2
          },
          {
            2, 1, 1
          },
          {
            1, 1, 1
          },
          {
            1, 1, 1
          }
        }, copy_no[3][3];
    string status[5][3] = {{"Issued", "Available", "Lost"},
                          {"Available", "on Order", "Available"},
                          {"Available", "Available", "Available"},
                          {"Available", "Available", "Available"},
                          {"Lost", "On Order", "On Order"}};
  } Category;
class Book 
  {
  public:
    time_t current_time;
    // time(&current_time);
    struct tm *timeinfo = localtime(&current_time);
    void book_not_found(string type, int user_name1) 
      {
        char answer;
        cout << "Sorry! We do not have this book/newspaper/magazine.\n";
        while (true) 
          {
            cout << "Want to issue another book/newspaper/magazine?(Y/N) = ";
            cin >> answer;
            system("cls");
            if (answer == 'Y') 
              {
                issue_book(type, user_name1);
                break;
              }
            else if (answer == 'N') 
              {
                cout << "Thanks for visiting.";
                menu();
                break;
              }
            else
              {
                cout << "Invalid Input.";
              }
          }
      }
    void issue_book()
      {
        string type, user_name;
        int user_name1;
        bool nameFound = false;
        cout<<"Enter user-type = ";cin>>type;
        system("cls");
        cin.ignore();
        cout<<"Enter name = ";
        getline(cin, user_name);
        system("cls");
        if (type == "Student")
          {
            for (int i = 0; i < 10; i++)
              {
                if (user_name == Students[i].name)
                  {
                    nameFound = true;
                    user_name1 = i;
                    issue_book(type, user_name1);
                    break;
                  }
                if (!nameFound)
                  {
                    cout<<"Name not found.\n";
                    name_not_found();
                  }
              }
          }
        else if (type == "Teacher")
          {
            for (int i = 0; i < 10; i++)
              {
                if (user_name == Teachers[i].name)
                  {
                    nameFound = true;
                    user_name1 = i;
                    issue_book(type, user_name1);
                    break;
                  }
                if (!nameFound)
                  {
                    cout<<"Name not found.\n";
                    name_not_found();
                  }
              }
          }
        else if (type == "Staff")
          {
            for (int i = 0; i < 10; i++)
              {
                if (user_name == Staff[i].name)
                  {
                    nameFound = true;
                    user_name1 = i;
                    issue_book(type, user_name1);
                    break;
                  }
                if (!nameFound)
                  {
                    cout<<"Name not found.\n";
                    name_not_found();
                  }
              }
          }
      }
    void issue_book(string type, int user_name1)
      {
        string category, name;
        int name1, category1;
        bool ctgFound = false;
        bool bookFound = false;
        cout << "Enter Category = ";
        cin.ignore();
        getline(cin, category);
        system("cls");
        // cin.ignore();
        cout << "Enter name of book/magazine/newspaper = ";
        getline(cin, name);
        system("cls");
        for (int i = 0; i < 5; i++)
          {
            if (category == Category.category[i])
              {
                category1 = i;
                ctgFound = true;
                for (int j = 0; j < 3; j++)
                  {
                    if (name == Category.name[i][j])
                      {
                        name1 = j;
                        bookFound = true;
                        issue_book(type, user_name1, category1, name1);
                        break;
                      }
                    if (!bookFound)
                      {
                        cout<<"No such book is found.";
                        system("pause");
                        menu();
                        break;
                      }
                  }
              }
          }
        if (!ctgFound)
          {
            cout<<"No such category is found.";
            system("pause");
            menu();
          }
      }
    void issue_book(string type, int user_name1, int category1, int name1)
      {
        char answer;
        if (Category.copies[category1][name1] > 0)
          {
            Category.status[category1][name1] = "Issued";
            Category.copies[category1][name1] -= 1;
            time(&current_time);
            struct tm *timeinfo2 = localtime(&current_time);
            if (type == "Student")
              {
                Students[user_name1].list_books_issued[Students[user_name1].issued_books + 1] = Category.name[category1][name1];
                Students[user_name1].issued_books += 1;
                cout << "You have successfully issued.\n";
                timeinfo2 -> tm_mday += 7;
                mktime(timeinfo2);
                cout << "You can return it after 1 week ("<< timeinfo2 -> tm_mday << "-" << timeinfo2 -> tm_mon + 1 << "-" << timeinfo2 -> tm_year - 100 << ") or re-issue it otherwise you will be fined.\n";
                // system("cls");
              }
            else if (type == "Teacher")
              {
                Teachers[user_name1].list_books_issued[Teachers[user_name1].issued_books + 1] = Category.name[category1][name1];
                Teachers[user_name1].issued_books += 1;
                cout << "You have successfully issued.\n";
                timeinfo2 -> tm_mon += 3;
                mktime(timeinfo2);
                cout << "You can return it after 3 months ("<< timeinfo2 -> tm_mday << "-" << timeinfo2 -> tm_mon + 1 << "-" << timeinfo2 -> tm_year - 100 << ") or re-issue it otherwise you will be fined.\n";
                // system("cls");
              }
            else if (type == "Staff")
              {
                Staff[user_name1].list_books_issued[Staff[user_name1].issued_books + 1] = Category.name[category1][name1];
                Staff[user_name1].issued_books += 1;
                cout << "You have successfully issued.\n";
                timeinfo2 -> tm_mday += 21;
                mktime(timeinfo2);
                cout << "You can return it after 3 weeks ("<< timeinfo2 -> tm_mday << "-" << timeinfo2 -> tm_mon + 1 << "-" << timeinfo2 -> tm_year - 100 << ") or re-issue it otherwise you will be fined.\n";
                // system("cls");
              }
            while (true)
              {
                cout << "Want to issue another book/newspaper/magazine?(Y/N) = ";
                cin >> answer;
                system("cls");
                if (answer == 'Y')
                  {
                    issue_book(type, user_name1);
                    break;
                  }
                else if (answer == 'N')
                  {
                    system("cls");
                    cout << "Thanks for visiting.";
                    menu();
                    break;
                  }
                else
                  {
                    cout << "Invalid Input.";
                  }
              }
          }
        else
          {
            cout<<"Sorry not enough copies.";
            menu();
          }
      }
    int abc;
    bool search(string book_to_be_searched)
      {
        bool bookFound = false;
        for (int i = 0; i < 5; i++)
          {
            for (int j = 0; j < 3; j++)
              {
                if (book_to_be_searched == Category.name[i][j])
                  {
                    if (Category.copies[i][j] > 0)
                      {
                        abc = j;
                        bookFound = true;
                        return true;
                      }
                  }
              }
          }
        return false;
      }
    void display_books()
      {
        bool user_nameFound = false;
        for (int i = 0; i < 5; i++)
          {
            cout << "Category:\t" << Category.category[i]<<endl;
            for (int j = 0; j < 3; j++)
              {
                cout <<j+1<<") "<<Category.name[i][j] << endl;
                if (Category.status[i][j] == "Issued")
                  {
                    cout << "Issued by ";
                    for (int k = 0; k < 3; k++)
                      {
                       for (int l = 0; l < 3; l++)
                          {
                            if (Category.name[i][j] == Students[k].list_books_issued[l])
                              {
                                user_nameFound = true;
                                cout << "Student = " << Students[k].name << endl;
                                break;
                              }
                            else if (Category.name[i][j] ==Teachers[k].list_books_issued[l])
                              {
                                user_nameFound = true;
                                cout << "Teacher = " << Teachers[k].name << endl;
                                break;
                              }
                            else if (Category.name[i][j] == Staff[k].list_books_issued[l])
                              {
                                user_nameFound = true;
                                cout << "Staff = " << Staff[k].name << endl;
                                break;
                              }
                          }
                      }
                  }
                else
                  {
                    cout << "   Status = " << Category.status[i][j];
                  }
                cout << endl;
              }
          }
        // system("pause");
        system("cls");
      }
    void search()
      {
        string category, name, type, user_name;
        int name1, user_name1, category1;
        display_books();
        cin.ignore();
        cout << "Enter user-type = ";
        cin >> type;
        system("cls");
        cin.ignore();
        cout << "Enter name = ";
        getline(cin, user_name);
        system("cls");
        cout << "Enter Category = ";
        getline(cin, category);
        system("cls");
        bool ctgFound = false;
        bool bookFound = false;
        bool usrname = false;
        for (int i = 0; i < 5; i++)
          {
            if (category == Category.category[i])
              {
                category1 = i;
                ctgFound = true;
                string book_search;
                // cin.ignore();
                cout << "Enter name of book = ";
                getline(cin, book_search);
                if (search(book_search) == true)
                  {
                    name1 = abc;
                    bookFound = true;
                    cout << "This book is available.\n";
                    char answer;
                    if (type == "Student")
                      {
                        for (int j = 0; i < 10; i++)
                          {
                            if (user_name == Students[j].name)
                              {
                                usrname = true;
                                if (Students[j].issued_books < 3)
                                  {
                                    while (true)
                                      {
                                        cout << "Wanna issue?(Y/N) = ";
                                        cin >> answer;
                                        system("cls");
                                        if (answer == 'Y')
                                          {
                                            issue_book(type, user_name1, category1, name1);
                                            break;
                                          }
                                        else if (answer == 'N')
                                          {
                                            cout << "Thanks for visiting.\n";
                                            menu();
                                            break;
                                          }
                                        else
                                          {
                                            cout << "Invalid input.";
                                          }
                                      }
                                  }
                                else
                                  {
                                    cout<<"Sorry! You can't issue more books.\nYou have to return some books.\n";
                                    system("pause");
                                    menu();
                                  }
                              }
                            if (!usrname)
                              {
                                name_not_found();
                              }
                          }
                      }
                    else if (type == "Teacher")
                      {
                        for (int j = 0; i < 10; i++)
                          {
                            if (user_name == Teachers[j].name)
                              {
                                usrname = true;
                                if (Teachers[j].issued_books < 10)
                                  {
                                    while (true)
                                      {
                                        cout << "Wanna issue?(Y/N) = ";
                                        cin >> answer;
                                        system("cls");
                                        if (answer == 'Y')
                                          {
                                            issue_book(type, user_name1, category1, name1);
                                            break;
                                          }
                                        else if (answer == 'N')
                                          {
                                            cout << "Thanks for visiting.\n";
                                            menu();
                                            break;
                                          }
                                        else
                                          {
                                            cout << "Invalid input.";
                                          }
                                      }
                                  }
                                else
                                  {
                                    cout<<"Sorry! You can't issue more books.\nYou have to return some books.\n";
                                    system("pause");
                                    menu();
                                  }
                              }
                            if (!usrname)
                              {
                                name_not_found();
                              }
                          }
                      }
                    else if (type == "Staff")
                      {
                        for (int j = 0; i < 10; i++)
                          {
                            if (user_name == Staff[j].name)
                              {
                                usrname = true;
                                if (Staff[j].issued_books < 5)
                                  {
                                    while (true)
                                      {
                                        cout << "Wanna issue?(Y/N) = ";
                                        cin >> answer;
                                        system("cls");
                                        if (answer == 'Y')
                                          {
                                            issue_book(type, user_name1, category1, name1);
                                            break;
                                          }
                                        else if (answer == 'N')
                                          {
                                            cout << "Thanks for visiting.\n";
                                            menu();
                                            break;
                                          }
                                        else
                                          {
                                            cout << "Invalid input.";
                                          }
                                      }
                                  }
                                else
                                  {
                                    system("cls");
                                    cout<<"Sorry! You can't issue more books.\nYou have to return some books.\n";
                                    system("pause");
                                    menu();
                                  }
                              }
                            if (!usrname)
                              {
                                name_not_found();
                              }
                          }
                      }
                  }
                if (!bookFound)
                  {
                    char answer;
                    cout << "We have no book of this name.\n";
                    while (true)
                      {
                        cout << "Do you want to place order?(Y/N) = ";
                        cin >> answer;
                        system("cls");
                        if (answer == 'Y')
                          {
                            cout<<"Your order has been placed.";
                            break;
                          }
                        else if (answer == 'N')
                          {
                            cout << "Thanks for visiting.\n";
                            menu();
                            break;
                          }
                        else
                          {
                            cout << "Invalid input.";
                          }
                      }
                    break;
                  }
                break;
              }
          }
        if (!ctgFound)
          {
            cout << "We have not such category.\n";
            menu();
          }
      }
    void return_book(string user_name, string type)
      {
        if (type == "Student")
          {
            int a = 0;
            for (int i = 0; i < 10; i++)
              {
                if (user_name == Students[i].name)
                  {
                    a = i;
                    for (int j = 0; j < Students[i].issued_books; j++)
                      {
                        cout << Students[i].list_books_issued[j] << endl;
                      }
                    int n;
                    while (true)
                      {
                        cout << "Enter numbers (1-" << Students[i].issued_books << ") = ";
                        cin >> n;
                        if (n < 4 and n > 0)
                          {
                            if ((Students[i].return_date[n] - time(&current_time)) < 0)
                              {
                                auto diff = Students[i].return_date[n] - time(&current_time);
                                timeinfo = localtime(&diff);
                                Students[i].fine[n] += 10 * (timeinfo -> tm_mday - 2);
                              }
                            if (Students[i].fine[n] > 0)
                              {
                                string name = Students[i].list_books_issued[n];
                                cout << "You are fined Rs." << Students[i].fine[n] << ".\n";
                                char answer;
                                while (true)
                                  {
                                    cout << "Do you want to pay fine or wanna remove it?(P/R) = ";
                                    cin >> answer;
                                    if (answer == 'P')
                                      {
                                        cout << "You have paid fine.\n";
                                        Students[i].fine[n] = 0;
                                        cout << "You have successfully returned book.\n";
                                        books_with_status(name, "Available", n);
                                        menu();
                                        break;
                                      }
                                    else if (answer == 'R')
                                      {
                                        remove_fine(type, Students[i].list_books_issued[n], a, n);
                                        break;
                                      }
                                    else
                                      {
                                        cout << "Invalid input.";
                                      }
                                  }
                              }
                            break;
                          }
                        else
                          {
                            cout << "Invalid input.";
                          }
                      }
                    break;
                  }
                }
              }
            else if (type == "Teacher")
              {
                int a = 0;
                for (int i = 0; i < 10; i++)
                  {
                    if (user_name == Teachers[i].name)
                      {
                        a = i;
                        for (int j = 0; j < Teachers[i].issued_books; j++)
                          {
                            cout << Teachers[i].list_books_issued[j] << endl;
                          }
                        int n;
                        while (true)
                          {
                            cout << "Enter numbers (1-" << Teachers[i].issued_books << ") = ";
                            cin >> n;
                            if (n < 4 and n > 0)
                              {
                                if ((Teachers[i].return_date[n] - time(&current_time)) < 0)
                                  {
                                    auto diff = Teachers[i].return_date[n] - time(&current_time);
                                    timeinfo = localtime(&diff);
                                    Teachers[i].fine[n] += 10 * (timeinfo -> tm_mday - 2);
                                  }
                                if (Teachers[i].fine[n] > 0)
                                  {
                                    cout << "You are fined Rs." << Teachers[i].fine[n] << ".\n";
                                    char answer;
                                    while (true)
                                      {
                                        cout << "Do you want to pay fine or wanna remove it?(P/R) = ";
                                        cin >> answer;
                                        if (answer == 'P')
                                          {
                                            string name = Teachers[i].list_books_issued[n];
                                            cout << "You have paid fine.\n";
                                            Teachers[i].fine[n] = 0;
                                            cout << "You have successfully returned book.\n";
                                            books_with_status(name, "Available", n);
                                            menu();
                                            break;
                                          }
                                        else if (answer == 'R')
                                          {
                                            remove_fine(type, Teachers[i].list_books_issued[n], a, n);
                                            break;
                                          }
                                        else
                                          {
                                            cout << "Invalid input.";
                                          }
                                      }
                                  }
                                break;
                              }
                            else
                              {
                                cout << "Invalid input.";
                              }
                          }
                        break;
                      }
                  }
              }
            if (type == "Staff")
              {
                  int a = 0;
                  for (int i = 0; i < 10; i++)
                    {
                      if (user_name == Staff[i].name)
                        {
                          a = i;
                          for (int j = 0; j < Staff[i].issued_books; j++)
                            {
                              cout << Staff[i].list_books_issued[j] << endl;
                            }
                          int n;
                          while (true)
                            {
                              cout << "Enter numbers (1-" << Staff[i].issued_books << ") = ";
                              cin >> n;
                              if (n < 4 and n > 0)
                                {
                                  if ((Staff[i].return_date[n] - time(&current_time)) < 0)
                                    {
                                      auto diff = Staff[i].return_date[n] - time(&current_time);
                                      timeinfo = localtime(&diff);
                                      Staff[i].fine[n] += 10 * (timeinfo -> tm_mday - 2);
                                    }
                                  if (Staff[i].fine[n] > 0)
                                    {
                                      cout << "You are fined Rs." << Staff[i].fine[n] << ".\n";
                                      char answer;
                                      while (true)
                                        {
                                          cout << "Do you want to pay fine or wanna remove it?(P/R) = ";
                                          cin >> answer;
                                          if (answer == 'P')
                                            {
                                              string name = Staff[i].list_books_issued[n];
                                              cout << "You have paid fine.\n";
                                              Staff[i].fine[n] = 0;
                                              cout << "You have successfully returned book.\n";
                                              books_with_status(name, "Available", n);
                                              menu();
                                              break;
                                            }
                                          else if (answer == 'R')
                                            {
                                              remove_fine(type, Staff[i].list_books_issued[n], a, n);
                                              break;
                                            }
                                          else
                                            {
                                              cout << "Invalid input.";
                                            }
                                        }
                                    }
                                  break;
                                }
                              else
                                {
                                  cout << "Invalid input.";
                                }
                            }
                          break;
                        }
                   }
              }
      }
    void re_issue(string type, string name, int a, int n) 
      {
        if (type == "Student")
          {
            cout << "You have successfully re-issued book.\n";
            timeinfo -> tm_mday += 7;
            mktime(timeinfo);
            auto days = timeinfo -> tm_mday;
            auto month = timeinfo -> tm_mon + 1;
            auto year = timeinfo -> tm_year - 100;
            cout << "Your new return date is " << days << "-" << month << "-" << year << endl;
            menu();
          }
        else if (type == "Teacher")
          {
            cout << "You have successfully re-issued book.\n";
            timeinfo -> tm_mon += 3;
            mktime(timeinfo);
            auto days = timeinfo -> tm_mday;
            auto month = timeinfo -> tm_mon + 1;
            auto year = timeinfo -> tm_year - 100;
            cout << "Your new return date is " << days << "-" << month << "-" << year << endl;
            menu();
          }
        else if (type == "Staff")
          {
            cout << "You have successfully re-issued book.\n";
            timeinfo -> tm_mday += 21;
            mktime(timeinfo);
            auto days = timeinfo -> tm_mday;
            auto month = timeinfo -> tm_mon + 1;
            auto year = timeinfo -> tm_year - 100;
            cout << "Your new return date is " << days << "-" << month << "-" << year << endl;
            menu();
          }
      }
    void books_with_status(string name, string status, int i) 
      {
          for (int j = 0; j < 5; j++) {
          if (name == Students[j].list_books_issued[i]) 
              {
                  Category.status[j][i] = status;
                  break;
              }
          }
      }
    void remove_fine(string type, string name, int a, int n)
      {
        char answer;
        while (true)
          {
            cout << "Want to return book(R) or re-issue book(I) = ";
            cin >> answer;
            system("cls");
            if (answer == 'R')
              {
                if (type == "Student")
                  {
                    Students[a].fine[n] = 0;
                  }
                else if (type == "Teacher")
                  {
                    Teachers[a].fine[n] = 0;
                  }
                else if (type == "Staff")
                  {
                    Staff[a].fine[n] = 0;
                  }
                return_book(name, type);
                break;
              }
            else if (answer == 'I')
              {
                if (type == "Student")
                  {
                    Students[a].fine[n] = 0;
                  }
                else if (type == "Teacher")
                  {
                    Teachers[a].fine[n] = 0;
                  }
                else if (type == "Staff")
                  {
                    Staff[a].fine[n] = 0;
                  }
                re_issue(type, name, a, n);
                break;
              }
            else
              {
                cout << "Invalid Input.";
              }
          }
      }
  } B;
class User_Detail
  {
  public:
    Book B;
    void list_of_books_issued(string name, string type)
      {
        if (type == "Student")
          {
            bool nameFound = false;
            for (int i = 0; i < 10; i++)
              {
                if (name == Students[i].name)
                  {
                    nameFound = true;
                    for (int j = 0; j < Students[i].issued_books; j++)
                      {
                        cout << Students[i].list_books_issued[j] << endl;
                        time_t timestamp = Students[i].return_date[j];
                        struct tm *timeinfo;
                        timeinfo = localtime(&timestamp);
                        cout << timeinfo -> tm_mday << "-" << timeinfo -> tm_mon + 1 << "-" << timeinfo -> tm_year - 100 << endl;
                        cout << "Fine = " << Students[i].fine[j] << endl;
                      }
                    break;
                  }
              }
          }
        else if (type == "Teacher")
          {
            bool nameFound = false;
            for (int i = 0; i < 10; i++)
              {
                if (name == Teachers[i].name)
                  {
                    nameFound = true;
                    for (int j = 0; j < Teachers[i].issued_books; j++)
                      {
                        cout << Teachers[i].list_books_issued[j] << endl;
                        time_t timestamp = Teachers[i].return_date[j];
                        struct tm *timeinfo;
                        timeinfo = localtime(&timestamp);
                        cout << timeinfo -> tm_mday << "-" << timeinfo -> tm_mon + 1 << "-" << timeinfo -> tm_year - 100 << endl;
                        cout << "Fine = " << Teachers[i].fine[j] << endl;
                      }
                    break;
                  }
              }
          }
        else if (type == "Staff")
          {
            bool nameFound = false;
            for (int i = 0; i < 10; i++)
              {
                if (name == Staff[i].name)
                  {
                    nameFound = true;
                    for (int j = 0; j < Staff[i].issued_books; j++)
                      {
                        cout << Staff[i].list_books_issued[j] << endl;
                        time_t timestamp = Staff[i].return_date[j];
                        struct tm *timeinfo;
                        timeinfo = localtime(&timestamp);
                        cout << timeinfo -> tm_mday << "-" << timeinfo -> tm_mon + 1 << "-" << timeinfo -> tm_year - 100 << endl;
                        cout << "Fine = " << Staff[i].fine[j] << endl;
                      }
                    break;
                  }
              }
          }
      }
    void move_to_menu()
      {
        char answer;
        while (true)
          {
            cout << "Move to main menu(Y/N) = ";
            cin >> answer;
            system("cls");
            if (answer == 'Y')
              {
                menu();
                break;
              }
            else if (answer == 'N')
              {
                cout << "Your program is successfully exited.";
                break;
              }
            else
              {
                cout << "Invalid Response.";
              }
          }
      }
    void show_detail()
      {
        string name, type;
        bool nameFound = false;
        cout << "Enter user-type = ";
        cin >> type;
        cin.ignore();
        if (type == "Student")
          {
            cout << "Enter name of student = ";
            getline(cin, name);
            system("cls");
            for (int i = 0; i < 10; i++)
              {
                if (name == Students[i].name)
                  {
                    nameFound = true;
                    cout << "\nName = " << Students[i].name;
                    cout << "\nID = " << Students[i].acc_no;
                    cout << "\nNo. of books issued = " << Students[i].issued_books;
                    cout << "\nList of issued books:\n";
                    list_of_books_issued(name, type);
                    cout << "\nRemaining number of books = " << 3 - Students[i].issued_books;
                    cout << "\nMoving to main menu!\n";
                    system("pause");
                    menu();
                    break;
                  }
                if (!nameFound)
                  {
                    name_not_found();
                    break;
                  }
              }
          }
        else if (type == "Teacher")
          {
            cout << "Enter name of teacher = ";
            getline(cin, name);
            system("cls");
            for (int i = 0; i < 10; i++)
              {
                if (name == Teachers[i].name)
                  {
                    nameFound = true;
                    cout << "\nName = " << Teachers[i].name;
                    cout << "\nID = " << Teachers[i].acc_no;
                    cout << "\nNo. of books issued = " << Teachers[i].issued_books;
                    cout << "\nList of issued books\n";
                    list_of_books_issued(name, type);
                    cout << "\nRemaining number of books = " << 10 - Teachers[i].issued_books;
                    system("pause");
                    cout << "\nMoving to main menu!\n";
                    menu();
                  }
                if (!nameFound)
                  {
                    name_not_found();
                    break;
                  }
              }
          }
        else if (type == "Staff")
          {
            cout << "Enter name of staff = ";
            getline(cin, name);
            system("cls");
            for (int i = 0; i < 10; i++)
              {
                if (name == Staff[i].name)
                  {
                    nameFound = true;
                    cout << "\nName = " << Staff[i].name;
                    cout << "\nID = " << Staff[i].acc_no;
                    cout << "\nNo. of books issued = " << Staff[i].issued_books;
                    cout << "\nList of issued books\n";
                    list_of_books_issued(name, type);
                    cout << "\nRemaining number of books = " << 5 - Staff[i].issued_books;
                    system("pause");
                    cout << "\nMoving to main menu!\n";
                    menu();
                  }
                if (!nameFound)
                  {
                    name_not_found();
                    break;
                  }
              }
          }
      }
  } D;
void menu()
  {
    int answer;
    cout << "1-User Detail\n";
    cout << "2-Register User\n";
    cout << "3-Issue Books\n";
    cout << "4-Search Books\n";
    cout << "5-Display Books\n";
    while (true)
      {
        cout << "Enter (1-5) to move further = ";
        cin >> answer;
        system("cls");
        if (answer == 1)
          {
            D.show_detail();
            break;
          }
        else if (answer == 2)
          {
            register_user();
            break;
          }
        else if (answer == 3)
          {
            B.issue_book();
            break;
          }
        else if (answer == 4)
          {
            B.search();
            break;
          }
        else if (answer == 5)
          {
            B.display_books();
            break;
          }
        else
          {
            cout << "Invalid Input.";
          }
      }
  }
void register_user()
  {
    string type, name;
    long acc_no;
    cout << "Enter user-type = ";
    cin >> type;
    system("cls");
    if (type == "Student")
      {
        cout << "Enter name = ";
        cin >> name;
        system("cls");
        cout << "Enter ID = ";
        cin >> acc_no;
        system("cls");
        cout << "You are registered!\n";
        Students[no_of_students + 1].name = name;
        Students[no_of_students + 1].acc_no = acc_no;
        char answer;
        while (true)
          {
            cout << "Want to (issue/search) books or nothing(I/S/N) = ";
            cin >> answer;
            system("cls");
            if (answer == 'I')
              {
                no_of_students += 1;
                B.issue_book(type, no_of_students);
                break;
              }
            else if (answer == 'N')
              {
                menu();
                break;
              }
            else if (answer == 'S')
              {
                B.search();
                break;
              }
            else
              {
                cout << "Invalid Input.";
              }
          }
      }
    else if (type == "Staff")
      {
        cout << "Enter name = ";
        cin >> name;
        system("cls");
        cout << "Enter ID = ";
        cin >> acc_no;
        system("cls");
        cout << "You are registered!\n";
        Staff[no_of_staff + 1].name = name;
        Staff[no_of_staff + 1].acc_no = acc_no;
        char answer;
        while (true)
          {
            cout << "Want to (issue/search) books or nothing(I/S/N) = ";
            cin >> answer;
            system("cls");
            if (answer == 'I')
              {
                no_of_staff += 1;
                B.issue_book(type, no_of_staff);
                break;
              }
            else if (answer == 'N')
              {
                menu();
                break;
              }
            else if (answer == 'S')
              {
                B.search();
                break;
              }
            else
              {
                cout << "Invalid Input.";
              }
          }
      }
    else if (type == "Teacher")
      {
        cout << "Enter name = ";
        cin >> name;
        system("cls");
        cout << "Enter ID = ";
        cin >> acc_no;
        system("cls");
        cout << "You are registered!\n";
        Teachers[no_of_teachers + 1].name = name;
        Teachers[no_of_teachers + 1].acc_no = acc_no;
        char answer;
        while (true)
          {
            cout << "Want to (issue/search) books or nothing(I/S/N) = ";
            cin >> answer;
            system("cls");
            if (answer == 'I')
              {
                no_of_teachers += 1;
                B.issue_book(type, no_of_teachers);
                break;
              }
            else if (answer == 'N')
              {
                menu();
                break;
              }
            else if (answer == 'S')
              {
                B.search();
                break;
              }
            else
              {
                cout << "Invalid Input.";
              }
          }
      }
  }
void name_not_found()
  {
    cout << "You are not registered yet.\n";
    char answer;
    while (true)
      {
        cout << "Want to register (Y/N) = ";
        cin >> answer;
        system("cls");
        if (answer == 'Y')
          {
            register_user();
            break;
          }
        else if (answer == 'N')
          {
            cout << "Thanks for visiting.";
            menu();
            break;
          }
        else
          {
            cout << "Invalid Response.";
          }
      }
  }
int main()
  {
    Students[0].name = "Muhammad Dawood Iqbal";
    Students[0].acc_no = 957980934;
    Students[0].list_books_issued[0] = {"The Art of Assembly Language, 2nd Edition"};
    Students[0].return_date[0] = {1705431600};
    Students[0].fine[0] = {70};
    Students[0].issued_books = 1;
    // Book  C;
    // C.issue_book("Student");
    menu();
  }