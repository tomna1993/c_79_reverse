#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[])
{
  WAVHEADER header = { 0 };
  
}

int check_format(WAVHEADER header)
{
  return EXIT_SUCCESS;
}

int get_block_size(WAVHEADER header)
{
  return EXIT_SUCCESS;
}