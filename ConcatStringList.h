#ifndef __CONCAT_STRING_LIST_H__
#define __CONCAT_STRING_LIST_H__

#include "main.h"

class ConcatStringList {
public:
    class ReferencesList; // forward declaration
    class DeleteStringList; // forward declaration

public:
    static ReferencesList refList;
    static DeleteStringList delStrList;

    // TODO: may provide some attributes
    class CharALNode
    {
    public:
        const char*  CharArrayList;
        CharALNode* next;
        CharALNode* head;
        CharALNode* tail;
    public:
        CharALNode(){
            this->CharArrayList=nullptr;
            this->head=nullptr;
            this->tail=nullptr;
            this->head->next=nullptr;
        }
        CharALNode(const char* inp){
                this->head->CharArrayList=inp;
                this->head->next=nullptr;
                this->tail=this->head;
        }
        void insert(const char* inp){
            if(this->head==nullptr){
                this->head->CharArrayList=inp;
                this->head->next=nullptr;
                this->tail=this->head;
                
            }
            else{
                while (this->tail!=nullptr)
                {
                    this->tail=this->tail->next;
                }
                this->tail->CharArrayList=inp;
                this->tail->next=nullptr;
            }
        }
        CharALNode ReCharALNode(char* inp, CharALNode* NEXT){
            if(this->head==nullptr){
                this->head->CharArrayList = inp;
                this->head->next=NEXT;
                CharALNode* cur=this->head->next;
                while (cur->next!=nullptr)
                {
                    cur=cur->next;
                }
                this->tail=cur;
            }
            else{
                this->tail->next = CharALNode(inp);
                CharALNode* cur=this->tail->next;
                cur->next=NEXT;
                while (cur->next!=nullptr)
                {
                    cur=cur->next;
                }
                this->tail=cur;
            }
            return this->head;
        }

        ~CharALNode();
        
    };
    CharALNode* Data;
    
public:
    ConcatStringList(const char * s);
    int length() const;
    char get(int index) const;
    int indexOf(char c) const;
    std::string toString() const;
    ConcatStringList concat(const ConcatStringList &otherS) const;
    ConcatStringList subString(int from, int to) const;
    ConcatStringList reverse() const;
    ~ConcatStringList();

public:
    class ReferencesList {
        // TODO: may provide some attributes
        public:
        CharALNode* Refdata;
        int Count_address_of;
        CharALNode* next;
        int size;
        public:
            void insertCharAlNode(CharALNode* inp){
                if(this->Refdata->head->CharArrayList==nullptr){
                    this->Refdata->insert(inp->head->CharArrayList);
                    this->next=nullptr;
                    this->Count_address_of=2;
                    size++;
                }
                else{
                    ReferencesList* cur = this;
                    while (cur->next!=nullptr)
                    {
                        cur=cur->next
                    }
                    cur=cur->next;
                    cur->Refdata->insert(inp->head->CharArrayList);
                    cur->next=nullptr;
                    cur->Count_address_of=2;
                    size++;
                }
            }
            int size() const{
                return this->size;
            }
            int refCountAt(int index) const{
                if(index<0||index>=this->size) throw out_of_range("Index of references list is invalid!");
                ReferencesList* cur=this;
                while(index--) cur=cur->next;
                return cur->Count_address_of;
            }
            std::string refCountsString() const{
                ReferencesList* cur = this;
                std::string rtn= "RefCounts[";
                while (cur->next!=nullptr)
                {
                    rtn+= (48 + cur->Count_address_of);
                    rtn+=",";
                    cur = cur->next;
                }
                rtn+= (48 + cur->Count_address_of);
                rtn+="]";
                return rtn;
            }
    };

    class DeleteStringList {
        // TODO: may provide some attributes
        
        public:
            int size() const;
            std::string totalRefCountsString() const;
    };
};

#endif // __CONCAT_STRING_LIST_H__