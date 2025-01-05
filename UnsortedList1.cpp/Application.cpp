//
//  Application.cpp
//  UnsortedList1.cpp
//
//  Created by 김현우 on 1/5/25.
//

#include "Application.hpp"
#include <iostream>

void Application::DisplayMenu() {
    std::cout << "------ID Command------\n";
    std::cout << " 1: Add\n";
    std::cout << " 2: Print\n";
    std::cout << " 3: Make empty\n";
    std::cout << " 4: Search item\n";
    std::cout << " 5: Delete item\n";
    std::cout << " 6: Update item\n";
    std::cout << " 7: Get from file\n";
    std::cout << " 8: Put to file\n";
    std::cout << " 0: Quit\n";
    std::cout << "Choose command --> ";
}

void Application::PlayMenu() {
    ArrayList list;
    int command;
    ItemType item;
    
    do {
        DisplayMenu();
        std::cin >> command;
        std::cin.ignore();
        
        switch (command) {
            case 1: {
                std::cout << "Enter item to add: ";
                item.Initialize();
                list.Add(item);
                std::cout << "Item added.\n";
                break;
            }
            case 2: {
                std::cout << "Current list items:\n";
                list.ResetList();
                while (list.GetNextItem(item)) {
                    item.Print();
                }
                break;
            }
            case 3: {
                list.MakeEmpty();
                std::cout << "List is now empty.\n";
                break;
            }
            case 4: {
                std::cout << "Enter item to search: ";
                item.Initialize();
                list.ResetList();
                bool found = false;
                while (list.GetNextItem(item)) {
                    if(item.ComparedTo(item) == 0) {
                        std::cout << "Item foind.\n";
                        found = true;
                        break;
                    }
                }
                if(!found) std::cout << "Item not found.\n";
                break;
            }
            case 5: {
                std::cout << "Enter item to delete: ";
                item.Initialize();
                std::cout << "Delete.\n";
            }
            case 0:
                std::cout << "Exiting program.\n";
                break;
        }
    } while (command != 0);
}
