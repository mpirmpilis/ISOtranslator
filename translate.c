/* **********************************
   *Name:Giwrgos Mpirmpilhs         *
   *Assignment 1: Translate program *
   ********************************** */

#include <stdio.h>
#include <string.h>

#define M_gr 204
#define m_gr 236
#define N_gr 205
#define n_gr 237
#define T_gr 212
#define t_gr 244
#define P_gr 208
#define p_gr 240
#define B_KEF_ENG 66
#define B_MIKRO_ENG 98
#define D_KEF_ENG 68
#define D_MIKRO_ENG 100
#define TONOS 39
#define DIALYTIKA 34


enum state {no_state = 0, state_M, state_N, state_m, state_n} state; 			/* Declaring the FSM and it's states */

void CreateArray(char cmap[256][3]) { 	/* Creating and initializing the cmap */

    int i, j, l;
    char lowercase_arr[] = "avgdezh8iklmnqoprsstufxyw"; 	/* Array that contains the lowercase english letters */
    char uppercase_arr[] = "AVGDEZH8IKLMNQOPR-STUFXYW"; 	/* Array that contains the uppercase english letters */

    i = j = l = 0;
    for(i = 0; i < 256; i++){       /* Initializing cmap's elements with the '\0' character */
        for(j = 0; j < 3; j++){
                cmap[i][0] = i;
                cmap[i][1] = '\0';
                cmap[i][2] = '\0';
            }
        }

    /* Manually inserting the English capital letters from uppercase_arr into cmap array (no TONOS/DIALYTIKA) */
    l = 0;    /* Initializing l to 0 so we can start working from the beginning of the uppercase_arr */
    i = 193;  /* i is initialized to 193 (193 refers to Greek capital letter A) and increased to refer to the next character and so on */
    while (i < 218) {
        cmap[i][0] = uppercase_arr[l];
        l++;
        i++;
    }

    /* Manually inserting the English lowercase letters from lowercase_arr into cmap array (no TONOS/DIALYTIKA) */
    j = 0;    /* Initializing j to 0 so we can start working from the beginning of the uppercase_arr */
    i = 224;  /* Initializing i to 224 so we can increase it when we enter the do-while and the first value to be inserted will be 225 after increment. (225--> greek lower a) */
    do{
        i++;
        cmap[i][0] = lowercase_arr[j];
        j++;
    } while(i < 250);
    /* Manually inserting the English capital letters with TONOS into cmap array */
    cmap[182][0] = TONOS;
    cmap[182][1] = 'A';
    cmap[184][0] = TONOS;
    cmap[184][1] = 'E';
    cmap[185][0] = TONOS;
    cmap[185][1] = 'H';
    cmap[186][0] = TONOS;
    cmap[186][1] = 'I';
    cmap[188][0] = TONOS;
    cmap[188][1] = 'O';
    cmap[190][0] = TONOS;
    cmap[190][1] = 'Y';
    cmap[191][0] = TONOS;
    cmap[191][1] = 'W';
    /* Manuatomally inserting the English lowercase letters with TONOS into cmap array */
    cmap[220][0] = 'a';
    cmap[220][1] = TONOS;
    cmap[221][0] = 'e';
    cmap[221][1] = TONOS;
    cmap[222][0] = 'h';
    cmap[222][1] = TONOS;
    cmap[223][0] = 'i';
    cmap[223][1] = TONOS;
    cmap[252][0] = 'o';
    cmap[252][1] = TONOS;
    cmap[253][0] = 'y';
    cmap[253][1] = TONOS;
    cmap[254][0] = 'w';
    cmap[254][1] = TONOS;
    /* Manually inserting both English capital and lowecase letters with TONOS/DIALYTIKA into cmap array */
    cmap[218][0] = 'I';
    cmap[218][1] = DIALYTIKA;
    cmap[219][0] = 'Y';
    cmap[219][1] = DIALYTIKA;
    cmap[250][0] = 'i';
    cmap[250][1] = DIALYTIKA;
    cmap[251][0] = 'y';
    cmap[251][1] = DIALYTIKA;
    cmap[192][0] = 'i';
    cmap[192][1] = TONOS;
    cmap[192][2] = DIALYTIKA;
    cmap[224][0] = 'y';
    cmap[224][1] = TONOS;
    cmap[224][2] = DIALYTIKA;

    /* Replacing english u/U with english y/Y when matching with greek u/Y */
    cmap[245][0] = 'y';
    cmap[213][0] = 'Y';
    /* Manually inserting the special cases KS/ks and PS/ps into cmap according to greek letter's decimal values */
    cmap[238][0] = 'k';
    cmap[238][1] = 's';
    cmap[248][0] = 'p';
    cmap[248][1] = 's';
    cmap[206][0] = 'K';
    cmap[206][1] = 'S';
    cmap[216][0] = 'P';
    cmap[216][1] = 'S';
}

