#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class User
{
private:
    string name;
    string email;
    string password;
    string role;

public:
    User() {}

    User(string n, string e, string p, string r)
    {
        name = n;
        email = e;
        password = p;
        role = r;
    }

    string getName()
    {
        return name;
    }

    string getEmail()
    {
        return email;
    }

    string getPassword()
    {
        return password;
    }

    string getRole()
    {
        return role;
    }
};

class Product
{
private:
    int id;
    string name;
    string description;
    double price;
    int stock;
    string category;

public:
    Product() {}

    Product(int i, string n, string d, double p, int s, string c)
    {
        id = i;
        name = n;
        description = d;
        price = p;
        stock = s;
        category = c;
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getDescription()
    {
        return description;
    }

    double getPrice()
    {
        return price;
    }

    int getStock()
    {
        return stock;
    }

    string getCategory()
    {
        return category;
    }

    void reduceStock(int quantity)
    {
        stock = stock - quantity;
    }

    void display()
    {
        cout << "\nProduct ID  : " << id;
        cout << "\nName        : " << name;
        cout << "\nDescription : " << description;
        cout << "\nPrice       : Rs." << fixed << setprecision(2) << price;
        cout << "\nStock       : " << stock;
        cout << "\nCategory    : " << category;
        cout << "\n--------------------------------------------\n";
    }
};

class CartItem
{
private:
    int productId;
    int quantity;

public:
    CartItem(int id, int q)
    {
        productId = id;
        quantity = q;
    }

    int getProductId()
    {
        return productId;
    }

    int getQuantity()
    {
        return quantity;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    void increaseQuantity(int q)
    {
        quantity += q;
    }
};

class Order
{
private:
    int orderId;
    double totalAmount;
    string status;
    string buyerEmail;

public:
    Order(int id, double total, string s, string email)
    {
        orderId = id;
        totalAmount = total;
        status = s;
        buyerEmail = email;
    }

    string getBuyerEmail()
    {
        return buyerEmail;
    }

    void display()
    {
        cout << "\nOrder ID : " << orderId;
        cout << "\nAmount   : Rs." << fixed << setprecision(2) << totalAmount;
        cout << "\nStatus   : " << status;
        cout << "\n--------------------------------------------\n";
    }
};

class Marketplace
{
private:
    vector<User> users;
    vector<Product> products;
    vector<Order> orders;

    int nextProductId;
    int nextOrderId;

    int findProduct(int productId)
    {
        for (int i = 0; i < products.size(); i++)
        {
            if (products[i].getId() == productId)
            {
                return i;
            }
        }

        return -1;
    }

    int findUser(string email)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getEmail() == email)
            {
                return i;
            }
        }

        return -1;
    }

