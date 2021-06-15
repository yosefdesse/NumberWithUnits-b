

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include "NumberWithUnits.hpp"

using namespace ariel;


// namespace ariel {
    
   
std :: map<std::string,map<string,double>> map_units;

    NumberWithUnits :: NumberWithUnits(double n, const string& str)
    {
        map_units.at(str);

        this->num_u = n;
        this->str_u = str;
    }

    // NumberWithUnits :: ~NumberWithUnits(){}

    void ariel::NumberWithUnits::read_units(ifstream &units)
    { 
        double num1 , num2  ;
        string unit1 , unit2 ;
        string eq;
        while(units >> num1 >> unit1 >> eq >> num2 >> unit2){
            map_units[unit1][unit2]= num2;
            map_units[unit2][unit1]= num1/num2;

         }

    }

    // double check_units(const NumberWithUnits &unit1, const NumberWithUnits &unit2)
    // {
    //     // if()
    // }
    // double convert_unit(double num, const string& from_unit, const string& to_unit);

    double  NumberWithUnits::convert_unit(double num, const string& from_unit, const string& to_unit)
    {
        map_units.at(from_unit);
        if(from_unit==to_unit) return num ;
       
        return num*map_units[from_unit][to_unit];
    }

        
    
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &unit1)
    {
        map_units.at(unit1.str_u);
        double unit_num =convert_unit(unit1.num_u , unit1.str_u , this->str_u);
        double new_num = unit_num+this->num_u ;
        NumberWithUnits new_unit(new_num ,unit1.str_u  );
        return new_unit ; 
    }
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &unit1)
    { 
        map_units.at(unit1.str_u);
        double unit_num =convert_unit(unit1.num_u , unit1.str_u , this->str_u);
        this->num_u = this->num_u + unit1.num_u ;
        return (*this) ; 
    }

    NumberWithUnits& NumberWithUnits::operator+()
    {
         return (*this) ; 
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &unit1)
    { 
        map_units.at(unit1.str_u);
        double unit_num =convert_unit(unit1.num_u , unit1.str_u , this->str_u);
        double new_num = unit_num-this->num_u ;
        NumberWithUnits new_unit(new_num ,unit1.str_u  );
        return new_unit ; 
    }

    NumberWithUnits& NumberWithUnits::operator-()
    {
         return (*this) ; 
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &unit1)
    { 
        map_units.at(unit1.str_u);
        double unit_num =convert_unit(unit1.num_u , unit1.str_u , this->str_u);
        this->num_u = this->num_u - unit1.num_u ;
        return (*this) ;  
    }
    // NumberWithUnits& NumberWithUnits::operator-( int){ return (*this) ; }
    
    bool NumberWithUnits::operator>(const NumberWithUnits &unit1)const
    { 
        map_units.at(unit1.str_u);
        if((this->num_u)>unit1.num_u) return true;
        return false ; 
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &unit1)const
    { 
        map_units.at(unit1.str_u);
        if((this->num_u)>unit1.num_u) return true;
        if((this->num_u)==unit1.num_u) return true;
        return false ; 
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &unit1)const
    {
        map_units.at(unit1.str_u);
        if((this->num_u)<unit1.num_u) return true;
        return false ; 
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &unit1)const
    { 
        map_units.at(unit1.str_u);
        if((this->num_u)<unit1.num_u) return true;
        if((this->num_u)==unit1.num_u) return true;
        return false ;
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &unit1)const
    {
        map_units.at(unit1.str_u);
        if((this->num_u)==unit1.num_u) return true;
        return false ;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &unit1)const
    {
        map_units.at(unit1.str_u);
        if((this->num_u)!=unit1.num_u) return true;
        return false ;    
    }
    NumberWithUnits& NumberWithUnits::operator=(const NumberWithUnits &unit1)
    {
        map_units.at(unit1.str_u);
        this->num_u=unit1.num_u;
        this->str_u=unit1.str_u;
        return (*this) ; 
    }


    NumberWithUnits NumberWithUnits::operator++()
    { 
        // this->num_u = this->num_u + 1.0;
        // this->num_u++;
        // return (*this) ; 

        double new_num = this->num_u+1.0;
        NumberWithUnits *new_unit = new NumberWithUnits(new_num ,this->str_u  ); 
        return (*new_unit) ; 

        // (this->num_u)++;
        // return *this;
    }


    //  לשנות ולסדר!!!!!!!!!!!!!!!!!!!!!

    NumberWithUnits NumberWithUnits::operator++(int n){
        
        NumberWithUnits unit{this->num_u,this->str_u};
        this->num_u++;
        return unit;

        
    } 

    NumberWithUnits NumberWithUnits::operator--()
    { 
        
        // this->num_u = this->num_u - 1.0;
        // this->num_u++;
        double new_num = this->num_u-1.0;
        NumberWithUnits new_unit(new_num ,this->str_u  ); 
        return new_unit ;   
    }

    NumberWithUnits NumberWithUnits::operator--(int n){
        
        NumberWithUnits unit{this->num_u,this->str_u};
        this->num_u--;
        return unit;

        
    } 

    NumberWithUnits  ariel:: operator*( const NumberWithUnits &unit1 , double num )
    {
        map_units.at(unit1.str_u);
        double new_num = num*unit1.num_u;
        NumberWithUnits new_unit(new_num ,unit1.str_u  ); 
        return new_unit ; 
    }
    NumberWithUnits ariel:: operator*(double num ,  const NumberWithUnits &unit1 )
    { 
        map_units.at(unit1.str_u);
        double new_num = num*unit1.num_u;
        NumberWithUnits new_unit(new_num ,unit1.str_u  ); 
        return new_unit ; 
    }



    ostream& ariel::operator<<(ostream &os , const NumberWithUnits &unit1)
    { 
        os << unit1.str_u << "[" << unit1.str_u << "]";
        return os ;
    }
    istream& ariel::operator>>(istream &is , const NumberWithUnits &unit1){
         return is ;
         };
    
// }
