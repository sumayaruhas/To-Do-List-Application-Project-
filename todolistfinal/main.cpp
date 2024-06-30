#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>
#include <sstream>
using namespace std;

class Task{
public:
    string taskno,name,description,dueDate;
    bool complete;

void welcome(){
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t**************************************"<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t=              Welcome To            ="<<endl;
        cout<<"\t\t\t=        To-Do List Application      ="<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t=                                    ="<<endl;
        cout<<"\t\t\t**************************************"<<endl;
conti();

}
    void opt(){
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t1. Add Task"<<endl;
        cout<<"\t\t\t\t2. Display Tasks"<<endl;
        cout<<"\t\t\t\t3. Mark Task as Completed"<<endl;
        cout<<"\t\t\t\t4. Update Tasks"<<endl;
        cout<<"\t\t\t\t5. Delete Task"<<endl;
        cout<<"\t\t\t\t6. Exit"<<endl;

        cout<<"\t\t\t\tEnter Your Choice : ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                system("cls");
                addTask();
                break;
            case 2:
                system("cls");
                displayTask();
                break;
            case 3:
                system("cls");
                markTask();
                break;
            case 4:
                system("cls");
                updateTask();
                break;
            case 5:
                system("cls");
                deleteTask();
                break;
            case 6:
                system("cls");
                 cout<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\tThank You For Using My App!"<<endl;
            exit(0);

            default:
                cout<<"Invalid Input! Please Try Again."<<endl;
                conti();
        }
    }

    void conti(){
        string xx;
        cout<<endl<<endl<<"\t\t\tPress Any Key To Continue : ";
        cin>>xx;
        system("cls");
        opt();
    }

    void addTask()
    {
        ofstream todo;
        todo.open("tododata.txt", ios::app);
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\tEnter Task No                    : ";
        cin>>taskno;
        todo<<taskno<<'\t';
        cout<<"\t\t\t\tEnter Task Name                  : ";
        cin.ignore();
        getline(cin,name);
        todo<<name<<'\t';
        cout<<"\t\t\t\tEnter Description                : ";
        getline(cin,description);
        todo<<description<<'\t';
        cout<<"\t\t\t\tEnter Task Due Date (YYYY-MM-DD) : ";
        getline(cin,dueDate);
        todo<<dueDate<<'\t';
        complete=false;
        todo<<complete<<endl;
        cout<<"\t\t\t\tTask Added Successfully!"<<endl;
       conti();
        todo.close();

    }
