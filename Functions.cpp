#include"Classes.h"
bool click = false;
void setclr(int clr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void gotoRowCol(int cpos, int rpos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}

void getRowColbyLeftClick(int& cpos, int& rpos) {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (Events > 0 && InputRecord.EventType == MOUSE_EVENT &&
            InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }

    } while (true);
}
void drawLine(char ch, int size) {
    for (int i = 0; i < size; i++) {
        cout << ch;
    }
    cout << endl;
}
void sleep() {
    for (int i = 0; i < 5; i++) {
        cout << ".";
        Sleep(500);
    }
}
void superMarket::loginpanel() {
    loginsuccess = false;
    cout << endl;
    do {
        cout << "Enter User Name and Password:" << endl;
        cout << "Enter Your Username: ";
        cin >> username;
        cout << "Enter Your Password : ";
        cin >> password;
        cout << "Logging into panel.";
        if (username == "ADMIN" && password == 1234) {
            sleep();
            cout << endl;
            cout << "\n You're Successfully Logged in :\n";
            loginsuccess = true;
            return;
        }

        else {
            cout << "Incorrect Username and Password :" << endl;
            cout << "Please try to Logged in again :" << endl;
        }

    } while (!loginsuccess);
}

void superMarket::changecredentials() {
    credentialsucces = false;
    do {
        cout << "Enter your current username: ";
        cin >> currentusername;
        cout << "Enter your current password: ";
        cin >> current_password;
        if (currentusername == username && current_password == password) {
            cout << "Authentication successfull!" << endl;
            cout << "Enter your new username: ";
            cin >> n_username;
            cout << "Enter your new password: ";
            cin >> n_password;
            cout << "Confirm your new password: ";
            cin >> newpassword;
        }

        if (n_password == newpassword) {
            cout << "Changing credentials.";
            sleep();
            cout << endl;
            credentialsucces = true;
            cout << "*** Credentials are change successfully! ***" << endl;
            return;
        }

        else {
            cout << "Incorrect current username or password so credentials are not change!" << endl;
        }
    } while (!credentialsucces);
}
void superMarket::setData() {
    node* temp = head;
    bool created = false;
    cout << "Enter ID of Item: ";
    cin >> id;
    cout << "Enter Name of Item: ";
    cin.ignore();
    getline(cin, name);
    do {
        created = false;
        while (temp != NULL) {
            if (temp->data.id == id) {
                created = true;
                cout << "Item with ID " << id << " already exists.\nEnter another ID: ";
                cin >> id;
                break;
            }
            if (temp->data.name == name) {
                created = true;
                cout << "Item with Name " << name << " already exists.\nEnter another Name: ";
                cin.ignore();
                getline(cin, name);
                break;
            }
            temp = temp->next;
        }
    } while (created);
    cout << "Enter Price of Item: ";
    cin >> price;
    cout << "Enter Quantity of Item: ";
    cin >> quantity;
}
void superMarket::add() {
    setData();
    items it{ id, name, price, quantity };
    node* newItem = new node(it);
    if (head == NULL) {
        head = newItem;
    }

    else {
        newItem->next = head;
        head = newItem;
    }
    cout << "Adding Item.";
    sleep();
    cout << endl;
    cout << "*** Item Added Successfully ***" << endl;

}

void superMarket::updateitemdetails() {
    int updateid;
    if (head == NULL) {
        cout << "No Item added " << endl;
        return;
    }
    cout << "Enter ID of Item to Update Details: ";
    cin >> updateid;
    node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == updateid) {
            cout << "Enter new details for ID " << updateid << " to update: " << endl;
            setData();

            temp->data.id = id;
            temp->data.name = name;
            temp->data.price = price;
            temp->data.quantity = quantity;

            cout << "Updating Details.";
            sleep();
            cout << endl;
            cout << "*** Item with ID " << updateid << " is updated successfully! ***" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "*** Item with ID " << updateid << " not found! ***" << endl;
}

