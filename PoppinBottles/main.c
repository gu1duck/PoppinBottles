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
Customer redeemDollars(Customer customer);
Customer redeemBottles(Customer customer);
Customer redeemCaps(Customer customer);

int main(int argc, const char * argv[]) {
    
    Customer bob = customerWithMoney(20);
    printf("Bob has $%d, %d bottles and %d caps\n", bob.dollars, bob.bottles, bob.caps);
    bob = redeemDollars(bob);
    printf("Bob has $%d, %d bottles and %d caps\n", bob.dollars, bob.bottles, bob.caps);
    bob = redeemBottles(bob);
    printf("Bob has $%d, %d bottles and %d caps\n", bob.dollars, bob.bottles, bob.caps);
    bob = redeemCaps(bob);
    printf("Bob has $%d, %d bottles and %d caps\n", bob.dollars, bob.bottles, bob.caps);

    
    
    return 0;
}

Customer customerWithMoney(int dollars){
    Customer customer;
    customer.dollars = dollars;
    customer.bottles = 0;
    customer.caps = 0;
    return customer;
}

Customer redeemDollars(Customer customer){
    int bottlesAcquired = customer.dollars/2;
    customer.dollars %= 2;
    customer.bottles += bottlesAcquired;
    customer.caps += bottlesAcquired;
    return customer;
}
Customer redeemBottles(Customer customer){
    int bottlesAcquired = customer.bottles/2;
    customer.bottles %= 2;
    customer.caps += bottlesAcquired;
    customer.bottles += bottlesAcquired;
    return customer;
}
Customer redeemCaps(Customer customer){
    int bottlesAcquired = customer.caps/4;
    customer.caps %= 4;
    customer.bottles += bottlesAcquired;
    customer.caps += bottlesAcquired;
    return customer;
}

