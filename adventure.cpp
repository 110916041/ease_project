#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;
using std::string;

class Commodity;
class Store;
class InputHandler;


class InputHandler {
public:
    /*
     * The function is used to read a full line into a string variable.
     * It read the redundant '\n' character to prevent the problem of getline function.
     * There is an overload version which can read from the specified data stream.
     * INPUT: None, or fstream
     * RETURN: Full line input by user
     * */
    static string readWholeLine() {
        string input;
        cin.get();
        getline(cin, input);
        return input;
    }

    static string readWholeLine(fstream& file) {
        string input;
        getline(file, input);
        return input;
    }

    /*
     * This function is used to configure whether the input string is a number
     * INPUT: A string
     * RETURN: Bool. True if input string is a number, otherwise false.
     */
    static bool isNum(string& str) {
        for (int i = 0; i < str.size(); i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }

    /*
     * Check the input string is a valid number.
     * First check the input is a number or not, then identify whether it is bigger than 0
     * INPUT: string
     * RETURN: bool
     */
    static bool isValidNum(string& str) {
        if (!isNum(str) || (isNum(str) && stoi(str) <= 0))
            return false;
        return true;
    }

    /*
     * Get a number from the user. This function will check the input validation.
     * INPUT: none
     * OUTPUT: integer, the input number
     */
    static int numberInput() {
        string input;
        cin >> input;
        while (!isValidNum(input)) {
            cout << "Please input again your input is NOT an integer or is lower than or equal to 0:" << endl;
            cin >> input;
        }
        return stoi(input);
    }

    /*
     * This function is used in function getInput. Check the input range is inside the specified range
     */
    static int inputCheck(string input, int maxChoiceLen, bool noZero) {
        // Change input to the general integer
        int choice = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i])) {
                choice = choice * 10 + (input[i] - '0');
            } else {
                return -1;
            }
        }

        if (noZero) {
            return (choice <= maxChoiceLen && choice > 0) ? choice : -1;
        } else {
            return (choice <= maxChoiceLen && choice >= 0) ? choice : -1;
        }
    }

    /*
     * Get the input from the user, and limit the input between the range [0, maxChoiceLen].
     * If noZero is signaled. Then the range will be [1, maxChoiceLen]
     * INPUT: integer, bool(option)
     * OUTPUT: integer, the choice number
     */
    static int getInput(int maxChoiceLen, bool noZero = false) {
        string input;

        cin >> input;
        int choice = inputCheck(input, maxChoiceLen, noZero);
        while (choice == -1) {
            cout << "your input is wrong, please input again:" << endl;
            cin >> input;
            choice = inputCheck(input, maxChoiceLen, noZero);
        }

        return choice;
    }
};

/*
 * Commodity is about an item which the user can buy and the manager can add or delete.
 * ATTRIBUTE:
 *  price: The price of the commodity, an integer.
 *  description: The text which describe the commodity detail, a string.
 *  commodityName: The name of the commodity, a string.
 */
class Commodity {
protected:
    int price;
    string description;
    string commodityName;
    Commodity* next;
    int itemno ;
    int classno;
public:
    ~Commodity() = default;
    Commodity() {
        price = 0;
        description = "";
        commodityName = "";
        next = NULL;
        itemno = 0;
        classno = 0;
    }

    Commodity(int price, string commodityName, string description) {
        this->price = price;
        this->commodityName = commodityName;
        this->description = description;
        this->itemno = 0;
        this->next = NULL;
        this->classno = 0;
    }


    /*
     * This method will show the full information of the commodity to user interface.
     * There is a overloading version, with an argument amount which will output the information with the amount
     * INPUT: None, or an integer specify the amount of this commodity
     * RETURN: None
     */
    virtual void detail() {

    }



    virtual void detail(int amount) {}

    /*
     * Use this function to get the information data from the user, this will init the object.
     * INPUT: none
     * OUTPUT: none
     */
    virtual void userSpecifiedCommodity() {}

    /*
     * Save and load function is used to write the data to the file or read the data from the file.
     * According to the input parameter fstream, they complete the I/O on the specified file.
     * There have no definition of those method, because it is used to be override in the derived class.
     * INPUT: fstream
     * OUTPUT: none
     */
    virtual void save(fstream& file) {}

    virtual void load(fstream& file) {}

