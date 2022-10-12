#include "ConcatStringList.h"


ConcatStringList::ReferencesList ConcatStringList::refList = ConcatStringList::ReferencesList();
ConcatStringList::DeleteStringList ConcatStringList::delStrList = ConcatStringList::DeleteStringList();

ConcatStringList::ConcatStringList(const char *s)
{
    this->Data->insert(s);
    refList.insertData(this->Data->head->ArrayChar,2);
    refList.total_ref++;
}
int ConcatStringList::length() const
{
    return this->Data->size;
}
char ConcatStringList::get(int index) const
{
    if (index < 0 || index >= (this->length() - 1))
        throw out_of_range("Index of string is invalid!");
    CharArrayList *cur = this->Data->head;
    while (cur != nullptr)
    {
        if (index > (int)cur->ArrayChar->length() - 1))
        {
            index -= (int)cur->ArrayChar->length();
            cur = cur->next;
            continue;
        }
        return cur->ArrayChar[index];
    }
}
int ConcatStringList::indexOf(char c) const
{
    if (this->Data->head != nullptr)
    {
        CharArrayList *cur = this->Data->head;
        while (cur != nullptr)
        {
            for (int i = 0; i < (int)cur->ArrayChar->length(); i++)
            {
                if (this->Data->CharArrayList[i] == c)
                    return i;
            }
            cur = cur->next;
        }
    }
    return -1;
}
std::string ConcatStringList::toString() const
{
    if (this->Data->head != nullptr)
    {
        CharArrayList *cur = this->Data->head;
        while (cur->next != nullptr)
        {
            totalStr += cur->ArrayChar;
            cur = cur->next;
        }
    }
    totalStr += cur->ArrayChar;
    return totalStr;
}
ConcatStringList ConcatStringList::concat(const ConcatStringList &otherS) const
{
    ConcatStringList concatstr;
    ReferencesList tmp = refList;
    while (tmp.refData != nullptr)
    {
        if (tmp.refData->Refdata == this->Data->head->ArrayChar || tmp.refData->Refdata == otherS.Data->tail->ArrayChar)
            tmp.refData->Count_address_of++;
        tmp.refData = tmp.refData->next;
    }

    ConcatStringList concatstr = new CharALNode();
    CharArrayList *cur = this->Data->head;
    while (cur != nullptr)
    {
        concatstr.Data->insert(cur->ArrayChar);
        cur = cur->next;
    }

    cur = otherS.Data->head;
    while (cur != nullptr)
    {
        concatstr.Data->insert(cur->ArrayChar);
        cur = cur->next;
    }

    return concatstr;
}

ConcatStringList ConcatStringList::subString(int from, int to) const
{
    if (from < 0 || to >= this->length())
        throw out_of_range("Index of string is invalid");
    if (from >= to)
        throw logic_error("Invalid range");
    ConcatStringList concatsubstr;
    int count_node=0;
    CharArrayList *cur = this->Data->head;
    while (cur != nullptr && to > 0)
    {
        if (to < (int)cur->ArrayChar->length())
        {
            // substring
            concatsubstr.Data->insert(cur->ArrayChar.substr(0,to-1));
            count_node++;
            break;
        }
        //substring
        concatsubstr.Data->insert(cur->ArrayChar.substr(from));
        from = 0;
        to = to - (int)cur->ArrayChar.length();
        cur = cur->next;
        count_node++;
    }
    if(count_node==1){
        refList.insertdata(concatsubstr.Data->head->ArrayChar,2);
        refList.total_ref++;
    }
    else if (count_node>1)
    {
        refList.insertdata(concatsubstr.Data->head->ArrayChar,1);
        refList.insertdata(concatsubstr.Data->tail->ArrayChar,1);
        refList.total_ref++;
    }
    
    return concatsubstr;
}

ConcatStringList ConcatStringList::reverse() const
{
    ConcatStringList concatRevstr;
    CharArrayList* cur=this->Data->head;
    while (cur->next!=nullptr)
    {
        std::string a = cur->ArrayChar;
        std::reverse(a.begin(),a.end());
        concatRevstr.Data->insertHead(a);
    }
    if(this->Data->head->next!=nullptr){
       refList.insertdata(concatRevstr.Data->head->ArrayChar,1);
       refList.insertdata(concatRevstr.Data->tail->ArrayChar,1);
       refList.total_ref++; 
    }
    else{
        refList.insertdata(concatRevstr.Data->head->ArrayChar,2);
        refList.total_ref++;
    }
    return concatRevstr;
}
ConcatStringList::~ConcatStringList()
{
    
}
