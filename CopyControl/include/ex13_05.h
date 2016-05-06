#ifndef EX13_05_H
#define EX13_05_H
#include <iostream>
#include <string>

using std::string;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
    HasPtr()=default;
    HasPtr(const string& s = string()) : ps(new string(s)), i(0),use(new std::size_t(1)){}
    HasPtr(const HasPtr& hp) : ps(hp.ps), i(hp.i),use(hp.use) {++*use;}
    HasPtr& operator=(const HasPtr &rhs)
    {

        //auto newp=new string(*rhs.ps);
        ++*rhs.use;
        if(--*use==0){
            delete ps;
            delete use;
        }
        //delete ps;
        ps=rhs.ps;
        i=rhs.i;
        use=rhs.use;
        return *this;
    }
    void swap(HasPtr& rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        std::cout << "call swap(HasPtr &rhs)" << std::endl;
    }
    void show() { std::cout << *ps << std::endl; }
    ~HasPtr()
    {

        if(--*use==0){
            delete ps;
            delete use;
        }
        //delete ps;
    }
private:
    string* ps;
    int i;
    std::size_t *use;
};


class Employee{
public:
    Employee();
    Employee(const string &name);
    Employee(const Employee&)=delete;
    Employee& operator=(const Employee&) = delete;
    //const int getId()const{return id_;}
private:
    string employeeName;
    int id_;
    static int s_increment;

};

/**
    1、引用计数的使用
    2、使用拷贝赋值操作符时，应先增加右侧引用计数，
        然后减少左侧引用计数，当左侧计数为零时，释放资源
        最后更新左侧对象为右侧对象
*/
class TreeNode
{
public:
    TreeNode():value(""),count(nullptr),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode &node)
    {
        value=node.value;
        count=node.count;
        left=node.left;
        right=node.right;
        ++*node.count;
    }
    TreeNode &operator=(const TreeNode &node)
    {
        ++*node.count;
        if (--*count == 0) {
            if (left) {
                delete left;
                left = nullptr;
            }
            if (right) {
                delete right;
                right = nullptr;
            }

            delete count;
            count = nullptr;
        }
        value=node.value;
        count=node.count;
        left=node.left;
        right=node.right;
        return *this;
    }
    ~TreeNode();
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
public:

    BinStrTree(TreeNode *nos):root(nos){}

    BinStrTree &operator=(const BinStrTree &node)
    {
        TreeNode *newroot=new TreeNode(*node.root);
        delete root;
        root=newroot;
        return *this;

    }
private:
    TreeNode *root;
};
#endif // EX13_05_H