    /*
     * The getter function of commodityName
     */
    string getName() {
        return commodityName;
    }

    /*
     * The getter function of price
     */
    int getPrice() {
        return price;
    }

    /*
     * The getter function of description
     */
    string getdescription() {
        return description;
    }

    Commodity* getNext() {
        return next;
    }

    void setNext(Commodity *head) {
        next = head;
    }
    int getitemno(){
        return itemno;
    }
    void setitemno(){
        itemno++;
    }
    int getclassno(){
        return classno;
    }
    virtual string get_str1(){}
    virtual string get_str2(){}
    virtual int get_int(){}

};



/*
 * [YOU SHOULD FINISH THREE TYPES OF DERIVED COMMODITY CLASS HERE]
 * Please try your best to complete the definition of three classes.
 * Use the knowledge you learned from this course.
 * You should follow the OOP concept.
 */
class car : public Commodity{
friend Commodity;
protected:
    string carbrand;          //品牌 BMW TOYOTA...
    int seat;//幾人座
public:
    void userspecifiedCommodity(){
        cout << "Please input the brand of the commodity" << endl;
        carbrand = InputHandler::readWholeLine();
        cout << "Please input how many seats of the commodity" << endl;
        seat = InputHandler::numberInput();
        cout << "Please input the commodity name:" << endl;
        commodityName = InputHandler::readWholeLine();
        cout << "Please input the commodity price:" << endl;
        price = InputHandler::numberInput();
        cout << "Please input the detail of the commodity:" << endl;
        description = InputHandler::readWholeLine();
        classno = 1;
    }

    void detail(){
        cout << carbrand << endl;
        cout << "Seat: " << seat << endl;
        cout << "Name: " << commodityName << endl;
        cout << "Price: " << price << endl;
        cout << description << endl;
        cout << "----------------------------" << endl;
    }

    void detail(int amount) {
        cout << carbrand << endl;
        cout << "Seat: " << seat << endl;
        cout << "Name: " << commodityName << endl;
        cout << "Price: " << price << endl;
        cout << description << endl;
        cout << "x " << amount << endl;
        cout << "----------------------------" << endl;
    }

    string getcarbrand(){
        return carbrand;
    }
    int getseat(){
        return seat;
    }
    void set(int _price,string d,string n,string car_brand,int _seat){
        price=_price;
        description=d;
        commodityName=n;
        carbrand=car_brand;
        seat=_seat;
        classno=1;
        itemno=1;
    }
    void setload(string _carbrand, int _seat, string _name, int _price, string d){
        carbrand=_carbrand;
        seat=_seat;
        commodityName=_name;
        price=_price;
        description=d;
        classno = 1;
        itemno=1;
    }
    string get_str1(){
        return carbrand;
    }
    string get_str2(){
        return carbrand;
    }
    int get_int(){
        return seat;
    }
};


class phone : public Commodity{
friend Commodity;
protected:
    string phonebrand;     //品牌 apple samsung...
    int lens;  //幾個鏡頭
public:
    void userSpecifiedCommodity() {
        cout << "Please input the brand of the commodity" << endl;
        phonebrand = InputHandler::readWholeLine();
        cout << "Please input how many lens of the commodity" << endl;
        lens = InputHandler::numberInput();
        cout << "Please input the commodity name:" << endl;
        commodityName = InputHandler::readWholeLine();
        cout << "Please input the commodity price:" << endl;
        price = InputHandler::numberInput();
        cout << "Please input the detail of the commodity:" << endl;
        description = InputHandler::readWholeLine();
        classno = 2;
    }

    void detail(){
        cout << phonebrand << endl;
        cout << "Lens: " << lens << endl;
        cout << "Name: " << commodityName << endl;
        cout << "price: " << price << endl;
        cout << description << endl;
        cout << "----------------------------" << endl;
    }

    void detail(int amount) {
        cout << phonebrand << endl;
        cout << "Lens: " << lens << endl;
        cout << "Name: " << commodityName << endl;
        cout << "Price: " << price << endl;
        cout << description << endl;
        cout << "x " << amount << endl;
        cout << "----------------------------" << endl;
    }

