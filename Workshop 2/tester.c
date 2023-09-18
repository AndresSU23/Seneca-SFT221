/*
--- Name: David Andres Sanchez Umbarila
--- Code: 140273228
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "shopping.c"

/**
 * This Function emulates the behavior of the main funtion of shopping.c that changes the scanf input
 * to controlled char arrar input and outputs are kept as the original
 * @param cart A Cart Struct already initilize
 * @param productList A char array that emulates the user input having the information of the desired products 
 * @param numSearchedProducts The Number of searched products the user would have at the end of the operation
 * @return the cart struct with the altered information of the shopping procedure
*/
struct Cart fullAppShopping(struct Cart cart,  char productList[][MAX_STRING_LEN + 1], int numSearchedProducts){
	int j, i, finished = 0;
	int total = 0, tax = 0;
    int numAvailableProducts = 6;
    double prices[MAX_PRODUCTS] = { 1.99, 2.48, 4.56, 3.47, 6.99, 2.99 };
	char descriptions[][MAX_STRING_LEN + 1] =
	{
		"flour",
		"sugar",
		"bananas",
		"potatoes",
		"milk",
		"tea"
	};
	printf("********************\n");
	printf("* Seneca Groceries *\n");
	printf("********************\n\n");
    for (j = 0; j < numSearchedProducts; j++)
    {
        int n = findString(productList[j], descriptions, numAvailableProducts);
			if (n < 0)
			{
				printf("Sorry, we do not have %s\n", productList[j]);
			}
			else
			{
				int rc = add2Cart(&cart, n);
				if (rc) printf("could not add item to cart\n");
			}
    }

	printf("\nYour Order:\n");
	for (i = 0; i < cart.nItems; i++)
	{
		printf("%30s%8.2lf\n", descriptions[cart.items[i]], prices[cart.items[i]]);
		total += (int)(prices[cart.items[i]] * 100 + 0.5);
	}

	printf("%30s%8.2lf\n", "TOTAL", total / 100.0);
	tax = (int)(TAX_RATE * total + 0.5);
	total = total + tax;
	printf("%30s%8.2lf\n", "TAX", tax / 100.0);
	printf("%30s%8.2lf\n", "GRAND TOTAL", total / 100.0);
    return cart;
}

