#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

const int totalFaculty = 56;
const int MAX = 50;

struct InventoryItem
{
    char name[MAX];
    char item_id[MAX];
    char category[MAX];
    int item_count;
    char allocated_to[MAX][totalFaculty] = {};
};


//FUNCTION PROTOTYPES:
void addItem (InventoryItem);

void viewItems (InventoryItem);

void searchItem (InventoryItem);

void editItem (InventoryItem);

void delItem (InventoryItem);

void assignItem (InventoryItem);

void retrieveItem (InventoryItem);

void list (InventoryItem);

int main()
{
    InventoryItem item;
    int option;
    char choice;

    do
    {
        cout << "Select an option (1-9)\n";
        cout << "1. Add an Inventory Item\n";
        cout << "2. View an Inventory Items\n";
        cout << "3. Search an Inventory Item\n";
        cout << "4. Edit an Inventory Item\n";
        cout << "5. Delete an Inventory Item\n";
        cout << "6. Assign an Inventory Item\n";
        cout << "7. Retrieve an Inventory Item\n";
        cout << "8. List of Faculty Members who have Borrowed a Specific Item\n";
        cout << "9. Close Program\n";
        cin >> option;

        switch(option)
        {
            case 1:
                addItem (item);
                break;
            case 2:
                viewItems (item);
                break;
            case 3:
                searchItem (item);
                break;
            case 4:
                editItem (item);
                break;
            case 5:
                delItem (item);
                break;
            case 6:
                assignItem (item);
                break;
            case 7:
                retrieveItem (item);
                break;
            case 8:
                list (item);
                break;
            case 9:
                cout << "Program Ending!";
                return 0;
        }
        cout << "Wish to Continue? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);

    } while (choice=='Y');

    return 0;
}

void addItem (InventoryItem item)
{
    bool flag = false;
    char itemId[MAX];

    ofstream inventory;
    inventory.open("inventory_item_data.txt", ios::app | ios::binary);

    cout << "Enter Item Name: ";
    cin >> item.name;
    cout << "Enter Item Id: ";
    cin >> item.item_id;
    cout << "Enter Item Category: ";
    cin >> item.category;
    cout << "Enter Quantity: ";
    cin >> item.item_count;
    cout << "----------------------------------------\n";
    
    inventory.write(reinterpret_cast<char *>(&item), sizeof(item));
    inventory.close();
}

void viewItems (InventoryItem item)
{
    ifstream inventory;
    inventory.open("inventory_item_data.txt", ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof ())
    {
        cout << setw(20) << left << "Item Name" << ": " <<  item.name << endl;
        cout << setw(20) << left << "Item Id" << ": " <<  item.item_id << endl;
        cout << setw(20) << left << "Item Category" << ": " << item.category << endl;
        cout << setw(20) << left << "Item Quantity" << ": " << item.item_count << endl;
        cout << "----------------------------------------\n";
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    inventory.close();
}

void searchItem (InventoryItem item)
{
    bool flag = true;
    char search[MAX];

    cout << "Enter Item ID to Search: ";
    cin >> search;

    ifstream inventory;
    inventory.open("inventory_item_data.txt", ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof())
    {
        if (!stricmp(search, item.item_id))
        {
            cout << setw(20) << left << "Item Name" << ": " <<  item.name << endl;
            cout << setw(20) << left << "Item Id" << ": " <<  item.item_id << endl;
            cout << setw(20) << left << "Item Category" << ": " << item.category << endl;
            cout << setw(20) << left << "Item Quantity" << ": " << item.item_count << endl;
            flag = false;
        }
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag)
        cout << "No Match!\n";
        cout << "----------------------------------------\n";

    inventory.close();
}

void editItem (InventoryItem item)
{
    bool flag = false;
    char recChange[MAX];

    cout << "Enter Item ID to Change: ";
    cin >> recChange;

    fstream inventory;
    inventory.open("inventory_item_data.txt", ios::in | ios::out | ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof())
    {
        if (!stricmp(recChange, item.item_id))
        {
            cout << setw(20) << left << "Item Name" << ": " <<  item.name << endl;
            cout << setw(20) << left << "Item Id" << ": " <<  item.item_id << endl;
            cout << setw(20) << left << "Item Category" << ": " << item.category << endl;
            cout << setw(20) << left << "Item Quantity" << ": " << item.item_count << endl;
            cout << "----------------------------------------\n";
            flag = true;
            break;
        }
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag)
    {
        cout << "Enter New Data\n";
        cout << "Enter Item Name: ";
        cin >> item.name;
        cout << "Enter Item Id: ";
        cin >> item.item_id;
        cout << "Enter Item Category: ";
        cin >> item.category;
        cout << "Enter Quantity: ";
        cin >> item.item_count;
        int x = inventory.tellp();
        inventory.seekp((x - sizeof(item)), ios::beg);
        inventory.write(reinterpret_cast<char *>(&item), sizeof(item));
    }
    else
        cout << "No Such Item Found!\n";
        cout << "----------------------------------------\n";

    inventory.close();
}

void delItem (InventoryItem item)
{
    bool flag = false;
    char del[MAX];

    cout << "Enter Item ID to Delete: ";
    cin >> del;

    ifstream old_inventory;
    ofstream new_inventory;
    old_inventory.open("inventory_item_data.txt", ios::binary);
    new_inventory.open("new_inventory.txt", ios::binary | ios::app);
    old_inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!old_inventory.eof())
    {
        if (stricmp (del, item.item_id))
            new_inventory.write(reinterpret_cast<char *>(&item), sizeof(item));
        else
            flag = true;
        old_inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag)
        cout << "Item Deleted!\n";
    else
        cout << "No Such Item Found!\n";
        cout << "----------------------------------------\n";

    old_inventory.close();
    new_inventory.close();
    remove("inventory_item_data.txt");
    rename("new_inventory.txt", "inventory_item_data.txt");
}

