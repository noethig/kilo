#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define bufSize 1024

#include "hashmap.h"

#define KEY_MAX_LENGTH (256)
#define KEY_PREFIX ("somekey")
#define KEY_COUNT (1024*1024)


typedef struct data_struct_s
{
    char key_string[KEY_MAX_LENGTH];
    int number;
} data_struct_t;

typedef struct encryptor_struct_t {
    map_t map;
    map_t inverseMap;
} encryptor_struct_t;


 
 
int main(int argc, char *argv[])
{
  FILE* fp;
  char buf[bufSize];
  if (argc != 2)
  {
    fprintf(stderr,
            "Usage: %s <soure-file>\n", argv[0]);
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) == NULL)
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
  return 0;
}

/*
int openfile(char *filename)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

void encryptor_new(char *filename) {
    openFile(filename);
}*/

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


















