#include <iostream>
#include <memory>
//#include "Resource.h"
int main() {

    std::unique_ptr<Resource> res(new Resource(10000000));

    return 0;
}
