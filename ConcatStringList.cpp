#include "ConcatStringList.h"

ConcatStringList::ReferencesList ConcatStringList::refList = ConcatStringList::ReferencesList();
ConcatStringList::DeleteStringList ConcatStringList::delStrList = ConcatStringList::DeleteStringList();

ConcatStringList::ConcatStringList(const char *s)
{
    this->Data->insert(s);
    refList.insertData(this->Data->head->ArrayChar);
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
        if (index > ((int)strlen(cur->ArrayChar) - 1))
        {
            index -= (int)strlen(cur->ArrayChar);
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
            for (int i = 0; i < (int)strlen(cur->ArrayChar); i++)
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
    std::string totalStr = "ConcatStringList[";
    if (this->Data->head != nullptr)
    {
        CharArrayList *cur = this->Data->head;
        while (cur->next != nullptr)
        {
            totalStr += cur->ArrayChar;
            totalStr += ",";
            cur = cur->next;
        }
    }
    totalStr += cur->ArrayChar;
    totalStr += "]";
    return totalStr;
}
ConcatStringList ConcatStringList::concat(const ConcatStringList &otherS) const
{
    ConcatStringList concatstr = new CharALNode();
    CharArrayList *cur = this->Data->head;

    ReferencesList tmp = refList;
    while (tmp.refData != nullptr)
    {
        if (tmp.refData->Refdata == cur->ArrayChar)
            tmp.refData->Count_address_of++;
        tmp.refData = tmp.refData->next;
    }

    while (cur != nullptr)
    {
        concatstr.Data->insert(cur->ArrayChar);
        cur = cur->next;
    }

    cur = otherS.Data->head;
    while (cur->next != nullptr)
    {
        concatstr.Data->insert(cur->ArrayChar);
        cur = cur->next;
    }
    concatstr.Data->insert(cur->ArrayChar);

    ReferencesList tmp = refList;
    while (tmp.refData != nullptr)
    {
        if (tmp.refData->Refdata == cur->ArrayChar)
            tmp.refData->Count_address_of++;
        tmp.refData = tmp.refData->next;
    }

    return concatstr;
}
ConcatStringList ConcatStringList::subString(int from, int to) const
{
    if (from < 0 || to >= this->length())
        throw out_of_range("Index of string is invalid");
    if (from >= to)
        throw logic_error("Invalid range");
    
}

ConcatStringList ConcatStringList::reverse() const
{
}
ConcatStringList::~ConcatStringList()
{
}
