#include <iostream>
using namespace std;

int maksimal = 6;
string arrayFilm[6];
int top = 0;
int arrayHarga[6];
int arrayDurasi[6];

bool apakahPenuh() {
    return top == maksimal;
}

bool apakahKosong() {
    return top == 0;
}

void tambahkanFIlm(string data, int harga, int durasi) {
    if (apakahPenuh()) {
        cout << "Data penuh" << endl;
    } else {
        arrayFilm[top] = data;
        arrayHarga[top] = harga;
        arrayDurasi[top] = durasi;
        top++;
    }
}

void hapusfilmterbaru() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        arrayFilm[top - 1] = "";
        arrayHarga[top - 1] = 0;
        arrayDurasi[top - 1] = 0;
        top--;
    }
}

void tampilkanDataFilm() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        cout << "Data stack array : " << endl;
        for (int i = maksimal - 1; i >= 0; i--) {
            if (arrayFilm[i] != "") {
                cout << "Judul Film: " << arrayFilm[i] << endl;
                cout << "Harga: Rp. " << arrayHarga[i] << endl;
                cout << "Durasi: " << arrayDurasi[i] << " menit" << endl;
                cout << endl;
            }
        }
        cout << "\n" << endl;
    }
}

void intipDataFilm(int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        int index = top;
        for (int i = 0; i < posisi; i++) {
            index--;
        }
        cout << "Judul Film: " << arrayFilm[index] << endl;
        cout << "Harga: Rp. " << arrayHarga[index] << endl;
        cout << "Durasi: " << arrayDurasi[index] << " menit" << endl;
    }
}

void gantiFIlm(string data, int harga, int durasi, int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        int index = top;
        for (int i = 0; i < posisi; i++) {
            index--;
        }
        arrayFilm[index] = data;
        arrayHarga[index] = harga;
        arrayDurasi[index] = durasi;
    }
}

int countArray() {
    return apakahKosong() ? 0 : top;
}

void hapusDataFilm() {
    for (int i = 0; i < top; i++) {
        arrayFilm[i] = "";
        arrayHarga[i] = 0;
        arrayDurasi[i] = 0;
    }
    top = 0;
}

// Pakai Linked List
struct datafilm {
    string namafilm;
    int hargatiket;
    int durasifilm;

    // pointer
    datafilm *prev;
    datafilm *next;
};

datafilm *head, *tail, *cur, *newNode, *del;
int maksimalfilm = 5;

void createFilm(string namafilm, int hargatiket, int durasifilm) {
    head = new datafilm();
    head->namafilm = namafilm;
    head->hargatiket = hargatiket;
    head->durasifilm = durasifilm;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countFilm() {
    if (head == NULL) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != NULL) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

bool isFullFilm() {
    return countFilm() == maksimalfilm;
}

bool isEmptyFilm() {
    return countFilm() == 0;
}

void tambahkanFilm(string namafilm, int hargatiket, int durasifilm) {
    if (isFullFilm()) {
        cout << "Stack Full!!" << endl;
    } else {
        if (isEmptyFilm()) {
            createFilm(namafilm, hargatiket, durasifilm);
        } else {
            newNode = new datafilm();
            newNode->namafilm = namafilm;
            newNode->hargatiket = hargatiket;
            newNode->durasifilm = durasifilm;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
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
    }
}

void tampilkanDataFilmLinkedList() {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else {
        cout << "\n\nData Film : " << endl;
        cur = tail;
        while (cur != NULL) {
            cout << "Nama Film : " << cur->namafilm << " - Rp." << cur->hargatiket << " - Durasi: " << cur->durasifilm << " menit" << endl;
            cur = cur->prev;
        }
    }
}

void intipFilm(int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Film Posisi ke-" << posisi << " : " << cur->namafilm << " - Rp." << cur->hargatiket << " - Durasi: " << cur->durasifilm << " menit" << endl;
    }
}

void gantiFilm(string namafilm, int hargatiket, int durasifilm, int posisi) {
    if (isEmptyFilm()) {
        cout << "Data Film kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cur->namafilm = namafilm;
        cur->hargatiket = hargatiket;
        cur->durasifilm = durasifilm;
    }
}

void hapusDataFilmLinkedList() {
    cur = head;
    while (cur != NULL) {
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
    head = tail = NULL;
}

int main() {
    // Array-based stack operations
    tambahkanFIlm("Tendangan si Madun", 50000, 120);
    tambahkanFIlm("Inception", 80000, 148);
    tambahkanFIlm("Harry Potter", 75000, 152);
    tambahkanFIlm("Mario Bros", 40000, 90);
    tambahkanFIlm("Laskar Pelangi", 60000, 120);
    tampilkanDataFilm();

    tambahkanFIlm("Spiderman", 70000, 135);
    tampilkanDataFilm();

    hapusfilmterbaru();
    tampilkanDataFilm();

    cout << "Apakah data penuh? : " << apakahPenuh() << endl;
    cout << "Apakah data kosong? : " << apakahKosong() << endl;

    intipDataFilm(2);

    cout << "Banyak data : " << countArray() << endl;

    gantiFIlm("The Shawshank Redemption", 90000, 142, 3);
    tampilkanDataFilm();

    hapusDataFilm();

    cout << "Apakah data penuh? : " << apakahPenuh() << endl;
    cout << "Apakah data kosong? : " << apakahKosong() << endl;

    // Linked List-based stack operations
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
