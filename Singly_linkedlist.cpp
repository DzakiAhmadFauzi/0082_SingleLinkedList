// #0082_singlyLinkedList

#include <iostream>
using namespace std;

class Node 
{
public:
    int noMhs;
    Node *next;
};

class Linkedlist
{
    Node *START;

public:
    Linkedlist()
    {
        START = NULL;
    }

    void addNote()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahsiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        