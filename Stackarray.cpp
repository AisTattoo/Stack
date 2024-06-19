#include <iostream>
using namespace std;

int maksimal = 6;
string arrayFilm[6];
int top = 0;
int arrayHarga[6];
int arrayDurasi[6];

bool apakahPenuh()
{
if( top == maksimal ){
return true;
}else{
return false;
}
}

bool apakahKosong()
{
if( top == 0 ){
return true;
}else{
return false;
}
}

void tambahkanFIlm(string data, int harga, int durasi){
if( apakahPenuh() ){
cout << "Data penuh" << endl;
}else{
arrayFilm[top] = data;
arrayHarga[top] = harga;
arrayDurasi[top] = durasi;
top++;
}
}

void hapusfilmterbaru()
{
if( apakahKosong() ){
cout << "Data kosong!!" << endl;
}else{
arrayFilm[top-1] = "";
arrayHarga[top-1] = 0;
arrayDurasi[top-1] = 0;
top--;
}
}

void tampilkanDataFilm(){
if( apakahKosong() ){
cout << "Data kosong!!" << endl;
}else{
cout << "Data stack array : " << endl;
for( int i = maksimal - 1; i >= 0; i-- ){
if( arrayFilm[i] != "" ){
cout << "Judul Film: " << arrayFilm[i] << endl;
cout << "Harga: Rp. " << arrayHarga[i] << endl;
cout << "Durasi: " << arrayDurasi[i] << " menit" << endl;
cout << endl;
}
}
cout << "\n" << endl;
}
}

void intipDataFilm(int posisi){
if( apakahKosong() ){
cout << "Data kosong!!" << endl;
}else{
int index = top;
for( int i = 0; i < posisi; i++ ){
index--;
}
cout << "Judul Film: " << arrayFilm[index] << endl;
cout << "Harga: Rp. " << arrayHarga[index] << endl;
cout << "Durasi: " << arrayDurasi[index] << " menit" << endl;
}
}

void gantiFIlm(string data, int harga, int durasi, int posisi){
if( apakahKosong() ){
cout << "Data kosong!!" << endl;
}else{
int index = top;
for( int i = 0; i < posisi; i++ ){
index--;
}
arrayFilm[index] = data;
arrayHarga[index] = harga;
arrayDurasi[index] = durasi;
}
}

int countArray()
{
if( apakahKosong() ){
return 0;
}else{
return top;
}
}

void hapusDataFilm(){
for( int i = 0; i < top; i++ ){
arrayFilm[i] = "";
arrayHarga[i] = 0;
arrayDurasi[i] = 0;
}
top = 0;
}

int main(){

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

}