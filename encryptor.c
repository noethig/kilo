#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define bufSize 1024

#include "hashmap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)

#define MAPPING_FILE_NAME ("mapping.conf")


typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    int number;
} data_struct_t;

typedef struct encryptor_struct_t {
    map_t map;
    map_t inverseMap;
} encryptor_struct_t;


void loadMappingFile(FILE* fp){
    char buf[bufSize];

    if ((fp = fopen(fp, "r")) == NULL)
    { /* Open source file. */
        perror("fopen source-file");
        return 1;
    }
    
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
        printf("%s\n", buf);
    }
    fclose(fp);
}
 
int main(int argc, char *argv[])
{
    encryptor_new();
    if (argc == 2) {
        printf("yallah %s", argv[1]);
    }
    
    return 0;
}

void encryptor_new() {
    loadMappingFile(MAPPING_FILE_NAME);
}

/*
int main(char* argv, int argc) {
    encryptor_new("mapping.conf");
    return 0;
}
*/

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


















