#include <iostream>
#include <stdio.h>
using namespace std;

class PhoneNumber
{
    friend ostream & operator << (ostream &, const PhoneNumber &);
    friend istream & operator >> (istream &, PhoneNumber &);
private:
    char areaCode[5];
    char cityCode[9];
};

ostream & operator << (ostream &output, const PhoneNumber &num)
{
    output << num.areaCode << " " << num.cityCode;
    return output;
}

istream & operator >> (istream &input, PhoneNumber &num)
{
    input >> num.areaCode;
    input>>num.cityCode;
    return input;
}

int main(){
    PhoneNumber phone;
    printf("Phone number: 4-9:\n");
    cin>>phone;
    cout<<"\nInserted number:\n";
    cout<<phone<<endl;
    getchar();
    return 0;
}