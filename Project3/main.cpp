#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <cctype>
#include "GroceryItem.h" 

using namespace std;

// Constants for menu selections to improve readability.
const int MENU_LOOKUP = 1;
const int MENU_PRINT_REPORT = 2;
const int MENU_HISTOGRAM = 3;
const int MENU_EXIT = 4;

// Function declarations
map<string, GroceryItem> loadFrequencyData(const string& filename);
void writeBackupFile(const map<string, GroceryItem>& groceryMap, const string& backupFilename);
void displayMenu();
string capitalizeFirstLetter(string word);

/**
 * Main function controlling the program loop and user selections.
 */
int main() {
	const string inputFilename = "CS210_Project_Three_Input_File.txt";
	const string backupFilename = "frequency.dat";

	int choice = 0;

	do {
		displayMenu();
		cout << "Enter your selection (1-4): ";

		// Input validation for menu choice
		if (!(cin >> choice)) {
			cout << "\n[Error] Invalid input\n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		
		// Always reload data on each choice
		map<string, GroceryItem> groceryMap = loadFrequencyData(inputFilename);

		// Automatically write backup file at program startup
		writeBackupFile(groceryMap, backupFilename);

		if (choice == MENU_LOOKUP) {
			// Menu Option One: Look up item frequency.
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
		else if (choice == MENU_PRINT_REPORT) {
			// Menu Option Two: Print all items and frequencies
			cout << "\n   CORNER GROCER PURCHASE REPORT   \n";
			for (map<string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
				cout << left << setw(15) << it->second.getItemName()
					<< " | " << it->second.getItemFrequency() << endl;
			}
		}
		else if (choice == MENU_HISTOGRAM) {
			// Menu Option Three: Print histogram report
			cout << "\n   CORNER GROCER HISTOGRAM REPORT   \n";
			for (map<string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
				cout << left << setw(15) << it->second.getItemName() << " ";
				for (int i = 0; i < it->second.getItemFrequency(); ++i) {
					cout << "*";
				}
				cout << endl;
			}
		}
		else if (choice == MENU_EXIT) {
			// Menu Option Four = Exit
			cout << "\nThank you for using the tracking program.\n";
		}
		else {
			cout << "\n[Error] invalid choice.\n\n";
		}

	} while (choice != MENU_EXIT);

	return 0;
}

/**
 * Loads and aggregates data from the input file into a map.
 * @param filename The path to the input text file.
 * @return A map containing grocery item names as keys and GroceryItem objects as values.
 */
map<string, GroceryItem> loadFrequencyData(const string& filename) {
	map<string, GroceryItem> groceryMap;
	ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		cerr << "[Error] Could not open file. " << filename << endl;
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

/** 
 * Writes backup frequency data to an output file.
 * @param groceryMap The map containing grocery items and frequencies.
 * @param backupFilename The destination filename for the backup data.
 */
void writeBackupFile(const map<string, GroceryItem>& groceryMap, const string& backupFilename) {
	ofstream backupFile(backupFilename);

	if (!backupFile.is_open()) {
		cerr << "[Error] Could not create backup. " << backupFilename << endl;
		return;
	}

	for (map<string, GroceryItem>::const_iterator it = groceryMap.begin(); it != groceryMap.end(); ++it) {
		backupFile << it->second.getItemName() << " " << it->second.getItemFrequency() << endl;
	}
	backupFile.close();
}

/**
 * Displays the main menu options.
 */
void displayMenu() {
	cout << "\n   CORNER GROCER MENU   \n";
	cout << "1. Look up item frequency\n";
	cout << "2. Print all items and frequencies\n";
	cout << "3. Print histogram of item frequencies\n";
	cout << "4. Exit\n";
}

/**
 * Normalizes a word by capitalizing the first letter and making the rest lowercase.
 * @param word The string to normalize.
 * @return The normalized string.
 */
string capitalizeFirstLetter(string word) {
	if (word.empty()) return word;
	word[0] = toupper(word[0]);
	for (size_t i = 1; i < word.length(); ++i) {
		word[i] = tolower(word[i]);
	}
	return word;
}
