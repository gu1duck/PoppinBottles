//
//  main.c
//  PoppinBottles
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>

struct Customer {
    int dollars;
    int bottles;
    int caps;
};

typedef struct Customer Customer;

Customer customerWithMoney(int dollars);
Customer redeemDollars(Customer *customer);
Customer redeemBottles(Customer *customer);
Customer redeemCaps(Customer *customer);

int main(int argc, const char * argv[]) {
    

    
    
    return 0;
}

Customer customerWithMoney(int dollars){
    Customer customer;
    customer.dollars = dollars;
    customer.bottles = 0;
    customer.caps = 0;
    return customer;
}

