#include "includes.h"
#include "Modules.h"


unsigned int factorial(const int& number) {
    //sanity check
    //TODO: no way to make it explicit without:
    //      - making temlate function and deleting possible conversions
    //      - making a class and defining it as explicit
    if (number < 0) {
        std::cout << "No factorial for numbers below zero!\n\a";
        return(EXIT_FAILURE);
    };
    if (number == 0) { return 1; }
    else return(factorial(number - 1) * number);
};
unsigned int factorial_iteratively(const int& number) {
    if (number < 0) {
        std::cout << "No factorial for numbers below zero!\n\a";
        return(EXIT_FAILURE);
    };
    unsigned int result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
    };
    return(result);
};
int factorial_tester() {
    //wymagania
    //program który oblicza silniê
    //n! z naturalnych
    //w momencie podania ujemnej b³¹d - nie nale¿y do dziedziny
    //0!=1
    //1!=1
    //5!=5*4*3*2*1
    //dobraæ odpowiednio typ danych
    /*overflow at 14th*/
    for (int i = -5; i < 13; i++) {
        std::cout << "Factorial for " << i << " is " << factorial(i) << '\n';
        std::cout << "Factorial for " << i << " is " << factorial_iteratively(i) << '\n';
    };
    return EXIT_SUCCESS;
};

double power(std::string& casetype, int base = 0, int pow = 0)
{
    double result = 1;

    if (!base) {
        if (pow < 0)
        {
            casetype = "Undefined";
            return -1;
        };
        if (!pow)
        {
            casetype = "Ambiguous";
            return -1;
        };
        return 0;
    }
    if (!pow)
    {
        casetype = "Normal";
        return result;
    };

    for (int i = 0; i < abs(pow); i++)
    {
        result *= base;
    };
    casetype = "Normal";
    return pow < 0 ? 1 / result : result;

    casetype = "Execution error!\a";
    return -1;
}
int power_tester()
{
    std::string exceptions = "Normal";
    double result = 0;
    std::cout << "\n2^3=  " << power(exceptions, 2, 3) << "\t exception=" << exceptions;
    std::cout << "\n2^-3= " << power(exceptions, 2, -3) << "\t exception=" << exceptions;
    std::cout << "\n0^-3= " << power(exceptions, 0, -3) << "\t exception=" << exceptions;
    std::cout << "\n2^0=  " << power(exceptions, 2, 0) << "\t exception=" << exceptions;
    std::cout << "\n0^0=  " << power(exceptions, 0, 0) << "\t exception=" << exceptions;
    return EXIT_SUCCESS;
};

int Module_01() {
	const unsigned int elements = 10;
    factorial_tester();
    power_tester();

	return EXIT_SUCCESS;
};