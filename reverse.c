#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

typedef struct WAVHEADER
{
  int32_t riff;
  int32_t file_size;
  char file_type[4];
  char formar_marker[4];
  int32_t format_data_length;
  int16_t format_type;
  int16_t channels;
  int32_t sample_rate;
  int32_t byte_rate;
  int16_t block_align;
  int16_t bits_per_sample;
  char data_chunk_header[4];
} WAVHEADER; 

int8_t main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Usage: <program> <input.wav> <output.wav>\n");
    return EXIT_FAILURE;
  }

  char input[MAX_CHARS] = { '\0' };
  char output[MAX_CHARS] = { '\0' };

  strcpy_s(input, MAX_CHARS, argv[1]);
  strcpy_s(output, MAX_CHARS, argv[2]);
  
  WAVHEADER header = { 0 };
  


  return EXIT_SUCCESS;
}

int8_t check_format(WAVHEADER header)
{
  return EXIT_SUCCESS;
}

int8_t get_block_size(WAVHEADER header)
{
  return EXIT_SUCCESS;
}