void superMarket::updatespecific() {
    int updateid;
    if (head == NULL) {
        cout << "No Item added " << endl;
        return;
    }
    cout << "Enter ID of Item to Update Specific Details: ";
    cin >> updateid;
    node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == updateid) {
            do {
                cout << "Enter part (Id,Name,Price,Quantity) to update for ID " << updateid << endl;
                cin >> partupdate;
                if (partupdate == "id" || partupdate == "Id" || partupdate == "name" || partupdate == "Name" || partupdate == "price" || partupdate == "Price" || partupdate == "quantity" || partupdate == "Quantity") {
                    if (partupdate == "id" || partupdate == "Id") {
                        cout << "Enter new id for id " << updateid << ": ";
                        cin >> id;
                        temp->data.id = id;
                        cout << "Updating ID.";
                    }
                    else if (partupdate == "name" || partupdate == "Name") {
                        cout << "Enter new Name for ID " << updateid << ": ";
                        cin.ignore();
                        getline(cin, name);
                        temp->data.name = name;
                        cout << "Updating Name.";
                    }
                    else if (partupdate == "price" || partupdate == "Price") {
                        cout << "Enter new Price for ID " << updateid << ": ";
                        cin >> price;
                        temp->data.price = price;
                        cout << "Updating Price.";
                    }
                    else if (partupdate == "quantity" || partupdate == "Quantity") {
                        cout << "Enter new Quantity for ID " << updateid << ": ";
                        cin >> quantity;
                        temp->data.quantity = quantity;
                        cout << "Updating Quantity.";
                    }

                    sleep();
                    cout << endl;
                    cout << "*** Details are updated successfully! ***" << endl;
                    return;
                }
                else {
                    cout << "*** Invalid part to update! ***" << endl;
                }
            } while (true);
        }
        temp = temp->next;
    }
    cout << "*** Item with ID " << updateid << " not found! ***" << endl;
}
void superMarket::searchitem() {
    if (head == NULL) {
        cout << "No Item added";
        return;
    }
    int searchid;
    bool search = false;
    node* temp = head;
    do {
        cout << "Enter ID of Item to Search: ";
        cin >> searchid;
        temp = head;
        search = false;
        while (temp != NULL) {
            if (temp->data.id == searchid) {
                search = true;
                cout << "Searching an Item.";
                sleep();
                cout << endl;
                cout << "*** Item founded ***" << endl;
                drawLine('-', 50);
                cout << "ID" << setw(15) << " Name" << setw(15) << "Price" << setw(15) << "Quantity" << endl;
                drawLine('-', 50);
                cout << temp->data.id << setw(15) << temp->data.name << setw(15) << temp->data.price << setw(15) << temp->data.quantity << endl;
                drawLine('-', 50);
                break;
            }
            temp = temp->next;
        }
        if (!search) {
            cout << "Invalid ID." << endl;
        }
    } while (!search);
}
void superMarket::deleteItem() {
    if (head == NULL) {
        cout << "No Item added";
        return;
    }
    int deleteid;
    node* temp = head;
    node* previous = NULL;
    bool del = false;
    char choice;
    display();
    cout << endl;
    do {
        cout << "Enter ID of Item to Delete: ";
        cin >> deleteid;
        temp = head;
        previous = NULL;
        del = false;
        while (temp != NULL) {
            if (temp->data.id == deleteid) {
                del = true;
                if (previous == NULL) {
                    head = temp->next;
                }
                else {
                    previous->next = temp->next;
                }
                delete temp;
                cout << "Deleting Item from stock.";
                sleep();
                cout << endl;
                cout << "*** Item with ID " << deleteid << " deleted from stock ***" << endl;
                break;
            }
            previous = temp;
            temp = temp->next;
        }
        if (!del) {
            cout << "*** Item with ID " << deleteid << " not found! ***" << endl;
        }
        cout << "Do you want to delete another item? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
}
void superMarket::display() {
    if (head == NULL) {
        cout << "*** No Item added ***";
        return;
    }
    node* temp = head;
    drawLine('-', 40);
    cout << "ID " << setw(15) << " Name " << setw(10) << "Price " << setw(10) << "Quantity " << endl;
    drawLine('-', 40);
    while (temp != NULL) {
        cout << temp->data.id << setw(15) << temp->data.name << setw(10) << temp->data.price << setw(10) << temp->data.quantity << endl;
        temp = temp->next;
    }
    drawLine('-', 40);
    system("pause");
}
void superMarket::TotalItems() {
    int c = 0;
    node* temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    cout << "Total Items in Store are: " << c << endl;
}
void superMarket::selectItem() {
    int itemId, ammount;
    char choice;
    bool idfound;
    display();
    if (head == NULL) {
        return;
    }
    do {
        idfound = false;
        node* temp = head;
        cout << "Enter Id of item to select: ";
        cin >> itemId;
        while (temp != NULL) {
            if (temp->data.id == itemId) {
                idfound = true;
                cout << "Enter Quantity for item: ";
                cin >> ammount;
                if (temp->data.quantity >= ammount) {
                    temp->data.quantity -= ammount;
                    customerItems ct{ itemId,temp->data.name,temp->data.price,ammount };
                    Node* newItem = new Node(ct);
                    if (customerHead == NULL) {
                        customerHead = newItem;
                    }
                    else {
                        newItem->next = customerHead;
                        customerHead = newItem;
                    }
                    cout << "Adding Item to Cart.";
                    sleep();
                    cout << endl;
                    cout << "*** Item added to your cart ***" << endl;
                    break;
                }
                else {
                    cout << "*** Not enough Quantity ***" << endl;
                }
            }
            temp = temp->next;
        }
        if (!idfound) {
            cout << "*** Invalid id which is not present ***\nDo you want to try again(Y/N) ";
            cin >> choice;
        }
        else {
            cout << "Do you want to add more items (Y/N)";
            cin >> choice;
        }
    } while (choice == 'Y' || choice == 'y');
}
void superMarket::generateBill() {
    if (customerHead == NULL) {
        cout << "*** There is no item in your cart ***";
        return;
    }
    float totalbill = 0.0;
    float totalItemBill = 0.0;
    Node* temp = customerHead;
    drawLine('-', 40);
    cout << "Id" << setw(15) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total" << endl;
    drawLine('-', 40);
    while (temp != NULL) {
        totalItemBill = temp->data.Price * temp->data.Quantity;

        cout << temp->data.Id << setw(15) << temp->data.Name << setw(15) << temp->data.Price << setw(15) << temp->data.Quantity << setw(15) << "Rs." << totalItemBill << endl;

        totalbill += totalItemBill;
        temp = temp->next;
    }
    drawLine('-', 40);
    cout << endl;
    cout << setw(15) << "TOTAL COST: " << "Rs." << totalbill << endl;
}
void superMarket::DisplayCustomer() {
    if (customerHead == NULL) {
        cout << "*** No Items in your cart ***";
        return;
    }
    Node* temp = customerHead;
    drawLine('-', 50);
    cout << "Id" << setw(15) << "Name" << setw(15) << "Price" << setw(15) << "Quantity" << endl;
    drawLine('-', 50);
    while (temp != NULL) {
        cout << temp->data.Id << setw(15) << temp->data.Name << setw(15) << temp->data.Price << setw(15) << temp->data.Quantity << endl;
        temp = temp->next;
    }
    drawLine('-', 50);
}
void superMarket::deleteSelectedItem() {
    bool found = false;
    int itemId;
    DisplayCustomer();

    if (customerHead == NULL) {
        return;
    }
    cout << "Enter Item id to delete: ";
    cin >> itemId;
    if (customerHead->data.Id == itemId) {
        found = true;
        Node* del = customerHead;
        customerHead = customerHead->next;
        delete del;
    }
    else {
        Node* temp = customerHead;
        Node* prev = NULL;
        while (temp->data.Id != itemId) {
            prev = temp;
            temp = temp->next;
        }
        found = true;
        Node* del = temp;
        prev->next = temp->next;
        delete del;
    }
    cout << "Deleting Item.";
    sleep();
    cout << endl;
    if (found) {
        cout << "*** Item with ID " << itemId << " deleted from cart ***" << endl;
    }
    else {
        cout << "*** Item with ID " << itemId << " not found in cart ***" << endl;
    }

}
void Boards::drawBoard(int xMid, int yMid, int height, int width) {
    gotoRowCol(xMid, yMid);
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            if (i == 1 || i == height || j == 1 || j == width) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        gotoRowCol(xMid, yMid + i);
    }
}

