#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <inttypes.h>

typedef int32_t (*callback)(int32_t, int32_t);
extern int32_t factorization(int32_t number, callback print_factor);

int search_wrong(char* num_str, int sign_num);
void factorization_call(int32_t number, callback print_factor);
int32_t print_factor(int32_t factor, int32_t new_number);

int main(int argc, char* argv[])
{
    // the program must accept two arg: file call and number
    if (argc != 2)
    {
        fprintf(stderr, "Error: too much/few arguments.\n\
                        Input example: ./<PROGRAM NAME> <YOUR NUMBER>\n");
        return 1;
    }

    char *number_str = argv[1];
    // check whether the input is valid for negative numbers
    if (number_str[0] == '-')
    {
        if (search_wrong(number_str, 1) != 0)
        {
            fprintf(stderr, "Error: the enter string is not a number\n");
            return 1;
        }
    }
    // check whether the input is valid for positive numbers
    else if (search_wrong(number_str, 0))
    {
        fprintf(stderr, "Error: the enter string is not a number\n");
        return 1;
    }
    
    // number from string, checking overflow
    int32_t number = (int32_t)strtol(number_str, NULL, 10);
    if (errno == ERANGE)
    {
        fprintf(stderr, "Error: the number is too large\n");
        return 1;
    }
    
    factorization_call(number, print_factor);
    return 0;
}

// sign_num = 1 if number is negative and = 0 if number is non-negative
int search_wrong(char* number_str, int sign_number)
{
    int i = sign_number;
    while (number_str[i] != '\0')
    {
        if (!((number_str[i] >= '0') && (number_str[i] <= '9')))
        {
            return 1;
        }
        i++;
    }    
    return 0;

}

void factorization_call(int32_t number, callback print_factor)
{
    // handling special cases
    if ((number == 0) || (number == 1) || (number == -1))
    {
        printf("%d\n", number);
        return;
    }
    // handling negative number
    if (number < 0)
    {
        printf("-1*");
        number = abs(number);
    }

    factorization(number, print_factor);

    return;
}

int32_t print_factor(int32_t factor, int32_t new_number)
{
    // handling last factor
    if (new_number == 1)
    {
        printf("%d\n", factor);
        return 0;
    }

    printf("%d*", factor);
    return 0;
} 