    string getphonebrand(){
        return phonebrand;
    }
    int getlens(){
        return lens;
    }
    void set(int _price,string d,string n,string phone_brand,int _lens){
        price=_price;
        description=d;
        commodityName=n;
        phonebrand=phone_brand;
        lens=_lens;
        classno=2;
        itemno=1;
    }
    void setload(string _phonebrand, int _lens, string _name, int _price, string d){
        phonebrand=_phonebrand;
        lens=_lens;
        commodityName=_name;
        price=_price;
        description=d;
        classno = 2;
        itemno=1;
    }
    string get_str1(){
        return phonebrand;
    }
    string get_str2(){
        return phonebrand;
    }
    int get_int(){
        return lens;
    }
};


class drink : public Commodity{
friend Commodity;
protected:
    int cups;
    string ice;
    string sugar;
public:
    void userSpecifiedCommodity() {
        cout << "Please input the commodity name:" << endl;
        commodityName = InputHandler::readWholeLine();
        cout << "Please input the commodity price:" << endl;
        price = InputHandler::numberInput();
        cout << "Please input how many ice of the commodity" << endl;
        ice = InputHandler::readWholeLine();
        cout << "Please input how many cups :" << endl;
        cups = InputHandler::numberInput();
        cout << "Please input the sugar of the commodity" << endl;
        sugar = InputHandler::readWholeLine();
        classno = 3;
    }

    void detail(){
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "Ice: " << ice << endl;
        cout << "Cups: " << cups << endl;
        cout << "Sugar: " << sugar << endl;
        cout << "----------------------------" << endl;
    }

    void detail(int amount) {
        cout << commodityName << endl;
        cout << "price: " << price << endl;
        cout << "Ice: " << ice << endl;
        cout << "Cups: " << cups << endl;
        cout << "Sugar: " << sugar << endl;
        cout << description << endl;
        cout << "x " << amount << endl;
        cout << "----------------------------" << endl;
    }
    string getsugar(){
        return sugar;
    }
    string getice(){
        return ice;
    }
    int getcups(){
        return cups;
    }
    void set(int _price,string d,string n,string _sugar,string _ice,int _cup){
        price=_price;
        description=d;
        commodityName=n;
        sugar=_sugar;
        ice=_ice;
        cups=_cup;
        classno=3;
        itemno=1;
    }
    void setload(string _name, int _price, string _ice, int _cups, string _sugar){
        commodityName=_name;
        price=_price;
        ice=_ice;
        cups=_cups;
        sugar=_sugar;
        classno = 3;
        itemno=1;
    }
    string get_str1(){
        return sugar;
    }
    string get_str2(){
        return ice;
    }
    int get_int(){
        return cups;
    }
};

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * This is a list storing the existing commodity in the store.
 * There are some method which can modify the content.
 * You may use any data structure to complete this class.
 */
