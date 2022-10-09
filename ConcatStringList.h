#ifndef __CONCAT_STRING_LIST_H__
#define __CONCAT_STRING_LIST_H__

#include "main.h"

class ConcatStringList
{
public:
    class ReferencesList;   // forward declaration
    class DeleteStringList; // forward declaration

public:
    static ReferencesList refList;
    static DeleteStringList delStrList;

    // TODO: may provide some attributes
    class CharArrayList
    {
    public:
        char *ArrayChar;
        CharArrayList *next;

    public:
        ChararrayList(const char *inp)
        {
            this->ArrayChar = inp;
            this->next = nullptr;
        }
        ~ChararrayList();
    };
    class CharALNode
    {
    public:
        int size;
        CharArrayList *head;
        CharArrayList *tail;

    public:
        CharALNode()
        {
            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }
        void insert(const char *inp)
        {
            this->size += strlen(inp);
            if (this->head == nullptr)
            {
                this->head = new CharArrayList(inp);
                this->tail = this->head;
            }
            else
            {
                while (this->tail != nullptr)
                {
                    this->tail = this->tail->next;
                }
                this->tail = new CharArrayList(inp);
            }
        }
        ~CharALNode()
        {
            this->tail = this->tail->next;
            while (this->head != nullptr)
            {
                CharArrayList *cur = this->head;
                this->head = this->head->next;
                delete cur;
            }
            this->size = 0;
        }
    };
    CharALNode *Data;

public:
    ConcatStringList(const char *s);
    int length() const;
    char get(int index) const;
    int indexOf(char c) const;
    std::string toString() const;
    ConcatStringList concat(const ConcatStringList &otherS) const;
    ConcatStringList subString(int from, int to) const;
    ConcatStringList reverse() const;
    ~ConcatStringList();

public:
    class ReferencesList
    {
        // TODO: may provide some attributes
    public:
        CharALNode *Refdata;
        int Count_address_of;
        CharALNode *next;
        int size;

    public:
        /* void insertCharAlNode(CharALNode *inp)
        {
            if (this->Refdata->head == nullptr)
            {
                this->Refdata->insert(inp->head->CharArrayList);
                this->next = nullptr;
                this->Count_address_of = 2;
                size++;
            }
            else
            {
                ReferencesList *cur = this;
                while (cur->next != nullptr)
                {
                    cur = cur->next
                }
                cur = cur->next;
                cur->Refdata->insert(inp->head->CharArrayList);
                cur->next = nullptr;
                cur->Count_address_of = 2;
                size++;
            }
        }*/
        int size() const
        {
            return this->size;
        }
        int refCountAt(int index) const
        {
            if (index < 0 || index >= this->size)
                throw out_of_range("Index of references list is invalid!");
            ReferencesList *cur = this;
            while (index--)
                cur = cur->next;
            return cur->Count_address_of;
        }
        std::string refCountsString() const
        {
            ReferencesList *cur = this;
            std::string rtn = "RefCounts[";
            while (cur->next != nullptr)
            {
                rtn += (48 + cur->Count_address_of);
                rtn += ",";
                cur = cur->next;
            }
            rtn += (48 + cur->Count_address_of);
            rtn += "]";
            return rtn;
        }
    };

    class DeleteStringList
    {
        // TODO: may provide some attributes

    public:
        int size() const;
        std::string totalRefCountsString() const;
    };
};
#endif // __CONCAT_STRING_LIST_H__