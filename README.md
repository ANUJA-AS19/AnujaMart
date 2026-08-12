# AnujaMart - C++ Marketplace

## Project Overview

AnujaMart is a console-based C++ marketplace application developed as part of Review 1.

The system provides basic marketplace functionality for two types of users:

- Buyer
- Seller

The project is implemented using Object-Oriented Programming (OOP) concepts in C++.

## Features

### User Management
- User registration
- User login
- Buyer and Seller role selection
- Email duplication checking

### Seller Features
- Add new products
- Enter product name, description, price, stock and category
- View available products

### Buyer Features
- Browse available products
- Add products to cart
- View cart
- Update cart quantity
- Remove products from cart
- Calculate total amount
- Checkout
- Mock payment confirmation
- View order history

### Order Management
- Generate order ID
- Store order amount
- Store buyer email
- Maintain order status
- Display previous orders

## Technologies Used

- C++
- Object-Oriented Programming
- Standard Template Library (STL)
- vector
- string
- Console-based interface

## OOP Concepts Used

### Classes and Objects

The project contains the following classes:

- User
- Product
- CartItem
- Order
- Marketplace

An object of the Marketplace class is created in the main() function.

### Encapsulation

Data members such as user details, product details and order details are declared as private and accessed through public member functions.

### Constructors

Constructors are used to initialize objects such as users, products, cart items and orders.

### Abstraction

The Marketplace class provides functions for registration, login, product management, cart management and checkout without exposing the internal implementation.

## Project Structure

```text
AnujaMart/
│
├── main.cpp
└── README.md
