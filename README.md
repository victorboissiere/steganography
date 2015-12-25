# Simple steganography program

## How to compile

In order to compile the program you must have opencv installed.
Then you can run make or make debug if you want to be able
to debug your program (ie gdb).

## Usage

### How to hide file content

```
./hide image path_of_text_to_hide
```

-Path_of_text_to_hide : file content to hide in an image
-Image : image where the text will be hidden

### How to find content back

```
./find image
```

The hidden content will be printed on the standart output.

## Details

This is a simple program with no deep security. It is just a simple way to hide
some text into an image.


