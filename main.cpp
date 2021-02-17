#include <iostream>
#include <string>
#include <list>
using namespace std;

class Product
{
protected:
    string _name;
    string _price;
    string _label;

public:
    Product() {}
    Product(string name, string price) : _name(name), _price(price) {}
    virtual void CheckItem()
    {
        cout << this->_name << " | price: " << this->_price << " | label: " << this->_label << endl;
    };
    void SetLabel(string label) { this->_label.assign(label); }
};

class Box : public Product
{

    list<Product *> _prod;
    string boxname;

public:
    Box(string bx) : boxname(bx)
    {
    }
    void addItem(Product *p)
    {
        p->SetLabel(this->boxname);
        _prod.push_back(p);
    }
    void CheckItem() override
    {
        for (auto p : _prod)
        {
            p->CheckItem();
        }
    }
};

class Glassess : public Product
{
public:
    Glassess(string name, string price) : Product(name, price) {}
};
class Belt : public Product
{
public:
    Belt(string name, string price) : Product(name, price) {}
};

int main()
{
    Product *g = new Glassess("eiger", "150k");
    Product *b = new Belt("aRei", "75k");
    Product *c = new Belt("crocodile", "75k");
    Box *boxA = new Box("boxa");
    Box *boxb = new Box("boxb");
    boxA->addItem(g);
    boxA->addItem(b);
    boxb->addItem(boxA);
    boxb->addItem(c);
    boxb->CheckItem();
    return 0;
}