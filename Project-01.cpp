#include <iostream>
using namespace std;
/******
Title: Project1.cpp
Abstract: This program will have an aoutomat that holds food items and drinks
that can be ordered and purchased or canceld.
Author: Kimberly Gaeta 
Email:
Kgaeta@csumb.edu 
Date:2/28/23 
Estimate: 10 hours
  ******/
const int AUTOMAT_MAX = 10;
const int ORDER_MAX = 5;
// food start
class Food {
public:
  Food();
  Food(string name, int calories, double price);
  string getName();
  int getCalories();
  double getPrice();
  void setName(string name);
  void setCalories(int calories);
  void setPrice(double price);
  void display();

private:
  string myName;
  int myCalories;
  double myPrice;
};
// drink start
class Drink {
public:
  Drink();
  Drink(string name, int ounces, double price);
  string getName();
  int getOunces();
  double getPrice();
  void setName(string name);
  void setOunces(int ounces);
  void setPrice(double price);
  void display();

private:
  string myName;
  int myOunces;
  double myPrice;
};
// automat start
class Automat {
public:
  Automat();
  bool emptyFood();
  bool emptyDrink();
  void enqueue(Food f);
  void enqueue(Drink d);
  void dequeueFood();
  void dequeueDrink();
  Food frontFood();
  Drink frontDrink();
  int foodCount();
  int drinkCount();
  int getTotalCalories();
  int getTotalOunces();
  double getTotalPrice();
  void display();

private:
  int myFoodFront;
  int myFoodBack;
  int myFoodCounter;
  int myDrinkFront;
  int myDrinkBack;
  int myDrinkCounter;
  Food myFood[AUTOMAT_MAX];
  Drink myDrink[AUTOMAT_MAX];
};
// order start
class Order{
public:
  Order();
  bool emptyFood();
  bool emptyDrink();
  void push(Food f);
  void push(Drink d);
  void popFood();
  void popDrink();
  Food topFood();
  Drink topDrink();
  int foodCount();
  int drinkCount();
  double getTotalPrice();
  void display();
  void cancel(Automat & a);
  void purchase();
  static int getTotalOrders();
private:
  int myFoodTop;
  int myFoodCounter;
  int myDrinkTop;
  int myDrinkCounter;
  Food myFood[ORDER_MAX];
  Drink myDrink[ORDER_MAX];
  static int myTotalOrders;
};



