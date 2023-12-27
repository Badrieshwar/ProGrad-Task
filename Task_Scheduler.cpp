#include<bits/stdc++.h>
#include<ctime>

using namespace std;

class Task {
public:
    string title;
    string description;
    string dueDate;

    Task(string& t, string& d, string& dd)
    {
    	this->title=t;
    	this->description=d;
    	this->dueDate=dd;
	}
};

class TaskScheduler {
private:
    vector<Task> tasks;

public:
    void addTask(string& title, string& description, string& dueDate) {
        Task newTask(title, description, dueDate);
        tasks.push_back(newTask);
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
        } else {
            cout << "Task List:\n";
            cout << setw(20) << "Title" << setw(30) << "Description" << setw(15) << "Due Date" << endl;
            cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;

            for (auto& task : tasks) {
                cout << setw(20) << task.title << setw(30) << task.description << setw(15) << task.dueDate << endl;
            }
        }
    }

    void removeTask(string& title) {
		auto temp=tasks.begin();
		for(auto it=tasks.begin();it!=tasks.end();it++)
		{
			
			if(it->title==title) temp=it;
		}

        if (temp != tasks.end()) {
            tasks.erase(temp);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Task not found." << endl;
        }
    }
    
    void pendingTasks()
    {
	    time_t t = time(0);
	    tm* now = localtime(&t);
		cout << "Task List:\n";
        cout << setw(20) << "Title" << setw(30) << "Description" << setw(15) << "Due Date" << endl;
        cout << setfill('-') << setw(65) << "-" << setfill(' ') << endl;
		for(auto &it:tasks)
		{
			int year=0,month=0,day=0;
			string date=it.dueDate,d="",m="",y="";
			d=date.substr(0,2);
			m=date.substr(3,2);
			y=date.substr(6,4);
			day=(d[0]-'0')*10+(d[1]-'0');
			month=(m[0]-'0')*10+(m[1]-'0');
			for(int i=0;i<y.size();i++) year=(y[i]-'0')+year*10;
			if(year<now->tm_year+1900) {
				cout << setw(20) << it.title << setw(30) << it.description << setw(15) << it.dueDate << endl;
				continue;
			}
			else if(year==now->tm_year+1900 && month<now->tm_mon+1){
				cout << setw(20) << it.title << setw(30) << it.description << setw(15) << it.dueDate << endl;
				continue;
			}
			else if(year==now->tm_year+1900 && month==now->tm_mon+1 && day<now->tm_mday){
				cout << setw(20) << it.title << setw(30) << it.description << setw(15) << it.dueDate << endl;
				continue;
			}
			
		}
	}
	
	void updateDueDateOfPendingTask(string &title,string &dueDate)
	{
		for(auto &it:tasks)
		{
			if(it.title==title)
			{
				 it.dueDate=dueDate;
				 cout << "DueDate of Pending Task is updated successfully!" << endl;
			}
		}
	}
};

int main() {
    TaskScheduler scheduler;

    while (true) {
        cout << "\nTask Scheduler Menu:\n";
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. pending Tasks\n5. update DueDate Of Pending Task\n6. Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, description, dueDate;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter task description: ";
                getline(cin, description);
                cout << "Enter due date: ";
                cin >> dueDate;

                scheduler.addTask(title, description, dueDate);
                break;
            }
            case 2:
                scheduler.viewTasks();
                break;
            case 3: {
                string title;
                cout << "Enter the title of the task to remove: ";
                cin.ignore();
                getline(cin, title);

                scheduler.removeTask(title);
                break;
            }
            case 4:{
            	scheduler.pendingTasks();
                break;
            }
            case 5:{
            	string title, dueDate;
                cout << "Enter task title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter updated due date: ";
                cin >> dueDate;
            	scheduler.updateDueDateOfPendingTask(title,dueDate);
            	break;
            }
            case 6:{
            	cout << "Exiting the program. Goodbye!\n";
            }
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
