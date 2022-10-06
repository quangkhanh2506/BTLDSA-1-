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
        std::string CharArrayList;
        CharALNode* next;
        CharALNode* head;
        CharALNode* tail;
    public:
        CharALNode(){
            this->CharArrayList=nullptr;
            this->head=nullptr;
            this->tail=nullptr;
            this->next=nullptr;
        }
        CharALNode(std::string inp){
            if(this->head==nullptr){
                this->head->CharArrayList=inp;
                this->tail=this->head;
                this->next=nullptr;
            }
            else{
                while (this->tail!=nullptr)
                {
                    this->tail=this->tail->next;
                }
                this->tail->CharArrayList=inp;
                 
            }
        }
        CharALNode(std::string inp, CharALNode* NEXT){
            if(this->head==nullptr){
                this->head->CharArrayList=inp;
                this->next=NEXT;
                CharALNode* cur=this->next;
                while (cur->next!=nullptr)
                {
                    cur=cur->next;
                }
                this->tail=cur;
            }
            else{
                this->tail->next->CharArrayList=inp;
                CharALNode* cur=this->tail->next;
                cur->next=NEXT;
                while (cur->next!=nullptr)
                {
                    cur=cur->next;
                }
                this->tail=cur;
            }
        }

        ~CharALNode();
        
    };
    
    
public:
    ConcatStringList(const char * s);
    int length() const;
    int get(int index) const;
    int indexOf(char c) const;
    std::string toString() const;
    ConcatStringList concat(const ConcatStringList & otherS) const;
    ConcatStringList subString(int from, int to) const;
    ConcatStringList reverse() const;
    ~ConcatStringList();

public:
    class ReferencesList {
        // TODO: may provide some attributes

        public:
            int size() const;
            int refCountAt(int index) const;
            std::string refCountsString() const;
    };

    class DeleteStringList {
        // TODO: may provide some attributes

        public:
            int size() const;
            std::string totalRefCountsString() const;
    };
};

#endif // __CONCAT_STRING_LIST_H__