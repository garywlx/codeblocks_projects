#ifndef FOLDER_H
#define FOLDER_H

#include <set>
#include "Message.h"

using namespace std;

class Message;

class Folder
{
    friend class Message;
public:
    Folder();
    void addMsg(Message*);
    void remMsg(Message*);
    virtual ~Folder();

protected:

private:
    set<Message*> messages;
};

#endif // FOLDER_H
