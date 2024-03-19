// task 5 library management sysytem
#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
using namespace std;

class BookDatabase{
	string title;
	string author;
	string ISBN;
	bool availability;
	
	public:
		BookDatabase()
		{
			title = "Default";
			author = "Default";
			ISBN = "0-000-00000-0";
			availability = true;
		}
		
		BookDatabase(string t, string a, string no) : title(t), author(a), ISBN(no), availability(true) {}
		
		void setTitle(string title)
		{
			this->title = title;
		}
		
		string getTitle() const
		{ 
		    return title; 
		}
		
		void setAuthor(string author)
		{
			this->author = author;
		}
		
        string getAuthor() const
		{ 
		    return author; 
		}
		
		void setISBN(string ISBN)
		{
			this->ISBN = ISBN;
		}
		
        string getISBN() const
		{ 
		    return ISBN; 
		}
		
		void setAvailability(bool availability) 
		{ 
		    this->availability = availability; 
		}
		
        bool getAvailability() const
		{ 
		    return availability; 
		}
};

class Library{
	BookDatabase* books[100];
	int booknum;
	
	public:
		Library()
		{
			booknum = 0;
		}
		
		void addBook(BookDatabase* b)
		{
			if (booknum < 100)
			{
				books[booknum] = b;
				booknum++;
				cout << "New book added in the library!" << endl;
			}
			else
			{
				cout << "Cannot add more books. Library full." << endl;
			}
		}
		
		void displayInventory()
		{
			cout << "Available Books in Library:" << endl;
			for (int i = 0; i < booknum; i++)
			{
				cout << "Title: " << books[i]->getTitle() << endl;
				cout << "Author: " << books[i]->getAuthor() << endl;
				cout << "ISBN: " << books[i]->getISBN() << endl;
				cout << endl;
			}
		}
		
		void BookSearch()
		{
			int option;
			cout << "1. Search by Book Title" << endl;
			cout << "2. Search by Book Author Name" << endl;
			cout << "3. Search by Book ISBN Number" << endl;
			cout << endl;
			
			cout << "Enter the number for which you want to search by: ";
			cin >> option;
			cout << endl;
			
			switch(option)
			{
				case 1:
					{
						string searchtitle;
						cout << "Enter the title of the book to search for: ";
						cin.ignore();
                        getline(cin, searchtitle);
						for (int i = 0; i < booknum; i++)
						{
							if (books[i]->getTitle() == searchtitle)
							{
								cout << "Book found!" << endl;
								cout << "Title: " << books[i]->getTitle() << endl;
								cout << "Author: " << books[i]->getAuthor() << endl;
								cout << "ISBN: " << books[i]->getISBN() << endl;
								if (books[i]->getAvailability())
									cout << "Available" << endl;
								else
									cout << "Not Available" << endl;
							}
						}
					}
					break;
				case 2:
					{
						string searchauthor;
						cout << "Enter the author of the book to search for: ";
						cin.ignore(); 
                        getline(cin, searchauthor);
						for (int i = 0; i < booknum; i++)
						{
							if (books[i]->getAuthor() == searchauthor)
							{
								cout << "Book found!" << endl;
								cout << "Title: " << books[i]->getTitle() << endl;
								cout << "Author: " << books[i]->getAuthor() << endl;
								cout << "ISBN: " << books[i]->getISBN() << endl;
								if (books[i]->getAvailability())
									cout << "Available" << endl;
								else
									cout << "Not Available" << endl;
							}
						}
					}
					break;
				case 3:
					{
						string searchisbn;
						cout << "Enter the author of the book to search for: ";
						cin >> searchisbn;
						cout << endl;
						for (int i = 0; i < booknum; i++)
						{
							if (books[i]->getISBN() == searchisbn)
							{
								cout << "Book found!" << endl;
								cout << "Title: " << books[i]->getTitle() << endl;
								cout << "Author: " << books[i]->getAuthor() << endl;
								cout << "ISBN: " << books[i]->getISBN() << endl;
								if (books[i]->getAvailability())
									cout << "Available" << endl;
								else
									cout << "Not Available" << endl;
							}
						}
					}
					break;
				default:
					cout << "Incorrect input. Try again." << endl;
			}
		}
		
