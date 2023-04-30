#include <iostream>
#include <string>
using namespace std;

/* LEXICAL SCOPE

1. BLOCK SCOPE => block variables
- block of code/ compound code
	- delimit: {}
	- appear: condition blocks, ...
- difference with fucntion
	- does not have name
	- block code is not call, b/c it belongs to compound codes

2. FUNCTION SCOPE => function variables; function formal parameter (func.s arguments)
- differences with compound code
	- it has a name
	- it has parameters

3. FILE SCOPE
- delimit: physical boudary of the file
- it can contain:
	type definitions,
	definitions and declarations of variables
	definitions and declarations of functions

4.PROGRAM SCOPE
- this scope has no delimiters. Anything belonging to any source file is part of the program
is within the program scope

*name conflict with the same scope is not allowed in C++


/*
LEXICAL SCOPE OF DIFFERENT PROGRAM ENTITIES
	- data types -> type names(data type)
		- type names(data type) can be declared in functions, a block, or file. they are  known within that block, function, or file
	- functions
	- parameters
		can be defined in a func only
	- variables -> NAME OF VARS.
			the same is true about the name of vars. NAME OF VARS. can be declared in a block, function, or file
	- labels

LEXICAL SCOPE OF VARIABLE NAMES
	block vars.
	function vars.
	function formal parameters
	global variables
	*names of structure fields are local to the block of the structure definition
*/


/*
Global scope operator ::
	e.g: ::count

	int count a;

	int main(){
		::count
	}


USING THE SAME VARIABLE NAMES IN INDEPENDENCE SCOPES
	e.g: the variable total in main() and getBalance are different

USING THE SAME NAME IN NESTED SCOPES
	concept of nesting 
	C++ is a block structured language
		=> scopes can be lexically nested within each other (nested)
		e.g:
			{
			code;
				{
				code;
				}
			code;
			}
			vocab: nest with
		=> scopes can be independet
			e.g:
			{
			code;
			}
			{
			code;
			}

THERE IS STILL SOMETHING TO LEARN

*/



struct account { //=> file scope
	long num;
	double balance;
};
/*
struct account has the file scope 
	- it is know from the place of definition to 
	the end of the source file
	- variable account can be defined anywhere in this scope(file scope)
	- the use of account for other purposes is invalid 
		e.g:
			int account = 5; XXX
*/


double getBalance(account a) {
	double total = a.balance;
	return total;
}
/*
getBalance() has the program scope, no object in the program scope can be called getBalance.
*/


/*
This program
	- account data
	- display data
	- compute the total of account balances

	-data source: from arrays, not from external file, database, or keyboard.

	- the data is loaded in the infinite while loop until the sentinel value (-1) is found for the account number
	- the second loop prints account numbers
	- the third loop prints account balances 
	- the fourth loop computes the total of account balances
*/
int lexicalVariables() {

	/* there are no global variables in this listing(6.1)*/

	typedef int Index; // local type definition
	Index const MAX = 5;
	Index i, count = 0; // integers in disguise

	/*
	* type Index has the function scope 
	*	it is know til the end of main()
		it can not be used outside of main(), for example getBalance()
	*/

	account a[MAX]; double total = 0; // data set, its total

	while (true) // break on the sentinel
	{
		long num[MAX] = { 800123456, 800123123, 800123333, -1 };

		double amounts[MAX] = { 1200, 1500, 1800 }; // data to load

		if (num[count] == -1) break; // sentinel is found

		/*
		amount[] and num[] are the block variables
			they are visible from the place of defenition until the end of the block
		*/

		a[count].num = num[count]; // loading data
		a[count].balance = amounts[count];
		count++;
	}

	cout << " Data is loaded\n\n";

	for (i = 0; i < count; i++)
	{
		long temp = a[i].num; // temp in independent scopes - the block variable
		cout << temp << endl;
	} // display account numbers

	for (i = 0; i < count; i++)
	{
		double temp = a[i].balance; // temp in independent scopes - the block variable
		cout << temp << endl;
	} // display account balances

	for (i = 0; i < count; i++)
	{
		total += getBalance(a[i]);
	} // accumulate total for 	balances

	cout << endl << "Total of balances $" << total << endl;

	return 0;
}