void displayTask() {
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
        ifstream display("tododata.txt");
        if (!display) {
            cerr << "\t\t\t\tError opening file!" << endl;
            return;
        }

        string line;
        while (getline(display, line)) {
            stringstream ss(line);
            string taskno, name, description, dueDate;
            bool complete;

            getline(ss, taskno, '\t');
            getline(ss, name, '\t');
            getline(ss, description, '\t');
            getline(ss, dueDate, '\t');
           ss >> complete;

            cout << "\t\t\t\tTask No          : " << taskno << endl;
            cout << "\t\t\t\tTask Name        : " << name << endl;
            cout << "\t\t\t\tTask Description : " << description << endl;
            cout << "\t\t\t\tTask Due Date    : " << dueDate << endl;
            cout<<  "\t\t\t\tCompleted        : "<< (complete?"Yes":"No")<<endl;
            cout<<"\t\t\t\t-------------------------------------"<<endl;

        }
        conti();
        display.close();

    }
    void markTask(){
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        vector<Task> tasks;
        ifstream markt("tododata.txt");

        string line;
        while(getline(markt,line)){
            Task task;
            stringstream ss(line);
            getline(ss, task.taskno, '\t');
            getline(ss, task.name, '\t');
            getline(ss, task.description, '\t');
            getline(ss, task.dueDate, '\t');
            ss >> task.complete;
            tasks.push_back(task);
        }
        markt.close();
        string tasktomark;
        cout<<"\t\t\t\tEnter Task No To Mark as Complete : ";
        cin>>tasktomark;
        int f=0;
        for(auto& task : tasks){
            if(tasktomark==task.taskno){
                f=1;
                task.complete=true;
                break;
            }
        }
        ofstream todo("tododata.txt", ios::trunc);
        for(const auto& task : tasks){
            todo<<task.taskno<<'\t'<<task.name<<'\t'<<task.description<<'\t'<<task.dueDate<<'\t'<<task.complete<<endl;
        }
        cout<<"\t\t\t\tTask Marked as Completed!"<<endl;
        todo.close();
           if(f==0){
            cout<<"\t\t\t\tTask Not Found"<<endl;
            return;
        }
 conti();
    }
    void updateTask(){
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        vector<Task> tasks;
        ifstream update("tododata.txt");

        string line;
        while(getline(update,line)){
            Task task;
            stringstream ss(line);
            getline(ss, task.taskno, '\t');
            getline(ss, task.name, '\t');
            getline(ss, task.description, '\t');
            getline(ss, task.dueDate, '\t');
            ss>>task.complete;
            tasks.push_back(task);
        }
        update.close();
        string uno;
               cout<<"\t\t\t\tEnter Task No To Update          : ";
        cin>>uno;
        auto it = find_if(tasks.begin(),tasks.end(), [&uno](const Task& task){
                        return task.taskno==uno;
                          });
                          if(it != tasks.end()){
                            int cho;
                            cout << "\t\t\t\tWhich field would you like to update?" << endl;
        cout << "\t\t\t\t1. Task Name" << endl;
        cout << "\t\t\t\t2. Task Description" << endl;
        cout << "\t\t\t\t3. Due Date" << endl;
        cout << "\t\t\t\t4. Exit" << endl;
        while(true){
        cout << "\t\t\t\tEnter your choice: ";
        cin >> cho;

        cin.ignore();
                switch (cho) {
            case 1:
                cout << "\t\t\t\tEnter new Task Name: ";
                getline(cin, it->name);
                break;
            case 2:
                cout << "\t\t\t\tEnter new Task Description: ";
                getline(cin, it->description);
                break;
            case 3:
                cout << "\t\t\t\tEnter new Due Date: ";
                getline(cin, it->dueDate);
                break;
            case 4:
                cout<<"\t\t\t\tSaved Successfully! "<<endl;
                {

                ofstream outFile("tododata.txt");
                        for (const auto& t : tasks) {
                            outFile << t.taskno << '\t' << t.name << '\t' << t.description << '\t'
                                    << t.dueDate << '\t' << t.complete << endl;
                        }
                        outFile.close();
                    }
                    cout << "\t\t\t\tTask updated successfully!" << endl;
                    conti();
                    return;
            default:
                cout << "\t\t\t\tInvalid choice!" << endl;
                conti();
        }
}
    }else {
        cout << "\t\t\t\tTask number not found!" << endl;
        conti();
    }
    }


    void deleteTask(){
        cout<<endl<<endl<<endl<<endl<<endl<<endl;
        vector<Task> tasks;
        ifstream markt("tododata.txt");

        string line;
        while(getline(markt,line)){
            Task task;
            stringstream ss(line);
            getline(ss, task.taskno, '\t');
            getline(ss, task.name, '\t');
            getline(ss, task.description, '\t');
            getline(ss, task.dueDate, '\t');
            ss >> task.complete;
            tasks.push_back(task);
        }
        markt.close();
string dlt;
        cout<<"\t\t\t\tEnter Task No to Delete : ";
cin>>dlt;
auto it=remove_if(tasks.begin(),tasks.end(), [&](Task& task){
    return task.taskno==dlt;
});
if(it==tasks.end()){
    cout<<"\t\t\t\tTask Not Found"<<endl;
    conti();
}
tasks.erase(it,tasks.end());
ofstream todo("tododata.txt",ios::trunc);
for(const auto& task : tasks){
            todo<<task.taskno<<'\t'<<task.name<<'\t'<<task.description<<'\t'<<task.dueDate<<'\t'<<task.complete<<endl;
        }
        cout<<"\t\t\t\tTask Deleted Sucessfully"<<endl;
        todo.close();
       conti();
    }

};

int main()
{
    Task t1;
    t1.welcome();
    t1.opt();
}