		void BookCheckout(string ISBN, string borrower)
		{
			for (int i = 0; i < booknum; i++)
			{
				if (books[i]->getISBN() == ISBN && books[i]->getAvailability())
				{
					books[i]->setAvailability(false);
					cout << "Book issued to " << borrower << " ." << endl;
					return;
				}
			}
			cout << "Book not available for issuing." << endl;
		}
		
		void BookReturn(string ISBN, time_t duedate)
		{
			for (int i = 0; i < booknum; i++)
			{
				if (books[i]->getISBN() == ISBN && !books[i]->getAvailability())
				{
					books[i]->setAvailability(true);
					cout << "Book returned by the customer." << endl;
					double fine = finecalculation(duedate);
                    if (fine > 0.0) 
					{
                        cout << "Fine for overdue book: $" << fine << endl;
                    }
					return;
				}
			}
			cout << "Book not returned by the customer yet." << endl;
		}
		
		double finecalculation(time_t duedate)
        {
            const double finerateperday = 0.5;
            time_t currenttime;
            time(&currenttime);
            double userfine = 0.0;

            if (currenttime > duedate) {
                double diffdays = difftime(currenttime, duedate) / (60 * 60 * 24); // Calculate difference in days
                userfine = finerateperday * diffdays;
            }

            return userfine;
        }
};

class Customer{
	BookDatabase* borrowedbook;
	string customername;
	bool returned;
	
	public:
		Customer(BookDatabase* book, string client)
		{
			borrowedbook = book;
			customername = client;
			returned = false;
		}
		
		void returning()
		{
			returned = true;
			borrowedbook->setAvailability(true);
		}
		
		bool checkifreturned()
		{
			return returned;
		}
};

int main()
{
	Library dhalibrary;
	BookDatabase b1("The Train", "Diane Hoh", "1-098-34512-2");
	BookDatabase b2("Harry Potter: Chamber of Secrets", "JK.Rowling", "3-099-66765-3");
	BookDatabase b3("It Ends With Us", "Colleen Hoover", "5-000-33322-9");
	dhalibrary.addBook(&b1);
	dhalibrary.addBook(&b2);
	dhalibrary.addBook(&b3);
	dhalibrary.displayInventory();
	
	int useroption;
	string isbn, borrower, duedate;
	struct tm tm = {};
	time_t date;
	
	cout << "Welcome to The Library Management System" << endl;
	cout << "1. Book Search" << endl;
	cout << "2. Book Checkout" << endl;
	cout << "3. Book Return" << endl;
	cout << "4. Exit" << endl;
	
	do {
		cout << "Enter your choice: ";
		cin >> useroption;

		switch (useroption) {
			case 1:
				dhalibrary.BookSearch();
				break;
			case 2:
				cout << "Enter ISBN of the book to checkout: ";
				cin >> isbn;
				cout << "Enter borrower's name: ";
				cin >> borrower;
				dhalibrary.BookCheckout(isbn, borrower);
				break;
			case 3:
				{
				cout << "Enter ISBN of the book to return: ";
				cin >> isbn;
				cout << "Enter due date (in standard format, e.g., 12-03-24): ";
                cin >> duedate;
                
                stringstream ss2(duedate);
                ss2 >> tm.tm_year; // year - 1900
                tm.tm_year += 100; // Add 100 to convert from years since 1900 to years since 2000
                ss2.ignore(1, '-'); // Ignore the dash separator
                ss2 >> tm.tm_mon; // month (0-11)
                tm.tm_mon -= 1; // Convert from 1-12 to 0-11
                ss2.ignore(1, '-'); // Ignore the dash separator
                ss2 >> tm.tm_mday; // day of the month (1-31)
                date = mktime(&tm);
                
				dhalibrary.BookReturn(isbn, date);
			    }
				break;
			case 4:
				cout << "Exiting program.";
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (useroption != 4);
	
	return 0;
}
