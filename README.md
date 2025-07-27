# 🏦 Banking System in C++

A Banking Management System built using C++ with Object-Oriented Programming (OOP) principles. This project models Customers, Accounts, and Transactions with features like deposits, withdrawals, fund transfers, and transaction history tracking. The system runs via a simple console interface.

# ✨ Features

~ Add and manage Customers.

~ Open and manage Accounts (Savings/Current).

~ Perform Deposits and Withdrawals.

~ Execute Fund Transfers between accounts.

~ Maintain and display Transaction History.

~ View Account Balance and detailed account statements.

~ Simple and modular OOP-based design.

~ Console-based User Interaction.

# 🚀 Getting Started
Prerequisites

~ C++ Compiler (GCC / MinGW / MSVC / Clang)

~ Visual Studio Code / Code::Blocks / DevC++ or any C++ IDE.

~ Understanding of OOP concepts in C++.

# 🖥️ Usage Flow
1.Create New Customer

~ Enter customer details (Name, ID, Contact Info).

2.Create Account

~ Link an account to the customer (Account No, Type, Initial Balance).

3.Deposit / Withdraw

~ Choose account and perform deposit or withdrawal operations.

4.Fund Transfer

~ Transfer funds from one account to another.

5.Transaction History

~ View recent transactions (deposits, withdrawals, transfers).

6.Account Information

~ Display balance, account details, and transaction statements.

# 🧱 System Design
Classes:

~ Customer

--> Attributes: customerID, name, contactInfo

--> Functions: displayCustomerDetails()

~ Account

--> Attributes: accountNumber, accountType, balance, linkedCustomer

--> Functions: deposit(), withdraw(), displayAccountInfo()

~ Transaction

--> Attributes: transactionID, dateTime, type, amount, description

--> Functions: recordTransaction(), displayTransaction()

Data Handling:

--> Transactions are stored in a vector/list.

--> Each Account maintains its own transaction history.

--> Simple In-Memory data (can be extended to file storage or DB).

# 🛠️ Future Enhancements

--> Persistent storage using files or databases.

--> Support for Multiple Branches & Employees.

--> Implement Interest Calculations.

--> Add GUI Interface.

--> Authentication & Role-based access.

# 📜 License
This project is licensed under the MIT License.

# 🙌 Acknowledgements
--> Inspired by basic Banking System Projects used in OOP learning.

--> C++ Documentation from cplusplus.com.

# 📧 Contact
For queries and suggestions:

Ronit Kumar — ronitsingh81025@gmail.com

GitHub: ronit7707
