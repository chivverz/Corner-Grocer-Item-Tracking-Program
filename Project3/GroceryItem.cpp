#include "GroceryItem.h"

/**
* Default constructor initializing empty name and zero frequency.
**/	
GroceryItem::GroceryItem() {
	m_itemName = "";
	m_itemFrequency = 0;
}

/** 
* Overloaded constructor initializing member variables with given values.
**/
GroceryItem::GroceryItem(std::string name, int frequency) {
	m_itemName = name;
	m_itemFrequency = frequency;
}

/**
* Returns the item name
*/
std::string GroceryItem::getItemName() const {
	return m_itemName;
}

/**
* Returns the item frequency.
*/

int GroceryItem::getItemFrequency() const {
	return m_itemFrequency;
}

/**
* Updates the item name.
*/
void GroceryItem::setItemName(std::string name) {
	m_itemName = name;
}

/** 
* Updates the item frequency.
**/	

void GroceryItem::setItemFrequency(int frequency) {
	m_itemFrequency = frequency;
}

/**
* Increments frequency by specified amount.
*/

void GroceryItem::incrementFrequency(int amount) {
	m_itemFrequency += amount;
}
