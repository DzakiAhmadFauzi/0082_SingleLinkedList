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

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim > (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (ListEmpty())
        {
            cout << "\nList Kosong\n";    
        }
        else
        {
            cout << "\nData didalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "Menu" << endl;
        cout << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari list" << endl;
        cout << "3. Menampilkan semua data didalama list" << endl;
        cout << "4. Mencari data didalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl;
             << "Masukkan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case '1':
            mhs.addNote();
            break;
    }

    case '2':
    {
        if (mhs.listEmpty())
        {
            cout << endl
                 << "List Kosong" << endl;
            break;
        }
        cout << endl
             << "\nMasukkan no mahasiswa yang akan dihapus : ";
        cin >> nim;
        if (mhs.delNode(nim) == false)
            cout << endl
                 << "Data tidak ditemukan" << endl;
        else
            cout << endl
                 << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus" << endl;       
}
        break;
        case '3':
        {
            mhs.tranverse();
        }
        break;
        case '4':
        {
            if (mhs.listEmpty() == true)
            {
                cout << endl
                     << "List Kosong" << endl;
                break;
            }
            Node *previous, *current;
            cout << endl
                 << "\nMasukkan no mahasiswa yang dicari : ";
            cin >> nim;
            if (mhs.Search(nim, &previous, &current) == false)
                cout << endl
                     << "Data tidak ditemukan" << endl;
            else
                cout << endl
                     << "Data ditemukan" << endl
                        << "\nNo Mahasiswa : " << current->noMhs << endl;
                    cout << "\n";
            }
    }
        break;
        case '5':
        {
        }
        break;
        default:
        {
            cout << "Pilihan salah !." << endl;
        }
        break;
        }
    }while (ch != '5');
}
    