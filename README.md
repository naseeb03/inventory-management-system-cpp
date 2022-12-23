<h3>Inventory Management System<h3/>
Welcome to the Inventory Management System! This program is designed to help manage and track the inventory of the Faculty College of Information and Technology.

<h3>Instructions<h3/>
This is an individual project and you must complete it on your own.<br />
Code should be well organized and variables should have proper names.<br />
The project must be uploaded to Github with a README file explaining the project. <br />
Any plagiarism in this project may result in a penalty ranging from zero sessional marks to an F grade in this course.<br />
If you have any other good ideas, you may discuss them with your instructor. The idea will be approved if it has at least the same level of functionality as the given project. Be sure to read the project requirements thoroughly and carefully.
<h3>Project Requirements<h3 />
The Faculty College of Information and Technology is responsible for providing necessary resources to its faculty members, such as stationery items, accessories, and machines. The current system for keeping track of this inventory is slow and needs to be replaced. As a student of this institute, it is your responsibility to provide a software solution to manage the inventory.

<h3>The system should be able to perform the following functionality:<h3 />

Add inventory items<br />
View all inventory items<br />
Search for a specific inventory item<br />
Edit an inventory item (including item count)<br />
Delete an inventory item<br />
Assign an inventory item to a faculty member<br />
Retrieve an inventory item from a faculty member<br />
View the list of faculty members who have borrowed a specific item<br />
Each inventory item is an instance of a structure called InventoryItem. It has the following attributes:

Name<br />
Item ID<br />
Category<br />
Item count<br />
Allocated to (an array containing the names or additional information of faculty members who have borrowed the item)
When an item is assigned to a faculty member, their name (or additional information) is added to the Allocated to array and the Item count of that specific item is decreased by one. When an inventory item is retrieved, the information of that faculty member is removed from the list and the Item count is increased by one.