// food definition start
Food::Food() {
  myName = " ";
  myCalories = 0;
  myPrice = 0.0;
}
Food::Food(string name, int calories, double price) {
  myName = name;
  myCalories = calories;
  myPrice = price;
}
string Food::getName() { 
  return myName; 
}
int Food::getCalories() { 
  return myCalories; 
}
double Food::getPrice() { 
  return myPrice; 
}
void Food::setName(string name) { 
  myName = name; 
}
void Food::setCalories(int calories) {
  myCalories = calories;
}
void Food::setPrice(double price) {
  myPrice = price;
}
void Food::display() {
  cout << myName << ": " << myCalories << " calories, $" 
    << myPrice << "\n";
}
// EVERYTHING FOOD WORKS!
// drink definitions start
Drink::Drink() {
  myName = " ";
  myOunces = 0;
  myPrice = 0.0;
}
Drink::Drink(string name, int ounces, double price) {
  myName = name;
  myOunces = ounces;
  myPrice = price;
}
string Drink::getName() { 
  return myName; 
}
int Drink::getOunces() { 
  return myOunces; 
}
double Drink::getPrice() { 
  return myPrice; 
}
void Drink::setName(string name) {
  myName = name; 
}
void Drink::setOunces(int ounces) { 
  myOunces = ounces;
}
void Drink::setPrice(double price) {
  myPrice = price; 
}
void Drink::display() {
  cout << myName << ": " << myOunces << " ounces, $" 
    << myPrice << "\n";
}
// EVERYTHING DRINK WOrKS!!
// automat definition start
Automat::Automat() {
  myFoodFront = 0;
  myFoodBack = 0;
  myFoodCounter = 0;
  myDrinkFront = 0;
  myDrinkBack = 0;
  myDrinkCounter = 0;
}
bool Automat::emptyFood() {
  if (myFoodFront == myFoodBack) {
    return true;
  }
  return false;
}
bool Automat::emptyDrink() {
  if (myDrinkFront == myDrinkBack) {
    return true;
  }
  return false;
}
void Automat::enqueue(Food f) {
  int newFoodBack = (myFoodBack + 1) % AUTOMAT_MAX;
  if (newFoodBack != myFoodFront) {
    myFood[myFoodBack] = f;
    myFoodBack = newFoodBack;
    myFoodCounter++;
  } else {
    cerr << "Automat food full; new food not added\n";
  }
}
void Automat::enqueue(Drink d) {
  int newDrinkBack = (myDrinkBack + 1) % AUTOMAT_MAX;
  if (newDrinkBack != myDrinkFront) {
    myDrink[myDrinkBack] = d;
    myDrinkBack = newDrinkBack;
    myDrinkCounter++;
  } else {
    cerr << "Automat drink full; new drink not added\n";
  }
}
void Automat::dequeueFood() {
  if (!emptyFood()) {
    myFoodFront = (myFoodFront + 1) % AUTOMAT_MAX;
    myFoodCounter--;
  } else {
    cerr << "Automat food empty - cannot order food\n";
  }
}
void Automat::dequeueDrink() {
  if (!emptyDrink()) {
    myDrinkFront = (myDrinkFront + 1) % AUTOMAT_MAX;
    myDrinkCounter--;
  } else {
    cerr << "Automt drink empty - cannot order drink\n";
  }
}
Food Automat::frontFood() {
  if (!emptyFood()) {
    return (myFood[myFoodFront]);
  } else {
    cerr << "Automat food empty - returning garbage values\n";
    Food yuck;
    return yuck;
  }
}
Drink Automat::frontDrink() {
  if (!emptyDrink()) {
    return (myDrink[myDrinkFront]);
  } else {
    cerr << "Automat drink empty - returning garbage values\n";
    Drink ew;
    return ew;
  }
}
int Automat::foodCount() {
  return myFoodCounter;
}
int Automat::drinkCount() { 
  return myDrinkCounter; 
}
int Automat::getTotalCalories() {
  int sum = 0;
  if (!emptyFood()) {
    for (int i = myFoodFront; i != myFoodBack; 
      i = (i + 1) % AUTOMAT_MAX) {
      sum += myFood[i].getCalories();
      }
    return sum;
  } else {
    return -1;
  }
}
int Automat::getTotalOunces(){
  int sum = 0;
  if (!emptyDrink()){
    for (int i = myDrinkFront; i != myDrinkBack;
      i = (i + 1) % AUTOMAT_MAX){
        sum += myDrink[i].getOunces();
      }
    return sum;
  } else {
    return -1;
  }
}
double Automat::getTotalPrice(){
  double sum = 0;
  if (!emptyFood() && ! emptyDrink()){
    for (int i = myFoodFront; i != myFoodBack; 
      i = (i + 1) % AUTOMAT_MAX) {
      sum += myFood[i].getPrice();
      }
    for (int i = myDrinkFront; i != myDrinkBack;
      i = (i + 1) % AUTOMAT_MAX){
        sum += myDrink[i].getPrice();
      }
    return sum;
  } else {
    return -1;
  }
}
void Automat::display(){
  cout << "Automat:\n\tFood:\n";
  for (int i = myFoodFront; i != myFoodBack; 
      i = (i + 1) % AUTOMAT_MAX) {
      cout << "\t\t";
      myFood[i].display();
      }
  cout << "\t\t" << myFoodCounter << " food items - Total Calories: "
    << getTotalCalories();
  cout << "\n\tDrinks:\n";
  for (int i = myDrinkFront; i != myDrinkBack;
      i = (i + 1) % AUTOMAT_MAX){
        cout << "\t\t";
        myDrink[i].display();
      }
  cout << "\t\t" << myDrinkCounter << " drinks - Total Ounces: "
    << getTotalOunces() << "\n\n";
}
// EVERYTHING AUTOMAT WORKS!!
// order definition start
int Order::myTotalOrders = 0;
Order::Order(){
  myFoodTop = -1;
  myFoodCounter = 0;
  myDrinkTop = -1;
  myDrinkCounter = 0;
  myTotalOrders++;
}
bool Order::emptyFood(){
  if (myFoodTop == -1){
    return true;
  }
  return false;
}
bool Order::emptyDrink(){
  if (myDrinkTop == -1){
    return true;
  }
  return false;
}
void Order::push(Food f){
  if (myFoodTop < ORDER_MAX - 1){
    myFoodTop++;
    myFood[myFoodTop] = f;
    myFoodCounter++;
  } else {
    cerr << "Order food full; new food not added";
  }
}
void Order::push(Drink d){
  if (myDrinkTop < ORDER_MAX - 1){
    myDrinkTop++;
    myDrink[myDrinkTop] = d;
    myDrinkCounter++;
  } else {
    cerr << "Order drink full; new drink not added";
  }
}
void Order::popFood(){
  if(!emptyFood()){
    myFoodTop--;
    myFoodCounter--;
  } else {
    cerr << "Order food empty";
  }
}
void Order::popDrink(){
  if(!emptyDrink()){
    myDrinkTop--;
    myDrinkCounter--;
  } else {
    cerr << "Order drink empty";
  }
}
Food Order::topFood(){
  if(!emptyFood()){
    return myFood[myFoodTop];
  } else {
    cerr << "Order food empty - returning garbage values";
    Food yuck;
    return yuck;
  }
}
Drink Order::topDrink(){
  if(!emptyDrink()){
    return myDrink[myDrinkTop];
  } else {
    cerr << "Order drink empty - returning garbage values";
    Drink ew;
    return ew;
  }
}
int Order::foodCount(){
  if(!emptyFood()){
    return myFoodCounter;
  }
  return 0;
}
int Order::drinkCount(){
  if (!emptyDrink()){
    return myDrinkCounter;
  }
  return 0;
}
double Order::getTotalPrice(){
  double sum = 0;
  if (!emptyFood() && ! emptyDrink()){
    for (int i = myFoodTop; i >= 0; i--) {
      sum += myFood[i].getPrice();
      }
    for (int i = myDrinkTop; i >= 0; i--){
        sum += myDrink[i].getPrice();
      }
    return sum;
  } else {
    return 0;
  }
}
void Order::display(){
  cout << "Order:\n\tFood(" << foodCount() << " items):\n";
  for (int i = myFoodTop; i >= 0; i--){
    cout << "\t\t";
    myFood[i].display();
  }
  cout << "\tDrinks (" << drinkCount() << " items):\n";
  for (int i = myDrinkTop; i >= 0; i--){
    cout << "\t\t";
    myDrink[i].display();
  }
  cout << "\tOrder total: $" << getTotalPrice() << "\n\n";
}
void Order::purchase(){ 
  myFoodTop = -1;
  myFoodCounter = 0;
  myDrinkTop = -1;
  myDrinkCounter = 0;
}
int Order::getTotalOrders(){
  return myTotalOrders;
}
//EVERYTHING ABOVE THIS WORKS!!
void Order::cancel(Automat & a){ // works <3
  for (int i = myFoodTop; i >= 0; i--){
    a.enqueue(myFood[i]);
    popFood();
    myFoodCounter--;
  }
  for (int i = myDrinkTop; i>= 0; i--){
    a.enqueue(myDrink[i]);
    popDrink();
    myDrinkCounter--;
  }
}
