#include <iostream>
#include <string>
#include <bitset>

using namespace std;
string convertToBinary(int decimal_number)
{
    string binary_number;

    int power_of_two=1;

    while(power_of_two*2<decimal_number)
        power_of_two*=2;

    while(power_of_two>0)
    {   
        if(decimal_number-power_of_two>=0)
        {
            binary_number+='1';
            decimal_number-=power_of_two;
        }
        else
            binary_number+='0';
        power_of_two/=2;
    }

    return binary_number;
}
int main()
{
    int input;
    while(true)
    {
    cin>>input;
    cout<<convertToBinary(input);
    std::string binary_str = std::bitset<8>(input).to_string();
    cout<<"\nSystem generated:"<<binary_str;
    }
    return 1;
}