#include "Museum.h"

#include <utility>

using namespace std;

Museum::Museum(Address adr, unsigned cap = 0, string name = ""): address(move(adr)), capacity(cap), name(move(name)) {
}

string Museum::getName() {
    return this->name;
}

Address Museum::getAddress() {
    return this->address;
}

unsigned Museum::getCapacity() {
    return this->capacity;
}

void Museum::setName(string name) {
    this->name = name;
}

void Museum::setAddress(Address adr) {
    this->address = move(adr);
}

void Museum::setCapacity(unsigned cap) {
    this->capacity = cap;
}

ostream & operator<<(ostream & out, const Museum & museum) {
    out << museum.name << museum.capacity << museum.address;
    return out;
}

istream & operator>>(istream & in, Museum ** museum) {
    string line;
    getline(in, line);
    vector<string> aux = split(line, "|");
    unsigned auxCapacity = stoi(aux.back());
    aux.pop_back();
    string auxName = trim(join(aux));
    Address *auxAddress;
    in >> &auxAddress;
    *museum = new Museum(*auxAddress, auxCapacity, auxName);
    return in;
}



