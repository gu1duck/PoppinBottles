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
    int lifetimeBottles;
    int fromDollars;
    int fromBottles;
    int fromCaps;
};

typedef struct Customer Customer;

Customer customerWithMoney(int dollars);
Customer redeemDollars(Customer customer);
Customer redeemBottles(Customer customer);
Customer redeemCaps(Customer customer);
Customer redeemAll(Customer customer);
Customer customerWithInput();
void customerOutput(Customer);

int main(int argc, const char * argv[]) {
    
    do{
        Customer customer = customerWithInput();
        customer = redeemAll(customer);
        customerOutput(customer);
    } while (1);
    
    return 0;
}

Customer customerWithInput(){
    printf("How many dollars will the customer spend?\n>");
    int dollars;
    scanf("%d", &dollars);
    return customerWithMoney(dollars);
}

Customer customerWithMoney(int dollars){
    Customer customer;
    customer.dollars = dollars;
    customer.bottles = 0;
    customer.caps = 0;
    customer.lifetimeBottles = 0;
    customer.fromDollars = 0;
    customer.fromBottles = 0;
    customer.fromCaps = 0;
    return customer;
}

Customer redeemAll(Customer customer){
    int lifetime = customer.lifetimeBottles;
    customer = redeemDollars(customer);
    customer = redeemBottles(customer);
    customer = redeemCaps(customer);
    
    /* if the customer can make further redemptions, 
     repeat until there are no further possible redemptions */
    if (lifetime != customer.lifetimeBottles){
        return redeemAll(customer);
    } else {
        return customer;
    }
}

Customer redeemDollars(Customer customer){
    int bottlesAcquired = customer.dollars/2;
    customer.dollars %= 2;
    customer.bottles += bottlesAcquired;
    customer.caps += bottlesAcquired;
    customer.lifetimeBottles += bottlesAcquired;
    customer.fromDollars += bottlesAcquired;
    return customer;
}
Customer redeemBottles(Customer customer){
    int bottlesAcquired = customer.bottles/2;
    customer.bottles %= 2;
    customer.caps += bottlesAcquired;
    customer.bottles += bottlesAcquired;
    customer.lifetimeBottles += bottlesAcquired;
    customer.fromBottles += bottlesAcquired;
    return customer;
}
Customer redeemCaps(Customer customer){
    int bottlesAcquired = customer.caps/4;
    customer.caps %= 4;
    customer.bottles += bottlesAcquired;
    customer.caps += bottlesAcquired;
    customer.lifetimeBottles += bottlesAcquired;
    customer.fromCaps += bottlesAcquired;
    return customer;
}

void customerOutput (Customer customer) {
    printf("Customer has $%d, %d bottle(s) and %d cap(s) left.\nThey've gotten %d bottles, total.\nThey purchased %d, got %d by redeeming bottles and %d from redeeming caps.\n", customer.dollars, customer.bottles, customer.caps, customer.lifetimeBottles, customer.fromDollars, customer.fromBottles, customer.fromCaps);
}