bool Boards::takeInput(int xMid, int yMid, int height, int width) {
    int clickX, clickY;
    getRowColbyLeftClick(clickX, clickY);
    if (clickX >= xMid && clickX <= xMid + width && clickY >= yMid && clickY <= yMid + height) {
        click = true;
        return true;
    }
    else {
        click = false;
        return false;
    }
}

void Boards::loginPanel(int bwidth, int bheight, int xMid, int yMid, int height, int width) {
    int choice;
    setclr(1);
    drawBoard(xMid, yMid, height, width);
    setclr(2);
    gotoRowCol(bwidth, bheight);
    cout << "Login panel";
    setclr(15);
    do {
        if (takeInput(xMid, yMid, height, width)) {
            system("cls");
            setclr(1);
            drawLine('-', 50);
            setclr(3);
            cout << "\t\tLOGIN PANEL";
            cout << endl;
            setclr(1);
            drawLine('-', 50);
            setclr(15);
            s.loginpanel();
            cout << endl;
            system("pause");
            system("cls");
        }
    } while (click != true);

}

void Boards::AdminSide(int bwidth, int bheight, int xMid, int yMid, int height, int width) {
h:
    char c;
    int nextBoard = 4;
    setclr(3);
    drawBoard(xMid, yMid, height, width);
    drawBoard(xMid, yMid + nextBoard, height, width);
    drawBoard(xMid, yMid + (nextBoard * 2), height, width);
    drawBoard(xMid, yMid + (nextBoard * 3), height, width);
    drawBoard(xMid, yMid + (nextBoard * 4), height, width);
    drawBoard(xMid, yMid + (nextBoard * 5), height, width);
    drawBoard(xMid, yMid + (nextBoard * 6), height, width);
    drawBoard(xMid + width + 2, yMid, height, width);
    drawBoard(xMid + width + 2, yMid + nextBoard, height, width);
    setclr(6);
    gotoRowCol(bwidth, bheight);
    cout << "Add Items";
    gotoRowCol(bwidth, bheight + nextBoard);
    cout << "Update Item";
    gotoRowCol(bwidth, bheight + (nextBoard * 2));
    cout << "Update Specifics";
    gotoRowCol(bwidth, bheight + (nextBoard * 3));
    cout << "Display items";
    gotoRowCol(bwidth, bheight + (nextBoard * 4));
    cout << "Change Logins ";
    gotoRowCol(bwidth, bheight + (nextBoard * 5));
    cout << "Delete items ";
    gotoRowCol(bwidth, bheight + (nextBoard * 6));
    cout << "Search Item";
    gotoRowCol(bwidth + width, bheight);
    cout << "Back to Main";
    gotoRowCol(bwidth + width, bheight + nextBoard);
    cout << "Total Items ";
    setclr(15);
    do {
        if (takeInput(xMid, yMid, height, width)) {
            system("cls");
            setclr(2);
            drawLine('=', 50);
            setclr(3);
            cout << "\t\tADD DATA";
            cout << endl;
            setclr(2);
            drawLine('=', 50);
            setclr(15);
            do {
                s.add();
                cout << "Do you want to add more Items(Y/N): ";
                cin >> c;
            } while (c == 'y' || c == 'Y');
            cout << endl;
            system("pause");
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + nextBoard, height, width)) {
            system("cls");
            setclr(3);
            drawLine('-', 50);
            cout << endl;
            setclr(4);
            cout << "\t\tUPDATE DETAILS";
            cout << endl;
            setclr(3);
            drawLine('-', 50);
            setclr(15);
            s.updateitemdetails();
            cout << endl;
            system("pause");
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + (nextBoard * 2), height, width)) {
            system("cls");
            setclr(4);
            drawLine('_', 50);
            cout << endl;
            setclr(5);
            cout << "\t\tUPDATE SPECIFIC DETAILS";
            cout << endl;
            setclr(4);
            drawLine('_', 50);
            setclr(15);
            s.updatespecific();
            system("pause");
            cout << endl;
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + (nextBoard * 3), height, width)) {
            system("cls");
            setclr(5);
            drawLine('-', 50);
            cout << endl;
            setclr(6);
            cout << "\t\tITEMS DETAILS";
            cout << endl;
            setclr(5);
            drawLine('-', 50);
            setclr(15);
            s.display();
            cout << endl;
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + (nextBoard * 4), height, width)) {
            system("cls");
            setclr(6);
            drawLine('+', 50);
            setclr(7);
            cout << "\t\tCHANGE CREDENTIALS";
            cout << endl;
            setclr(6);
            drawLine('+', 50);
            setclr(15);
            s.changecredentials();
            cout << endl;
            system("pause");
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + (nextBoard * 5), height, width)) {
            system("cls");
            setclr(7);
            drawLine('#', 50);
            cout << endl;
            setclr(8);
            cout << "\t\tDELETION PANEL";
            cout << endl;
            setclr(7);
            drawLine('#', 50);
            setclr(15);
            s.deleteItem();
            cout << endl;
            system("pause");
            system("cls");
            goto h;
        }
        if (takeInput(xMid, yMid + (nextBoard * 6), height, width)) {
            system("cls");
            setclr(8);
            drawLine('=', 50);
            cout << endl;
            setclr(9);
            cout << "\t\tSEARCH PANEL";
            cout << endl;
            setclr(8);
            drawLine('=', 50);
            setclr(15);
            s.searchitem();
            cout << endl;
            system("pause");
            system("cls");
            goto h;
        }
        if (takeInput(xMid + width, yMid, height, width)) {
            system("cls");
            MainMenu(bwidth, bheight, xMid, yMid, height, width);
        }
        if (takeInput(xMid + width, yMid + nextBoard, height, width)) {
            system("cls");
            setclr(9);
            drawLine('*', 50);
            cout << endl;
            setclr(10);
            cout << "\t\tTOTAL STOCK";
            cout << endl;
            setclr(9);
            drawLine('*', 50);
            setclr(15);
            cout << endl;
            s.TotalItems();
            system("pause");
            system("cls");
            goto h;
        }
    } while (click != true);
}
void Boards::CustomerSide(int bwidth, int bheight, int xMid, int yMid, int height, int width) {
    int nextBoard = 4;
g:
    setclr(6);
    drawBoard(xMid, yMid, height, width);
    drawBoard(xMid, yMid + nextBoard, height, width);
    drawBoard(xMid, yMid + (nextBoard * 2), height, width);
    drawBoard(xMid, yMid + (nextBoard * 3), height, width);
    drawBoard(xMid, yMid + (nextBoard * 4), height, width);
    setclr(8);
    gotoRowCol(bwidth, bheight);
    cout << "Select Items";
    gotoRowCol(bwidth, bheight + nextBoard);
    cout << "Customer Items";
    gotoRowCol(bwidth, bheight + (nextBoard * 2));
    cout << "Delete Item";
    gotoRowCol(bwidth, bheight + (nextBoard * 3));
    cout << "Generate Bill";
    gotoRowCol(bwidth, bheight + (nextBoard * 4));
    cout << "Back to Main";
    setclr(15);
    do {
        if (takeInput(xMid, yMid, height, width)) {
            system("cls");
            setclr(10);
            drawLine('-', 50);
            cout << endl;
            setclr(11);
            cout << "\t\tCHOOSE ITEMS";
            cout << endl;
            setclr(10);
            drawLine('-', 50);
            setclr(15);
            s.selectItem();
            cout << endl;
            system("pause");
            system("cls");
            goto g;
        }
        else if (takeInput(xMid, yMid + nextBoard, height, width)) {
            system("cls");
            setclr(11);
            drawLine('*', 50);
            cout << endl;
            setclr(12);
            cout << "\t\tCART ITEMS";
            cout << endl;
            setclr(11);
            drawLine('*', 50);
            setclr(15);
            s.DisplayCustomer();
            cout << endl;
            system("pause");
            system("cls");
            goto g;
        }
        else if (takeInput(xMid, yMid + (nextBoard * 2), height, width)) {
            system("cls");
            setclr(12);
            drawLine('+', 50);
            cout << endl;
            setclr(13);
            cout << "\t\tDELETION PANEL";
            cout << endl;
            setclr(12);
            drawLine('+', 50);
            setclr(15);
            s.deleteSelectedItem();
            cout << endl;
            system("pause");
            system("cls");
            goto g;
        }
        else if (takeInput(xMid, yMid + (nextBoard * 3), height, width)) {
            system("cls");
            setclr(13);
            drawLine('-', 50);
            cout << endl;
            setclr(14);
            cout << "\t\tINVOICE";
            cout << endl;
            setclr(13);
            drawLine('-', 50);
            setclr(15);
            s.generateBill();
            cout << endl;
            system("pause");
            system("cls");
            goto g;
        }
        else if (takeInput(xMid, yMid + (nextBoard * 4), height, width)) {
            system("cls");
            MainMenu(bwidth, bheight, xMid, yMid, height, width);
        }
    } while (click != true);
}
void Boards::MainMenu(int &bwidth, int &bheight, int &xMid, int &yMid, int &height, int &width) {
    int nextBoard = 4;
    setclr(8);
    drawBoard(xMid, yMid, height, width);
    drawBoard(xMid, yMid + nextBoard, height, width);
    drawBoard(xMid, yMid + (nextBoard * 2), height, width);
    setclr(9);
    gotoRowCol(bwidth, bheight);
    cout << "ADMIN SIDE";
    gotoRowCol(bwidth, bheight + nextBoard);
    cout << "CUSTOMER SIDE";
    gotoRowCol(bwidth, bheight + (nextBoard * 2));
    cout << "EXIT";
    setclr(15);
    do {
        if (takeInput(xMid, yMid, height, width)) {
            system("cls");
            loginPanel(bwidth, bheight, xMid, yMid, height, width);
            AdminSide(bwidth, bheight, xMid, yMid, height, width);
        }
        else if (takeInput(xMid, yMid + nextBoard, height, width)) {
            system("cls");
            CustomerSide(bwidth, bheight, xMid, yMid, height, width);
        }
        else if (takeInput(xMid, yMid + (nextBoard * 2), height, width)) {
            system("cls");
            exit(0);
        }
    } while (click != true);
}