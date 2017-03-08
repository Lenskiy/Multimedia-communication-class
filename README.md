# Multimedia communication and digital broadcasting

### Course description


You have probably heard of such big names as Kakao talk, Skype, WhatsApp, or Tango. Well, all of these apps cost billions of dollars and were established just a few years ago. The core technologies of these apps are text messaging, and real-time communication and lossy/lossless compression. The text messaging part is relatively easy to implement and is based on network sockets; we will briefly discuss them. However, the multimedia communication, i.e. transmission of audio and video is more sophisticated because of two reasons. Firstly, multimedia content is very heavy and as result requires compression. Secondly, often audio and video have to be transferred in real-time over unreliable channels, so packets can be lost, or received in a wrong order.  All these issues have to be addressed.

Thus, in this course we will focus on the theory and the practice of broadcasting of multimedia content. First, we cover the real-time transfer protocol (RTP) and Real Time Control Protocol (RTCP) as well as streaming over TCP and HTTP, that are used for delivering almost any kind of multimedia content. Then, we will study coding theory and the coding standards that include JPEG (Motion JPEG), H.26x and MPEG. These standards are also used in many Internet Video Broadcasting services; the most famous example is YouTube service.  

###Lab: Command line interface in Linux, Building tools

###### Problem 1. Command Line Interface of Linux (See "The linux Command Line" textbook for further details)
1.	Open terminal (_hint_: press Ctrl Alt t)
2.	Create folder c_language in your home folder ~/ (_hint_: use mkdir)
3.	Create folder lab1in the folder c_language (_hint_: use mkdir)
4.	Enter the folder ~/c_language/lab1(_hint_: use cd)
5.	Create file first.c (_hint_: use touch) 
6.	Copy first.c to second.c in the same folder (_hint_: use cp)
7.	Delete second.c (_hint_: use rm)
8.	Rename first.c to lab1.c (_hint_ use mv)

###### Problem 2.  Install Eclipse. The process of eclipse installation and Java VM is performed in the shell. 
1. 	Depending on your OS, download eclipse for C++  (http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/mars2), 64 bit, or 32 bit.

2. 	Extract the file by double clicking on the archive or by typing 

	tar xvfz eclipse-cpp-mars-2-linux-gtk-x86_64.tar.gz 
	or
	tar xvfz eclipse-cpp-mars-2-linux-gtk.tar.gz

3. 	Eclipse is written in Java,  thus to run Eclipse you have to download Java Virtual Machine
	http://www.oracle.com/technetwork/java/javase/downloads/jdk8-downloads-2133151.html

4.	Create a folder as a super user (sudo)
	```
	sudo mkdir /usr/local/java
	```
	Copy the downloaded file to /usr/local/java by typing
	```
	sudo cp -r jdk-8u73-linux-x64.tar.gz /usr/local/java
	```
	or	
	``` 
	sudo cp -r jdk-8u73-linux-i586.tar.gz /usr/local/java
	```
	Unpack the compressed Java binaries, in the directory /usr/local/java
	```
			sudo tar xvzf jdk-8u73-linux-x64.tar.gz 
	```
	or 	
	```
	    sudo tar xvzf jdk-8u73-linux-i586.tar.gz
	```
5.	Type sudo nano /etc/profile
	Scroll down and add at the bottom of the file and the following
	````
	JRE_HOME=/usr/local/java/jdk1.8.0_73
	PATH=$PATH:$JRE_HOME/bin
	export JRE_HOME
	export PATH
	```
6.	Inform your Ubuntu Linux system where your Oracle Java JDK/JRE is located by typing
	```
	sudo update-alternatives --install "/usr/bin/java" "java" "/usr/local/java/jdk1.8.0_73/bin/java" 1
	sudo update-alternatives --set java /usr/local/java/jdk1.8.0_73/bin/java
	```
7.	Test by typing in the shell: java -version

###### Problem 3. Create a C project in Eclipse by giving the following name cbasic, 

1.	add new file main.c and type the following 
```
#include 

