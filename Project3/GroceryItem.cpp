#include "GroceryItem.h"

//Defualt Constructor
GroceryItem::GroceryItem() {
	m_itemName = "";
	m_itemFrequency = 0;
}

//Overloaded  Construcutor
GroceryItem::GroceryItem(std::string name, int frequency) {
	m_itemName = name;
	m_itemFrequency = frequency;
}

//Getters
std::string GroceryItem::getItemName() const {
	return m_itemName;
}
int GroceryItem::getItemFrequency() const {
	return m_itemFrequency;
}

//Setters 
void GroceryItem::setItemName(std::string name) {
	m_itemName = name;
}

void GroceryItem::setItemFrequency(int frequency) {
	m_itemFrequency = frequency;
}

//Increment frequency
void GroceryItem::incrementFrequency(int amount) {
	m_itemFrequency += amount;
}