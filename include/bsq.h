#ifndef BSQ_PROJECT
#define BSQ_PROJECT

#define UNUSED(x) x __attribute((unused))

/* --- get_file.c --- */
char *get_file(char *path);

/* --- char_to_int_array.c --- */
int *char_to_int_array(char *c_array, size_t size);

/* --- algo.c --- */
char *get_map_size(char *map, size_t *size);
char *algo(char *map, size_t size);

#endif /* BSQ_PROJECT */