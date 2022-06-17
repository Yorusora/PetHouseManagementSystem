#ifndef LINKNODE_H
#define LINKNODE_H

#endif // LINKNODE_H

#pragma once

#include<iostream>
#include<string>
#include<QString>

using namespace std;

struct LinkNode
{
    QString petKind;
    QString petName;
    QString petHouse;
    LinkNode* next;
};

void InitList(LinkNode* &HL)
{
    HL = NULL;
}

void ClearList(LinkNode* &HL)
{
    LinkNode* cp;
    LinkNode* np;
    cp = HL;
    while (cp != NULL) {
        np = cp->next;
        delete cp;
        cp = np;
    }
    HL = NULL;
}

int LenthList(LinkNode* HL)
{
    int count = 0;
    while (HL != NULL)
    {
        count++;
        HL = HL->next;
    }
    return count;
}

bool EmptyList(LinkNode* HL)
{
    return HL == NULL;
}

void TraverseList(LinkNode* HL)
{
    while (HL != NULL) {
        HL = HL->next;
    }
}

bool FindListPetKind(LinkNode* HL, QString item)
{
    while(HL != NULL)
        if(HL->petKind == item)
        {
            item = HL->petKind;
            return true;
        }
        else HL = HL->next;
    return false;
}

bool FindListPetName(LinkNode* HL, QString item)
{
    while(HL != NULL)
        if(HL->petName == item)
        {
            item = HL->petName;
            return true;
        }
        else HL = HL->next;
    return false;
}

bool FindListPetHouse(LinkNode* HL, QString item)
{
    while(HL != NULL)
        if(HL->petHouse == item)
        {
            item = HL->petHouse;
            return true;
        }
        else HL = HL->next;
    return false;
}

void InsertList(LinkNode* &HL, QString petKind, QString petName, QString petHouse)
{
    LinkNode* newptr;
    newptr = new LinkNode;
    newptr->petKind = petKind;
    newptr->petName = petName;
    newptr->petHouse = petHouse;
    LinkNode* cp = HL;
    LinkNode* ap = NULL;
    while (cp != NULL) {
        ap = cp;
        cp = cp->next;
    }
    if (ap == NULL) {
        newptr->next = HL;
        HL = newptr;
    }
    else {
        newptr->next = cp;
        ap->next = newptr;
    }
}

bool DeleteList(LinkNode* &HL, QString item)
{
    if(HL == NULL)
    {
        return false;
    }
    LinkNode* cp = HL;
    LinkNode* ap = NULL;
    while(cp != NULL)
    {
        if(item == cp->petName) break;
        else
        {
            ap = cp;
            cp = cp->next;
        }
    }
    if(cp == NULL)
    {
        return false;
    }
    if(ap == NULL)
        HL = HL->next;
    else
        ap->next = cp->next;
    delete cp;
    return true;
}
