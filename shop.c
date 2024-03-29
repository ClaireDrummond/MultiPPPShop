// Claire Drummond G00364781 
// Multi Paradigm Programming 
// Shop Project

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Modelling the entities using a struct
// a struct is a custom data type
// product structure
struct Product {
    // each Product has name and a price
	char* name;
	double price;
};

// product stock structure
struct ProductStock {
    // each ProductStock has a product and a quantity
	struct Product product;
	//contains an integer that is a quantity
	int quantity;
};

// shop structure
struct Shop {
    // amount of money in the the shop
	double cash;
    // this is the stock in the shop
	struct ProductStock stock[20];
    // this is used to track the shop stock array
	int index;
};

//customer structure
struct Customer {
    // each Customer has a name and a budget and a shopping list
	char* name;
	// double means it can be a decimal number
	double budget;
	// an array of product stock
	//array brackets must go after identifer
	struct ProductStock shoppingList[10];
	//keep track of the value
	int index;
};
// takes in a product. Print the name and the Price
void printProduct(struct Product p)
{
	printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------\n");
};

void printCustomer(struct Customer c)
{
	printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	printf("-------------\n");
	for(int i = 0; i < c.index; i++)
	{
		printProduct(c.shoppingList[i].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
		double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price; 
		printf("The cost to %s will be €%.2f\n", c.name, cost);
	}
}

struct Product findProduct(struct Shop s, char* n){
   // get product from shop 
   struct Product p;
   for (int i = 0; i < s.index; i++){
	   //accessing the product
      if(strcmp(s.stock[i].product.name,n)==0){
        p = s.stock[i].product;
      }
   }
   return p;
};

struct Shop createAndStockShop()
{
	
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    // open the stock csv file. If file doesnt exist, show error
    fp = fopen("stock.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   // read the first line from the file
   getline(&line,&len,fp);
   double cashinshop = atof(line);
   //open shop with cash taken from first line of file
   struct Shop shop = {cashinshop};
   //create the stock by looping through the file   
    while ((read = getline(&line, &len, fp)) != -1) {
        // printf("Retrieved line of length %zu:\n", read);
        // printf("%s IS A LINE", line);
		char *n = strtok(line, ",");
		char *p = strtok(NULL, ",");
		char *q = strtok(NULL, ",");
		int quantity = atoi(q);
		double price = atof(p);
		char *name = malloc(sizeof(char) * 50);
		strcpy(name, n);
		struct Product product = { name, price };
		struct ProductStock stockItem = { product, quantity };
		shop.stock[shop.index++] = stockItem;
		// printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %d\n", name, price, quantity);
    }
	
	return shop;
}

void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
	}
}

int main(void) 
{
	// struct Customer dominic = { "Dominic", 100.0 };
	//
	// struct Product coke = { "Can Coke", 1.10 };
	// struct Product bread = { "Bread", 0.7 };
	// // printProduct(coke);
	//
	// struct ProductStock cokeStock = { coke, 20 };
	// struct ProductStock breadStock = { bread, 2 };
	//
	// dominic.shoppingList[dominic.index++] = cokeStock;
	// dominic.shoppingList[dominic.index++] = breadStock;
	//
	// printCustomer(dominic);
	
	struct Shop shop = createAndStockShop();
	printShop(shop);
	
// printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);
	
    return 0;
}