#include <iostream>
using namespace std;

struct datafilm {
    string namafilm;
    int hargatiket;
    int durasifilm;

    datafilm *prev;
    datafilm *next;
};

datafilm *head = NULL;
datafilm *tail = NULL;
datafilm *cur = NULL;
datafilm *newNode = NULL;
datafilm *del = NULL;

int maksimalfilm = 5;

void createFilm(string namafilm, int hargatiket, int durasifilm) {
    newNode = new datafilm();
    newNode->namafilm = namafilm;
    newNode->hargatiket = hargatiket;
    newNode->durasifilm = durasifilm;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int countFilm() {
    int banyak = 0;
    cur = head;
    while (cur != NULL) {
        cur = cur->next;
        banyak++;
    }
    return banyak;
}

bool isFullFilm() {
    return countFilm() >= maksimalfilm;
}

bool isEmptyFilm() {
    return head == NULL;
}

void tambahkanFilm(string namafilm, int hargatiket, int durasifilm) {
    if (isFullFilm()) {
        cout << "Linked List Full!!" << endl;
    } else {
        createFilm(namafilm, hargatiket, durasifilm);
    }
}

void hapusFilm() {
    if (!isEmptyFilm()) {
        del = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete del;
    } else {
        cout << "Linked List Empty!!" << endl;
    }
}

void tampilkanDataFilmLinkedList() {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else {
        cout << "\n\nData Film : " << endl;
        cur = head;
        while (cur != NULL) {
            cout << "Nama Film : " << cur->namafilm << " - Rp." << cur->hargatiket << " - Durasi: " << cur->durasifilm << " menit" << endl;
            cur = cur->next;
        }
    }
}

void intipFilm(int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else if (posisi <= countFilm() && posisi > 0) {
        int nomor = 1;
        cur = head;
        while (nomor < posisi) {
            cur = cur->next;
            nomor++;
        }
        cout << "Data Film Posisi ke-" << posisi << " : " << cur->namafilm << " - Rp." << cur->hargatiket << " - Durasi: " << cur->durasifilm << " menit" << endl;
    } else {
        cout << "Posisi film tidak valid." << endl;
    }
}

void gantiFilm(string namafilm, int hargatiket, int durasifilm, int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else if (posisi <= countFilm() && posisi > 0) {
        int nomor = 1;
        cur = head;
        while (nomor < posisi) {
            cur = cur->next;
            nomor++;
        }
        cur->namafilm = namafilm;
        cur->hargatiket = hargatiket;
        cur->durasifilm = durasifilm;
    } else {
        cout << "Posisi film tidak valid." << endl;
    }
}

void hapusDataFilmLinkedList() {
    cur = head;
    while (cur != NULL) {
        del = cur;
        head = head->next;
        delete del;
        cur = head;
    }
    head = tail = NULL;
}

int main() {
    tambahkanFilm("Hulk", 500000, 60);
    tampilkanDataFilmLinkedList();

    tambahkanFilm("Avatar", 1000000, 90);
    tambahkanFilm("Mission Impossible", 1800000, 102);
    tambahkanFilm("Real steel", 250000, 156);
    tambahkanFilm("X-Man", 650000, 120);
    tampilkanDataFilmLinkedList();
    tambahkanFilm("Shaolin Soccer", 1500000, 60);
    tampilkanDataFilmLinkedList();

    cout << "Apakah data film full ? : " << isFullFilm() << endl;
    cout << "Apakah data film kosong ? : " << isEmptyFilm() << endl;
    cout << "Jumlah data film : " << countFilm() << endl;

    hapusFilm();
    tampilkanDataFilmLinkedList();

    intipFilm(3);

    gantiFilm("Fast and Furious", 750000, 50, 2);
    tampilkanDataFilmLinkedList();

    hapusDataFilmLinkedList();
    cout << "Apakah data film full ? : " << isFullFilm() << endl;
    cout << "Apakah data film kosong ? : " << isEmptyFilm() << endl;
    cout << "Jumlah data film : " << countFilm() << endl;
    tampilkanDataFilmLinkedList();

    return 0;
}
