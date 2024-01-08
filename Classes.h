#include <iostream>
#include<string>
#include<windows.h>
#include<iomanip>
using namespace std;
struct items {
    int id;
    string name;
    int price;
    int quantity;
};
struct node {
    items data;
    node* next;
    node(items it) {
        data = it;
        next = NULL;
    }
};
struct customerItems {
    int Id;
    string Name;
    int Price;
    int Quantity;
};
struct Node {
    customerItems data;
    Node* next = NULL;
    Node(customerItems ct) {
        data = ct;
        next = NULL;
    }
};
class superMarket {
private:
    node* head = NULL;
    Node* customerHead = NULL;
    int id, price, quantity;
    string name;
    string username;
    string n_username;
    string currentusername;
    string partupdate;
    int password;
    int n_password;
    int current_password;
    int newpassword;
    bool loginsuccess;
    bool credentialsucces;

public:
    void loginpanel();
    void changecredentials();
    void setData();
    void add();
    void updateitemdetails();
    void updatespecific();
    void searchitem();
    void deleteItem();
    void display();
    void TotalItems();
    void selectItem();
    void generateBill();
    void DisplayCustomer();
    void deleteSelectedItem();
};
class Boards {
private:
    int xMid, yMid, height, width, bwidth, bheight;
public:
    Boards(int xMid, int yMid, int height, int width, int bwidth, int bheight) {
        this->xMid = xMid;
        this->yMid = yMid;
        this->height = height;
        this->width = width;
        this->bwidth = bwidth;
        this->bheight = bheight;
    }
    superMarket s;
    void drawBoard(int xMid, int yMid, int height, int width);
    bool takeInput(int xMid, int yMid, int height, int width);
    void loginPanel(int bwidth, int bheight, int xMid, int yMid, int height, int width);
    void AdminSide(int bwidth, int bheight, int xMid, int yMid, int height, int width);
    void CustomerSide(int bwidth, int bheight, int xMid, int yMid, int height, int width);
    void MainMenu(int &bwidth, int &bheight, int &xMid, int &yMid, int &height, int &width);
};