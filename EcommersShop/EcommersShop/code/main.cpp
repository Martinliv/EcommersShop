//Martin Liverant 205869498
//Nitzan Ismailov 208412569
#pragma warning(disable: 4996)

#include<iostream>
using namespace std;
#include<string.h>
#include <cstring>

#include"system.h"
#include"addres.h"
#include"item.h"
#include"seller.h"
#include"buyer.h"
#include"cart.h"

//prototypes//
void addBuyer(System& mysystem);
void addSeller(System& mysystem);
void addItemToSeller(System& mysystem);
void addProductToBuyer(System& mysystem);
void orderPayment(System& mysystem);
void displayBuyers(System& mysystem);
void displaySellers(System& mysystem);
void displayHistory(System& mysystem);
void addUser(System& mysystem);
void comperBuyersByTotalCartPrice(System& mysystem);


int main()
{
    int choice;
    System mysystem;

    // hardcoded for system input (3 buyers and 3 sellers)
    Addres a1("street", 1, "city", "country");
    Seller newseller("s", "123", a1);
    mysystem += newseller;

    Addres a2("street", 2, "city", "country");
    Seller newsellerr("ss", "123", a2);
    mysystem += newsellerr;

    Addres a3("street", 3, "city", "country");
    Seller newsellerrr("sss", "123", a3);
    mysystem += newsellerrr;

    Addres b1("street", 1, "city", "country");
    Buyer newbuyer("b", "123", b1);
    mysystem += newbuyer;

    Addres b2("street", 2, "city", "country");
    Buyer newbuyerr("bb", "123", b2);
    mysystem += newbuyerr;

    Addres b3("street", 3, "city", "country");
    Buyer newbuyerrr("bbb", "123", b3);
    mysystem += newbuyerrr;

    do
    {
        // Display menu
        cout << "*****************************\n";
        cout << "\nWelcome to Martin's & Nitzan's Shop :)\n";
        cout << "Select an action from the menu:\n";
        cout << "1. Add new USER.\n";
        cout << "2. SELLER - Add item for sale.\n";
        cout << "3. BUYER - Choose item & Add to cart.\n";
        cout << "4. BUYER - Pay for order.\n";
        cout << "5. Display details of all buyers.\n";
        cout << "6. Display details of all sellers.\n";
        cout << "7. Display buyer's order history.\n";
        cout << "8. Comper buyers by cart  total price.\n";
        cout << "9. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            addUser(mysystem);

            break;

        case 2:

            addItemToSeller(mysystem);

            break;

        case 3:

            addProductToBuyer(mysystem);

            break;

        case 4:

            orderPayment(mysystem);

            break;

        case 5:

            displayBuyers(mysystem);

            break;

        case 6:

            displaySellers(mysystem);

            break;

        case 7:

            displayHistory(mysystem);

            break;

        case 8:

            comperBuyersByTotalCartPrice(mysystem);

            break;

        case 9:

            cout << "\nExiting...\n";

            break;

        default:

            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}


void addUser(System& mysystem)
{
    int choice;
    cout << "Are you Buyer or Seller ? " << endl << "For Buyer press 1" << endl << "For Seller press 2" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        addBuyer(mysystem);
        cout << "\nBuyer added!" << endl;
        break;
    case 2:
        addSeller(mysystem);
        cout << "\nSeller added!" << endl;
        break;
    default:
        cout << "\nInvalid choice. Please try again.\n";
        break;
    }

}


void addBuyer(System& mysystem)
{
    char buyer_name[100];
    char buyer_password[100];
    char street[100];
    int houseNum;
    char city[100];
    char country[100];

    mysystem.read_user_det(buyer_name, buyer_password, street, houseNum, city, country);
    Addres add(street, houseNum, city, country);
    Buyer newbuyer(buyer_name, buyer_password, add);
    mysystem += newbuyer;
    
}


void addSeller(System& mysystem)
{
    char seller_name[100];
    char seller_password[100];
    char street[100];
    int houseNum;
    char city[100];
    char country[100];

    mysystem.read_user_det(seller_name, seller_password, street, houseNum, city, country);
    Addres add(street, houseNum, city, country);;
    Seller newseller(seller_name, seller_password, add);
    mysystem += newseller;
}


