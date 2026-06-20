#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Product{
    public:
    string name;
    double price;
    int stock;
    Product(string name,double price,int stock){
        this->name=name;
        this->price=price;
        this->stock=stock;
    }
       void showInfo(){
        cout<<"Name : "<<name<<endl;
        cout<<"Price : "<<price<<endl;
        cout<<"Stock : "<<stock<<endl;
    }
};


class Store{
public:
vector<Product*>inventory;
void addProduct(string name,double price,int stock){
    inventory.push_back(new Product(name,price,stock));
}
void displayInventory(){
    for(Product*p:inventory){
        p->showInfo();
    }
}
void showInfo(){
    if(inventory.empty()){
        cout<<"Inventory is empty"<<endl;
    }
    for(auto*inv:inventory){
        cout<<"Name : "<<inv->name<<endl;
        cout<<"Price : "<<inv->price<<endl;
        cout<<"Stock : "<<inv->stock<<endl;
        cout<<endl;
    }
}
~Store(){
    for(Product *p : inventory){
        delete p;
    }
}
};


class Cart{
public:
vector<pair<Product*,int>>cartItems;
double totalPrice=0;
void addProduct(Store& currentstore,int idx,int quantity){
    if(idx>=0 && idx<currentstore.inventory.size()){

        Product* selectedProduct=currentstore.inventory[idx];
        if(selectedProduct->stock<quantity){
            cout<<"Insufficient stock of "<<selectedProduct->name<<endl;
        }
        else{
            cartItems.push_back({selectedProduct,quantity});
        }
    }
    else{
        cout<<"Invalid product idx"<<endl;
    }
}
void removeProduct(int idx){
    if(idx>=0 && idx<cartItems.size()){
        cout<<cartItems[idx].first->name<<" removed from cart"<<endl;
        cartItems.erase(cartItems.begin()+idx);
    }
    else{
        cout<<"Invalid product"<<endl;
    }
}
double calculateTotalPrice(){
    totalPrice=0;
    if(cartItems.empty()){
        return 0;
    }
    else{
        for(auto&items:cartItems){
            Product*p=items.first;
            int quantity=items.second;
            totalPrice+=p->price*quantity;
        }
        return totalPrice;
    }
}
void checkOut(){
    if(cartItems.empty()){
        cout<<"Your cart is empty!"<<endl;
        return;
    }
    for(auto &items:cartItems){
       Product* p=items.first;
       int quantity=items.second;
       p->stock-=quantity;
    }
    cout<<"Checkout successful! Total paid : "<<calculateTotalPrice()<<endl;
}
void showInfo(){
    for(auto&item:cartItems){
        Product*p=item.first;
        int quantity=item.second;
        double total=p->price*quantity;
        cout<<"Name : "<<p->name<<endl;
        cout<<"Price : "<<p->price<<endl;
        cout<<"Quantity : "<<quantity<<endl;
        cout<<"Total cost :"<<total<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<"Total Cost of all items : "<<calculateTotalPrice()<<endl;
}

};



int main(){

    Store store;
    store.addProduct("Laptop", 50000, 5);
    store.addProduct("Mouse", 500, 20);
    
    store.showInfo();   // confirm both products listed correctly
    
    Cart cart;
    cart.addProduct(store, 0, 2);    // buy 2 laptops
    cart.addProduct(store, 1, 3);    // buy 3 mice
    cart.addProduct(store, 0, 10);   // should fail — insufficient stock
    cart.addProduct(store, 5, 1);    // should fail — invalid index
    
    cart.showInfo();    // confirm correct totals
    cart.checkOut();    // confirm stock reduces in store
    
    store.showInfo();   // confirm Laptop stock is now 3, Mouse stock is now 17
    
    return 0;




    return 0;
}