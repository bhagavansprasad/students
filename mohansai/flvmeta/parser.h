#include "stdint.h"
#include "types.h"
#include "types.h"

#define DMX_ERR_OK

#define MAX_STACK_BUFF (30*1024)


typedef struct input_dat_t
{
	char flv_file[100];
	FILE *flvin;
} input_data;


typedef struct __flv_header {
    byte            signature[3]; /* always "FLV" */
    uint8           version; /* should be 1 */
    uint8_bitmask   flags;
    uint32_be       offset; /* always 9 */
} flv_header;

#if 0
typedef struct __flv_tag 
{
   int           previous_tagesize;
   unsigned char type;
   unsigned char body_length[3]; /* in bytes, total tag size minus 11 */
   unsigned char timestamp[3]; /* milli-seconds */
    /* body comes next */
} flv_tag;
#endif

typedef struct __flv_tag {
	uint32_be  previous_tag_size;
    uint8      type;
    unsigned int     body_length; /* in bytes, total tag size minus 11 */
    unsigned int     timestamp; /* milli-seconds */
    uint8      timestamp_extended; /* timestamp extension */
    uint32_be  stream_id; /* reserved, must be "\0\0\0" */
    /* body comes next */
} flv_tag;

#if 0
typedef struct __flv_tag {
   unsigned  char      type;
   unsigned  char    body_length[3]; /* in bytes, total tag size minus 11 */
   unsigned  char    timestamp[3]; /* milli-seconds */
   unsigned  char    timestamp_extended; /* timestamp extension */
   unsigned  char    stream_id[3]; /* reserved, must be "\0\0\0" */
    /* body comes next */
} flv_tag;
#endif
# define swap_uint32(x) ((uint32)((((x) & 0x000000FFU) << 24) | \
    (((x) & 0x0000FF00U) << 8)  | \
    (((x) & 0x00FF0000U) >> 8)  | \
    (((x) & 0xFF000000U) >> 24)))