/**
 * A tester for the function stringFinder with teste cases already written with the structure
 * * {list} an string array of searched item list
 * * {nstings} the number of items in the searched list
 * * {searchedStr} the searched string
 * It will prompt of expected postion vs the actual result.
 * Multiple test are written in code with the same structure
*/
void stringFinderTest(){
    /**
     * !Test Structure
     * char list[][MAX_STRING_LEN + 1] = LIST_TO_SEARCH_ON;
     * int nstrings = LIST_SIZE;
     * char searchStr[] = SEARCHED_STRING;
     * int position = findString(searchStr, list, nstrings);
     * printf("Position should be EXPEXTED_POSITON Actual result : %d\n", position); 
    */

    printf("-----------------------------------------------------\n"
            "String Identifier Tests: \n\n");

    char list[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings = 4;
    char searchStr[] = "cherry";
    int position = findString(searchStr, list, nstrings);
    printf("Position should be 2 Actual result : %d\n", position); 

    char list2[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings2 = 4;
    char searchStr2[] = "apple";
    position = findString(searchStr2, list2, nstrings2);
    printf("Position should be 0 Actual result : %d\n", position); 

    char list3[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings3 = 4;
    char searchStr3[] = "date";
    position = findString(searchStr3, list3, nstrings3);
    printf("Position should be 3 Actual result : %d\n", position); 

    char list4[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings4 = 4;
    char searchStr4[] = "grape";
    position = findString(searchStr4, list4, nstrings4);
    printf("Position should be -1 Actual result : %d\n", position); 

    char list5[][MAX_STRING_LEN + 1] = {""};
    int nstrings5 = 0;
    char searchStr5[] = "apple";
    position = findString(searchStr5, list5, nstrings5);
    printf("Position should be -1 Actual result : %d\n", position); 

    char list6[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings6 = 4;
    char searchStr6[] = "";
    position = findString(searchStr6, list6, nstrings6);
    printf("Position should be -1 Actual result : %d\n", position); 

    char list7[][MAX_STRING_LEN + 1] = {"apple", "banana", "cherry", "date"};
    int nstrings7 = 4;
    char searchStr7[MAX_STRING_LEN + 1] = "banana"; // Exactly MAX_STRING_LEN characters
    position = findString(searchStr7, list7, nstrings7);
    printf("Position should be -1 Actual result : %d\n", position); 
}

/**
 * A tester for the function init with teste cases already written with the structure
 * * {arr} an integer array of the created list
 * * {value} the integer that wants to be placed and that will mean an empty space
 * * {size} the real size of the given array
 * It will prompt of expected content of the array vs the actual result.
 * Multiple test are written in code with the same structure
*/
void initTester(){
    /**
     * !Test Structure
     * int arr[] = NEW_TEST_ARRAY;
     * const int value = FILL_NUMBER;
     * const int size = ARRAY_SIZE;
     * init(arr, value, size);
     * printf("arr should be EXPECTED_ARRAY Actual value : {");
     * for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
     * {printf("%d, ", arr[i]);}
     * printf("\b\b}\n");
    */

    int i;
    printf("-----------------------------------------------------\n"
        "Init Tests: \n\n");

    int arr[] = {0, 0, 0, 0, 0};
    int value = 42;
    int size = 5;
    init(arr, value, size);
    printf("arr should be {42, 42, 42, 42, 42} Actual value : {");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {printf("%d, ", arr[i]);}
    printf("\b\b}\n");

    int arr2[MAX_PRODUCTS] = {0};
    int value2 = 99;
    int size2 = 0;
    init(arr2, value2, size2);
    printf("arr should be empty Actual value : {");
    for (i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {printf("%d, ", arr2[i]);}
    printf("\b\b}\n");

    int arr3[] = {7};
    int value3 = 77;
    int size3 = 1;
    init(arr3, value3, size3);
    printf("arr should be {77} Actual value : {");
    for (i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++)
    {printf("%d, ", arr3[i]);}
    printf("\b\b}\n");

    int arr4[1000]; 
    int value4 = -5;
    int size4 = 1000;
    init(arr4, value4, size4);
    printf("arr should be -5 everywhere Actual value : {");
    for (i = 0; i < sizeof(arr4) / sizeof(arr4[0]); i++)
    {printf("%d, ", arr4[i]);}
    printf("\b\b}\n");
    
    int arr5[] = {1, 1, 1, 1, 1};
    int value5 = 1;
    int size5 = 5;
    init(arr5, value5, size5);
    printf("arr should be unchanged so 1 Actual value : {");
    for (i = 0; i < sizeof(arr5) / sizeof(arr5[0]); i++)
    {printf("%d, ", arr5[i]);}
    printf("\b\b}\n");
}

/**
 * A tester for the function Add2Cart with teste cases already written with the structure
 * * {cart} a Cart struct initialize with { {0}, 0 } values
 * * This struct is then officially initialize using init and the desired number
 * * {itemToAdd} the wanted item number to add
 * It will prompt of expected result  vs the actual result.
 * Additionally it would show the last contents of the shopping card and its last size
 * Multiple test are written in code with the same structure
*/
void add2CartTest(){
    /**
     * !Test Structure
     * struct Cart emptyCart= { {0}, 0 };
     *init(emptyCart.items, -1, MAX_CART);
     *int itemToAdd = TEST_ITEM;
     *int result = add2Cart(&emptyCart, itemToAdd);
     *printf("result should be EXPECTED_OUTPUT and cart should be EXPECTED_CART size EXPECTED_SIZE Actual result {");
     *for (i = 0; i < MAX_CART; i++)
     *{printf("%d, ", emptyCart.items[i]);}
    * printf("\b\b} With size %d\n", emptyCart.nItems);
    */

    int i;
    printf("-----------------------------------------------------\n"
        "Add2Cart Tests: \n\n");
    
    struct Cart emptyCart= { {0}, 0 };
    init(emptyCart.items, -1, MAX_CART);
    int itemToAdd = 42;
    int result = add2Cart(&emptyCart, itemToAdd);
    printf("result should be 0 and cart should be {42} size 1 Actual result {");
    for (i = 0; i < MAX_CART; i++)
    {printf("%d, ", emptyCart.items[i]);}
    printf("\b\b} With size %d\n", emptyCart.nItems);


    struct Cart cartWithItems= { {0}, 0 };
    init(cartWithItems.items, -1, MAX_CART);
    add2Cart(&cartWithItems, 10);
    add2Cart(&cartWithItems, 20);
    itemToAdd = 30;
    result = add2Cart(&cartWithItems, itemToAdd);
    printf("result should be 0 and cart should be {10,20,30} size 3 Actual result {");
    for (i = 0; i < MAX_CART; i++)
    {printf("%d, ", cartWithItems.items[i]);}
    printf("\b\b} With size %d\n", cartWithItems.nItems);


    struct Cart cartWithItem= { {0}, 0 };;
    init(cartWithItem.items, -1, MAX_CART);
    add2Cart(&cartWithItem, 5);
    itemToAdd = 5; 
    result = add2Cart(&cartWithItem, itemToAdd);
    printf("result should be 0 and cart should be {5,5} size 2 Actual result {");
    for (i = 0; i < MAX_CART; i++)
    {printf("%d, ", cartWithItem.items[i]);}
    printf("\b\b} With size %d\n", cartWithItem.nItems);


    struct Cart fullCart= { {0}, 0 };
    init(fullCart.items, -1, MAX_CART);
    for (int i = 0; i < MAX_CART; i++) {
        add2Cart(&fullCart, i);
    }
    itemToAdd = 100; 
    result = add2Cart(&fullCart, itemToAdd);
    printf("result should be non zero and cart should be full size %d Actual result {", MAX_CART);
    for (i = 0; i < MAX_CART; i++)
    {printf("%d, ", fullCart.items[i]);}
    printf("\b\b} With size %d\n", fullCart.nItems);

}

/**
 * A tester for the function shopping (integrated main) with teste cases already written with the structure
 * * {cart} a Cart struct initialize with { {0}, 0 } values
 * * This struct is then officially initialize using init and the desired number
 * * {productList} All the searches that would have been read with scanf (user selections)
 * * {numSearchedProducts} The number of searches or enter querys by the user (size of prouctList)
 * Multiple test are written in code with the same structure
*/
void shoppingTests(){
    /**
     * !Test Structure
     * printf("\n-----------------------------------------------------\n"
     *"Case #n TEST_CASE\n");
     * struct Cart cart = {{0}, 0 };
     * init(cart.items, DESIRED_NUMBERED, MAX_CART);
     * char productList[][MAX_STRING_LEN + 1] = {TEST_INPUTS};
     * int numSearchedProducts = NUM_INPUTS;
     *fullAppShopping(cart,  productList, numSearchedProducts);
    */

    printf("-----------------------------------------------------\n"
    "Shopping Tests: \n\n");

    printf("\n-----------------------------------------------------\n"
    "Case #1 Initialize cart with different than -1 (expected with scanf)\n");
    struct Cart cart = {{0}, 0 };
    init(cart.items, 3, MAX_CART);
    char productList[][MAX_STRING_LEN + 1] = {"flour","end"};
    int numSearchedProducts = 2;
    fullAppShopping(cart,  productList, numSearchedProducts);


    printf("\n-----------------------------------------------------\n"
    "\nCase #2 Empty press (expected with scanf)\n");
    struct Cart cart2 = {{0}, 0 };
    init(cart2.items, -1, MAX_CART);
    char productList2[][MAX_STRING_LEN + 1] = {"sugar","\n","\n","end"};
    numSearchedProducts = 4;
    fullAppShopping(cart2,  productList2, numSearchedProducts);

}
 
 /**
  * Executes all the test Functions
 */
int main()
{
    //stringFinderTest();
    //initTester();
    //add2CartTest();
    shoppingTests();
    return 0;
}
