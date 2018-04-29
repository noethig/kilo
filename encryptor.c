#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <wchar.h>
#include <locale.h>
#include "hashmap.h"


#define bufSize 1024

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

#define MAPPING_FILE_NAME ("mapping.conf")

#define true 1
#define false 0

#define space 32


typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    char val_string[KEY_MAX_LENGTH];
} data_struct_t;

typedef struct encryptor_s {
    map_t* map;
    map_t* inverseMap;
    map_t* curMap;
} encryptor_t;


void addPairToMap(encryptor_t* e, wint_t keyChar, wint_t valueChar) {

//     int index;
//     int error;
//     map_t mymap;
//     char key_string[KEY_MAX_LENGTH];
     data_struct_t* value;
    
//     mymap = hashmap_new();

//     /* First, populate the hash map with ascending values */
//     for (index=0; index<KEY_COUNT; index+=1)
//     {
//         /* Store the key string along side the numerical value so we can free it later */
         value = malloc(sizeof(data_struct_t));
//         snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
//         value->number = index;

//         error = hashmap_put(mymap, value->key_string, value);
//         assert(error==MAP_OK);
//     }


	hashmap_put(e->map, keyChar, valueChar);
		
	printf("pair <");
        putwchar(keyChar);
        putwchar(',');
        putwchar(valueChar);
        printf(">\n");
}

int loadMappingFile(FILE* fp, encryptor_t* e) {
    char* locale = setlocale(LC_ALL, "");
    FILE* in = fopen(MAPPING_FILE_NAME, "rb");
    
    wint_t keyChar;
    wint_t valueChar;

//     int index;
//     int error;
//     map_t mymap;
//     char key_string[KEY_MAX_LENGTH];
     //data_struct_t* value;
    
//     mymap = hashmap_new();

//     /* First, populate the hash map with ascending values */
//     for (index=0; index<KEY_COUNT; index+=1)
//     {
//         /* Store the key string along side the numerical value so we can free it later */
//         value = malloc(sizeof(data_struct_t));
//         snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
//         value->number = index;

//         error = hashmap_put(mymap, value->key_string, value);
//         assert(error==MAP_OK);
//     }
    
    wint_t c = fgetwc(in);
    while (c != NULL && c != WEOF) {
        while (c == '\n' ||  c == space) c = fgetwc(in); if (c == WEOF) break;
        keyChar = c;
        c = fgetwc(in);
        while (c == '\n' ||  c == space) c = fgetwc(in); if (c == WEOF) break;
        valueChar = c;
	addPairToMap(e, keyChar, valueChar);
	
        c = fgetwc(in);
    }
    fclose(in);
    
    return EXIT_SUCCESS;
}

 
 

encryptor_t* encryptor_new() {
    encryptor_t* e = (encryptor_t*) malloc(sizeof(encryptor_t));
    e->map = hashmap_new();

    
    loadMappingFile(MAPPING_FILE_NAME, e);

	return e;
}

void free_encryptor(encryptor_t* e) {
    hashmap_free(e->map);
}



// int main(char* argv, int argc)
// {
//     int index;
//     int error;
//     map_t mymap;
//     char key_string[KEY_MAX_LENGTH];
//     data_struct_t* value;
    
//     mymap = hashmap_new();

//     /* First, populate the hash map with ascending values */
//     for (index=0; index<KEY_COUNT; index+=1)
//     {
//         /* Store the key string along side the numerical value so we can free it later */
//         value = malloc(sizeof(data_struct_t));
//         snprintf(value->key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);
//         value->number = index;

//         error = hashmap_put(mymap, value->key_string, value);
//         assert(error==MAP_OK);
//     }

//     /* Now, check all of the expected values are there */
//     for (index=0; index<KEY_COUNT; index+=1)
//     {
//         snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

//         error = hashmap_get(mymap, key_string, (void**)(&value));
        
//         /* Make sure the value was both found and the correct number */
//         assert(error==MAP_OK);
//         assert(value->number==index);
//     }
    
//     /* Make sure that a value that wasn't in the map can't be found */
//     snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, KEY_COUNT);

//     error = hashmap_get(mymap, key_string, (void**)(&value));
        
//     /* Make sure the value was not found */
//     assert(error==MAP_MISSING);

//     /* Free all of the values we allocated and remove them from the map */
//     for (index=0; index<KEY_COUNT; index+=1)
//     {
//         snprintf(key_string, KEY_MAX_LENGTH, "%s%d", KEY_PREFIX, index);

//         error = hashmap_get(mymap, key_string, (void**)(&value));
//         assert(error==MAP_OK);

//         error = hashmap_remove(mymap, key_string);
//         assert(error==MAP_OK);

//         free(value);        
//     }
    
//     /* Now, destroy the map */
//     hashmap_free(mymap);

//     return 1;
// }


void printFile() {
    char *locale = setlocale(LC_ALL, "");
    FILE* in = fopen(MAPPING_FILE_NAME, "rb");
    
    wint_t c = fgetwc(in);
    while (c != NULL && c != EOF) {
        if (c == '\n') printf(" ... EOL");
        if (c == space) printf(" space ");
        putwchar(c);
        
        c = fgetwc(in);
    }
    fclose(in);
    
    return EXIT_SUCCESS;
}



int main(int argc, char* argv) {
    encryptor_t* e = encryptor_new();
    free_encryptor(e);

// TODO: free all entries in hashmap

    //printFile();
}