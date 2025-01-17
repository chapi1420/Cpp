#include <iostream>
#include <limits> 
using namespace std;

struct bank {
    unsigned int Id;
    string firstName;
    string lastName;
    float cash; 
    bank(unsigned int Id, string fName, string lName) {
        this->Id = Id;
        firstName = fName;
        lastName = lName;
        cash = 0; 
    }
};

void decor() {
    cout << "***************************\n";
}

bank createAccount(bank users) {
    cout << "Enter your first name: ";
    cin >> users.firstName;
    cout << "Enter your last name: ";
    cin >> users.lastName;
    cout << "Enter the initial amount of money you want to deposit: ";
    
    while (!(cin >> users.cash) || users.cash < 0) {
        cout << "Invalid amount. Please enter a positive number: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    
    users.Id = 1; 
    cout << "Registration is successful\n";
    decor();
    return users;
}

float withdraw(float cash) {
    float amount;
    decor();
    cout << "Enter the amount of money you want to withdraw: ";
    
    while (!(cin >> amount) || amount < 0) {
        cout << "Invalid amount. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    amount *= 1.02; 
    char choose;
    cout << "Please insert A to confirm the withdrawal of " << amount << " with transaction fee included\n";
    cin >> choose;

    if (choose == 'A') {
        if (cash >= amount) {
            cash -= amount;
            cout << "Withdrawal successful.\n";
            decor();
            return cash;
        } else {
            cout << "Sorry, insufficient balance to withdraw the required amount.\n";
            return cash;
        }
    } else {
        decor();
        cout << "Transaction has been canceled.\n";
        decor();
        return cash;
    }
}

float deposits(float cash) {
    float amount;
    decor();
    cout << "Enter the amount of money you want to deposit: ";
    
    while (!(cin >> amount) || amount < 0) {
        cout << "Invalid amount. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cash += amount;
    cout << "Deposit successful.\n";
    decor();
    return cash;
}

int main() {
    bank user1(1, "no_one", "unknown");
    int count = 0;


    char choose;
    if(count<1){
        cout << "Welcome to Catallizo Banking System\n";
        cout << "**************************************\n";
        cout << "Enter A to create new account\n";}
    cout << "Enter B to withdraw money\n";
    cout << "Enter C to deposit money\n";
    cout << "Enter E to exit the system\n";
    cin >> choose;

    do{
        if (choose == 'A') {
        user1 = createAccount(user1);
        cout << "Account has been successfully created!\n";
        decor();
        cout +=1;
        main();
    } else if (choose == 'B') {
        user1.cash = withdraw(user1.cash);
        main();
    } else if (choose == 'C') {
        user1.cash = deposits(user1.cash);
        main();
    } else if (choose == 'E') {
        cout << "Exiting the system. Thank you!\n";
        exit; 
    } else {
        cout << "Invalid option. Please try again.\n";
    }
    }while(choose != 'E');
    

return 0;
}