void addItemToSeller(System& mysystem)
{
    char seller_name[100];
    char seller_password[100];
    char item_name[100];
    int item_price;
    Category category;

    mysystem.read_item_det(item_name, item_price, category);
    Item item(item_name, item_price, category);
    mysystem.identity_verification(seller_name, seller_password);
    Seller* s;
    s = mysystem.find_seller_byName_and_byPassword(seller_name, seller_password);
    if (s != nullptr)
    {
        mysystem += item;
        *s += item;
        cout << "\nItem added!" << endl;
    }
    else
    {
        cout << "\nThe seller does not exist !!!!!\nPlease try again !" << endl;
    }
}
void addProductToBuyer(System& mysystem)
{
    char Buyer_name[100];
    char Buyer_password[100];
    int choice;

    if (mysystem.get_num_of_items() == 0 )
    {
        cout << "The store is empty of products!!" << endl;
    }
    else
    {
        cout << "*****************************\n";
        cout << "What product you want to buy? Choose from the list (by the number): " << endl;
        for (int i = 0; i < mysystem.get_num_of_items(); i++)
        {
            cout << i + 1 << ".";
            cout << *mysystem.get_list_of_items_for_sale()[i] << endl;

        }
        cin >> choice;
        Item* i;
        i = mysystem.find_item_from_list_by_number(choice);
        if (i != nullptr)
        {
            Item i1(i->get_item_name(), i->get_item_price(), i->get_item_category());
            mysystem.identity_verification(Buyer_name, Buyer_password);
            Buyer* b;
            b = mysystem.find_buyer_byName_and_byPassword(Buyer_name, Buyer_password);
            if (b != nullptr)
            {
                *b += i1;
                cout << "\nProduct added to cart!" << endl;
            }
            else
            {
                cout << "\nThe buyer does not exist !!!!!\nPlease try again !" << endl;
            }
        }
        else
        {
            cout << "The number does not exist !!!! Please try again !" << endl;
        }
    }
}
void orderPayment(System& mysystem)
{
    char Buyer_name[100];
    char Buyer_password[100];
    int choice;

    cout << "*****************************\n";
    mysystem.identity_verification(Buyer_name, Buyer_password);
    Buyer* b;
    b = mysystem.find_buyer_byName_and_byPassword(Buyer_name, Buyer_password);
    if (b != nullptr)
    {
        if (b->get_cart()->get_num_of_items() == 0)
        {
            cout << "Cart is EMPTY!!" << endl;
        }
        else
        {
            cout << *b->get_cart() << endl;
            cout << "Do you want to buy the cart? choose options 1/2.." << endl;
            cout << "1.YES!";
            cout << "\n2.NO\n";
            cin >> choice;
            if (choice == 1)
            {
                b->buy_the_cart();
                cout << "\nPayment Succeeded!" << endl;
            }
        }
    }
    else
    {
        cout << "\nThe buyer does not exist !!!!!\nPlease try again !" << endl;
    }
}

void displayBuyers(System& mysystem)
{
    cout << "*****************************\n";
    for (int i = 0; i < mysystem.get_num_of_buyers(); i++)
    {
        cout << i + 1 << ".";
        cout << *mysystem.get_list_of_buyers()[i] << endl;

    }
}

void displaySellers(System& mysystem)
{
    cout << "*****************************\n";
    for (int i = 0; i < mysystem.get_num_of_sellers(); i++)
    {
        cout << i + 1 << ".";
        cout << *mysystem.get_list_of_sellers()[i] << endl;
    }
}

void displayHistory(System& mysystem)
{
    char Buyer_name[100];
    char Buyer_password[100];

    cout << "*****************************\n";
    mysystem.identity_verification(Buyer_name, Buyer_password);
    Buyer* b;
    b = mysystem.find_buyer_byName_and_byPassword(Buyer_name, Buyer_password);
    if (b != nullptr)
    {
        if (b->get_num_of_carts() == 0)
        {
            cout << "No order history!!" << endl;
        }
        else
        {
            cout << "Buyer's order history: " << endl;
            for (int i = 0; i < b->get_num_of_carts(); i++)
            {
                cout << *b->get_order_history()[i];
            }
        }  
    }
    else
    {
        cout << "\nThe buyer does not exist !!!!!\nPlease try again !" << endl;
    }
}
void comperBuyersByTotalCartPrice(System& mysystem)
{
    char Buyer_name[100];
    char Buyer_password[100];


    cout << "\nFirst buyer: " << endl;
    mysystem.identity_verification(Buyer_name, Buyer_password);
    Buyer* b1;
    b1 = mysystem.find_buyer_byName_and_byPassword(Buyer_name, Buyer_password);
    cout << "\nSecond buyer: " << endl;
    mysystem.identity_verification(Buyer_name, Buyer_password);
    Buyer* b2;
    b2 = mysystem.find_buyer_byName_and_byPassword(Buyer_name, Buyer_password);
    if (b1 != nullptr && b2 != nullptr)
    {
        if (*b1 > *b2)
        {
            cout << b1->get_name() << "'s" << " shopping cart amount is greater then " << b2->get_name() << "'s" << " !" << endl;
            cout << b1->get_cart()->get_total_price() << " > " << b2->get_cart()->get_total_price() << endl;
        }
        if (*b2 > *b1)
        {
            cout << b2->get_name() << "'s" << " shopping cart amount is greater then " << b1->get_name() << "'s" << " !" << endl;
            cout << b2->get_cart()->get_total_price() << " > " << b1->get_cart()->get_total_price() << endl;
        }
        if ((!(*b1 > *b2)) && (!(*b2 > *b1)))
        {
            cout << b1->get_name() << "'s" << " shopping cart amount equals to " << b2->get_name() << "'s" << " !" << endl;
            cout << b1->get_cart()->get_total_price() << " = " << b2->get_cart()->get_total_price() << endl;
        }
    }
    else
    {
        cout << "\nThe information provided does not match the database !!!!!\nPlease try again !" << endl;
    }
    

    
}