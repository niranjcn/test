/* vowel_counter.l */
%{
    // Global variables to store the counts
    int vowel_count = 0;
    int consonant_count = 0;
%}

%%
[aeiouAEIOU]      { vowel_count++; }
[a-zA-Z]          { consonant_count++; }
.|\n              { /* Ignore all other characters, including spaces and newlines */ }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a string and press Ctrl+D when done:\n");
    
    // This function starts the lexical analysis
    yylex(); 
    
    printf("\n------------------------------------\n");
    printf("Number of Vowels: %d\n", vowel_count);
    printf("Number of Consonants: %d\n", consonant_count);
    printf("------------------------------------\n");
    
    return 0;
}