#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<sstream>
using namespace std;
class lms
{
public:
    void menu();
    void admin();
    void admin_menu();
    void add();
    void st_issue();
    void st_return();
    void show_bk();
    void student();
    void issue();
    void return_();
    void show_bok();
};
void lms::menu()
{
    system("cls");
    int choice,ch;
	string email,password;
	cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t                                            LIBRARY MAIN MENU                                            \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t                                            ENTER YOUR CHOICE                                            \t\t\t\t";
	cout<<"\n\t\t\t                                            1)- ADMINISTRATOR                                            \t\t\t\t";
	cout<<"\n\t\t\t                                            2)- CUSTOMER                                                 \t\t\t\t";
	cout<<"\n\t\t\t                                            3)- EXIT                                                     \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t\t\t\t\t\t -> ";
	cin>>choice;
	switch(choice)
	{
		case 1:
            admin();
            break;
		case 2:
			student();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"\n\t\t\t                                              INVALID CHOICE                                             \t\t\t\t";
			menu();
			break;
	}
}
void lms::admin()
{
    system("cls");
    string email,password;
    int ch;
    cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
    cout<<"\n\t\t\t                                            ENTER ADMIN EMAIL                                            \t\t\t\t";
    cout<<"\n\t\t\t\t\t\t\t\t -> ";
    cin>>email;
    cout<<"\n\t\t\t                                            ENTER PASSWORD                                               \t\t\t\t";
    cout<<"\n\t\t\t\t\t\t\t\t -> ";
    cin>>password;
    if(email=="admin123" && password=="admin")
    {
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                           SUCCESSFULLY  LOGIN                                           \t\t\t\t";
        admin_menu();
    }
    else
    {
        cout<<"\n\t\t\t                                      INVALID USERNAME AND PASSWORD                                      \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR CHOICE                                            \t\t\t\t";
        cout<<"\n\t\t\t                                            1)- TRY AGAIN                                                \t\t\t\t";
        cout<<"\n\t\t\t                                            2)- GO BACK                                                  \t\t\t\t";
        cout<<"\n\t\t\t                                            3)- EXIT                                                     \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>ch;
        if(ch==1)
        {
            admin();
        }
        else if(ch==2)
        {
            menu();
        }
        else if(ch==3)
        {
            exit(0);
        }
        else
        {
            cout<<"\n\t\t\t                                              INVALID CHOICE                                             \t\t\t\t";
        }
    }
}
void lms::admin_menu()
{
    int chi;
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR CHOICE                                            \t\t\t\t";
        cout<<"\n\t\t\t                                            1)- ADD A BOOK                                               \t\t\t\t";
        cout<<"\n\t\t\t                                            2)- STUDENT RETURN BOOK                                      \t\t\t\t";
        cout<<"\n\t\t\t                                            3)- STUDENT ISSUE BOOK                                       \t\t\t\t";
        cout<<"\n\t\t\t                                            4)- LIST OF BOOKS                                            \t\t\t\t";
        cout<<"\n\t\t\t                                            5)- GO BACK                                                  \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>chi;
        if(chi==1)
        {
            add();
        }
        else if(chi==2)
        {
            st_return();
        }
        else if(chi==3)
        {
            st_issue();
        }
        else if(chi==4)
        {
            show_bk();
        }
        else if(chi==5)
        {
            menu();
        }
        else
        {
            cout<<"\n\t\t\t                                              INVALID CHOICE                                             \t\t\t\t";
        }
}
void lms::add()
{
    system("cls");
    string a,b,c;
    double d;
    int e,f;
    MYSQL* conn;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn){
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER BOOK ID                                                \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>d;
        getline(cin,a);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER BOOK NAME                                              \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,b);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER AUTHOR                                                 \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,c);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER PRICE                                                  \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>e;
        int qstate=0;
        stringstream ss;
        ss<<"INSERT INTO book_add (name,id,author,price) VALUES ('"<<b<<"','"<<d<<"','"<<c<<"','"<<e<<"')";
        string query =ss.str();
        const char *q=query.c_str();
        qstate=mysql_query(conn,q);
        if(qstate == 0){
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                         BOOK ADDED SUCCESSFULLY                                         \t\t\t\t";
        }
        else{
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                            OPERATION FAILED                                             \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        }
        admin_menu();
    }
    else{
        cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                           SOMETHING WENT WRONG                                          \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
    }
    admin();
}
void lms::student()
{
    int choice;
    cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t                                            STUDENT MAIN MENU                                            \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t                                            ENTER YOUR CHOICE                                            \t\t\t\t";
	cout<<"\n\t\t\t                                            1)- ISSUE A BOOK                                             \t\t\t\t";
	cout<<"\n\t\t\t                                            2)- RETURN A BOOK                                            \t\t\t\t";
	cout<<"\n\t\t\t                                            3)- AVAILABLE BOOK                                           \t\t\t\t";
	cout<<"\n\t\t\t                                            4)- GO BACK                                                  \t\t\t\t";
	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
	cout<<"\n\t\t\t\t\t\t\t\t -> ";
	cin>>choice;
	switch(choice)
	{
    case 1:
        issue();
        break;
    case 2:
        return_();
        break;
    case 3:
        show_bok();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"\n\t\t\t                                              INVALID CHOICE                                             \t\t\t\t";
        student();
        break;
	}
}
void lms::show_bok()
{
    system("cls");
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn)
    {
        int qstate=mysql_query(conn,"SELECT id,name,author,price FROM book_add");
        if(!qstate)
        {
            res=mysql_store_result(conn);
            	cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
                cout<<"\n\t\t\t            BOOK ID            BOOK NAME             AUTHOR                   PRICE                    \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\t\t\t            "<<row[0]<<"\t       "<<row[1]<<"\t\t     "<<row[2]<<"\t  \t      "<<row[3];
            }
        }
    }
    else{
        cout<<"not\n";
    }
    student();
}
void lms::show_bk()
{
    system("cls");
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn)
    {
        int qstate=mysql_query(conn,"SELECT id,name,author,price FROM book_add");
        if(!qstate)
        {
            res=mysql_store_result(conn);
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            	cout<<"\n\t\t\t                                                BOOK RECORD                                               \t\t\t\t";
            	cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
                cout<<"\n\t\t\t            BOOK ID            BOOK NAME             AUTHOR                   PRICE                      \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\t\t\t            "<<row[0]<<"\t       "<<row[1]<<"\t\t     "<<row[2]<<"\t  \t      "<<row[3];
            }
        }
    }
    else{
        cout<<"not\n";
    }
    admin_menu();
}
void lms::issue()
{
    system("cls");
    string a,b,c;
    double d;
    int e,f;
    MYSQL* conn;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn){
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR STUDENT ID                                        \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>d;
        getline(cin,a);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR NAME                                              \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,b);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR COURSE                                            \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,c);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER BOOK ID                                                \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>e;

        int qstate=0;
        stringstream ss;
        ss<<"INSERT INTO issue_record (id,name,course,book_id) VALUES ('"<<d<<"','"<<b<<"','"<<c<<"','"<<e<<"')";
        string query =ss.str();
        const char *q=query.c_str();
        qstate=mysql_query(conn,q);
        if(qstate == 0){
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                         BOOK ISSUED SUCCESSFULLY                                        \t\t\t\t";

        }
        else{
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                            OPERATION FAILED                                             \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        }
        student();
    }
    else{
        cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                           SOMETHING WENT WRONG                                          \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";

    }
    student();
}
void lms::return_()
{
    system("cls");
    string a,b,c;
    double d;
    int e,f;
    MYSQL* conn;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn){
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR STUDENT ID                                        \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>d;
        getline(cin,a);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR NAME                                              \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,b);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER YOUR COURSE                                            \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        getline(cin,c);
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                            ENTER BOOK ID                                                \t\t\t\t";
        cout<<"\n\t\t\t\t\t\t\t\t -> ";
        cin>>e;

        int qstate=0;
        stringstream ss;
        ss<<"INSERT INTO return_record (student_id,name,course,book_id) VALUES ('"<<d<<"','"<<b<<"','"<<c<<"','"<<e<<"')";
        string query =ss.str();
        const char *q=query.c_str();
        qstate=mysql_query(conn,q);
        if(qstate == 0){
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                       BOOK RETURNED SUCCESSFULLY                                        \t\t\t\t";

        }
        else{
            cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            cout<<"\n\t\t\t                                            OPERATION FAILED                                             \t\t\t\t";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        }
        student();
    }
    else{
        cout<<"\n\t\t\t                                                                                                         \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
        cout<<"\n\t\t\t                                           SOMETHING WENT WRONG                                          \t\t\t\t";
        cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";

    }
    student();
}
void lms::st_issue()
{
    system("cls");
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn)
    {
        int qstate=mysql_query(conn,"SELECT id,name,course,book_id FROM issue_record");
        if(!qstate)
        {
            res=mysql_store_result(conn);
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            	cout<<"\n\t\t\t                                              ISSUE RECORD                                               \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
                cout<<"\n\t\t\t            STUDENT ID               STUDENT NAME        COURSE             BOOK ID                      \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\t\t\t            "<<row[0]<<"\t\t     "<<row[1]<<"\t\t "<<row[2]<<"\t\t    "<<row[3];
            }
        }
    }
    else{
        cout<<"not\n";
    }
    admin_menu();
}
void lms::st_return()
{
    system("cls");
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn =mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "admin", "admin", "lms", 0, NULL, 0);
    if(conn)
    {
        int qstate=mysql_query(conn,"SELECT student_id,name,course,book_id FROM return_record");
        if(!qstate)
        {
            res=mysql_store_result(conn);
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            	cout<<"\n\t\t\t                                              RETURN RECORD                                              \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
                cout<<"\n\t\t\t            STUDENT ID               STUDENT NAME        COURSE             BOOK ID                      \t\t\t\t";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------------------------------\t\t\t\t";
            while(row=mysql_fetch_row(res))
            {
                cout<<"\n\t\t\t            "<<row[0]<<"\t\t     "<<row[1]<<"\t\t "<<row[2]<<"\t\t    "<<row[3];
            }
        }
    }
    else{
        cout<<"not\n";
    }
    admin_menu();
}
int main()
{
    lms l;
    l.menu();
    return 0;
}