int main(){
printf("Hello world!");
return 0;
}
```
2.	Build and the following C program


###### Problem 4. Create a C project in Eclipse by giving the following name ctest. Implement a simple program that copies the characters from the standard input and writes them to standard outputs until EOF  (end of file) symbol occurs.

```
#include 
int main(){
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
    return 0;
}
```

Create a text file input.txt with some content and build the C program, then tests as follows:

1.	Creating a text file using nano:
`nano test.txt`
exit and save the file by pressing Ctrl X

2.	Run the compiled program and redirect the input form a keyboard to from a file:
`./ctest < test.txt`

###Lab: Imaging basics

######Problem 1: Implement two functions, one for reading and one for writing of the PGM P5(binary, greyscale) and P6(binary, color) types

The header for PGM files is defined as a C structure

```
struct image_header{
    char format[3]; //Image format, example: P5
    int rows;       //Image height
    int cols;       //Image width
    int levels;     //Number of gray/each color levels
};
```
######Problem 2: Implement RGB to YCbCr and YCbCr to RGB color space conversion

######Problem 3: Implement RGB to YCbCr and YCbCr to RGB color space conversion

The formulas for transforming RGB to YCbCr color spaces using integer arithmetics are given below
```
Y = ( 19595 * R + 38470 * G + 7471 * B ) >> 16;
Cb = ( 36962 * ( B - Y ) >> 16) + 128;
Cr = (46727 * ( R - Y ) >> 16) + 128;
```
and the formulas for inverse transformation to RGB from YCbCr are as follows
```
R = Y + (91881 * Cr >> 16) - 179;
G = Y -( ( 22544 * Cb + 46793 * Cr ) >> 16) + 135;
B = Y + (116129 * Cb >> 16) - 226;
```
######Problem 4: Image down- and up-sampling
Implement two functions. The first function accepts a YCbCr image and returns downsampled Cb and Cr channels according to 4:2:0 scheme.

The second function acceptes downsampled version of YCbCr image and upsamples it by simply copying each value to the four nearest neighbors in up-sampled image.
![alt text](http://i.stack.imgur.com/768xM.png "4:2:0")

######Problem 5: Calculate PSNR
Implement a function that accepts two argumetns, which is an original image and areconstructed image and returns Peak Signal-to-Noise Ratio (PSNR). The PSNR is calcualted as follows

`MSE = (1/(m*n))*sum(sum((f-g).^2))`

`PSNR = 20*log(max(max(f)))/((MSE)^0.5)`

######Problem 6: All the above functions should be tested in the following final program

* Read a color PPM image.
* Equalize histogram
* Convert RGB image to YCbCr.
* Down-sample YCbCr to 4:2:0, i.e. uses the 2:1 horizontal downsampling and the 2:1 vertical downsampling. You will irreversibly lose information here.
* Up-sample Cb and Cr channels to the original resolution
* Convert obtained YCbCr image to RGB image.
* Calculate PSNR between original RGB image and the reconstructed one.


###Lab: Information theory

######Problem 1: Implement a function that calculates the information entropy (Shannon entropy) of a given data.

* To test the implemented code for entropy estimation, use the source code program as an input:

__./entropy < main.c__

* Generate a 10000 bytes file with random characters. Use the following code

```
//randtest.cpp: Generates 10000 bytes of data
//Compile: gcc -o randtest randtest.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int x;
    char *pc = (char *)&x;
    for ( int i = 0; i < 10000; ++i ){ //output 10000 bytes
        x = rand();                    //output only lowest byte
        putchar ( (int) *pc );         //output one byte
    }
    return 0;
}
```
* Use two PBM files attached as inputs for your program, compare the entropies of the content of each file.

######Problem 2: Compare the Shannon's entropy and the Kolmogorov's complexity

Modify your program in such way that its source size is minimized, then calculate its entropy and Kolmogorov complexity then compare them with the original code’s entropies and Kolmogorov complexity.

###Lab: Block representation

######Problem 1: Implement the function that splits a grayscale image into an array of blocks of a given size

######Problem 2: Implement the function that splits an RGB image into RGB macroblocks of 16x16 size

######Problem 3: Implement the function that splits an RGB image into macroblocks and converts them to YCbCr using 4:2:0  

###Lab: Discrete cosine transform

######Problem 1.  Test the DCT and IDCT functions

Build and test the DCT and IDCT functions.

######Problem 2. Increase the block size and test it on an image of the same size

Modify the above program by increasing the block size to 64 by 64, and instead of using an artificially generated input image, load a grayscale image 64 x 64  and use it as an input.

######Problem 3. Implement simple frequency filtering

* After calculating DCT in the previous problem set high frequency components  (i.e 64 < u + v) to zero and then invoke IDCT.
* Repeate the same experiemnt but this time remove lowe frequencies (i.e. u + v < 8) but keep the zero frequency F(0,0) untouched.

######Problem 4. Split an image into blocks and apply DCT and IDCT on each of them

Implement a function that splits an input image into blocks of 8 by 8 size and call DCT and IDCT on each block. For partitioning an image into blocks see previous lab.

######Problem 5. Block based filtering

In the previous problem set higher frequency components in each DCT block to zero.

 
###Lab:  Image compression via DCT coefficients quantization and Run-level coding

So far we implemented RGB to YCbCr conversion and splitting an image into 8 x 8 blocks following 4:2:0 convention.
We implemented a simple DCT and IDCT algorithms. In this lab the functions for forward and inverse quantization,
zigzag reordering and run-level encoding and decoding are studied. The task of this lab is
to test presented functions in one program. The programs should read a PBM file, compress it
using the above functions and then decompress it and stored in a file.

######Problem 1.  Implement an encoder program that performs the following steps
* Read a grayscale P5 type PBM image
* Split into 8 x 8 blocks and apply DCT to every block
* Quantize DCT coefficients
* Apply zigzag reordering
* Apply run-level encoding and store the codes in `Run3D  runs[64];`
* Print them on the screen, while running the program redirect standard stream to a file i.e.
__./encode image.pbm > run3d.code__


######Problem 2.  Implement a decoder program that performs the following steps

* Read run-level code from a standard input. To do so, redirect standard input form a keyboard to from a file i.e.
__./encode image_t.pbm < run3d.code__
* Decode run-level code
* Apply inverse zigzag ordering
* Inverse quantize DCT coefficients
* Perform IDCT or every DCT block, and assemble the image
* Store the reconstructed image into a PBM file


######Problem 3. Compare original and reconstructed images

* Read original image.pbm and reconstructed image_t.pbm
* Calculate and print out the PSNR. The PSNR is calculated as follows

`MSE = (1/(m*n))*sum(sum((f-g)^2))`

`PSNR = 20*log(max(max(f)))/((MSE)^0.5)`


###Lab:  Huffman coding

######Problem 1. Huffman tree traversal

* Implement the following code:
```
#include <stdio.h>