class CommodityList {
private:
    int itotal = 0;
    Commodity *carhead,*phonehead,*drinkhead ;
public:
    int caramount , phoneamount , drinkamount ;
    CommodityList():carhead(NULL) , phonehead(NULL) , drinkhead(NULL) , caramount(0) , phoneamount(0) , drinkamount(0){}
    ~CommodityList(){
        Commodity *p=carhead;
        while(caramount>1){
            carhead=carhead->getNext();
            delete p;
            caramount--;
        }
        delete p;

        Commodity *q=phonehead;
        while(phoneamount>1){
            phonehead=phonehead->getNext();
            delete q;
            phoneamount--;
        }
        delete q;

        Commodity *r=drinkhead;
        while(drinkamount>1){
            drinkhead=drinkhead->getNext();
            delete r;
            drinkamount--;
        }
        delete r;
    }
    /*
     * Print the full information of the commodities inside the list
     * You must call Commodity.detail() to show the commodity information.
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesDetail() {
        int i = 0;
        itotal = caramount+phoneamount+drinkamount;
        Commodity* first = carhead;
        cout << "Car type :" << endl ;
        while (first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                first->detail();
                first = first->getNext();
                i++;
            }
            cout << endl ;
        }
        first = phonehead;
        cout << "Phone type :" << endl ;
        while (first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                first->detail();
                first = first->getNext();
                i++;
            }
            cout << endl ;
        }
        first = drinkhead;
        cout << "Drink type :" << endl ;
        while (first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                first->detail();
                first = first->getNext();
                i++;
            }
        }
    }

    /*
     * Print only the commodity name of the commodities inside the list
     * You don't need to use Commodity.detail() here, just call the Commodity.getName() function is ok
     * INPUT: None
     * RETURN: None
     */
    void showCommoditiesName() {
        itotal = caramount+phoneamount+drinkamount;
        int i = 0 ;
        Commodity* first = carhead;
        cout << "Car type :" << endl ;
        while(first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                cout <<first->getName() << endl;
                first = first->getNext();
                i++;
            }
        }
        first = phonehead;
        cout << "Phone type :" << endl ;
        while(first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                cout <<first->getName() << endl;
                first = first->getNext();
                i++;
            }
        }
        first = drinkhead;
        cout << "Drink type :" << endl ;
        while(first != NULL){
            if(i < itotal){
                cout << i+1 << ". " ;
                cout <<first->getName() << endl;
                first = first->getNext();
                i++;
            }
        }
    }

    /*
     * Check whether the list is empty or not
     * INPUT: None
     * RETURN: Bool. True if the list is empty, otherwise false
     */
    bool empty() {
        if(carhead == NULL && phonehead == NULL && drinkhead == NULL){
            return true ;
        }
        else{
            return false ;
        }
    }

    /*
     * Return the size(or length) of the list
     * INPUT: None
     * RETURN: Integer. List size
     */
    int size() {
        itotal = caramount+phoneamount+drinkamount;
        return itotal;
    }

    /*
     * Return a commodity object at specified position
     * INPUT: Integer. The index of that commodity
     * RETURN: Commodity. The wanted commodity object
     */
    Commodity* get(int index) {
        Commodity* first = NULL;
        if(index+1 < caramount+1 ){
            first = carhead;
            for(int j=0 ; j < index ; j++){
                first=first->getNext();
            }
            return first;
        }else if(index+1 < phoneamount+1+caramount ){
            first = phonehead;
            for(int j=0 ; j < index-caramount ; j++){
                first=first->getNext();
            }
            return first;
        } else{
            first = drinkhead;
            for (int j=0 ; j <index-caramount-phoneamount ; j++) {
                first = first->getNext();
            }
            return first;
        }
    }

    /*
     * Push a new commodity object into the list
     * INPUT: Commodity. The object need to be pushed
     * RETURN: None
     */
    void add(Commodity* newCommodity, string& cat) {
        string a(cat);
        if(a == "car"){
            if(carhead == NULL){
                carhead = newCommodity;
            }
            else{
                Commodity* check1=carhead;
                for(int i=0;i<caramount-1;i++){
                    check1 = check1->getNext();
                }
                check1->setNext(newCommodity);
            }
            caramount++;
        }else if(a == "phone"){
            if(phonehead == NULL){
                phonehead = newCommodity;
            }
            else{
                Commodity* check2=phonehead;
                for(int i=0;i<phoneamount-1;i++){
                    check2 = check2->getNext();
                }
                check2->setNext(newCommodity);
            }
            phoneamount++;
        } else{
            if(drinkhead == NULL){
                drinkhead = newCommodity;
            }
            else{
                Commodity* check3=drinkhead;
                for(int i=0;i<drinkamount-1;i++){
                    check3 = check3->getNext();
                }
                check3->setNext(newCommodity);
            }
            drinkamount++;
        }
    }

    /*
     * Check the input commodity object is existing inside the list
     * If the commodity name is the same, we take those objects the same object
     * INPUT: Commodity. The object need to be checked
     * OUTPUT: Bool. True if the object existing, otherwise false
     */
    bool isExist(Commodity* commodity , string& cat) {
        string a(cat);
        if(a == "car"){
            Commodity* check = carhead;
            while(check != NULL && check->getName() != commodity->getName()){
                check=check->getNext();
            }
            if(check == NULL){
                return false;
            }
            else{
                return true;
            }
        }else if(a == "phone"){
            Commodity* check = phonehead;
            while(check != NULL && check->getName() != commodity->getName()){
                check=check->getNext();
            }
            if(check == NULL){
                return false;
            }
            else{
                return true;
            }
        } else{
            Commodity* check = drinkhead;
            while(check != NULL && check->getName() != commodity->getName()){
                check=check->getNext();
            }
            if(check == NULL){
                return false;
            }
            else{
                return true;
            }
        }
    }

    /*
     * Remove an object specified by the position
     * INPUT: Integer. The position of the object which need to be removed
     * OUTPUT: None
     */
    void remove(int index) {
        Commodity* first = NULL;
        if(index+1 < caramount+1 ){
            first = carhead;
            if(index == 0){
                carhead=carhead->getNext();
            }else if(index == 1){
                carhead->setNext(carhead->getNext()->getNext());
            }else{
                for(int i=0 ; i < index-1 ; i++){
                    first=first->getNext();
                }
                first->setNext(first->getNext()->getNext());
            }
            caramount--;
        }else if(index+1-caramount < phoneamount+1 ){
            first = phonehead;
            if(index+1-caramount == 1){
                phonehead=phonehead->getNext();
            }else if(index+1-caramount == 2){
                phonehead->setNext(phonehead->getNext()->getNext());
            }else{
                for(int i=0 ; i < index-1 ; i++){
                    first=first->getNext();
                }
                first->setNext(first->getNext()->getNext());
            }
            phoneamount--;
        } else{
            first = drinkhead;
            if(index+1-caramount-phoneamount == 1){
                drinkhead=drinkhead->getNext();
            }else if(index+1-caramount-phoneamount == 2){
                drinkhead->setNext(drinkhead->getNext()->getNext());
            }else{
                for(int i=0 ; i < index-1 ; i++){
                    first=first->getNext();
                }
                first->setNext(first->getNext()->getNext());
            }
            drinkamount--;
        }
    }
    void save(){
        int a ,b ,c;
        a=caramount;
        b=phoneamount;
        c=drinkamount;
        fstream file;
        file.open("hw2.txt",ios_base::trunc | ios_base::out);
        int i = 0;
        itotal = caramount+phoneamount+drinkamount;
        file << a << ' ' << b << ' ' << c <<endl;
        Commodity* first = carhead;
        while (first != NULL){
            if(i < itotal){
                file.fill(' ');
                file << first->get_str1() << endl;
                file << first->get_int() << endl;
                file << first->getName()  << endl;
                file << first->getPrice() << endl;
                file << first->getdescription() << endl;
                first = first->getNext();
                i++;
            }
        }
        first = phonehead;
        while (first != NULL){
            if(i < itotal){
                file.fill(' ');
                file << first->get_str1() << endl ;
                file << first->get_int() << endl ;
                file << first->getName()  << endl;
                file << first->getPrice() << endl ;
                file << first->getdescription() << endl;
                first = first->getNext();
                i++;
            }
        }
        first = drinkhead;
        while (first != NULL){
            if(i < itotal){
                file.fill(' ');
                file << first->getName()<<endl ;
                file << first->getPrice()<<endl;
                file << first->get_str1()<<endl;
                file << first->get_int() <<endl;
                file << first->get_str2()<<endl;
                first = first->getNext();
                i++;
            }
        }
    }

    void load(){
        int a1,a2;
        string s,s1,s2;
        Commodity* last;
        fstream file;
        file.open("hw2.txt" ,ios_base::in);
        if(!file){
            cout << "cannot open the txt file !!"<<endl;
            return;
        }
        else{
            file >> caramount;
            file >> phoneamount;
            file >> drinkamount;
            for(int i=0 ;i<caramount ; i++){
                if(carhead == NULL){
                    car* p=new car();
                    file.get();
                    s=InputHandler::readWholeLine(file);
                    file>>a1;
                    file.get();
                    s1=InputHandler::readWholeLine(file);
                    file>>a2;
                    file.get();
                    s2=InputHandler::readWholeLine(file);
                    p->setload(s,a1,s1,a2,s2);
                    p->setNext(NULL);
                    carhead=p;
                    last=carhead;
                }
                else{
                    car* p=new car();
                    s=InputHandler::readWholeLine(file);
                    file>>a1;
                    file.get();
                    s1=InputHandler::readWholeLine(file);
                    file>>a2;
                    file.get();
                    s2=InputHandler::readWholeLine(file);
                    p->setload(s,a1,s1,a2,s2);
                    p->setNext(NULL);
                    last->setNext(p);
                    last=p;
                }
            }
            for(int i=0 ; i < phoneamount ; i++){
                phone* p=new phone();
                s=InputHandler::readWholeLine(file);
                file>>a1;
                file.get();
                s1=InputHandler::readWholeLine(file);
                file>>a2;
                file.get();
                s2=InputHandler::readWholeLine(file);
                p->setload(s,a1,s1,a2,s2);
                p->setNext(NULL);
                if(phonehead == NULL){
                    phonehead=p;
                    last=phonehead;
                }
                else{
                    last->setNext(p);
                    last=p;
                }
            }
            for(int i=0 ; i < drinkamount ; i++){
                drink* p=new drink();
                s=InputHandler::readWholeLine(file);
                file>>a1;
                file.get();
                s1=InputHandler::readWholeLine(file);
                file>>a2;
                file.get();
                s2=InputHandler::readWholeLine(file);
                p->setload(s,a1,s1,a2,s2);
                p->setNext(NULL);
                if(drinkhead == NULL){
                    drinkhead=p;
                    last=drinkhead;
                }
                else{
                    last->setNext(p);
                    last=p;
                }
            }
        }
        file.close();
    }
};

