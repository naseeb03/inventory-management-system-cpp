<h3>Inventory Management System</h3>
Welcome to the Inventory Management System! This system is designed to manage the inventory of resources provided to faculty members at the Faculty College of Information and Technology.

Functionality
The system is able to perform the following functionality:

Add inventory items
View all inventory items
Search inventory items
Edit inventory items (including item count)
Delete inventory items
Assign inventory items
Retrieve inventory items
View the list of faculty members who have borrowed a specific item.
Data Structure
Each inventory item is represented as an instance of a structure called InventoryItem, which has the following attributes:

Name
Item ID
Category
Item count
Allocated to (an array containing information about the faculty members who have borrowed the item)
File Storage
Inventory items are stored and retrieved from a file named inventory_item_data.txt.
