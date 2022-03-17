#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


bool validate_key(string key);
void encipher(string key, string input);

int main(int argc, string argv[]) // runs program and requests key input from user
{
    // declared variables to use later
    string plain_text; 
    string user_key = argv[1];
    
    if (argc != 2) // evaluates count of arguments
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (validate_key(user_key)) // validates user inputted key
    {
        plain_text = get_string("plaintext: "); // prompts user for text 
    }
    else
    {
        return 1; // stops program if conditions are not met 
    }
    encipher(user_key, plain_text); // evaluates user input key/text and prints ciphertext
}

bool validate_key(string key)
{
    if (strlen(key) != 26) // evaluates length of key
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    
    for (int i = 0, n = strlen(key); i < n; i++) // evaluates for non-alphabetic characters in string
    {
        if (isalpha(key[i]) == 0) // if isalpha returns a 0 (ith index is non-letter)
        {
            printf("Usage: ./substitution key\n");
            return false;
        }
        
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((toupper(key[i])) == (toupper(key[j]))) // compares first letter to second letter
            {
                count++;
                if (count > 1) 
                {
                    printf("Key must not contain repeated characters\n"); 
                    return false;
                }    
            }
        }
    }
    return true;
    
}

void encipher(string key, string input)
{   
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        char current_letter = input[i];
        int array_place = toupper(current_letter) - 'A'; // associates user input letter to key
        char key_letter = key[array_place];
        
        if (isalpha(current_letter)) // evaluates if user input char is letter
        {
            if (current_letter - 'A' >= 32) // evaluates if user input char is capitalized
            {
                printf("%c", tolower(key_letter)); 
            }
            else
            {
                printf("%c", toupper(key_letter));
            }
        }
        else 
        {
            printf("%c", current_letter);
        }
    }
    printf("\n");
}