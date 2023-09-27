#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class item
{
public:
    string item_ID;
    string name;
    int quantity;
    float price;

    void display_item_details()
    {
        cout << "ID: " << item_ID << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
    }

    void update_id()
    {
        cout << "ID: ";
        cin >> item_ID;
        cout << "ID updated successfully!\n";
    }

    /* This method returns name beacuse later in the
    program we use a map(hashmap/dictionary/key-value pairs) to store the
    data, and the key for the "item" objects is their name
    so it will be helpful later */
    string update_name()
    {
        cout << "Name: ";
        cin >> name;
        cout << "Name updated successfully!\n";
        return name;
    }

    void update_quantity()
    {
        int old_quantity = quantity;
        // Error handling
        do
        {
            cout << "Quantity: ";
            cin >> quantity;
            if (quantity < 0)
            {
                cout << "Enter a positive Integer\n";
            }
        } while (quantity < 0);
        // Adjusting price according to new quantity
        price = (price / old_quantity) * quantity;
        cout << "Quantity updated successfully!\n";
    }

    void update_price()
    {
        cout << "Enter price of " << quantity << " units: ";
        cin >> price;
        cout << "Price updated successfully!\n";
    }
};

class inventory
{
public:
    // Using a map(hashmap/dictionary/key-value pairs) for storing data
    map<string, item> inventory_storage;

    void display_inventory()
    {
        map<string, item>::iterator i; // Using an iterator to loop through the map
        cout << "ID\t\tName\tQty\tPrice\n";

        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_print = i->second;
            cout << item_to_print.item_ID << "\t" << item_to_print.name << "\t  " << item_to_print.quantity << "\t" << item_to_print.price << endl;
        }
    }

    void add_new_item(string item_ID, string name, int quantity, float price)
    {
        item new_item;

        new_item.item_ID = item_ID;
        new_item.name = name;
        new_item.quantity = quantity;
        new_item.price = price;

        inventory_storage[new_item.name] = new_item;
        cout << "Item added successfully!\n";
    }

    void remove_item(string key)
    {
        // Error handling. If the item does exist then display "Item not found!"
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            inventory_storage.erase(key);
            cout << "Item erased successfully!\n";
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    void update_id(string key)
    {
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            item item_to_update = inventory_storage.find(key)->second; // ->second means value, ->first means key
            item_to_update.update_id();
            // Storing the new item in the map
            inventory_storage[key] = item_to_update;
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    void update_name(string key)
    {
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            item item_to_update = inventory_storage.find(key)->second;
            // The key is the name attribute so the new_name will be new key
            string new_key = item_to_update.update_name();
            // Storing the item by the new key
            inventory_storage[new_key] = item_to_update;
            // Removing the old copy of the item with the old name
            inventory_storage.erase(key);
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    void update_quantity(string key)
    {
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            item item_to_update = inventory_storage.find(key)->second;
            item_to_update.update_quantity();
            inventory_storage[key] = item_to_update;
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    void update_price(string key)
    {
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            item item_to_update = inventory_storage.find(key)->second;
            item_to_update.update_price();
            inventory_storage[key] = item_to_update;
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    // Method for searching for a specific item and displaying it
    void display_item(string key)
    {
        if (inventory_storage.find(key) != inventory_storage.end())
        {
            item item_to_display = inventory_storage.find(key)->second;
            item_to_display.display_item_details();
        }
        else
        {
            cout << "Item not found!\n";
        }
    }

    // Functions for Calculating the analytics so we can display them in the "show_summary" method
    float total_price()
    {
        float sum = 0;
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_add = i->second;
            sum += item_to_add.price;
        }
        return sum;
    }

    void most_units()
    {
        item most_units = inventory_storage.begin()->second;
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_compare = i->second;
            if (item_to_compare.quantity > most_units.quantity)
            {
                most_units = item_to_compare;
            }
        }
        cout << "Most units: " << most_units.name << '(' << most_units.quantity << ')' << endl;
    }

    int least_units()
    {
        item least_units = inventory_storage.begin()->second;
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_compare = i->second;
            if (item_to_compare.quantity < least_units.quantity)
            {
                least_units = item_to_compare;
            }
        }
        cout << "Least units: " << least_units.name << '(' << least_units.quantity << ')' << endl;
    }

    void most_expensive()
    {
        item most_expensive = inventory_storage.begin()->second;
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_compare = i->second;
            if (item_to_compare.price > most_expensive.price)
            {
                most_expensive = item_to_compare;
            }
        }
        cout << "Most Expensive item: " << most_expensive.name << '(' << most_expensive.price << ')' << endl;
    }

    void least_expensive()
    {
        item least_expensive = inventory_storage.begin()->second;
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_compare = i->second;
            if (item_to_compare.price < least_expensive.price)
            {
                least_expensive = item_to_compare;
            }
        }
        cout << "Least Expensive item: " << least_expensive.name << '(' << least_expensive.price << ')' << endl;
    }

    void show_summary()
    {
        cout << "\n---------SUMMARY---------\n";
        cout << "Total items: " << inventory_storage.size() << endl;
        cout << "Total Price: " << total_price() << endl;
        most_units();
        least_units();
        most_expensive();
        least_expensive();
        cout << endl;
    }

    void read_from_storage()
    {
        ifstream readFile("inventory-storage.txt");
        // Check if the file is empty. If it is then close it and return
        if (readFile.peek() == std::ifstream::traits_type::eof()) // peeks in the file that whether it is eof(end of file) or not
        {
            readFile.close();
            return;
        }
        // Else read from it and store them in the map
        else
        {
            while (true)
            {
                // When reach the end of file break out of the loop
                if (readFile.eof())
                {
                    break;
                }
                item new_item;
                readFile >> new_item.item_ID >> new_item.name >> new_item.quantity >> new_item.price;
                inventory_storage[new_item.name] = new_item;
            }
            readFile.close();
        }
    }

    void write_to_storage()
    {
        ofstream writeFile("inventory-storage.txt");
        map<string, item>::iterator i;
        for (i = inventory_storage.begin(); i != inventory_storage.end(); i++)
        {
            item item_to_write = i->second;
            /* Formatting the code. If it is the beginning of the file then dont enter a new line
            This kept making an error that it would put an extra empty line at the start and the
            read method would also read that line as an item and assigned garbage values to it */
            if (i == inventory_storage.begin())
                writeFile << item_to_write.item_ID << ' ' << item_to_write.name << ' ' << item_to_write.quantity << ' ' << item_to_write.price;
            else
                writeFile << endl
                          << item_to_write.item_ID << ' ' << item_to_write.name << ' ' << item_to_write.quantity << ' ' << item_to_write.price;
        }
        writeFile.close();
    }
};

