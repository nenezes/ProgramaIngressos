#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Ingresso
{
private:
    int idIngresso;
    string titular;
    string infos;
public:
    void setInfo(int id, string t, string i);
    string getInfo();
};