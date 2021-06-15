#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ostream>
#include <istream>

using namespace std;

namespace ariel
{

    class NumberWithUnits
    {
        // private:
        public:

            double num_u;
            string str_u;
            NumberWithUnits(){};
            NumberWithUnits(double n, const string& str);
            // ~NumberWithUnits(){};
            static void read_units(ifstream &unit);
            // double check_units(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            double convert_unit(double num, const string& from_unit, const string& to_unit);

            // friend NumberWithUnits operator+(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend NumberWithUnits operator+=(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend NumberWithUnits operator++(const NumberWithUnits &unit1, int);
            // friend NumberWithUnits operator-(const NumberWithUnits &unit1);
            // friend NumberWithUnits operator-(const NumberWithUnits &unit1 , const NumberWithUnits &unit2);
            // friend NumberWithUnits operator-=(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend NumberWithUnits operator--(const NumberWithUnits &unit1, int);

            NumberWithUnits& operator=(const NumberWithUnits &unit1);
            NumberWithUnits operator+(const NumberWithUnits &unit1 );
            NumberWithUnits& operator+=(const NumberWithUnits &unit1 );
            NumberWithUnits& operator+();
            NumberWithUnits operator-(const NumberWithUnits &unit1);
            NumberWithUnits& operator-();
            NumberWithUnits& operator-=(const NumberWithUnits &unit1);
            // NumberWithUnits& operator-( int);




            // friend bool operator>(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend bool operator>=(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend bool operator<(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend bool operator<=(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend bool operator==(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            // friend bool operator!=(const NumberWithUnits &unit1, const NumberWithUnits &unit2);
            bool operator>(const NumberWithUnits &unit1) const;
            bool operator>=(const NumberWithUnits &unit1)const;
            bool operator<(const NumberWithUnits &unit1)const;
            bool operator<=(const NumberWithUnits &unit1)const;
            bool operator==(const NumberWithUnits &unit1)const;
            bool operator!=(const NumberWithUnits &unit1)const;




            NumberWithUnits operator++();
            NumberWithUnits operator++(int n); 
            NumberWithUnits operator--();
            NumberWithUnits operator--(int n); 

            friend ostream& operator<<(ostream &os , const NumberWithUnits &unit1);
            friend istream& operator>>(istream &is , const NumberWithUnits &unit1);
           


            friend  NumberWithUnits operator*( const NumberWithUnits &unit1 , double num );
            friend  NumberWithUnits operator*(double num , const NumberWithUnits &unit1 );










    };

}