int main()
{
    inventory Inventory;
    int user_choice;

    Inventory.read_from_storage();
    do
    {
        cout << "\n1. View current inventory\n";
        cout << "2. View details of a specific item\n";
        cout << "3. Add new item\n";
        cout << "4. Update values\n";
        cout << "5. Remove an item\n";
        cout << "6. View Summary\n";
        cout << "7. Exit\n\n";

        do
        {
            cout << "Enter your choice: ";
            cin >> user_choice;

            if (user_choice > 7 || user_choice < 1)
            {
                cout << "Invalid choice\n";
            }
        } while (user_choice > 7 || user_choice < 1);

        string item_ID, name;
        int quantity;
        float price;
        switch (user_choice)
        {
        case 1:
            Inventory.display_inventory();
            break;
        case 2:
            cout << "Enter the name of the quantity you want to display: ";
            cin >> name;
            Inventory.display_item(name);
            break;
        case 3:
            cout << "*Please use hyphens(-) instead of spaces*\n";

            cout << "ID: ";
            cin >> item_ID;

            cout << "Name: ";
            cin >> name;

            do
            {
                cout << "Quantity: ";
                cin >> quantity;
                if (quantity < 0)
                {
                    cout << "Enter a positive integer!\n";
                }
            } while (quantity < 0);

            do
            {
                cout << "Price: ";
                cin >> price;
                if (price < 0)
                {
                    cout << "Enter a positive number\n";
                }
            } while (price < 0);

            Inventory.add_new_item(item_ID, name, quantity, price);
            break;
        case 4:
            // This case takes the user to a separate menu which also has a back option
            int user_choice_2;
            do
            {
                cout << "\n1. Update ID\n";
                cout << "2. Update name\n";
                cout << "3. Update quantity\n";
                cout << "4. Update price\n";
                cout << "5. Back\n\n";

                do
                {
                    cout << "Enter your choice: ";
                    cin >> user_choice_2;
                    if (user_choice_2 < 0 || user_choice_2 > 5)
                    {
                        cout << "Invalid choice!\n";
                    }
                } while (user_choice_2 < 0 || user_choice_2 > 5);

                string item_key;

                switch (user_choice_2)
                {
                case 1:
                    cout << "Enter the name of the item you want to update: ";
                    cin >> item_key;
                    Inventory.update_id(item_key);
                    break;
                case 2:
                    cout << "Enter the name of the item you want to update: ";
                    cin >> item_key;
                    Inventory.update_name(item_key);
                    break;
                case 3:
                    cout << "Enter the name of the item you want to update: ";
                    cin >> item_key;
                    Inventory.update_quantity(item_key);
                    break;
                case 4:
                    cout << "Enter the name of the item you want to update: ";
                    cin >> item_key;
                    Inventory.update_price(item_key);
                    break;
                case 5:
                    break;
                }
            } while (user_choice_2 != 5);
            break;
        case 5:
            cout << "Enter the name of the quantity you want to remove: ";
            cin >> name;
            Inventory.remove_item(name);
            break;
        case 6:
            Inventory.show_summary();
            break;
        case 7:
            break;
        }
    } while (user_choice != 7);
    Inventory.write_to_storage();

    return 0;
}