/*
 * [YOU NEED TO FINISH THIS CLASS]
 * The shopping cart is used to store the commodities user wanted.
 * Because the same name represents the same object, if there is a commodity which have more than one object inside
 * the cart, then it will be store as the same object and the cart must keep the amount of the object.
 * You may use any data structure to complete this class.
 */
class ShoppingCart {
private:
    int itotal1 =0;
    Commodity* carthead = NULL ;
    int cartamount = 0;
    vector<Commodity*> cart;
public:

    /*
     * Push an commodity object into the cart.
     * Be careful that if the input object is existing in the list, then keep the amount of that object rather than
     * actually push the object into the cart.
     * INPUT: Commodity. The object need to be pushed.
     * OUTPUT: None.
     */

    void push(Commodity *entry) {
        bool ispush=true;
        if(entry->getclassno()==1){
            car *item=new car;
            item->set(entry->getPrice(),entry->getdescription(),entry->getName(),entry->get_str1(),entry->get_int());
            for(int i=0;i<cart.size();i++){
                if(cart[i]->getName()==item->getName()){
                    cart[i]->setitemno();
                    ispush=false;
                    break;
                }
            }
            if(ispush){
                cart.push_back(item);
                cartamount++;
            }
        }
        else if(entry->getclassno()==2){
            phone *item=new phone;
            item->set(entry->getPrice(),entry->getdescription(),entry->getName(),entry->get_str1(),entry->get_int());
            for(int i=0;i<cart.size();i++){
                if(cart[i]->getName()==item->getName()){
                    cart[i]->setitemno();
                    ispush=false;
                    break;
                }
            }
            if(ispush){
                cart.push_back(item);
                cartamount++;
            }
        }
        else{
            drink *item=new drink;
            item->set(entry->getPrice(),entry->getdescription(),entry->getName(),entry->get_str1(),entry->get_str2(),entry->get_int());
            for(int i=0;i<cart.size();i++){
                if(cart[i]->getName()==item->getName()){
                    cart[i]->setitemno();
                    ispush=false;
                    break;
                }
            }
            if(ispush){
                cart.push_back(item);
                cartamount++;
            }
        }
    }

