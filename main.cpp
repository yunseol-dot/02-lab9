#include <memory>
#include "dayOfYearPtr.h"

int main(){
    using namespace yunseol2649038;
    dayOfYearPtr dp1{dayOfYear{11,5}}; dp1.print();
    dayOfYearPtr dp2{dp1}; dp1.print(); dp2.print();
    dayOfYearPtr dp3{std::move(dp2)}; dp2.print(); dp3.print();

    dp2 = std::move(dp3);
    dp3 = dp2;

    dayOfYearPtr* dp{new dayOfYearPtr{dayOfYear{11,5}}};
    delete dp;

    std::unique_ptr<dayOfYearPtr> up1;
    
    auto up2{std::make_unique<dayOfYearPtr>(dayOfYear{11,5})};
    up1 = std::move(up2); up1->print();

    auto sp1{std::make_shared<dayOfYearPtr> (dayOfYearPtr{dayOfYear{12,5}})};
    std::cout << sp1.use_count() <<std::endl;
    std::shared_ptr<dayOfYearPtr> sp2{sp1};
    std::cout << sp1.use_count() << " " << sp2.use_count() <<std::endl;


    std::weak_ptr<dayOfYearPtr> wp;
    std::cout << sp1.use_count() << " " << sp2.use_count() <<std::endl;

    sp1.reset();
    std::cout << sp1.use_count() << " " << sp2.use_count() <<std::endl;

    if(!wp1.expired()) sp1=wp1.lock();


    return 0;
}

//원하는 값으로 클래스1Ptr형 객체1 생성, 출력

//클래스1Ptr형 객체1 값으로 클래스1Ptr형 객체2 생성, 출력 

//클래스1Ptr형 객체2를 이동시켜 클래스1Ptr형 객체3 생성, 객체2와 객체3 출력

//클래스1Ptr형 객체2에 클래스1Ptr형 객체3을 이동시켜 할당

//클래스1Ptr형 객체3에 객체2를 복사할당



//클래스1Ptr형을 가리키는 unique_ptr 객체1을 선언

//클래스1Ptr형을 가리키는 unique_ptr 객체2를 선언하면서 원하는 값으로 초기화 (make_unique 사용)

//unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력



//클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화

//클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화

//shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

//shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

//클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화

//shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

//shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

//shared_ptr 객체1에서 reset 멤버함수를 호출한 후

//shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

//shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력

//weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)

//weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

//shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

//shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력