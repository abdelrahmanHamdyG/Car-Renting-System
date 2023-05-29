#include <iostream>
#include <string>
#include "User.h"
#include "Renter.h"
#include "Owner.h"
#include"Organization.h"
#include"OpeningUI.h"
using namespace std;




 int main() {
     
     // we are initializing the Organization which is responisble for reading and writing 
    Organization* org=Organization::getInstance();
    org->readFiles();
    openingUI();
    
    
}