    /*
     * Show the content of the cart to user interface.
     * INPUT: None.
     * OUTPUT: None.
     */
    void showCart() {
        for(int i=0;i<cart.size();i++){
            cout << i+1 <<". "<<endl;
            if(cart[i]->getclassno()==1){
                cout << cart[i]->get_str1() << endl;
                cout << "Seat: " << cart[i]->get_int() << endl;
                cout << "Name" << cart[i]->getName() << endl;
                cout << "Price: " << cart[i]->getPrice() << endl;
                cout << cart[i]->getdescription() << endl;
                cout << "x " << cart[i]->getitemno() << endl;
                cout << "----------------------------" << endl;
            }
            else if(cart[i]->getclassno()==2){
                cout << cart[i]->get_str1() << endl;
                cout << "Lens: " << cart[i]->get_int() << endl;
                cout << "Name" << cart[i]->getName() << endl;
                cout << "Price: " << cart[i]->getPrice() << endl;
                cout << cart[i]->getdescription() << endl;
                cout << "x " << cart[i]->getitemno() << endl;
                cout << "----------------------------" << endl;
            }
            else{
                cout << cart[i]->getName() << endl;
                cout << "price: " << cart[i]->getPrice() << endl;
                cout << "Ice: " << cart[i]->get_str2() << endl;
                cout << "Cups: " << cart[i]->get_int() << endl;
                cout << "Sugar: " << cart[i]->get_str1() << endl;
                cout << cart[i]->getdescription() << endl;
                cout << "x " << cart[i]->getitemno() << endl;
                cout << "----------------------------" << endl;
            }
        }
    }

