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
        std::string ArrayChar;
        CharArrayList *next;

    public:
        CharArrayList(std::string inp)
        {
            this->ArrayChar = inp;
            this->next = nullptr;
        }
        ~CharArrayList();
    };
    class CharALNode
    {
    public:
        int size_string;
        CharArrayList *head;
        CharArrayList *tail;

    public:
        CharALNode()
        {
            this->size = 0;
            this->head = nullptr;
            this->tail = nullptr;
        }
        void insert(std::string inp)
        {
            this->size_string += (int)cur->ArrayChar->length();
            if (this->head == nullptr)
            {
                this->head = new CharArrayList(inp);
                this->tail = this->head;
            }
            else
            {
                this->tail = this->tail->next;
                this->tail = new CharArrayList(inp);
            }
        }
        void insertHead(std::string inp)
        {
            this->size_string += (int)cur->ArrayChar->length();
            if (this->head == nullptr)
            {
                this->head = new CharArrayList(inp);
                this->tail = this->head;
            }
            else
            {
                CharArrayList *cur = new CharArrayList(inp);
                cur->next=this->head;
                this->head=cur;
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
        class ReferencesListData
        {
        public:
            std::string *Refdata;
            int Count_address_of;
            ReferencesListData *next;

        public:
            ReferencesListData(std::string s, int total_address)
            {
                this->Refdata = s;
                this->Count_address_of = total_address;
                this->next = nullptr;
            }
            ~ReferencesListData();
        };
        ReferencesListData *refData;
        int total_ref = 0;

    public:
        void insertdata(std::string s, int total_address)
        {
            if (this->refData == nullptr)
            {
                this->refData = new ReferencesListData(s, total_address);
            }
            else
            {
                ReferencesListData *cur = this->refData->next;
                while (cur != nullptr)
                {
                    cur = cur->next;
                }
                cur = new ReferencesListData(s, total_address);
            }
        }
        int size() const
        {
            return this->total_ref;
        }
        int refCountAt(int index) const
        {
            if (index < 0 || index >= this->size)
                throw out_of_range("Index of references list is invalid!");
            ReferencesListData *cur = this->refData;
            while (index--)
                cur = cur->next;
            return cur->Count_address_of;
        }
        std::string refCountsString() const
        {
            ReferencesListData *cur = this->refData;
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
        CharALNode *del;
        int total_del;
        int total_refer;

    public:
        void insertDel(CharALNode *inp)
        {
            this->del->insert(inp->head->ArrayChar);
            this->del->insert(inp->tail->ArrayChar);
        }
        int size() const
        {
            returnt total_del;
        }
        std::string totalRefCountsString() const
        {
            return "TotalRefCounts[" + to_string(this->total_refer) + "]";
        }
    };
};
#endif // __CONCAT_STRING_LIST_H__