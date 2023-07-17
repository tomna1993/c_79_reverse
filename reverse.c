#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

typedef struct WAVHEADER
{
  int32_t riff;
  int32_t file_size;
  char file_type[5];
  char format_marker[5];
  int32_t format_data_len;
  int16_t format_type;
  int16_t channels;
  int32_t sample_rate;
  int32_t byte_rate;
  int16_t block_align;
  int16_t bits_per_sample;
  char data_chunk_header[5];
  int32_t data_size;
  int32_t data_start_addr;
} WAVHEADER; 

int8_t ReadHeader(FILE *input_fp, WAVHEADER *header);
int8_t PrintHeader(WAVHEADER *header);
int8_t CheckFormat(WAVHEADER header);
int8_t GetBlockSize(WAVHEADER header);

int32_t main(int argc, char *argv[])
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
  
  FILE *input_fp = fopen(input, "rb");

  if(input_fp == NULL)
  {
    printf("Can't open file!\n");
    return EXIT_FAILURE;
  }

  WAVHEADER header = { 0 };
  int16_t *audio_data = (int16_t *)malloc(sizeof(audio_data) * 10);

  ReadHeader(input_fp, &header);
  PrintHeader(&header);

  if(CheckFormat(header) == EXIT_FAILURE)
  {
    printf ("Wrong file type!\n");
    return EXIT_FAILURE;
  }




  fclose(input_fp);
  input_fp = NULL;

  return EXIT_SUCCESS;
}

int8_t ReadHeader(FILE *input_fp, WAVHEADER *header)
{
  fread(&(header->riff), sizeof(header->riff), 1, input_fp);
  fread(&(header->file_size), sizeof(header->file_size), 1, input_fp);
  fread(&(header->file_type[0]), sizeof(header->file_type[0]), 4, input_fp);
  fread(&(header->format_marker[0]), sizeof(header->format_marker[0]), 4, input_fp);
  fread(&(header->format_data_len), sizeof(header->format_data_len), 1, input_fp);
  fread(&(header->format_type), sizeof(header->format_type), 1, input_fp);
  fread(&(header->channels), sizeof(header->channels), 1, input_fp);
  fread(&(header->sample_rate), sizeof(header->sample_rate), 1, input_fp);
  fread(&(header->byte_rate), sizeof(header->byte_rate), 1, input_fp);
  fread(&(header->block_align), sizeof(header->block_align), 1, input_fp);
  fread(&(header->bits_per_sample), sizeof(header->bits_per_sample), 1, input_fp);
  fread(&(header->data_chunk_header[0]), sizeof(header->data_chunk_header[0]), 4, input_fp);
  fread(&(header->data_size), sizeof(header->data_size), 1, input_fp);
  header->data_start_addr = ftell(input_fp);

  header->file_type[4] = '\0';
  header->format_marker[4] = '\0';
  header->data_chunk_header[4] = '\0';

  return EXIT_SUCCESS;
}

int8_t PrintHeader(WAVHEADER *header)
{
  printf("RIFF: %i\n", header->riff);
  printf("File Size: %i\n", header->file_size);
  printf("File Type: %s\n", header->file_type);
  printf("Format Marker: %s\n", header->format_marker);
  printf("Format Data Length: %i\n", header->format_data_len);
  printf("Format Type: %i\n", header->format_type);
  printf("Channels: %i\n", header->channels);
  printf("Sample Rate: %i\n", header->sample_rate);
  printf("Byte Rate: %i\n", header->byte_rate);
  printf("Block Align: %i\n", header->block_align);
  printf("Bits Per Sample: %i\n", header->bits_per_sample);
  printf("Data header: %s\n", header->data_chunk_header);
  printf("Data Size: %i\n", header->data_size);
  printf("Data Start Address: %i\n", header->data_start_addr);

  return EXIT_SUCCESS;
}

int8_t CheckFormat(WAVHEADER header)
{
  if(strncmp(header.file_type, "WAVE", 5) == 0)
  {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}

int8_t GetBlockSize(WAVHEADER header)
{
  return EXIT_SUCCESS;
}