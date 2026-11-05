#include <iostream>

namespace yunseol2649038
{
    class dayOfYear
    {
        int month;
        int day;
        void testMonth()
        {
            if(month <1 || month>12){
                std::cout << "invaild month\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if((day < 1) || (day > 31)){
                std::cout << "invalid day";
                std::exit(1);
            }
        }
        public:
        dayOfYear(int m = 1, int d = 1): month{m}, day{d}
        {
            testMonth();
            testDay();
        }

       void input()
       {
        std::cout << "enter month:";
        std::cin  >> month; testMonth();
        std::cout << "enter day:";
        std::cin  >> day; testDay();
       } 

// -프렌드함수로서 입력연산자 >>, 출력연산자 <<, 이항연산자 ==, 이항연산자 + 정의
friend std::istream&operator >>(std::istream& is, dayOfYear& d){
        std::cout << "enter month";
        is >> d.month; d.testMonth();
        std::cout << "enter day";
        is  >> d.day; d.testDay();
    
    return is;
}

       void setMonth(int m) {month = m; testMonth();}
       void setDay(int d) {day = d; testDay();}
       void print() const
    {
        switch (month)
        {
        case 1:
        std::cout << "January "; break;
        case 2:
        std::cout << "Febuary "; break;
        case 3:
        std::cout << "March "; break;
        case 4:
        std::cout << "April "; break;
        case 5:
        std::cout << "May "; break;
        case 6:
        std::cout << "June "; break;
        case 7:
        std::cout << "July "; break;
        case 8:
        std::cout << "August "; break;
        case 9:
        std::cout << "September "; break;
        case 10:
        std::cout << "October "; break;
        case 11:
        std::cout << "November "; break;
        case 12:
        std::cout << "December "; break;
        }
    
        std::cout << day <<"\n";
}

    friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d){
    switch (d.month)
        {
        case 1:
        os << "January "; break;
        case 2:
        os << "Febuary "; break;
        case 3:
        os << "March "; break;
        case 4:
        os << "April "; break;
        case 5:
        os << "May "; break;
        case 6:
        os << "June "; break;
        case 7:
        os << "July "; break;
        case 8:
        os << "August "; break;
        case 9:
        os << "September "; break;
        case 10:
        os << "October "; break;
        case 11:
        os << "November "; break;
        case 12:
        os << "December "; break;
        }
    
        os << d.day <<"\n";
        return os;
}
    int getMonth() const{return month;}
    int getDay() const{return day;}

//dayOfYear d{1,31}        
dayOfYear operator++()
{
    ++day;
    if(day >31){
        ++month;
        if(month > 12) month -= 12;
        day -= 31;
    }
    return dayOfYear{month, ++day};
}

dayOfYear operator++(int)
{
    dayOfYear temp{month, day};
    operator++();
    return temp;
}

friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
{
    return d1.month == d2.month && d1.day ==d2.day;
}

friend dayOfYear operator+(const dayOfYear& d1, const dayOfYear& d2){
    return dayOfYear(d1.month + d2.month, d1.day + d2.day);
}

};

}