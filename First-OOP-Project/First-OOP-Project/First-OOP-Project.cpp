#include <iostream>
#include <string>
#include "User.h"
#include "Renter.h"
#include "Owner.h"
#include"Organization.h"
#include"OpeningUI.h"
using namespace std;




 int main() {

    Organization org;
    org.readFiles();
    openingUI(&org);
    
    
}