#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

#include <string>

class GroceryItem {
private: 
	std::string m_itemName;
	int m_itemFrequency;

public:
//Constructors 
	GroceryItem();
	GroceryItem(std::string name, int frequency);


//Getters and Setters 
	std::string getItemName() const;
	int getItemFrequency() const;
	void setItemName(std::string name);
	void setItemFrequency(int frequency);

//Helper to increment frequency
	void incrementFrequency(int amount = 1);
};

#endif