    /*
     * Return the cart size. (The same object must be seen as one entry)
     * INPUT: None.
     * OUTPUT: Integer. The cart size.
     */
    int size() {
        return cartamount;
    }

    /*
     * Remove an entry from the cart. forDon't care about the amount of the commodity, just remove it.
     * INPUT: The order of the entry.
     * OUTPUT: None.
     */
    void remove(int index) {
        auto iter = cart.erase(cart.begin()+index);
    }

    /*
     * Check the total amount of price for the user.
     * Remember to clear the list after checkout.
     * INPUT: None.
     * OUTPUT: Integer. The total price.
     */
    int checkOut() {
        int total = 0;
        for(int i = 0 ; i < cart.size() ; i++){
            total=total+(cart[i]->getPrice()*cart[i]->getitemno()
			);
        }
        cart.clear();
        return total;
    }

    /*
     * Check if the cart have nothing inside.
     * INPUT: None.
     * OUTPUT: Bool. True if the cart is empty, otherwise false.
     */
    bool empty() {
        if(cart.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/*
 * [DO NOT MODIFY ANY CODE HERE]
 * The Store class manage the flow of control, and the interface showing to the user.
 * Store use status to choose the interface to show. As the result, status control is very important here.
 * If you can understand the code here, you will have great work on the above two class.
 * The detail of Store is in the README
 */
class Store {
private:
    enum UMode {USER, MANAGER} userStatus;
    enum SMode {OPENING, DECIDING, SHOPPING, CART_CHECKING, CHECK_OUT, MANAGING, CLOSE} storeStatus;
    CommodityList commodityList;
    ShoppingCart cart;


    void commodityInput() {
        cout << "Which type of commodity you want to add?" << endl;
        cout << "1. car , 2.phone , 3.drink"<<endl;
        int choose = 0;
        cin >> choose;
        if(choose == 1){
            car* newcom = new car;
            newcom->userspecifiedCommodity();
            string a("car");
            if (commodityList.isExist(newcom , a)) {
                cout << "[WARNING] " << newcom->getName() << " is exist in the store. If you want to edit it, please delete it first" << endl;
            } else {
                commodityList.add(newcom , a);
            }
        } else if(choose == 2){
            phone* newcom = new phone;
            newcom->userSpecifiedCommodity();
            string a("phone");
            if (commodityList.isExist(newcom , a)) {
                cout << "[WARNING] " << newcom->getName() << " is exist in the store. If you want to edit it, please delete it first" << endl;
            } else {
                commodityList.add(newcom , a);
            }
        } else if(choose == 3){
            drink* newcom = new drink;
            newcom->userSpecifiedCommodity();
            string a("drink");
            if (commodityList.isExist(newcom , a)) {
                cout << "[WARNING] " << newcom->getName() << " is exist in the store. If you want to edit it, please delete it first" << endl;
            } else {
                commodityList.add(newcom , a);
            }
        }
        /*
         * You should finish this method, because you need to identify the type of commodity, and instantiate a
         * corresponding derived commodity class here.
         */

    }

    void deleteCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        int choice;
        cout << "There are existing commodity in our store:" << endl;
        commodityList.showCommoditiesName();
        cout << "Or type 0 to regret" << endl
             << "Which one do you want to delete?" << endl;

        choice = InputHandler::getInput(commodityList.size());

        if (choice != 0) {
            commodityList.remove(choice - 1);
        }
    }

    void showCommodity() {
        if (commodityList.empty()) {
            cout << "No commodity inside the store" << endl;
            return;
        }

        cout << "Here are all commodity in our store:" << endl;
        commodityList.showCommoditiesDetail();
        cout << endl;
    }

    void askMode() {
        string input;

        cout << "Are you a general user or a manager?" << endl
             << "1. general user, 2. manager" << endl
             << "Or type 0 to close the store" << endl;

        int choice = InputHandler::getInput(2);

        userStatus = (choice == 2) ? UMode::MANAGER : UMode::USER;

        if (choice == 0) {
            storeStatus = SMode::CLOSE;
        } else if (userStatus == UMode::USER) {
            storeStatus = SMode::DECIDING;
        } else if (userStatus == UMode::MANAGER) {
            storeStatus = SMode::MANAGING;
        }
    }

    void decideService() {
        string input;

        cout << "Below are our service:" << endl
             << "1. Buy the commodity you want" << endl
             << "2. Check your shopping cart" << endl
             << "3. Check out" << endl
             << "Or type 0 to exit user mode" << endl
             << "You may choose what you need:" << endl;

        int choice = InputHandler::getInput(3);

        if (choice == 1) {
            storeStatus = SMode::SHOPPING;
        } else if (choice == 2) {
            storeStatus = SMode::CART_CHECKING;
        } else if (choice == 3) {
            storeStatus = SMode::CHECK_OUT;
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void chooseCommodity() {
        string input;
        showCommodity();
        cout << "Or input 0 to exit shopping" << endl;

        int choice = InputHandler::getInput(commodityList.size());

        // Push the commodity into shopping cart here
        if (choice == 0) {
            storeStatus = SMode::DECIDING;
        } else {
            // May be some bug here, test later
            cart.push(commodityList.get(choice - 1));
            // cart.saveget(commodityList.get(choice-1))
        }
    }

    void showCart() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty" << endl;
            storeStatus = SMode::DECIDING;
            return;
        }

        int choice;
        do {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();

            cout << "Do you want to delete the entry from the cart?" << endl
                 << "1. yes, 2. no" << endl;

            choice = InputHandler::getInput(2, true);

            if (choice == 1) {
                cout << "Which one do you want to delete(type the commodity index)?" << endl
                     << "Or type 0 to regret" << endl;
                int index = InputHandler::getInput(cart.size());
                // **
                if (index == 0) {
                    break;
                }
                cart.remove(index - 1);
            }
        } while (choice == 1);

        cout << "Do you want to checkout?" << endl
             << "1. yes, 2. No, I want to buy more" << endl;
        choice = InputHandler::getInput(2, true);
        if (choice == 1) {
            storeStatus = SMode::CHECK_OUT;
        } else {
            storeStatus = SMode::DECIDING;
        }
    }

    void checkOut() {
        if (cart.empty()) {
            cout << "Your shopping cart is empty, nothing can checkout" << endl;
        } else {
            cout << "Here is the current cart content:" << endl;
            cart.showCart();
            cout << "Are you sure you want to buy all of them?" << endl
                 << "1. Yes, sure, 2. No, I want to buy more" << endl;

            int choice = InputHandler::getInput(2, true);

            if (choice == 1) {
                int amount = cart.checkOut();
                cout << "Total Amount: " << amount << endl;
                cout << "Thank you for your coming!" << endl;
                cout << "------------------------------" << endl << endl;
            }
        }

        storeStatus = SMode::DECIDING;
    }

    void managerInterface() {
        cout << "Here are some manager services you can use:" << endl
             << "1. Add new commodity" << endl
             << "2. Delete commodity from the commodity list" << endl
             << "3. Show all existing commodity" << endl
             << "Or type 0 to exit manager mode" << endl
             << "Which action do you need?" << endl;

        int choice = InputHandler::getInput(3);

        if (choice == 1) {
            commodityInput();
        } else if (choice == 2) {
            deleteCommodity();
        } else if (choice == 3) {
            showCommodity();
        } else if (choice == 0) {
            storeStatus = SMode::OPENING;
        }
    }

    void userInterface() {
        if (storeStatus == SMode::OPENING) {
            askMode();
        } else if (storeStatus == SMode::DECIDING) {
            decideService();
        } else if (storeStatus == SMode::SHOPPING) {
            chooseCommodity();
        } else if (storeStatus == SMode::CART_CHECKING) {
            showCart();
        } else if (storeStatus == SMode::CHECK_OUT) {
            checkOut();
        } else if (storeStatus == SMode::MANAGING) {
            managerInterface();
        } else if (storeStatus == SMode::CLOSE) {
            return;
        }
    }

public:
    Store() {
        userStatus = UMode::USER;
        storeStatus = SMode::CLOSE;
    }

    void open() {
        commodityList.load();
        storeStatus = SMode::OPENING;
        while (storeStatus != SMode::CLOSE) {
            userInterface();
        }
        commodityList.save();
    }
};


int main() {
    Store csStore;
    csStore.open();
    return 0;
}