void assignItem (InventoryItem item)
{
    char name[MAX], itemAssign[MAX];
    bool flag = true;
    
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Item ID To Assign: ";
    cin >> itemAssign;

    fstream inventory;
    inventory.open("inventory_item_data.txt", ios::in | ios::out | ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof())
    {
        if (!stricmp (itemAssign, item.item_id) && item.item_count>0)
        {
            item.item_count--;
            for (int i=0; i<totalFaculty; i++)
                if (!strcmp(item.allocated_to[i], ""))
                {
                    strcpy(item.allocated_to[i], name);
                    break;
                }
            int x = inventory.tellp();
            inventory.seekp((x - sizeof(item)), ios::beg);
            inventory.write(reinterpret_cast<char *>(&item), sizeof(item));
            flag = false;
            break;
        }
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag)
        cout << "Sorry Mr." << name <<  ", No Such Item Found!\n";
    else
        cout << "Item Assigned!\n";
        cout << "----------------------------------------\n";

    inventory.close();
}

void retrieveItem (InventoryItem item)
{
    char name[MAX], itemAssign[MAX];
    bool flag1 = true, flag2 = false;

    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter Item ID To Retrieve: ";
    cin >> itemAssign;

    fstream inventory;
    inventory.open("inventory_item_data.txt", ios::in | ios::out | ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof())
    {
        if (!stricmp (itemAssign, item.item_id))
        {
            item.item_count++;
            for (int i=0; i<totalFaculty; i++)
            {
                if (!strcmp(item.allocated_to[i], name))
                    flag2 = true;
                if (flag2)
                    strcpy(item.allocated_to[i], item.allocated_to[i+1]);
                if (!strcmp(item.allocated_to[i], ""))
                    break;
            }
            int x = inventory.tellp();
            inventory.seekp((x - sizeof(item)), ios::beg);
            inventory.write(reinterpret_cast<char *>(&item), sizeof(item));
            flag1 = false;
            break;
        }
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag1)
        cout << "Sorry Mr." << name <<  ", No Such Item Found!\n";
    else if (!flag2)
        cout << "Sorry Mr." << name <<  ", You Haven't Assigned This Item!\n";
    else
        cout << "Item Retrieved!\n";
        cout << "----------------------------------------\n";

    inventory.close();

}

void list (InventoryItem item)
{
    bool flag = true;
    char borrowItem[MAX];

    cout << "Enter Item ID: ";
    cin >> borrowItem;

    ifstream inventory;
    inventory.open("inventory_item_data.txt", ios::binary);
    inventory.read(reinterpret_cast<char *>(&item), sizeof(item));

    while (!inventory.eof())
    {
        if (!stricmp(borrowItem, item.item_id))
        {
            for (int i=0; i<totalFaculty; i++)
            {
                if (!strcmp(item.allocated_to[i], ""))
                    break;
                else
                    cout << "Person " << i+1 << ": " << item.allocated_to[i] << endl;
            }
            flag = false;
        }
        inventory.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    if (flag)
        cout << "No Such Item Found!\n";
        cout << "----------------------------------------\n";

    inventory.close();
}
