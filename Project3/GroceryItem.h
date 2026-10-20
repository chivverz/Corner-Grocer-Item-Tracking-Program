#ifndef GROCERY_ITEM_H
#define GROCERY_ITEM_H

#include <string>

/**
 * Class representing an item and its purchase frequency.
 */	
class GroceryItem {
private: 
	std::string m_itemName;
	int m_itemFrequency;

public:
/**
* Default constructor for GroceryItem.
*/
	GroceryItem();
/**
* Overloaded constructor for GroceryItem.
* @param name the name of the grocery item.
* @param frequency the initial purchase frequency.
*/

    GroceryItem(std::string name, int frequency);
/** Gets the name of the item.
* @return the item name as a string.
*/
    std::string getItemName() const;
	
/**
* Gets the purchase frequency of the grocery item.
* @return the frequency as an integer.
*/
	int getItemFrequency() const;

/**
* Sets the name of the grocery item.
* @param name the new name for the item.
*/
    void setItemName(std::string name);

/**
* Sets the purchase frequency of the item.
* @param frequency the new frequency value.
*/

	void setItemFrequency(int frequency);

/**Increments the purchase frequency of the item.
* @param amount the amount to increment by (defaults to 1).
**/

	void incrementFrequency(int amount = 1);
};

#endif
