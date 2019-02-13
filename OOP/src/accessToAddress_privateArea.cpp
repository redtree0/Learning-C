//
//  main.cpp
//  practice
//
//  Created by 김천규 on 12/02/2019.
//  Copyright © 2019 김천규. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Test {
    private :
    int hidden;
    public :
    int opened;
    Test(int val);
};

Test::Test(int val) {
    hidden = val;
//    cout << &hidden << endl;
}

int main(int argc, const char * argv[]) {
    
    Test *test = new Test(100);
    
    cout << "-------- 값 --------" << endl;
    test->opened = 20;
    // cout << test->hidden << endl; //'hidden' is a private member of 'Test'
    cout << "test member variable hidden value"<< *(&test->opened -1) << endl;
    cout << "test member variable opened value" << test->opened << endl;
    
    cout << "-------- 주소 --------" << endl;
    cout << "test instance address : "<< &test << endl;
    cout << "test member variable hidden address : " << (&test->opened -1)<< endl;
    cout << "test member variable opened address : " << &test->opened << endl;
    
    delete test;
    return 0;
}
