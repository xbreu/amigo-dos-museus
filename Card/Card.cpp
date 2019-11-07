#include "Card.h"

#include <utility>

Card::Card(string n, Date acqdate, Date bday, Address ad, unsigned cont): acquisitionDate(acqdate), birthday(bday) {
    name = move(n);
    address = move(ad);
    contact = cont;
}

string Card::getName() const{
    return name;
}
Date Card::getAcquisitionDate() const{
    return acquisitionDate;
}
Date Card::getBirthday() const{
    return birthday;
}
Address Card::getAddress() const{
    return address;
}
unsigned Card::getContact() const{
    return contact;
}
void Card::setName(string n){
    name = move(n);
}
void Card::setAddress(Address ad){
    address = move(ad);
}
void Card::setContact(unsigned cont){
    contact = cont;
}

float SilverCard::cost = 30;
float SilverCard::getCost(){
    return cost;
}

float UniCard::cost = 32.45;
float UniCard::getCost(){
    return cost;
}

float IndividualCard::cost = 52.9;
float IndividualCard::getCost(){
    return cost;
}

bool validCard(Card *card) {
    bool valid = true;
    valid && validDate(card->getAcquisitionDate().getDay(),card->getAcquisitionDate().getMonth(),card->getAcquisitionDate().getYear());
    valid && validDate(card->getBirthday().getDay(),card->getBirthday().getMonth(),card->getBirthday().getYear());
    for(size_t i;i<card->getName().size();i++)(valid && (!isdigit(card->getName().at(i))));
    valid && validAddress(card->getAddress());
    return valid;
}