void PrintChars(int c) {     	/* Printing the characters to console */
   	char cmap[256][3];
    CreateArray(cmap);
                               	/* We print characters as long as we dont meet an element that containts the '\0' character */
    if(cmap[c][0] != '\0')
        putchar(cmap[c][0]);  	/* Print the first column's element */
    if(cmap[c][1] != '\0')
        putchar(cmap[c][1]);   	/* Print the second column's element */
    if(cmap[c][2] != '\0')
       putchar(cmap[c][2]);    	/* Print the third column's element */
}


enum state function_any(int c) { 	/* We check for a character's state */
		switch (c){
	        case M_gr:
	            return state_M;     /* If the character was M, return state_M */
	            break;
	        case m_gr:
	            return state_m;     /* If the character was m, return state_m */
	            break;
	        case N_gr:
	            return state_N;     /* If the character was N, return state_N */
	            break;
	        case n_gr:
	            return state_n;     /* If the character was n, return state_n */
	            break;
	        default:                /* If a character is not M/m or N/n, it will be printed instantly without any further checks */
	            PrintChars(c);
	            return no_state;
	            break;
    }
}
enum state function_M(int c) { 		/* If the character is M(Greek capital M) */
		switch(c){
		    case P_gr:
		        PrintChars(B_KEF_ENG);
		        return no_state;
		        break;
		    case p_gr:
		        PrintChars(B_KEF_ENG);
		        return no_state;
		        break;
		    case M_gr:
		        PrintChars(M_gr);
		        return state_M;
		        break;
		    case m_gr:
		        PrintChars(M_gr);
		        return state_m;
		        break;
		    case N_gr:
		        PrintChars(M_gr);
		        return state_N;
		        break;
		    case n_gr:
		        PrintChars(M_gr);
		        return state_n;
		        break;
		    default:
		        PrintChars(M_gr);
		        PrintChars(c);
		        return no_state;
		        break;
    }
}

enum state function_N(int c) { 	/* If the character is N(Greek capital N) */
        switch(c){
	        case T_gr:
	                PrintChars(D_KEF_ENG);
	                return no_state;
	                break;
	        case t_gr:
	                PrintChars(D_KEF_ENG);
	                return no_state;
	                break;
	        case N_gr:
	                PrintChars(N_gr);
	                return state_N;
	                break;
	        case n_gr:
	                PrintChars(N_gr);
	                return state_n;
	                break;
	        case M_gr:
	                PrintChars(N_gr);
	                return state_M;
	                break;
	        case m_gr:
	                PrintChars(N_gr);
	                return state_m;
	                break;
	        default:
	                PrintChars(N_gr);
	                PrintChars(c);
	                return no_state;
	                break;
        }
}

enum state function_m(int c) { 	/* If the character is m(Greek lowercase m) */
        switch(c){
            case P_gr:
                    PrintChars(B_MIKRO_ENG);
                    return no_state;
                    break;
            case p_gr:
                    PrintChars(B_MIKRO_ENG);
                    return no_state;
                    break;
            case M_gr:
                    PrintChars(m_gr);
                    return state_M;
                    break;
            case m_gr:
                    PrintChars(m_gr);
                    return state_m;
                    break;
            case N_gr:
                    PrintChars(m_gr);
                    return state_N;
                    break;
            case n_gr:
                    PrintChars(m_gr);
                    return state_n;
                    break;
            default:
                    PrintChars(m_gr);
                    PrintChars(c);
                    return no_state;
                    break;
        }
}

enum state function_n(int c) { 	/* If the character is n(Greek lowercase n) */
        switch(c){
            case T_gr:
                    PrintChars(D_MIKRO_ENG);
                    return no_state;
                    break;
            case t_gr:
                    PrintChars(D_MIKRO_ENG);
                    return no_state;
                    break;
            case M_gr:
                    PrintChars(n_gr);
                    return state_M;
                    break;
            case m_gr:
                    PrintChars(n_gr);
                    return state_m;
                    break;
            case N_gr:
                    PrintChars(n_gr);
                    return state_N;
                    break;
            case n_gr:
                    PrintChars(n_gr);
                    return state_n;
                    break;
            default:
                    PrintChars(n_gr);
                    PrintChars(c);
                    return no_state;
                    break;
        }
}
enum state (*action[])(int c) =  {function_any, function_M, function_N, function_m, function_n}; 	/* Functions that refer to whatever the character is and will choose the correct one */

/* main() function */
int main(void)
{
    int c;      		/* Declaring an integer variable called c (it will be used to store the characters */
    
    state = no_state;  	        /* Declaring an enum state type variable called state and giving it the first value from enum type */
    c = 'a';  			/* Initializing c (with character 'z') to avoid garbage value */
    do{
        c = getchar();   	/* Read a character and store it to int variable c */
    	if(c == EOF) return 0;			/* If the given c is EOF, terminate the program */
	   	state = (action[state])(c);  	/* Otherwise, the character is a Greek one and we need to check if it is one of the special characters M/m or N/n */

    }while(c != EOF);  					/* Program will read characters until the EOF is met */
    printf("\n");
	
	return 0;
}
