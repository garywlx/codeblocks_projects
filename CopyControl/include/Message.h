#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>
#include "Folder.h"

using namespace std;

class Folder;

class Message
{
    friend class Folder;
public:
    Message();
    explicit Message(const string &str=""):contents(str){}
    Message(const Message&);
    Message(Message &&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    void move_Folders(Message *);
    virtual ~Message();
    void save(Folder&);
    void remove(Folder&);

protected:

private:
    string contents;
    set<Folder*> folders;
    void add_to_folders(const Message&);
    void remove_from_folders();
};

#endif // MESSAGE_H
