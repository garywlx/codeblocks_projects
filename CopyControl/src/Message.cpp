#include "Message.h"

Message::Message()
{
    //ctor
}

Message::Message(const Message &m):contents(m.contents),folders(m.folders)
{
    add_to_folders(m);
}
Message::Message(Message &&m):contents(std::move(m.contents))
{
    move_Folders(&m);
}
Message& Message::operator=(const Message &m)
{
    remove_from_folders();
    contents=m.contents;
    folders=m.folders;
    add_to_folders(m);
    return *this;

}
Message& Message::operator=(Message &&m)
{
    if(this!=&m){
        remove_from_folders();
        contents=std::move(m.contents);
        //folders=(std::move(m.folders));
        move_Folders(&m);
    }
    return *this;
}
void Message::move_Folders(Message *m)
{
    folders=std::move(m->folders);
    for(auto f: folders){
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m)
{
    for(auto &f:m.folders){
        f->addMsg(this);
    }
}
void Message::remove_from_folders()
{
    for(auto &f:folders){
        f->remMsg(this);
    }
}

Message::~Message()
{
    remove_from_folders();
}