public:
    Marketplace()
    {
        nextProductId = 1;
        nextOrderId = 1001;
    }

    void registerUser()
    {
        string name;
        string email;
        string password;
        string role;

        cout << "\n============================================\n";
        cout << "                  REGISTER\n";
        cout << "============================================\n";

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter email: ";
        cin >> email;

        if (findUser(email) != -1)
        {
            cout << "\nEmail already registered!\n";
            return;
        }

        cout << "Enter password: ";
        cin >> password;

        int roleChoice;

        cout << "\nSelect role:\n";
        cout << "1. Buyer\n";
        cout << "2. Seller\n";

        cout << "Enter choice: ";
        cin >> roleChoice;

        if (roleChoice == 1)
        {
            role = "BUYER";
        }
        else if (roleChoice == 2)
        {
            role = "SELLER";
        }
        else
        {
            cout << "\nInvalid role!\n";
            return;
        }

        User newUser(name, email, password, role);

        users.push_back(newUser);

        cout << "\nRegistration successful!\n";
    }

    int loginUser()
    {
        string email;
        string password;

        cout << "\n============================================\n";
        cout << "                   LOGIN\n";
        cout << "============================================\n";

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter password: ";
        cin >> password;

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].getEmail() == email &&
                users[i].getPassword() == password)
            {
                cout << "\nLogin successful!\n";
                cout << "Welcome " << users[i].getName() << "!\n";
                cout << "Role: " << users[i].getRole() << "\n";

                return i;
            }
        }

        cout << "\nInvalid email or password!\n";

        return -1;
    }

    void addProduct()
    {
        string name;
        string description;
        string category;

        double price;
        int stock;

        cout << "\n============================================\n";
        cout << "                ADD PRODUCT\n";
        cout << "============================================\n";

        cout << "Enter product name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter description: ";
        getline(cin, description);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter stock quantity: ";
        cin >> stock;

        cout << "Enter category: ";
        cin >> ws;
        getline(cin, category);

        if (price < 0 || stock < 0)
        {
            cout << "\nInvalid price or stock!\n";
            return;
        }

        Product product(
            nextProductId,
            name,
            description,
            price,
            stock,
            category
        );

        products.push_back(product);

        nextProductId++;

        cout << "\nProduct added successfully!\n";
    }

    void displayProducts()
    {
        if (products.empty())
        {
            cout << "\nNo products available.\n";
            return;
        }

        cout << "\n============================================\n";
        cout << "             AVAILABLE PRODUCTS\n";
        cout << "============================================\n";

        for (int i = 0; i < products.size(); i++)
        {
            products[i].display();
        }
    }

    void addToCart(vector<CartItem>& cart)
    {
        if (products.empty())
        {
            cout << "\nNo products available.\n";
            return;
        }

        int productId;
        int quantity;

        displayProducts();

        cout << "\nEnter Product ID: ";
        cin >> productId;

        int index = findProduct(productId);

        if (index == -1)
        {
            cout << "\nProduct not found!\n";
            return;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0)
        {
            cout << "\nInvalid quantity!\n";
            return;
        }

        if (quantity > products[index].getStock())
        {
            cout << "\nNot enough stock available!\n";
            return;
        }

        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i].getProductId() == productId)
            {
                int newQuantity =
                    cart[i].getQuantity() + quantity;

                if (newQuantity > products[index].getStock())
                {
                    cout << "\nNot enough stock available!\n";
                    return;
                }

                cart[i].setQuantity(newQuantity);

                cout << "\nProduct quantity updated in cart!\n";
                return;
            }
        }

        CartItem item(productId, quantity);

        cart.push_back(item);

        cout << "\nProduct added to cart successfully!\n";
    }

    double displayCart(vector<CartItem>& cart)
    {
        if (cart.empty())
        {
            cout << "\nCart is empty.\n";
            return 0;
        }

        double total = 0;

        cout << "\n============================================\n";
        cout << "                  YOUR CART\n";
        cout << "============================================\n";

        for (int i = 0; i < cart.size(); i++)
        {
            int productIndex =
                findProduct(cart[i].getProductId());

            if (productIndex != -1)
            {
                double amount =
                    products[productIndex].getPrice()
                    * cart[i].getQuantity();

                cout << "\nProduct  : "
                     << products[productIndex].getName();

                cout << "\nQuantity : "
                     << cart[i].getQuantity();

                cout << "\nAmount   : Rs."
                     << fixed << setprecision(2)
                     << amount;

                cout << "\n--------------------------------------------\n";

                total += amount;
            }
        }

        cout << "\nTOTAL AMOUNT = Rs."
             << fixed << setprecision(2)
             << total << endl;

        return total;
    }

    void updateCart(vector<CartItem>& cart)
    {
        if (cart.empty())
        {
            cout << "\nCart is empty.\n";
            return;
        }

        displayCart(cart);

        int productId;
        int quantity;

        cout << "\nEnter Product ID to update: ";
        cin >> productId;

        int productIndex = findProduct(productId);

        if (productIndex == -1)
        {
            cout << "\nProduct not found!\n";
            return;
        }

        int cartIndex = -1;

        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i].getProductId() == productId)
            {
                cartIndex = i;
                break;
            }
        }

        if (cartIndex == -1)
        {
            cout << "\nProduct is not in your cart!\n";
            return;
        }

        cout << "Enter new quantity: ";
        cin >> quantity;

        if (quantity < 0)
        {
            cout << "\nInvalid quantity!\n";
            return;
        }

        if (quantity > products[productIndex].getStock())
        {
            cout << "\nNot enough stock!\n";
            return;
        }

        if (quantity == 0)
        {
            cart.erase(cart.begin() + cartIndex);

            cout << "\nProduct removed from cart!\n";
        }
        else
        {
            cart[cartIndex].setQuantity(quantity);

            cout << "\nCart updated successfully!\n";
        }
    }

    void removeFromCart(vector<CartItem>& cart)
    {
        if (cart.empty())
        {
            cout << "\nCart is empty.\n";
            return;
        }

        displayCart(cart);

        int productId;

        cout << "\nEnter Product ID to remove: ";
        cin >> productId;

        for (int i = 0; i < cart.size(); i++)
        {
            if (cart[i].getProductId() == productId)
            {
                cart.erase(cart.begin() + i);

                cout << "\nProduct removed from cart!\n";
                return;
            }
        }

        cout << "\nProduct is not in your cart!\n";
    }

    void checkout(
        vector<CartItem>& cart,
        string buyerEmail)
    {
        if (cart.empty())
        {
            cout << "\nYour cart is empty!\n";
            return;
        }

        double total = displayCart(cart);

        char confirm;

        cout << "\nConfirm mock payment? (Y/N): ";
        cin >> confirm;

        if (confirm != 'Y' && confirm != 'y')
        {
            cout << "\nPayment cancelled.\n";
            return;
        }

        for (int i = 0; i < cart.size(); i++)
        {
            int productIndex =
                findProduct(cart[i].getProductId());

            if (productIndex != -1)
            {
                products[productIndex].reduceStock(
                    cart[i].getQuantity()
                );
            }
        }

        Order newOrder(
            nextOrderId,
            total,
            "CONFIRMED",
            buyerEmail
        );

        orders.push_back(newOrder);

        nextOrderId++;

        cout << "\n============================================\n";
        cout << "          ORDER PLACED SUCCESSFULLY\n";
        cout << "============================================\n";

        cout << "Payment : Successful\n";
        cout << "Status  : CONFIRMED\n";

        newOrder.display();

        cart.clear();

        cout << "\nThank you for your purchase!\n";
    }

    void orderHistory(string buyerEmail)
    {
        bool found = false;

        cout << "\n============================================\n";
        cout << "                ORDER HISTORY\n";
        cout << "============================================\n";

        for (int i = 0; i < orders.size(); i++)
        {
            if (orders[i].getBuyerEmail() == buyerEmail)
            {
                orders[i].display();
                found = true;
            }
        }

        if (!found)
        {
            cout << "\nNo previous orders found.\n";
        }
    }

    void buyerMenu(string buyerEmail)
    {
        vector<CartItem> cart;

        int choice;

        while (true)
        {
            cout << "\n============================================\n";
            cout << "                  BUYER MENU\n";
            cout << "============================================\n";

            cout << "1. Browse Products\n";
            cout << "2. Add to Cart\n";
            cout << "3. View Cart\n";
            cout << "4. Update Cart\n";
            cout << "5. Remove from Cart\n";
            cout << "6. Checkout\n";
            cout << "7. Order History\n";
            cout << "8. Logout\n";

            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    displayProducts();
                    break;

                case 2:
                    addToCart(cart);
                    break;

                case 3:
                    displayCart(cart);
                    break;

                case 4:
                    updateCart(cart);
                    break;

                case 5:
                    removeFromCart(cart);
                    break;

                case 6:
                    checkout(cart, buyerEmail);
                    break;

                case 7:
                    orderHistory(buyerEmail);
                    break;

                case 8:
                    cout << "\nLogged out successfully.\n";
                    return;

                default:
                    cout << "\nInvalid choice!\n";
            }
        }
    }

    void sellerMenu()
    {
        int choice;

        while (true)
        {
            cout << "\n============================================\n";
            cout << "                 SELLER MENU\n";
            cout << "============================================\n";

            cout << "1. View Products\n";
            cout << "2. Add Product\n";
            cout << "3. Logout\n";

            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    displayProducts();
                    break;

                case 2:
                    addProduct();
                    break;

                case 3:
                    cout << "\nLogged out successfully.\n";
                    return;

                default:
                    cout << "\nInvalid choice!\n";
            }
        }
    }

    void start()
    {
        int choice;

        while (true)
        {
            cout << "\n\n============================================\n";
            cout << "               ANUJAMART\n";
            cout << "             C++ MARKETPLACE\n";
            cout << "============================================\n";

            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Exit\n";

            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    registerUser();
                    break;

                case 2:
                {
                    int userIndex = loginUser();

                    if (userIndex != -1)
                    {
                        if (users[userIndex].getRole() == "BUYER")
                        {
                            buyerMenu(
                                users[userIndex].getEmail()
                            );
                        }
                        else if (
                            users[userIndex].getRole()
                            == "SELLER")
                        {
                            sellerMenu();
                        }
                    }

                    break;
                }

                case 3:
                    cout << "\nThank you for using YourNameMart!\n";
                    return;

                default:
                    cout << "\nInvalid choice!\n";
            }
        }
    }
};

int main()
{
    Marketplace marketplace;

    marketplace.start();

    return 0;
}


