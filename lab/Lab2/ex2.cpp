/*
 * Lab2 Ex2 VE280 20SU
 * Created by: Yiqing Fan
 * Last update: May 25, 2020
 */

#include <cstdlib>
#include <iostream>

using namespace std;

typedef struct student{
    // TODO: complete struct
    char name[16];
    int ch_score;
    int ma_score;
    int  en_score;
} Student;

int compare(const void* p1, const void* p2) {
    // TODO: complete compare function for qsort()
    Student stu1 = *(Student*)p1;
    Student stu2 = *(Student*)p2;
    if ((stu1.ch_score + stu1.en_score + stu1.en_score) > (stu2.ch_score + stu2.ma_score + stu2.en_score)) return -1;
    if ((stu1.ch_score + stu1.en_score + stu1.en_score) < (stu2.ch_score + stu2.ma_score + stu2.en_score)) return 1;
    if ((stu1.ch_score + stu1.en_score + stu1.en_score) == (stu2.ch_score + stu2.ma_score + stu2.en_score)) return 0;
    return 0;
}

int main() {
    // TODO: read input
    int number;
    Student tem_stu, stu_array[10];
    cin >> number;
    for (int i = 0; i < number; ++i) {
        cin >> tem_stu.name;
        cin >> tem_stu.ch_score;
        cin >> tem_stu.ma_score;
        cin >> tem_stu.en_score;
        stu_array[i] = tem_stu;
    }
    // TODO: sort array with qsort()
    qsort(stu_array, number, sizeof(Student), compare);
    // TODO: print result
    for (int j = 0; j < number; ++j) {
        cout << stu_array[j].name << " " << stu_array[j].ch_score << " " << stu_array[j].ma_score << " " << stu_array[j].en_score << endl;
    }
    return 0;
}