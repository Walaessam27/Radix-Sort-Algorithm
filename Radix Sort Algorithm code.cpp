// Wala' Essam Ashqar 12027854

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int most(const vector<int>& k) {
    return *max_element(k.begin(), k.end());}
void c(vector<int>& k, int e) {
    int s = k.size();
       vector<int> res(s);
    int cc[10] = {0}; 
    for (int i = 0; i < s; i++) {
        int j = (k[i] / e) % 10;
        cc[j]++;}
    for (int i = 1; i < 10; i++) {
        cc[i] += cc[i - 1];}
    for (int i = s - 1; i >= 0; i--) {
        int j = (k[i] / e) % 10;
        res[cc[j] - 1] = k[i];
        cc[j]--;}
    for (int i = 0; i < s; i++) {
        k[i] = res[i];}}
void sorting(vector<int>& k) {int mostnum = most(k);
    for (int e = 1; mostnum / e > 0; e *= 10) {
        c(k, e);}}

int main() {
    int input;
    cin >> input;
    vector<int> k(input);
    for (int i = 0; i < input; i++) {
        cin >> k[i];}
    sorting(k);
    cout << "[";
    for (int i = 0; i < input; i++) {
        cout << k[i];
        if (i != input - 1) {
            cout << ",";}}
    cout << "]" << endl;
    return 0;}
