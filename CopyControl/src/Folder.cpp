#include "Folder.h"

Folder::Folder()
{
    //ctor
}

Folder::~Folder()
{
    //dtor
}
void Folder::addMsg(Message *m)
{
    messages.insert(m);
}
void Folder::remMsg(Message *m)
{
    messages.erase(m);
}
