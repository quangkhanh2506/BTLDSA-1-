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
                cur->next = this->head;
                this->head = cur;
            }
        }
        ~CharALNode()
        {
            this->tail = this->tail->next;
            while (this->head != nullptr)
            {
                CharArrayList *cur = this->head;
                this->head = this->head->next;
                cur->next=nullptr;
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
            std::string Refdata;
            int Count_address_of;
            ReferencesListData *next;

        public:
            ReferencesListData()
            {
                this->Refdata = nullptr;
                this->Count_address_of = 0;
                this->next = nullptr;
            }
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
                this = new ReferencesListData(s, total_address);
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
        void delNode(std::string s)
        {
            if (this->refDatas->Refdata == s)
            {
                ReferencesListData *tmp = this->refData;
                this->refData = this->refData->next;
                tmp->next = nullptr;
                delete tmp;
            }
            ReferencesListData *cur = this->refData;
            while (cur->next != nullptr)
            {
                if (cur->next->Refdata == s)
                {
                    ReferencesListData *tmp = cur->next;
                    cur->next = cur->next->next;
                    tmp->next = nullptr;
                    delete tmp;
                    break;
                }
                cur=cur->next;
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
            if (cur->Count_address_of == 0)
                cur = cur->next;
            return cur->Count_address_of;
        }
        std::string refCountsString() const
        {
            ReferencesListData *cur = this->refData;
            std::string rtn = "RefCounts[";
            while (cur->next != nullptr)
            {
                if (cur->Count_address_of == 0)
                {
                    cur = cur->next;
                    continue;
                }
                rtn += (48 + cur->Count_address_of);
                rtn += ",";
                cur = cur->next;
            }
            rtn += (48 + cur->Count_address_of);
            rtn += "]";
            cur = cur->next;
            return rtn;
        }
    };

    class DeleteStringList
    {
        class DeleteStringListData
        {
        public:
            CharALNode *del;
            int total_refer;
            DeleteStringListData *next;

        public:
            DeleteStringListData()
            {
                this->del = 0;
                this->total_refer = 0;
                this->next = 0;
            }
            DeleteStringListData(std::string s, int total_address)
            {
                this->del->insert(s);
                this->total_refer = total_address;
                this->next = nullptr;
            }
            ~DeleteStringListData();
        };
        DeleteStringListData *delData;
        int total_del = 0;

    public:
        void insertDel(std::string s, int total_address)
        {
            if (total_address == 0)
                total_del++;
            if (this->delData->del == nullptr)
            {
                this->delData = new DeleteStringListData(s, total_address);
            }
            else
            {
                DeleteStringListData *cur = this->delData->next;
                while (cur != nullptr)
                {
                    cur = cur->next;
                }
                cur = new DeleteStringListData(s, total_address);
            }
        }
        int size() const
        {
            returnt total_del;
        }
        std::string totalRefCountsString() const
        {
            std::string TotalRefcount = "TotalRefCounts[";
            DeleteStringListData *cur = this->delData;
            while (cur->next != nullptr)
            {
                if (cur->total_refer == 0)
                {
                    cur = cur->next;
                    continue;
                }
                TotalRefcount += to_string(cur->total_refer);
                TotalRefcount += ",";
                cur = cur->next;
            }
            TotalRefcount += to_string(cur->total_refer);
            TotalRefcount += "]";
            cur = cur->next;
            return TotalRefcount;
        }
    };
};
#endif // __CONCAT_STRING_LIST_H__