char huff_decode(unsigned char htree[], int N, unsigned char buffer[], unsigned long *bit_num){
    int loc0, loc = 3 * N - 3;             //start from root, N = # of symbols
    do {
        loc0 = loc;                //in is data pointer pointing to
        //  encoded data
        if ( read_one_bit(buffer, (*bit_num)++) == 0 ) //a 0, go left
            loc = htree[loc0];
        else
            loc =  htree[loc0 - 1];  //a 1, go right
    } while ( loc >= N );        //traverse until reach leaf

    return htree[loc];           //return symbol
}


int main(int argc, const char * argv[]) {
    static unsigned long bit_num = 0;
    unsigned char buffer[] = {74, 191, 186, 128};
    unsigned char htree[] = {'a', 'b', 'c', 'd', 'e', 3, 2, 6, 1, 4, 8, 10, 0};

    printf("Decoded sequence: ");
    do{
        printf("%c", huff_decode(htree, 5, buffer,  &bit_num));
    }while(bit_num < sizeof(buffer) * 8);

    return 0;
}
```
* Feel up htree with a different Huffman tree
* Change content of the buffer accordingly

######Problem 2. Alternative repesenation of a Huffman tree
* Change and test the modified decoding function given as follows:
```
char huff_decode2(unsigned char htree[], int N, unsigned char buffer[], unsigned long *bit_num){
    //N = # of symbols
    unsigned short left_mask = 0xFF00; //to extract upper byte(left child)
    unsigned short  right_mask = 0x00FF; //to extract lower byte(right child)
    int loc0, loc = ( N - 1 ) + N; //start from root; add offset N to
    // distinguish pointers from symbols

    do {
        loc0 = loc - N;
        if ( read_one_bit(buffer, (*bit_num)++) == 0 ){  //a 0, go left
            loc = ( htree[loc0] & left_mask ) >> 8;
        } else{
            loc =  htree[loc0] & right_mask;
        }
    } while ( loc >= N );       //traverse until reaches leaf
    return loc;                 //symbol value = loc
}
```

###Lab: Socket programming

###Lab: Broadcasting over HTTP

###Lab: Real-time Transfer Protocol

######Problem 1:  Download the source codes attached. Build sender and receiver. To build use the following commands in the terminal:
__gcc receiver.c rtp.c -o receiver__

__gcc sender.c rtp.c -o sender__

Select an image file of your choice, and execute the receiver as follows

__./receiver 12345 > image_rcv.jpg__

then in a new terminal window execute

__./sender 127.0.0.1 12345 < image.jpg__

where 12345 is a port of a receiver and image.jpg is your image file.
The symbols < and > are used to redirect standard output and input.  By typing sender < image.jpg we redirect input from a file, instead of a keyboard and by typing receiver > image_rcv.jpg  we redirect output to  a file instead of a screen.

######Problem 2:  Study source codes very carefully and add detailed comments for as many statements as you think is necessary, keeping in mind that the more the better. The goal of this problem is to understand the codes in depth.  



###Final project

The goal of the project is to develop image transmission software that uses RTP as a transport. Before the transmission an image is compressed. 

The project employs RTP transmission software we studied before, and color compression that employs imperfections in human visual system. Thus, the software should include the following functionality

* Reading and writing PBM files
* Color space conversion RGB to YCbCr and YCbCr to RGB
* Down and upsampling
* Sending and receiving data using RTP

For simplicity assume that receiver knows parameters of the image being transmitted. Make sure that the image is transmitted in a compressed form.

The main function of the sender can be represented in the flow chart shown below:

`Read a PBM image --> Convert to YCbCr --> Downsample Cb and Cr --> Send using RTP`

The main function of the receiver can be represented in the flow chart shown below:

`Receive using RTP --> Upsample --> Convert to RGB --> Write to a PBM file`


You have to decide how compressed image is transmitted. Either every channel is transmitted separately i.e. with three different `rtp_send_packets calls`, or first you combine three color channels Y, Cb and Cr into a contiguous memory block and then send it at once.

The submitted source codes should contain substantial amount of comments.
