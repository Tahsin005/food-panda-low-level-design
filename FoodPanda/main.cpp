#include <iostream>
#include "FoodPanda.h"
using namespace std;

int main() {
    // Create FoodPanda Object
    FoodPanda* foodpanda = new FoodPanda();

    // Simulate a user coming in (Happy Flow)
    User* user = new User(101, "Tahsin", "Dhanmondi");
    cout << "User: " << user->getName() << " is active." << endl;

    // User searches for restaurants by location
    vector<Restaurant*> restaurantList = foodpanda->searchRestaurants("Dhanmondi");

    if (restaurantList.empty()) {
        cout << "No restaurants found!" << endl;
        return 0;
    }
    cout << "Found Restaurants:" << endl;
    for (auto restaurant : restaurantList) {
        cout << " - " << restaurant->getName() << endl;
    }

    // User selects a restaurant
    foodpanda->selectRestaurant(user, restaurantList[0]);

    cout << "Selected restaurant: " << restaurantList[0]->getName() << endl;

    // User adds items to the cart
    foodpanda->addToCart(user, "P1");
    foodpanda->addToCart(user, "P2");

    foodpanda->printUserCart(user);

    // User checkout the cart
    Order* order = foodpanda->checkoutNow(user, "Delivery", new BkashPaymentStrategy("1234567890"));
    
    // User pay for the cart. If payment is success, notification is sent.
    foodpanda->payForOrder(user, order);

    // Cleanup Code.
    delete foodpanda;
    delete user;
    
    return 0;
}
