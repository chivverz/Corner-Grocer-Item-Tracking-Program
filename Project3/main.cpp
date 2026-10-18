#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <cctype>
#include "GroceryItem.h" 

using namespace std;

//Function declerations 
map<string, GroceryItem> loadFrequencyData(const string& filename);
void writeBackupFile(const map<string, GroceryItem>& groceryMap, const string& backupFilename);
void displayMenu();
string capitalizeFirstLetter(string word);

int main() {
	const string inputFilename = "CS210_Project_Three_Input_File.txt";
	const string backupFilename = "frequency.dat";

	int choice = 0;

	do {
		displayMenu();
		cout << "Enter your selection (1-4): ";

		//Input validation for menu choice
		if (!(cin >> choice)) {
			cout << "\n[Error] Invalid input\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		//Always reload data on each choice
		map<string, GroceryItem> groceryMap = loadFrequencyData(inputFilename);

		//Automatically write backup file at program startup
		writeBackupFile(groceryMap, backupFilename);

		if (choice == 1) {
			//Menu Option One
			string searchItem;
			cout << "\nEnter the item you want to look for: ";
			cin >> searchItem;
			searchItem = capitalizeFirstLetter(searchItem);

			if (groceryMap.count(searchItem) > 0) {
				cout << "Result: " << searchItem << " was purchased "
					<< groceryMap.at(searchItem).getItemFrequency() << " time(s).\n";
			}
			else {
				cout << "Results: '" << searchItem << "' was not found.\n";
			}
		}
		else if (choice == 2) {
			//Menu Option Two
			cout << "\n   CORNER GROCER PURCHASE REPORT   \n";
			for (auto const& [key, val] : groceryMap) {
				cout << left << setw(15) << val.getItemName()
					<< " | " << val.getItemFrequency() << endl;

			}
		}
		else if (choice == 3) {
			//Menu Option Three 
			cout << "\n   CORNER GROCER HISTOGRAM REPORT   \n";
			for (auto const& [key, val] : groceryMap) {
				cout << left << setw(15) << val.getItemName() << " ";
				for (int i = 0; i < val.getItemFrequency(); ++i) {
					cout << "*";
				}
				cout << endl;
			}

		}
		else if (choice == 4) {
			//Menu Option Four = Exit
			cout << "\nThank you for using the tracking program.\n";

		}
		else {
			cout << "\n[Error] invalid choice.\n\n";
		}

	} while (choice != 4);

	return 0;
}

//Function to load and aggregate data from input file
map<string, GroceryItem> loadFrequencyData(const string& filename) {
	map<string, GroceryItem> groceryMap;
	ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		cerr << "[Error] Could not open file." << filename << endl;
		return groceryMap;
	}

	string itemName;
	while (inputFile >> itemName) {
		itemName = capitalizeFirstLetter(itemName);
		if (groceryMap.count(itemName) > 0) {
			groceryMap.at(itemName).incrementFrequency();
		}
		else {
			GroceryItem newItem(itemName, 1);
			groceryMap.emplace(itemName, newItem);
		}
	}

	inputFile.close();
	return groceryMap;
}

//Function to write backup frequency data 
void writeBackupFile(const map<string, GroceryItem>& groceryMap, const string& backupFilename) {
	ofstream backupFile(backupFilename);

	if (!backupFile.is_open()) {
		cerr << "[Error] Could not creat backup." << backupFilename << endl;
		return;
	}

	for (auto const& [key, val] : groceryMap) {
		backupFile << val.getItemName() << " " << val.getItemFrequency() << endl;


	}
	backupFile.close();

}

//Display menu options
void displayMenu() {
	cout << "\n   CORNER GROCER MENU   \n";
	cout << "1. Look up item frequency\n";
	cout << "2. Print all items and frequencies\n";
	cout << "3. Print histogram of item frequencies\n";
	cout << "4. Exit";
}

//Helper to normalize items strings
string capitalizeFirstLetter(string word) {
	if (word.empty()) return word;
	word[0] = toupper(word[0]);
	for (size_t i = 1; i < word.length(); ++i) {
		word[i] = tolower(word[i]);

	}
	return word;
}
