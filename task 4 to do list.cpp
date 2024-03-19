#include <iostream>
#include <string>
using namespace std;

class Task{
protected:
    string taskdescription;
    bool taskcompleted;

public:
    Task(string desc) : taskdescription(desc), taskcompleted(false) {}

    void markTaskCompleted() 
	{
        taskcompleted = true;
    }

    void markTaskPending() 
	{
        taskcompleted = false;
    }

    bool isTaskCompleted() 
	{
        return taskcompleted;
    }

    string getTaskDescription() 
	{
        return taskdescription;
    }
};

class ToDoList{
private:
    static const int MAX_TASKS = 50;
    Task* tasks[MAX_TASKS];
    int numtasks;

public:
    ToDoList() : numtasks(0) {}

    void addTask(string desc) 
	{
        if (numtasks < MAX_TASKS) 
		{
            tasks[numtasks++] = new Task(desc);
            cout << "Task added." << endl;
            cout << endl;
        } 
		else 
		{
            cout << "List full. Can not add more tasks to your To-Do List." << endl;
        }
    }

    void viewTasks() 
	{
        if (numtasks == 0) 
		{
            cout << "No tasks in the list." << endl;
        } 
		else 
		{
            cout << "Your Tasks:" << endl;
            for (int i = 0; i < numtasks; ++i) 
			{
                cout << (i + 1) << ". " << tasks[i]->getTaskDescription();
                if (tasks[i]->isTaskCompleted()) 
				{
                    cout << " - Completed" << endl;
                } 
				else 
				{
                    cout << " - Pending" << endl;
                }
            }
            cout << endl;
        }
    }

    void markcompleted(int index) 
	{
        if (index >= 1 && index <= numtasks) 
		{
            tasks[index-1]->markTaskCompleted();
            cout << "Task marked as completed." << endl;
        } 
		else 
		{
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index) 
	{
        if (index >= 1 && index <= numtasks) 
		{
            delete tasks[index-1];
            for (int i = index-1; i<numtasks-1; ++i) 
			{
                tasks[i] = tasks[i + 1];
            }
            numtasks--;
            cout << "Task removed from your list." << endl;
        } 
		else 
		{
            cout << "Invalid task index." << endl;
        }
    }

    ~ToDoList() 
	{
        for (int i = 0; i < numtasks; ++i) 
		{
            delete tasks[i];
        }
    }
};

int main() 
{
    ToDoList todo;
    int choice;
    string desc;
    int index;
    
    cout << "1. Add Task "<< endl;
	cout << "2. View Tasks" << endl;
	cout << "3. Mark Task as Completed" << endl;
	cout << "4. Remove Task" << endl;
	cout << "5. Exit" << endl;
    
    do 
	{
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) 
		{
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, desc);
                todo.addTask(desc);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markcompleted(index);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
