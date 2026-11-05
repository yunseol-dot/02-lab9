#include "dayOfYear.h"
//private 멤버변수 선언: 클래스1형을 가리키는 포인터

//public 멤버함수 정의

//-생성자, 소멸자, 복사생성자, 복사=연산자, 이동생성자, 이동=연산자

//-print: 멤버변수가 가리키는 데이터가 있을 경우 표준스트림으로 출력, 없으면 no data (nullptr) 출력


namespace yunseol2649038{
    class dayOfYearPtr{
        dayOfYear* dPtr;

        public:
        dayOfYearPtr(const dayOfYear& d = dayOfYear{1,1})
        : dPtr{new dayOfYear{d}}{}

        ~dayOfYearPtr(){delete dPtr;}
        dayOfYearPtr(const dayOfYearPtr& copy){
            dPtr = copy.dPtr ? new dayOfYear{*copy.dPtr} : nullptr;
        }

        dayOfYearPtr(dayOfYearPtr&& move) noexcept
        {
           std::cout << "move constructor\n";
            dPtr = move.dPtr;
            move.dPtr = nullptr;

        }

        dayOfYearPtr& operator=(const dayOfYear& copy){
            if (this != &copy){
                delete dPtr;
                dPtr = copy.dPtr ? new dayOfYear{*copy.dPtr} : nullptr;
            }
            return *this;
        }
        dayOfYearPtr& operator=(dayOfYearPtr&& move) noexcept
        {
            if(this!=&move)
            {
                delete dPtr;
                dPtr = move.dPtr;
                move.dPtr = nullptr;
            }
            return *this;            
        }

        void print() const{
            if(dPtr) std::cout << *dPtr;
            else std::cout << "no data(nullptr)\n";
        }


    };
}