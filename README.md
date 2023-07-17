# c_79_reverse

## DESCRIPTION

Implement a program that reverses a WAV file.

In Electric Light Orchestra’s “Fire on High”, there’s something a little off about the first minute or so of the music. If you take a listen, it sounds almost like the audio is playing backwards. As it turns out, if you play the beginning section of the song in reverse, you’ll hear the following:

```“The music is reversible. Time is not. Turn back, turn back!”```

Creepy, right? This is a technique called “backmasking,” or hiding messages in music that can only be heard when the song is played backwards. Many artists have used (or been suspected of using) this technique in their songs. To be able to do our own investigation into backmasking, we’ve asked you to write a program that can reverse WAV files for us!

Unlike MP3 audio files, WAV files are not compressed. This makes the files much easier to edit and manipulate, which is useful for the task at hand. To learn a little more about WAV files, we need to take a closer look at the WAV file format.

[Informations about WAV file structure](https://en.wikipedia.org/wiki/WAV)

[Informations about WAV file header](https://docs.fileformat.com/audio/wav/)

### IMPLEMENTATION DETAILS

- Ensure the program accepts two command-line arguments: the name of the input WAV file and the name of the output WAV file. If the program does not meet these conditions, print an appropriate error message and return `1`, ending the program.

- We’ll need to open the input file in `read-only` mode, since we’ll only read data from the input file. It may be wise to check that the file has been opened successfully. Otherwise, we should print an appropriate error message and return `1`, exiting the program.

- Complete the `check_format` function. `check_format` takes a single argument, a `WAVHEADER` called `header`, representing a struct containing the input file’s header. If header indicates the file is indeed a WAV file, the `check_format` function should return `true`. If not, `check_format` should return `false`. To check if a file is of the WAV format, we can compare the elements from the input file header to those we would expect from a WAV file. It suffices to show the `“WAVE”` marker characters are found in the format member of the `WAVHEADER` struct.

- Create and open the output file for writing. It would still be wise to check that the file has been opened successfully.

- Now that the file type has been verified, write the header to the output file. The reversed WAV file will still have the same underlying file structure as the input file (same size, number of channels, bits per sample, etc.), so it suffices to copy the header we read in from the input file to the output file.

- Implement the `get_block_size` function. `get_block_size`, like `check_format`, takes a single argument: this is a `WAVHEADER` called `header`, representing the struct containing the input file’s header. `get_block_size` should return an integer representing the block size of the given WAV file, in bytes. We can think of a block as a unit of auditory data. For audio, we calculate the size of each block with the following calculation:

  ```number of channels multiplied by bytes per sample```.

  Luckily, the header contains all the information we need to compute these values.

- And now the actual audio reversing takes place. To do this, we need to read in each block of auditory data starting from the very end of the input file and moving backwards, simultaneously writing each block to the output file so they are written in reverse order. We’ll want to be sure we read through all of the audio, but don’t erroneously copy any of the data from the header! Additionally, for testing purposes, we would like to maintain the order of the channels for each audio block. For example, in a WAV file with two channels (stereophonic sound), we want to make sure that the first channel of the last audio block in the input becomes the first channel of the first audio block in the output.
